#pragma once

#include <QtWidgets>

#include "gui/render_area.hpp"
#include "game.hpp"

class Window : public QWidget{
  // Q_OBJECT
  private:
    RenderArea* m_render_area;
  public:
    Window(ConnectFour* game);
    ~Window();
};
