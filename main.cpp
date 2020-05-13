/*
 * Author: Youssef Hussein
 * Project: Connect Four
 * Topic: Artificial Intelligence
 */

#include <iostream>

#include "game.hpp"
#include "connect_four_game.hpp"
#include "player.hpp"


int
main(int argc, char* argv[]){
  std::cout << "This is Connect Four!! \n";

  std::cout << "Which game would you like to play:\n";
  std::cout << "1. Connect Four 3x3x3\n";
  std::cout << "2. Connect Four 3x5x3\n";
  std::cout << "3. Connect Four 6x7x4\n";
  int choice = 3; 
  // std::cin >> choice;
  while(choice > 3 || choice < 1){
    std::cout << "please choose one of the optionsi: ";
    std::cin >> choice;
  }
  Game* game;
  if(choice == 1) game = new ConnectFour(3,3,3);
  if(choice == 2) game = new ConnectFour(5,3,3);
  if(choice == 3) game = new ConnectFour(7,6,4);

  // create the game

  // create the players
  Player* player1 = new HumanPlayer(game);
  // Player* player1 = new  MiniMaxPlayer(game);
  Player* player2 = new H_MiniMaxPlayer(game, 5);

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

    if(g_state == S_DONE){
      int score = game->current_state()->utility();
      if(score == 0)
        std::cout << "GAME OVER: the game is a draw\n";
      else
        std::cout << "GAME OVER: Player " << ((!player1_turn)? "1":"2") << " Wins\n";

    }
  }



  delete player2;
  delete player1;
  delete game;


  return EXIT_SUCCESS;
}
