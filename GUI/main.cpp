#include <iostream>
#include <QtWidgets>

#include "gui.hpp"
#include "window.hpp"


int
main(int argc, char** argv){
  QApplication app(argc, argv);
  Window window;
  window.setWindowTitle("Top-level Widget");
  window.resize(640, 480);
  window.show();

  return app.exec();
}
