/*
 * Author: Youssef Hussein
 * Project: Connect Four
 * Topic: Artificial Intelligence
 */

#include <iostream>

#include "game.hpp"
#include "player.hpp"


int
main(int argc, char* argv[]){
  std::cout << "This is Connect Four!! \n";

  // create the game
  Game* game = new ConnectFour();

  // create the players
  Player* player1 = new HumanPlayer(game);
  Player* player2 = new MiniMaxPlayer(game);

  bool player1_turn = true;

  GameState g_state = S_GOING;

  while(g_state == S_GOING){
    if(player1_turn) g_state = player1->move();
    else g_state = player2->move();
    if(g_state == S_FAILED){
      std::cout << "The Game Failed !!\n";
      return EXIT_FAILURE;
    }
    game->display();
    player1_turn = !player1_turn;
  }

  std::cout << "GAME OVER: Player " << ((!player1_turn)? "1":"2") << " Wins\n";

  delete player2;
  delete player1;
  delete game;


  return EXIT_SUCCESS;
}
