# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/chen/ruanjian/clion-2016.3.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/chen/ruanjian/clion-2016.3.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chen/CLionProjects/ImageTrans

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chen/CLionProjects/ImageTrans/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ImageTrans.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageTrans.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageTrans.dir/flags.make

CMakeFiles/ImageTrans.dir/main.cpp.o: CMakeFiles/ImageTrans.dir/flags.make
CMakeFiles/ImageTrans.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chen/CLionProjects/ImageTrans/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageTrans.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageTrans.dir/main.cpp.o -c /home/chen/CLionProjects/ImageTrans/main.cpp

CMakeFiles/ImageTrans.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageTrans.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chen/CLionProjects/ImageTrans/main.cpp > CMakeFiles/ImageTrans.dir/main.cpp.i

CMakeFiles/ImageTrans.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageTrans.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chen/CLionProjects/ImageTrans/main.cpp -o CMakeFiles/ImageTrans.dir/main.cpp.s

CMakeFiles/ImageTrans.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ImageTrans.dir/main.cpp.o.requires

CMakeFiles/ImageTrans.dir/main.cpp.o.provides: CMakeFiles/ImageTrans.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ImageTrans.dir/build.make CMakeFiles/ImageTrans.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ImageTrans.dir/main.cpp.o.provides

CMakeFiles/ImageTrans.dir/main.cpp.o.provides.build: CMakeFiles/ImageTrans.dir/main.cpp.o


CMakeFiles/ImageTrans.dir/util.cpp.o: CMakeFiles/ImageTrans.dir/flags.make
CMakeFiles/ImageTrans.dir/util.cpp.o: ../util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chen/CLionProjects/ImageTrans/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ImageTrans.dir/util.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageTrans.dir/util.cpp.o -c /home/chen/CLionProjects/ImageTrans/util.cpp

CMakeFiles/ImageTrans.dir/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageTrans.dir/util.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chen/CLionProjects/ImageTrans/util.cpp > CMakeFiles/ImageTrans.dir/util.cpp.i

CMakeFiles/ImageTrans.dir/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageTrans.dir/util.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chen/CLionProjects/ImageTrans/util.cpp -o CMakeFiles/ImageTrans.dir/util.cpp.s

CMakeFiles/ImageTrans.dir/util.cpp.o.requires:

.PHONY : CMakeFiles/ImageTrans.dir/util.cpp.o.requires

CMakeFiles/ImageTrans.dir/util.cpp.o.provides: CMakeFiles/ImageTrans.dir/util.cpp.o.requires
	$(MAKE) -f CMakeFiles/ImageTrans.dir/build.make CMakeFiles/ImageTrans.dir/util.cpp.o.provides.build
.PHONY : CMakeFiles/ImageTrans.dir/util.cpp.o.provides

CMakeFiles/ImageTrans.dir/util.cpp.o.provides.build: CMakeFiles/ImageTrans.dir/util.cpp.o


CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o: CMakeFiles/ImageTrans.dir/flags.make
CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o: ../ImageDeal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chen/CLionProjects/ImageTrans/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o -c /home/chen/CLionProjects/ImageTrans/ImageDeal.cpp

CMakeFiles/ImageTrans.dir/ImageDeal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageTrans.dir/ImageDeal.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chen/CLionProjects/ImageTrans/ImageDeal.cpp > CMakeFiles/ImageTrans.dir/ImageDeal.cpp.i

CMakeFiles/ImageTrans.dir/ImageDeal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageTrans.dir/ImageDeal.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chen/CLionProjects/ImageTrans/ImageDeal.cpp -o CMakeFiles/ImageTrans.dir/ImageDeal.cpp.s

CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o.requires:

.PHONY : CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o.requires

CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o.provides: CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o.requires
	$(MAKE) -f CMakeFiles/ImageTrans.dir/build.make CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o.provides.build
.PHONY : CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o.provides

CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o.provides.build: CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o


CMakeFiles/ImageTrans.dir/test.cpp.o: CMakeFiles/ImageTrans.dir/flags.make
CMakeFiles/ImageTrans.dir/test.cpp.o: ../test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chen/CLionProjects/ImageTrans/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/ImageTrans.dir/test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageTrans.dir/test.cpp.o -c /home/chen/CLionProjects/ImageTrans/test.cpp

