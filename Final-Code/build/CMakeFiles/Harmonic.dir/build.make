# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build

# Include any dependencies generated for this target.
include CMakeFiles/Harmonic.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Harmonic.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Harmonic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Harmonic.dir/flags.make

CMakeFiles/Harmonic.dir/src/main.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/src/main.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/main.cpp
CMakeFiles/Harmonic.dir/src/main.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Harmonic.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/src/main.cpp.o -MF CMakeFiles/Harmonic.dir/src/main.cpp.o.d -o CMakeFiles/Harmonic.dir/src/main.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/main.cpp

CMakeFiles/Harmonic.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/main.cpp > CMakeFiles/Harmonic.dir/src/main.cpp.i

CMakeFiles/Harmonic.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/main.cpp -o CMakeFiles/Harmonic.dir/src/main.cpp.s

CMakeFiles/Harmonic.dir/src/utils.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/src/utils.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/utils.cpp
CMakeFiles/Harmonic.dir/src/utils.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Harmonic.dir/src/utils.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/src/utils.cpp.o -MF CMakeFiles/Harmonic.dir/src/utils.cpp.o.d -o CMakeFiles/Harmonic.dir/src/utils.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/utils.cpp

CMakeFiles/Harmonic.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/src/utils.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/utils.cpp > CMakeFiles/Harmonic.dir/src/utils.cpp.i

CMakeFiles/Harmonic.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/src/utils.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/utils.cpp -o CMakeFiles/Harmonic.dir/src/utils.cpp.s

CMakeFiles/Harmonic.dir/src/cage.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/src/cage.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/cage.cpp
CMakeFiles/Harmonic.dir/src/cage.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Harmonic.dir/src/cage.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/src/cage.cpp.o -MF CMakeFiles/Harmonic.dir/src/cage.cpp.o.d -o CMakeFiles/Harmonic.dir/src/cage.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/cage.cpp

CMakeFiles/Harmonic.dir/src/cage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/src/cage.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/cage.cpp > CMakeFiles/Harmonic.dir/src/cage.cpp.i

CMakeFiles/Harmonic.dir/src/cage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/src/cage.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/src/cage.cpp -o CMakeFiles/Harmonic.dir/src/cage.cpp.s

CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_impl_glfw.cpp
CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o -MF CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o.d -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_impl_glfw.cpp

CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_impl_glfw.cpp > CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.i

CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_impl_glfw.cpp -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.s

CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_impl_opengl3.cpp
CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o -MF CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o.d -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_impl_opengl3.cpp

CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_impl_opengl3.cpp > CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.i

CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_impl_opengl3.cpp -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.s

CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui.cpp
CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o -MF CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o.d -o CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui.cpp

CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui.cpp > CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.i

CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui.cpp -o CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.s

CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_demo.cpp
CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o -MF CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o.d -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_demo.cpp

CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_demo.cpp > CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.i

CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_demo.cpp -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.s

CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_draw.cpp
CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o -MF CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o.d -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_draw.cpp

CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_draw.cpp > CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.i

CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_draw.cpp -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.s

CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o: CMakeFiles/Harmonic.dir/flags.make
CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_widgets.cpp
CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o: CMakeFiles/Harmonic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o -MF CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o.d -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o -c /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_widgets.cpp

CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_widgets.cpp > CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.i

CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/depends/imgui/imgui_widgets.cpp -o CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.s

# Object files for target Harmonic
Harmonic_OBJECTS = \
"CMakeFiles/Harmonic.dir/src/main.cpp.o" \
"CMakeFiles/Harmonic.dir/src/utils.cpp.o" \
"CMakeFiles/Harmonic.dir/src/cage.cpp.o" \
"CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o" \
"CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o" \
"CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o" \
"CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o" \
"CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o" \
"CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o"

# External object files for target Harmonic
Harmonic_EXTERNAL_OBJECTS =

/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/src/main.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/src/utils.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/src/cage.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_glfw.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/depends/imgui/imgui_impl_opengl3.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/depends/imgui/imgui.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/depends/imgui/imgui_demo.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/depends/imgui/imgui_draw.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/depends/imgui/imgui_widgets.cpp.o
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/build.make
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: /opt/homebrew/lib/libglfw.3.3.dylib
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: /opt/homebrew/lib/libGLEW.2.2.0.dylib
/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic: CMakeFiles/Harmonic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Harmonic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Harmonic.dir/build: /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/Harmonic
.PHONY : CMakeFiles/Harmonic.dir/build

CMakeFiles/Harmonic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Harmonic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Harmonic.dir/clean

CMakeFiles/Harmonic.dir/depend:
	cd /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build /Users/vinayakgoel/Desktop/Computer-Graphics-Project/Final-Code/build/CMakeFiles/Harmonic.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Harmonic.dir/depend

