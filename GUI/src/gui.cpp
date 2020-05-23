

#include <iostream>
#include "gui.hpp"

GUI::
GUI()
  : QWidget()
{
}

GUI::
~GUI(){
}

/*
void
GUI::
init_systems(){
  SDL_Init(SDL_INIT_VIDEO);
  m_window = SDL_CreateWindow("GUI", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_screen_width, m_screen_height, SDL_WINDOW_OPENGL);
  if(m_window == nullptr){
    std::cerr << "Window creation didn't";
    return;
  }
}

void
GUI::
run(){
  init_systems();
  loop();
}

void
GUI::
loop(){
  while(m_status != Status::EXIT){
    process_input();
  }
}


void
GUI::
process_input(){
  SDL_Event ev;
  while(SDL_PollEvent(&ev)){
    switch(ev.type){
      case SDL_QUIT:
        m_status = Status::EXIT;
        break;
    }
  }
}
*/
