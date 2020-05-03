cmake_minimum_required( VERSION 2.8 )
project( connect_four )

add_definitions("-std=c++11")

include_directories(include)
add_library(state lib/state.cpp)
add_library(game lib/game.cpp)
add_library(player lib/player.cpp)
add_library(action lib/action.cpp)
add_executable(app main.cpp)

add_executable(test test.cpp)

target_link_libraries(app state game action player)
