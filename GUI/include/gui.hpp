#pragma once


#include <QtWidgets>

// enum class Status{RUNNING, EXIT};

class GUI: public QWidget{
// class GUI{
  private:
    int m_screen_width;
    int m_screen_height;

  public:
    GUI();
    ~GUI();

};
