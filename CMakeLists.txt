cmake_minimum_required( VERSION 2.8 )
project( connect_four )

add_definitions("-std=c++11")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(MINIMAX_AI_PKG_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/minimax_ai")
set(MINIMAX_AI_CONFIG_PATH "${MINIMAX_AI_PKG_PATH}/bin/MinimaxAI")
set(MINIMAX_AI_INCLUDE_DIR "${MINIMAX_AI_PKG_PATH}/include")


list(APPEND CMAKE_PREFIX_PATH "/Library/Frameworks")
list(APPEND CMAKE_PREFIX_PATH "${MINIMAX_AI_CONFIG_PATH}")

message("the path used by packages : ${CMAKE_PREFIX_PATH}")

find_package(minimax_ai REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED HINTS "/usr/local/Cellar/qt/5.14.2/lib/cmake/Qt5")
# find_package(sdl2 REQUIRED)
# find_package(glew REQUIRED)




include_directories(include ${MINIMAX_AI_INCLUDE_DIR}) 

# add_library(connect_four_game src/connect_four_game.cpp)

# add_library(connect_four_state src/connect_four_state.cpp)
# add_library(connect_four_action src/connect_four_action.cpp)
add_library(
  connect_four_game 
  src/game/connect_four_action.cpp
  src/game/connect_four_state.cpp
  src/game/connect_four_game.cpp
)

add_library(
  connect_four_gui
  src/gui/window.cpp
  src/gui/render_area.cpp
)
target_link_libraries(
  connect_four_gui
  Qt5::Gui
  Qt5::Widgets
)

add_executable(app main.cpp)


target_link_libraries(
  app
  connect_four_game
  connect_four_gui
  MinimaxAI::player
  MinimaxAI::state
  MinimaxAI::game
  MinimaxAI::action
  Qt5::Gui
  Qt5::Widgets
)
