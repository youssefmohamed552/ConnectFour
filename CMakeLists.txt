cmake_minimum_required( VERSION 2.8 )
project( connect_four )

add_definitions("-std=c++11")

set(MINIMAX_AI_PKG_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/minimax_ai")
set(MINIMAX_AI_CONFIG_PATH "${MINIMAX_AI_PKG_PATH}/bin/MinimaxAI")
set(MINIMAX_AI_INCLUDE_DIR "${MINIMAX_AI_PKG_PATH}/include")

list(APPEND CMAKE_PREFIX_PATH "${MINIMAX_AI_CONFIG_PATH}")

find_package(minimax_ai REQUIRED)

include_directories(include ${MINIMAX_AI_INCLUDE_DIR}) 

add_library(connect_four_game src/connect_four_game.cpp)
add_library(connect_four_state src/connect_four_state.cpp)
add_library(connect_four_action src/connect_four_action.cpp)

add_executable(app main.cpp)


target_link_libraries(
  app
  connect_four_game
  connect_four_state
  connect_four_action
  MinimaxAI::player
  MinimaxAI::state
  MinimaxAI::game
  MinimaxAI::action
)
