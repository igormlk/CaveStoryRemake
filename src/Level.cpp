//
// Created by igor on 16/09/18.
//

#include "../headers/Level.h"
#include "../headers/Graphics.h"
#include "../headers/globals.h"
#include <SDL2/SDL.h>
#include <tinyxml2.h>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <boost/algorithm/string.hpp>

using namespace tinyxml2;

Level::Level()
{

}

Level::Level(std::string mapName, Vector2 spawnPoint, Graphics &graphics) :
            _mapName(mapName),_spawnPoint(spawnPoint),_size(Vector2::zero())
{
    this->loadMap(mapName,graphics);
}

Level::~Level()
{

}

void Level::update(int elapsedTime)
{

}

void Level::draw(Graphics &graphics)
{
    //Draw the background
    for(int i = 0; i < this->_tileList.size(); i++)
        this->_tileList.at(i).draw(graphics);

}

void Level::loadMap(std::string name, Graphics &graphics)
{
    ///Parse the .tmx file
    XMLDocument doc;
    std::stringstream ss;

    ss << "../maps/" << name << ".tmx";
    doc.LoadFile(ss.str().c_str());

    XMLElement * mapNode = doc.FirstChildElement("map");

    //Width and height of the whole map
    int width, height;
    mapNode->QueryAttribute("width", &width);
    mapNode->QueryAttribute("height", &height);
    this->_size = Vector2(width,height);

    int tileWidth, tileHeight;
    //get the width and height of the tiles and store it in _tileSize
    mapNode->QueryAttribute("tilewidth", &tileWidth);
    mapNode->QueryAttribute("tileheight", &tileHeight);
    this->_tileSize = Vector2(width, height);

    XMLElement * pTileset = mapNode->FirstChildElement("tileset");
    if(pTileset != nullptr)
    {
        while(pTileset)
        {
            int firstGid = 0;
            const char * src = pTileset->Attribute("source",0);
            std::string strTeste(src);
            boost::replace_all(strTeste,".tsx", ".png");
            pTileset->QueryAttribute("firstgid", &firstGid);
            SDL_Texture * tex = SDL_CreateTextureFromSurface(graphics.getRenderer(),graphics.loadImage(strTeste));
            _tileSets.push_back(Tileset(tex,firstGid));
            pTileset = pTileset->NextSiblingElement("tileset");
        }
    }

    //Load layers
    XMLElement * pLayer = mapNode->FirstChildElement("layer");
    if(pLayer != nullptr)
    {
        while(pLayer)
        {
            XMLElement * pData = pLayer->FirstChildElement("data");
            std::string stringT(pData->GetText());
            boost::replace_all(stringT,"\n","");
            std::vector<std::string> tilesArray;
            splitTiles(stringT, tilesArray);
            Tileset tls;
            int tileCounter = 0;
            for(tileCounter = 0; tileCounter < tilesArray.size(); tileCounter++)
            {
                int gid = atoi(tilesArray[tileCounter].c_str());
                if(gid == 0)
                    continue;

                for(int j = 0; j < _tileSets.size(); j++)
                {
                    if(this->_tileSets[j].getFirstGid() <= gid)
                    {
                        tls = this->_tileSets[j];
                        break;
                    }
                }

                if(tls.getFirstGid() == -1)
                    continue;

                int xx = 0;
                int yy = 0;

                xx = tileCounter % width;
                xx *= tileWidth;
                yy += tileHeight * (tileCounter / width);
                Vector2 finalTilePosition = Vector2(xx,yy);

                int tilesetWidth, tilesetHeight;
                SDL_QueryTexture(tls.getTexture(),NULL, NULL, &tilesetWidth, &tilesetHeight);
                int tsxx = gid % (tilesetWidth / tileWidth) - 1;
                tsxx *= tileWidth;

                int tsyy = 0;
                int amt = (gid / (tilesetWidth / tileWidth));
                tsyy = tileHeight * amt;

                Vector2 finalTileSetPosition = Vector2(tsxx, tsyy);

                Tile tile (tls.getTexture(), Vector2(tileWidth, tileHeight), finalTileSetPosition,finalTilePosition);
                this->_tileList.push_back(tile);

            }


            pLayer = pLayer->NextSiblingElement("layer");
        }
    }

    //parse out the collisions
    XMLElement * pObjectGroup = mapNode->FirstChildElement("objectgroup");

    if(pObjectGroup != nullptr)
    {
        while(pObjectGroup)
        {
            const char *  name = pObjectGroup->Attribute("name");
            std::stringstream ss;
            ss << name;
            parseCollisions(pObjectGroup, ss, this->_collisionRects);
            parseSpawnPoints(pObjectGroup, ss);

            pObjectGroup = pObjectGroup->NextSiblingElement("objectgroup");
        }
    }


}

void Level::parseCollisions(XMLElement * pObjectGroup, const std::stringstream &ss, std::vector<Rectangle> & list) const
{
    if(ss.str() == "collisions")
    {
        XMLElement * pObject = pObjectGroup->FirstChildElement("object");
        if(pObject != nullptr)
        {
            while(pObject)
            {
                float x,y,width,height;
                x = std::ceil(pObject->FloatAttribute("x")) * globals::SPRITE_SCALE;
                y = std::ceil(pObject->FloatAttribute("y")) * globals::SPRITE_SCALE;
                width = std::ceil(pObject->FloatAttribute("width")) * globals::SPRITE_SCALE;
                height = std::ceil(pObject->FloatAttribute("height")) * globals::SPRITE_SCALE;

                Rectangle r = Rectangle(x,y,width,height);

                list.push_back(r);
                pObject = pObject->NextSiblingElement("object");
            }
        }
    }
}

void Level::splitTiles(std::string &stringT, std::vector<std::string> &tilesArray) const
{
    boost::split(tilesArray, stringT, boost::algorithm::is_any_of(","));
}

std::vector<Rectangle> Level::checkTileCollisions(const Rectangle &other)
{
    std::vector<Rectangle> others;
    for(Rectangle i : this->_collisionRects)
    {
        if(i.collidesWith(other))
        {
            others.push_back(i);
        }
    }
    return others;
}

void Level::parseSpawnPoints(tinyxml2::XMLElement *pObjectGroup, std::stringstream &ss)
{
    if(ss.str() == "spawnPoints")
    {
        XMLElement *pObject = pObjectGroup->FirstChildElement("object");
        if (pObject != nullptr)
        {
            while (pObject)
            {
                float x, y;
                x = std::ceil(pObject->FloatAttribute("x")) * globals::SPRITE_SCALE;
                y = std::ceil(pObject->FloatAttribute("y")) * globals::SPRITE_SCALE;
                const char * name = pObject->Attribute("name");
                std::stringstream strName;
                strName << name;
                setPlayerSpawnPoint(x, y, strName);

                pObject = pObject->NextSiblingElement("object");
            }
        }
    }
}

void Level::setPlayerSpawnPoint(float x, float y, const std::stringstream &strName)
{
    if(strName.str() == "player")
    {
        _spawnPoint = Vector2(x,y);
    }
}

const Vector2 Level::getPlayerSpawnPoint() const
{
    return _spawnPoint;
}
