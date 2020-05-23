

#include "window.hpp"
Window::
Window()
  : QWidget(), render_area(new RenderArea(this))
{
}

Window::
~Window(){
}
