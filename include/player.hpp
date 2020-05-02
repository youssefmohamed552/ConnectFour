#ifndef PLAYER_HPP
#define PLAYER_HPP


#include <unordered_set>
#include "game.hpp"


class Player{
  protected:
    Game* m_game;
    int m_order;
    // std::unordered_set<Action*> m_actions;
  public:
    static int count;
    virtual ~Player();
    virtual GameState move() = 0;
};

class HumanPlayer : public Player {
  public:
    HumanPlayer(Game* game);
    virtual ~HumanPlayer();
    virtual GameState move();
};

class ComputerPlayer : public Player {
  public:
    virtual ~ComputerPlayer();

};

class RandomPlayer : public ComputerPlayer {
  public:
    RandomPlayer(Game* game);
    virtual ~RandomPlayer();
    virtual GameState move();
    int get_random_number(int bound);
};

class MiniMaxPlayer : public ComputerPlayer {
  // private;
    // StateNode m_root;
  public:
    MiniMaxPlayer(Game* game);
    virtual ~MiniMaxPlayer();
    virtual GameState move();
    StateNode& search(StateNode& s, int player_order, int depth, bool is_maximize);
    std::pair<int,int> eval(StateNode root, bool is_maximize, int depth);
};

class H_MiniMaxPlayer : public ComputerPlayer {
  // TODO
};



#endif /* PLAYER_HPP */
