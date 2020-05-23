cmake_minimum_required(VERSION 3.12)
project(graphics)

add_definitions("-std=c++11")




set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)





# find_package(sdl2 REQUIRED)
# find_package(glew REQUIRED)
# find_package(qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED PATHS "/usr/local/Cellar/qt/5.14.2/lib/cmake/Qt5" NO_DEFAULT_PATH)

# message("Qt5_NOT_FOUND: ${Qt5_FOUND}")
# if(${Qt5_NOT_FOUND})
  # message("Qt5 was not found")
# endif()

# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
    #  message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

include_directories(include)

add_library(gui src/gui.cpp)
target_link_libraries(gui Qt5::Widgets)
add_library(window src/window.cpp)
target_link_libraries(window Qt5::Widgets)
add_library(render_area src/render_area.cpp)
target_link_libraries(render_area Qt5::Gui Qt5::Widgets)

add_executable(app main.cpp)

# target_link_libraries(app gui ${SDL2_LIBRARIES})
target_link_libraries(app window gui render_area Qt5::Gui Qt5::Widgets)
