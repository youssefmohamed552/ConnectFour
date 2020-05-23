/*
 * Author: Youssef Hussein
 * Project: Connect Four
 * Topic: Artificial Intelligence
 */

#include <iostream>
#include <QtWidgets>

#include "game.hpp"
#include "game/connect_four_game.hpp"
#include "player.hpp"
#include "gui/window.hpp"


int
main(int argc, char* argv[]){
  QApplication app(argc, argv);

  // create the players
  Player* player1 = new HumanPlayer();
  // Player* player1 = new  MiniMaxPlayer(game);
  Player* player2 = new H_MiniMaxPlayer(5);

  // create the game
  ConnectFour* game = new ConnectFour(player1,player2);



  Window window(game);
  window.setWindowTitle("Connect Four");
  window.resize(640, 480);
  window.show();



  // bool player1_turn = true;

  // GameState g_state = S_GOING;

  // while(g_state == S_GOING){

    // if(player1_turn) g_state = player1->move();
    // else g_state = player2->move();
    // if(g_state == S_FAILED){
      // std::cout << "The Game Failed !!\n";
      // return EXIT_FAILURE;
    // }
    // game->display();
    // player1_turn = !player1_turn;

    // if(g_state == S_DONE){
      // int score = game->current_state()->utility();
      // if(score == 0)
        // std::cout << "GAME OVER: the game is a draw\n";
      // else
        // std::cout << "GAME OVER: Player " << ((!player1_turn)? "1":"2") << " Wins\n";
    // }
  // }



  // delete player2;
  // delete player1;
  // delete game;


  return app.exec();
  // return EXIT_SUCCESS;
}
