#pragma once

#include <QtWidgets>

#include "render_area.hpp"

class Window : public QWidget{
  // Q_OBJECT
  private:
    RenderArea* render_area;
  public:
    Window();
    ~Window();
};
