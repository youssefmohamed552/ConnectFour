# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.o: app_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.o -c /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build/app_autogen/mocs_compilation.cpp

CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build/app_autogen/mocs_compilation.cpp > CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.i

CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build/app_autogen/mocs_compilation.cpp -o CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.s

CMakeFiles/app.dir/main.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/app.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/main.cpp.o -c /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/main.cpp

CMakeFiles/app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/main.cpp > CMakeFiles/app.dir/main.cpp.i

CMakeFiles/app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/main.cpp -o CMakeFiles/app.dir/main.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/app.dir/main.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/app_autogen/mocs_compilation.cpp.o
app: CMakeFiles/app.dir/main.cpp.o
app: CMakeFiles/app.dir/build.make
app: libwindow.a
app: libgui.a
app: librender_area.a
app: /usr/local/Cellar/qt/5.14.2/lib/QtWidgets.framework/QtWidgets
app: /usr/local/Cellar/qt/5.14.2/lib/QtGui.framework/QtGui
app: /usr/local/Cellar/qt/5.14.2/lib/QtCore.framework/QtCore
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app

.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build /Users/youssefhussein/programming/cplusplus/ai/connect_four/GUI/build/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend

