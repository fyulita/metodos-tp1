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
CMAKE_COMMAND = /snap/clion/111/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/111/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/ejec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ejec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ejec.dir/flags.make

CMakeFiles/ejec.dir/main.o: CMakeFiles/ejec.dir/flags.make
CMakeFiles/ejec.dir/main.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ejec.dir/main.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ejec.dir/main.o -c "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/main.cpp"

CMakeFiles/ejec.dir/main.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejec.dir/main.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/main.cpp" > CMakeFiles/ejec.dir/main.i

CMakeFiles/ejec.dir/main.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejec.dir/main.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/main.cpp" -o CMakeFiles/ejec.dir/main.s

CMakeFiles/ejec.dir/funciones-principales.o: CMakeFiles/ejec.dir/flags.make
CMakeFiles/ejec.dir/funciones-principales.o: ../funciones-principales.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ejec.dir/funciones-principales.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ejec.dir/funciones-principales.o -c "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/funciones-principales.cpp"

CMakeFiles/ejec.dir/funciones-principales.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejec.dir/funciones-principales.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/funciones-principales.cpp" > CMakeFiles/ejec.dir/funciones-principales.i

CMakeFiles/ejec.dir/funciones-principales.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejec.dir/funciones-principales.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/funciones-principales.cpp" -o CMakeFiles/ejec.dir/funciones-principales.s

CMakeFiles/ejec.dir/funciones-secundarias.o: CMakeFiles/ejec.dir/flags.make
CMakeFiles/ejec.dir/funciones-secundarias.o: ../funciones-secundarias.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ejec.dir/funciones-secundarias.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ejec.dir/funciones-secundarias.o -c "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/funciones-secundarias.cpp"

CMakeFiles/ejec.dir/funciones-secundarias.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ejec.dir/funciones-secundarias.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/funciones-secundarias.cpp" > CMakeFiles/ejec.dir/funciones-secundarias.i

CMakeFiles/ejec.dir/funciones-secundarias.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ejec.dir/funciones-secundarias.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/funciones-secundarias.cpp" -o CMakeFiles/ejec.dir/funciones-secundarias.s

# Object files for target ejec
ejec_OBJECTS = \
"CMakeFiles/ejec.dir/main.o" \
"CMakeFiles/ejec.dir/funciones-principales.o" \
"CMakeFiles/ejec.dir/funciones-secundarias.o"

# External object files for target ejec
ejec_EXTERNAL_OBJECTS =

../ejec: CMakeFiles/ejec.dir/main.o
../ejec: CMakeFiles/ejec.dir/funciones-principales.o
../ejec: CMakeFiles/ejec.dir/funciones-secundarias.o
../ejec: CMakeFiles/ejec.dir/build.make
../ejec: CMakeFiles/ejec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../ejec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ejec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ejec.dir/build: ../ejec

.PHONY : CMakeFiles/ejec.dir/build

CMakeFiles/ejec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ejec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ejec.dir/clean

CMakeFiles/ejec.dir/depend:
	cd "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01" "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01" "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug" "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug" "/home/fyulita/Documents/Fede/UBA/2020-1C/Metodos Numericos/Laboratorio/tp01/cmake-build-debug/CMakeFiles/ejec.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ejec.dir/depend