CMakeFiles/ImageTrans.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageTrans.dir/test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chen/CLionProjects/ImageTrans/test.cpp > CMakeFiles/ImageTrans.dir/test.cpp.i

CMakeFiles/ImageTrans.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageTrans.dir/test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chen/CLionProjects/ImageTrans/test.cpp -o CMakeFiles/ImageTrans.dir/test.cpp.s

CMakeFiles/ImageTrans.dir/test.cpp.o.requires:

.PHONY : CMakeFiles/ImageTrans.dir/test.cpp.o.requires

CMakeFiles/ImageTrans.dir/test.cpp.o.provides: CMakeFiles/ImageTrans.dir/test.cpp.o.requires
	$(MAKE) -f CMakeFiles/ImageTrans.dir/build.make CMakeFiles/ImageTrans.dir/test.cpp.o.provides.build
.PHONY : CMakeFiles/ImageTrans.dir/test.cpp.o.provides

CMakeFiles/ImageTrans.dir/test.cpp.o.provides.build: CMakeFiles/ImageTrans.dir/test.cpp.o


# Object files for target ImageTrans
ImageTrans_OBJECTS = \
"CMakeFiles/ImageTrans.dir/main.cpp.o" \
"CMakeFiles/ImageTrans.dir/util.cpp.o" \
"CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o" \
"CMakeFiles/ImageTrans.dir/test.cpp.o"

# External object files for target ImageTrans
ImageTrans_EXTERNAL_OBJECTS =

ImageTrans: CMakeFiles/ImageTrans.dir/main.cpp.o
ImageTrans: CMakeFiles/ImageTrans.dir/util.cpp.o
ImageTrans: CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o
ImageTrans: CMakeFiles/ImageTrans.dir/test.cpp.o
ImageTrans: CMakeFiles/ImageTrans.dir/build.make
ImageTrans: /usr/local/lib/libopencv_videostab.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_ts.a
ImageTrans: /usr/local/lib/libopencv_superres.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_stitching.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_contrib.so.2.4.13
ImageTrans: /usr/lib/x86_64-linux-gnu/libGLU.so
ImageTrans: /usr/lib/x86_64-linux-gnu/libGL.so
ImageTrans: /usr/local/lib/libopencv_nonfree.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_ocl.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_gpu.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_photo.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_objdetect.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_legacy.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_video.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_ml.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_calib3d.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_features2d.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_highgui.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_imgproc.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_flann.so.2.4.13
ImageTrans: /usr/local/lib/libopencv_core.so.2.4.13
ImageTrans: /usr/local/cuda/lib64/libcudart.so
ImageTrans: /usr/local/cuda/lib64/libnppc.so
ImageTrans: /usr/local/cuda/lib64/libnppi.so
ImageTrans: /usr/local/cuda/lib64/libnpps.so
ImageTrans: /usr/local/cuda/lib64/libcufft.so
ImageTrans: CMakeFiles/ImageTrans.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chen/CLionProjects/ImageTrans/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ImageTrans"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageTrans.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageTrans.dir/build: ImageTrans

.PHONY : CMakeFiles/ImageTrans.dir/build

CMakeFiles/ImageTrans.dir/requires: CMakeFiles/ImageTrans.dir/main.cpp.o.requires
CMakeFiles/ImageTrans.dir/requires: CMakeFiles/ImageTrans.dir/util.cpp.o.requires
CMakeFiles/ImageTrans.dir/requires: CMakeFiles/ImageTrans.dir/ImageDeal.cpp.o.requires
CMakeFiles/ImageTrans.dir/requires: CMakeFiles/ImageTrans.dir/test.cpp.o.requires

.PHONY : CMakeFiles/ImageTrans.dir/requires

CMakeFiles/ImageTrans.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageTrans.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageTrans.dir/clean

CMakeFiles/ImageTrans.dir/depend:
	cd /home/chen/CLionProjects/ImageTrans/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chen/CLionProjects/ImageTrans /home/chen/CLionProjects/ImageTrans /home/chen/CLionProjects/ImageTrans/cmake-build-debug /home/chen/CLionProjects/ImageTrans/cmake-build-debug /home/chen/CLionProjects/ImageTrans/cmake-build-debug/CMakeFiles/ImageTrans.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageTrans.dir/depend

