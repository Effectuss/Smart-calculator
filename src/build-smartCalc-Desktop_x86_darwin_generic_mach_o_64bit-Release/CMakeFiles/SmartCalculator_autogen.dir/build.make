# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/englishk/CPP3_SmartCalc_v2.0-0/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/englishk/CPP3_SmartCalc_v2.0-0/src/build-smartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release

# Utility rule file for SmartCalculator_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/SmartCalculator_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SmartCalculator_autogen.dir/progress.make

CMakeFiles/SmartCalculator_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/englishk/CPP3_SmartCalc_v2.0-0/src/build-smartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target SmartCalculator"
	/usr/local/bin/cmake -E cmake_autogen /Users/englishk/CPP3_SmartCalc_v2.0-0/src/build-smartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release/CMakeFiles/SmartCalculator_autogen.dir/AutogenInfo.json Release

SmartCalculator_autogen: CMakeFiles/SmartCalculator_autogen
SmartCalculator_autogen: CMakeFiles/SmartCalculator_autogen.dir/build.make
.PHONY : SmartCalculator_autogen

# Rule to build all files generated by this target.
CMakeFiles/SmartCalculator_autogen.dir/build: SmartCalculator_autogen
.PHONY : CMakeFiles/SmartCalculator_autogen.dir/build

CMakeFiles/SmartCalculator_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SmartCalculator_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SmartCalculator_autogen.dir/clean

CMakeFiles/SmartCalculator_autogen.dir/depend:
	cd /Users/englishk/CPP3_SmartCalc_v2.0-0/src/build-smartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/englishk/CPP3_SmartCalc_v2.0-0/src /Users/englishk/CPP3_SmartCalc_v2.0-0/src /Users/englishk/CPP3_SmartCalc_v2.0-0/src/build-smartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release /Users/englishk/CPP3_SmartCalc_v2.0-0/src/build-smartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release /Users/englishk/CPP3_SmartCalc_v2.0-0/src/build-smartCalc-Desktop_x86_darwin_generic_mach_o_64bit-Release/CMakeFiles/SmartCalculator_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SmartCalculator_autogen.dir/depend

