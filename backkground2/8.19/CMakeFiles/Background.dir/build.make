# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fzk/backkground2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fzk/backkground2/8.19

# Include any dependencies generated for this target.
include CMakeFiles/background.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/background.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/background.dir/flags.make

CMakeFiles/background.dir/background.cc.o: CMakeFiles/background.dir/flags.make
CMakeFiles/background.dir/background.cc.o: ../background.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/background.dir/background.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/background.dir/background.cc.o -c /home/fzk/backkground2/background.cc

CMakeFiles/background.dir/background.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/background.dir/background.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzk/backkground2/background.cc > CMakeFiles/background.dir/background.cc.i

CMakeFiles/background.dir/background.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/background.dir/background.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzk/backkground2/background.cc -o CMakeFiles/background.dir/background.cc.s

CMakeFiles/background.dir/src/EventAction.cc.o: CMakeFiles/background.dir/flags.make
CMakeFiles/background.dir/src/EventAction.cc.o: ../src/EventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/background.dir/src/EventAction.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/background.dir/src/EventAction.cc.o -c /home/fzk/backkground2/src/EventAction.cc

CMakeFiles/background.dir/src/EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/background.dir/src/EventAction.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzk/backkground2/src/EventAction.cc > CMakeFiles/background.dir/src/EventAction.cc.i

CMakeFiles/background.dir/src/EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/background.dir/src/EventAction.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzk/backkground2/src/EventAction.cc -o CMakeFiles/background.dir/src/EventAction.cc.s

CMakeFiles/background.dir/src/GasSD.cc.o: CMakeFiles/background.dir/flags.make
CMakeFiles/background.dir/src/GasSD.cc.o: ../src/GasSD.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/background.dir/src/GasSD.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/background.dir/src/GasSD.cc.o -c /home/fzk/backkground2/src/GasSD.cc

CMakeFiles/background.dir/src/GasSD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/background.dir/src/GasSD.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzk/backkground2/src/GasSD.cc > CMakeFiles/background.dir/src/GasSD.cc.i

CMakeFiles/background.dir/src/GasSD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/background.dir/src/GasSD.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzk/backkground2/src/GasSD.cc -o CMakeFiles/background.dir/src/GasSD.cc.s

CMakeFiles/background.dir/src/RunAction.cc.o: CMakeFiles/background.dir/flags.make
CMakeFiles/background.dir/src/RunAction.cc.o: ../src/RunAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/background.dir/src/RunAction.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/background.dir/src/RunAction.cc.o -c /home/fzk/backkground2/src/RunAction.cc

CMakeFiles/background.dir/src/RunAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/background.dir/src/RunAction.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzk/backkground2/src/RunAction.cc > CMakeFiles/background.dir/src/RunAction.cc.i

CMakeFiles/background.dir/src/RunAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/background.dir/src/RunAction.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzk/backkground2/src/RunAction.cc -o CMakeFiles/background.dir/src/RunAction.cc.s

CMakeFiles/background.dir/src/RunActionMessenger.cc.o: CMakeFiles/background.dir/flags.make
CMakeFiles/background.dir/src/RunActionMessenger.cc.o: ../src/RunActionMessenger.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/background.dir/src/RunActionMessenger.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/background.dir/src/RunActionMessenger.cc.o -c /home/fzk/backkground2/src/RunActionMessenger.cc

CMakeFiles/background.dir/src/RunActionMessenger.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/background.dir/src/RunActionMessenger.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzk/backkground2/src/RunActionMessenger.cc > CMakeFiles/background.dir/src/RunActionMessenger.cc.i

CMakeFiles/background.dir/src/RunActionMessenger.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/background.dir/src/RunActionMessenger.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzk/backkground2/src/RunActionMessenger.cc -o CMakeFiles/background.dir/src/RunActionMessenger.cc.s

CMakeFiles/background.dir/src/backgroundActionInitialization.cc.o: CMakeFiles/background.dir/flags.make
CMakeFiles/background.dir/src/backgroundActionInitialization.cc.o: ../src/backgroundActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/background.dir/src/backgroundActionInitialization.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/background.dir/src/backgroundActionInitialization.cc.o -c /home/fzk/backkground2/src/backgroundActionInitialization.cc

CMakeFiles/background.dir/src/backgroundActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/background.dir/src/backgroundActionInitialization.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzk/backkground2/src/backgroundActionInitialization.cc > CMakeFiles/background.dir/src/backgroundActionInitialization.cc.i

