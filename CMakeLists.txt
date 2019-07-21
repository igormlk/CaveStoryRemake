cmake_minimum_required(VERSION 3.10)
project(CaveStoryRemake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(Boost COMPONENTS thread REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_executable(CaveStoryRemake src/main.cpp headers/Graphics.h
                src/Graphics.cpp headers/Game.h src/Game.cpp headers/InputKeyboard.h
                src/InputKeyboard.cpp headers/Sprite.h src/Sprite.cpp headers/globals.h
                headers/Vector2.h src/Vector2.cpp headers/AnimatedSprite.h src/AnimatedSprite.cpp
                headers/Player.h src/Player.cpp headers/Level.h src/Level.cpp headers/Tile.h src/Tile.cpp headers/Tileset.h src/Tileset.cpp headers/Rectangle.h headers/Slope.h)

target_link_libraries(CaveStoryRemake ${SDL2_LIBRARIES} ${Boost_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} tinyxml2)
