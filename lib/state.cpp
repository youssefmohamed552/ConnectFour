#include <iostream>

#include "state.hpp"

State::
~State(){
  // std::cout << "State destroyed !!\n";
}

ConnectFourState::
ConnectFourState(int width, int height, int connect)
  : m_board(std::vector<ConnectFourToken>(width*height, T_EMPTY)), m_col(std::vector<int>(width)), m_width(width), m_height(height), m_connect(connect)
{
  // std::cout << "Connect Four State Created !!\n";
  m_utility = -2;
  m_status = S_NON_TERMINAL;
}


ConnectFourState::
~ConnectFourState(){
  // std::cout << "Connect Four State Destroyed !!\n";
}

void
ConnectFourState::
display() const {
  std::cout << "  ";
  for(int i = 0; i < m_width; i++)
    std::cout << i << " ";
  std::cout << std::endl;

  for(int i = 0; i < m_height; i++){
    std::cout << m_height - i - 1  << " ";
    for(int j = 0; j < m_width; j++){
      if(get(j, i) == T_EMPTY) std::cout << "  ";
      if(get(j, i) == T_RED) std::cout << "R ";
      if(get(j, i) == T_YELLOW) std::cout << "Y ";
    }
    std::cout << m_height - i - 1 << std::endl;
  }

  std::cout << "  ";
  for(int i = 0; i < m_width; i++)
    std::cout << i << " ";
  std::cout << std::endl;
}

bool
ConnectFourState::
act(const Action& a, int p){
  if(a.move() >= m_width || a.move() < 0) return false;
  int h = m_col[a.move()];
  if(h >= m_height ) return false;
  if(a.player() == 1)
    set(a.move(), m_height-h-1, T_RED);
  else
    set(a.move(), m_height-h-1, T_YELLOW);
  m_col[a.move()]++;
  compute_utility(p);
  return true;
}

// StateStatus
void
ConnectFourState::
compute_utility(int player_order) {
  ConnectFourToken player_token = (player_order == 1)? T_RED : T_YELLOW;
  int w = m_width - m_connect;
  int h = m_width - m_connect;



  // check horizontally
  for(int i = 0; i < m_height; i++){
    for(int j = 0; j <= w; j++){
      if(get(j, i) == T_EMPTY) continue;
      ConnectFourToken first_token = get(j, i);
      int k = 1;
      for(; k < m_connect; k++){
        if(get(j+k, i) != first_token) break;
      }
      if(k >= m_connect){
        m_utility =  ((first_token == player_order)? 1 : -1 );
        m_status = S_TERMINAL;
        return;
      }
    }
  }

  // check vertically
  for(int i = 0; i <= h; i++){
    for(int j = 0; j < m_width; j++){
      if(get(j, i) == T_EMPTY) continue;
      ConnectFourToken first_token = get(j, i);
      int k = 1;
      for(; k < m_connect; k++){
        if(get(j, i+k) != first_token) break;
      }
      if(k >= m_connect){
        m_utility =  ((first_token == player_order)? 1 : -1 );
        m_status = S_TERMINAL;
        return;
      }
    }
  }

  // check diagonally top right
  for(int i = 0; i <= h; i++){
    for(int j = 0; j <= w; j++){
      if(get(j, i) == T_EMPTY) continue;
      ConnectFourToken first_token = get(j, i);
      int k = 1;
      for(; k < m_connect; k++){
        if(get(j+k, i+k) != first_token) break;
      }
      if(k >= m_connect){
        m_utility =  ((first_token == player_order)? 1 : -1);
        m_status = S_TERMINAL;
        return;
      }
    }
  }


  // check diagonally bottom right
  for(int i = m_connect-1; i < m_width; i++){
    for(int j = 0; j <= h; j++){
      if(get(j, i) == T_EMPTY) continue;
      ConnectFourToken first_token = get(j, i);
      int k = 1;
      for(; k < m_connect; k++){
        if(get(j+k, i-k) != first_token) break;
      }
      if(k >= m_connect){
        m_utility =  ((first_token == player_order)? 1 : -1);
        m_status = S_TERMINAL;
        return;
      }
    }
  }



  StateStatus status = check_draw();
  if(status == S_TERMINAL){
    m_status = S_TERMINAL;
    m_utility = 0;
    return;
  }

  m_status = S_NON_TERMINAL;
}

StateStatus
ConnectFourState::
check_draw() const{
  for(int i = 0; i < m_width; i++){
    if(m_col[i] < m_height) return S_NON_TERMINAL;
  }
  return S_TERMINAL;
}



std::vector<Action*> 
ConnectFourState::
action_set(int player_order) const{
  std::vector<Action*> act_set;
  for(int i = 0; i < m_width; i++){
    if(m_col[i] >= m_height) continue;
    act_set.push_back(new ConnectFourAction(i,player_order));
  }
  return act_set;
}


State*
ConnectFourState::
copy(){
  ConnectFourState* new_state = new ConnectFourState(m_width, m_height, m_connect);
  *new_state = *this;
  return new_state;
}

StateStatus
ConnectFourState::
check_status(){
  // TODO
  return S_TERMINAL;
}



int
StateNode::
count = 0;

StateNode::
StateNode( State* state, int player)
  : m_state(state), m_player(player), m_utility(-2)
{
  // std::cout << "State Node Destroyed !!\n";
  count++;
}

StateNode::
StateNode( const StateNode& other){
  // std::cout << "State Node Copied !!\n";
  m_state = other.state()->copy();
  m_player = other.player();
  m_utility = other.utility();
  count++;
}

StateNode::
~StateNode(){
  // std::cout << "State Node Created !!\n";
}

bool
StateNode::
update(const Action& a, int p){
  bool res = m_state->act(a, p);
  m_utility = m_state->utility();
  return res;
}