CMakeFiles/background.dir/src/backgroundActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/background.dir/src/backgroundActionInitialization.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzk/backkground2/src/backgroundActionInitialization.cc -o CMakeFiles/background.dir/src/backgroundActionInitialization.cc.s

CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.o: CMakeFiles/background.dir/flags.make
CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.o: ../src/backgroundDetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.o -c /home/fzk/backkground2/src/backgroundDetectorConstruction.cc

CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzk/backkground2/src/backgroundDetectorConstruction.cc > CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.i

CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzk/backkground2/src/backgroundDetectorConstruction.cc -o CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.s

CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.o: CMakeFiles/background.dir/flags.make
CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.o: ../src/backgroundPrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.o -c /home/fzk/backkground2/src/backgroundPrimaryGeneratorAction.cc

CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fzk/backkground2/src/backgroundPrimaryGeneratorAction.cc > CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.i

CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fzk/backkground2/src/backgroundPrimaryGeneratorAction.cc -o CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.s

# Object files for target background
background_OBJECTS = \
"CMakeFiles/background.dir/background.cc.o" \
"CMakeFiles/background.dir/src/EventAction.cc.o" \
"CMakeFiles/background.dir/src/GasSD.cc.o" \
"CMakeFiles/background.dir/src/RunAction.cc.o" \
"CMakeFiles/background.dir/src/RunActionMessenger.cc.o" \
"CMakeFiles/background.dir/src/backgroundActionInitialization.cc.o" \
"CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.o" \
"CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.o"

# External object files for target background
background_EXTERNAL_OBJECTS =

background: CMakeFiles/background.dir/background.cc.o
background: CMakeFiles/background.dir/src/EventAction.cc.o
background: CMakeFiles/background.dir/src/GasSD.cc.o
background: CMakeFiles/background.dir/src/RunAction.cc.o
background: CMakeFiles/background.dir/src/RunActionMessenger.cc.o
background: CMakeFiles/background.dir/src/backgroundActionInitialization.cc.o
background: CMakeFiles/background.dir/src/backgroundDetectorConstruction.cc.o
background: CMakeFiles/background.dir/src/backgroundPrimaryGeneratorAction.cc.o
background: CMakeFiles/background.dir/build.make
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4Tree.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4GMocren.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4visHepRep.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4RayTracer.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4VRML.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4OpenGL.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4gl2ps.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4interfaces.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4persistency.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4analysis.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4error_propagation.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4readout.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4physicslists.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4parmodels.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4FR.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4vis_management.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4modeling.so
background: /usr/lib/x86_64-linux-gnu/libSM.so
background: /usr/lib/x86_64-linux-gnu/libICE.so
background: /usr/lib/x86_64-linux-gnu/libX11.so
background: /usr/lib/x86_64-linux-gnu/libXext.so
background: /usr/lib/x86_64-linux-gnu/libGL.so
background: /usr/lib/x86_64-linux-gnu/libGLU.so
background: /usr/lib/x86_64-linux-gnu/libXmu.so
background: /usr/lib/x86_64-linux-gnu/libQtOpenGL.so
background: /usr/lib/x86_64-linux-gnu/libQtGui.so
background: /usr/lib/x86_64-linux-gnu/libQtCore.so
background: /usr/lib/x86_64-linux-gnu/libfreetype.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4run.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4event.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4tracking.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4processes.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4zlib.so
background: /usr/lib/x86_64-linux-gnu/libexpat.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4digits_hits.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4track.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4particles.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4geometry.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4materials.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4graphics_reps.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4intercoms.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4global.so
background: /home/fzk/geant4/g4.10.03/geant4.10.03-install/lib/libG4clhep.so
background: CMakeFiles/background.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fzk/backkground2/8.19/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable background"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/background.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/background.dir/build: background

.PHONY : CMakeFiles/background.dir/build

CMakeFiles/background.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/background.dir/cmake_clean.cmake
.PHONY : CMakeFiles/background.dir/clean

CMakeFiles/background.dir/depend:
	cd /home/fzk/backkground2/8.19 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fzk/backkground2 /home/fzk/backkground2 /home/fzk/backkground2/8.19 /home/fzk/backkground2/8.19 /home/fzk/backkground2/8.19/CMakeFiles/background.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/background.dir/depend

