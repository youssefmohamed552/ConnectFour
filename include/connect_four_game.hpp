#ifndef CONNECT_FOUR_GAME_HPP
#define CONNECT_FOUR_GAME_HPP

#include <unordered_set>

#include "game.hpp"
#include "state.hpp"



class ConnectFour : public Game{
  bool is_player1 = true;
  public:
    ConnectFour(int width, int height, int connect);
    virtual ~ConnectFour();
    virtual GameState make_human_move(int player_order);
    virtual GameState make_move(const Action& action);
    virtual int utility(const State* s) const;
    virtual std::vector<Action*> action_set(int player_order) const;
    virtual GameState status(const State* s) const; 
};

#endif /* CONNECT_FOUR_GAME_HPP */
