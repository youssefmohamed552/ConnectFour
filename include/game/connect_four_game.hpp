#ifndef CONNECT_FOUR_GAME_HPP
#define CONNECT_FOUR_GAME_HPP

#include <unordered_set>

#include "game.hpp"
#include "state.hpp"
#include "player.hpp"



class ConnectFour : public Game{
  Player* m_player1;
  Player* m_player2;
  Player* m_current_player;
  bool is_player1 = true;
  public:
    ConnectFour(Player* player1, Player* player2);
    virtual ~ConnectFour();
    virtual GameState make_human_move(int player_order);
    virtual GameState make_move(const Action& action);
    virtual int utility(const State* s) const;
    virtual std::vector<Action*> action_set(int player_order) const;
    virtual GameState status(const State* s) const; 
    Player* current_player(){return m_current_player; }
    void next_player();
};

#endif /* CONNECT_FOUR_GAME_HPP */
