

#include "gui/window.hpp"
Window::
Window(ConnectFour* game)
  : QWidget(), m_render_area(new RenderArea(this, game))
{
}

Window::
~Window(){
}
