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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aidanw/work/4980/UDPtester/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aidanw/work/4980/UDPtester/Client/build

# Include any dependencies generated for this target.
include src/CMakeFiles/udp_tester_client.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/udp_tester_client.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/udp_tester_client.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/udp_tester_client.dir/flags.make

src/CMakeFiles/udp_tester_client.dir/main.c.o: src/CMakeFiles/udp_tester_client.dir/flags.make
src/CMakeFiles/udp_tester_client.dir/main.c.o: ../src/main.c
src/CMakeFiles/udp_tester_client.dir/main.c.o: src/CMakeFiles/udp_tester_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidanw/work/4980/UDPtester/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/udp_tester_client.dir/main.c.o"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=*,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-clang-analyzer-security.insecureAPI.strcpy,-concurrency-mt-unsafe,-android-cloexec-accept,-android-cloexec-dup,-google-readability-todo,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cert-dcl03-c,-hicpp-static-assert,-misc-static-assert,-altera-struct-pack-align,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling;--quiet;--extra-arg-before=--driver-mode=gcc" --source=/home/aidanw/work/4980/UDPtester/Client/src/main.c -- /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/udp_tester_client.dir/main.c.o -MF CMakeFiles/udp_tester_client.dir/main.c.o.d -o CMakeFiles/udp_tester_client.dir/main.c.o -c /home/aidanw/work/4980/UDPtester/Client/src/main.c

src/CMakeFiles/udp_tester_client.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_tester_client.dir/main.c.i"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aidanw/work/4980/UDPtester/Client/src/main.c > CMakeFiles/udp_tester_client.dir/main.c.i

src/CMakeFiles/udp_tester_client.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_tester_client.dir/main.c.s"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aidanw/work/4980/UDPtester/Client/src/main.c -o CMakeFiles/udp_tester_client.dir/main.c.s

src/CMakeFiles/udp_tester_client.dir/tcp_connection.c.o: src/CMakeFiles/udp_tester_client.dir/flags.make
src/CMakeFiles/udp_tester_client.dir/tcp_connection.c.o: ../src/tcp_connection.c
src/CMakeFiles/udp_tester_client.dir/tcp_connection.c.o: src/CMakeFiles/udp_tester_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidanw/work/4980/UDPtester/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/udp_tester_client.dir/tcp_connection.c.o"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=*,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-clang-analyzer-security.insecureAPI.strcpy,-concurrency-mt-unsafe,-android-cloexec-accept,-android-cloexec-dup,-google-readability-todo,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cert-dcl03-c,-hicpp-static-assert,-misc-static-assert,-altera-struct-pack-align,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling;--quiet;--extra-arg-before=--driver-mode=gcc" --source=/home/aidanw/work/4980/UDPtester/Client/src/tcp_connection.c -- /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/udp_tester_client.dir/tcp_connection.c.o -MF CMakeFiles/udp_tester_client.dir/tcp_connection.c.o.d -o CMakeFiles/udp_tester_client.dir/tcp_connection.c.o -c /home/aidanw/work/4980/UDPtester/Client/src/tcp_connection.c

src/CMakeFiles/udp_tester_client.dir/tcp_connection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_tester_client.dir/tcp_connection.c.i"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aidanw/work/4980/UDPtester/Client/src/tcp_connection.c > CMakeFiles/udp_tester_client.dir/tcp_connection.c.i

src/CMakeFiles/udp_tester_client.dir/tcp_connection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_tester_client.dir/tcp_connection.c.s"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aidanw/work/4980/UDPtester/Client/src/tcp_connection.c -o CMakeFiles/udp_tester_client.dir/tcp_connection.c.s

src/CMakeFiles/udp_tester_client.dir/udp_socket.c.o: src/CMakeFiles/udp_tester_client.dir/flags.make
src/CMakeFiles/udp_tester_client.dir/udp_socket.c.o: ../src/udp_socket.c
src/CMakeFiles/udp_tester_client.dir/udp_socket.c.o: src/CMakeFiles/udp_tester_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidanw/work/4980/UDPtester/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/udp_tester_client.dir/udp_socket.c.o"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=*,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-clang-analyzer-security.insecureAPI.strcpy,-concurrency-mt-unsafe,-android-cloexec-accept,-android-cloexec-dup,-google-readability-todo,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cert-dcl03-c,-hicpp-static-assert,-misc-static-assert,-altera-struct-pack-align,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling;--quiet;--extra-arg-before=--driver-mode=gcc" --source=/home/aidanw/work/4980/UDPtester/Client/src/udp_socket.c -- /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/udp_tester_client.dir/udp_socket.c.o -MF CMakeFiles/udp_tester_client.dir/udp_socket.c.o.d -o CMakeFiles/udp_tester_client.dir/udp_socket.c.o -c /home/aidanw/work/4980/UDPtester/Client/src/udp_socket.c

src/CMakeFiles/udp_tester_client.dir/udp_socket.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_tester_client.dir/udp_socket.c.i"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aidanw/work/4980/UDPtester/Client/src/udp_socket.c > CMakeFiles/udp_tester_client.dir/udp_socket.c.i

src/CMakeFiles/udp_tester_client.dir/udp_socket.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_tester_client.dir/udp_socket.c.s"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aidanw/work/4980/UDPtester/Client/src/udp_socket.c -o CMakeFiles/udp_tester_client.dir/udp_socket.c.s

src/CMakeFiles/udp_tester_client.dir/test_data.c.o: src/CMakeFiles/udp_tester_client.dir/flags.make
src/CMakeFiles/udp_tester_client.dir/test_data.c.o: ../src/test_data.c
src/CMakeFiles/udp_tester_client.dir/test_data.c.o: src/CMakeFiles/udp_tester_client.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aidanw/work/4980/UDPtester/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/udp_tester_client.dir/test_data.c.o"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && $(CMAKE_COMMAND) -E __run_co_compile --tidy="clang-tidy;-checks=*,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-clang-analyzer-security.insecureAPI.strcpy,-concurrency-mt-unsafe,-android-cloexec-accept,-android-cloexec-dup,-google-readability-todo,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cert-dcl03-c,-hicpp-static-assert,-misc-static-assert,-altera-struct-pack-align,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling;--quiet;--extra-arg-before=--driver-mode=gcc" --source=/home/aidanw/work/4980/UDPtester/Client/src/test_data.c -- /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/udp_tester_client.dir/test_data.c.o -MF CMakeFiles/udp_tester_client.dir/test_data.c.o.d -o CMakeFiles/udp_tester_client.dir/test_data.c.o -c /home/aidanw/work/4980/UDPtester/Client/src/test_data.c

src/CMakeFiles/udp_tester_client.dir/test_data.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/udp_tester_client.dir/test_data.c.i"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/aidanw/work/4980/UDPtester/Client/src/test_data.c > CMakeFiles/udp_tester_client.dir/test_data.c.i

src/CMakeFiles/udp_tester_client.dir/test_data.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/udp_tester_client.dir/test_data.c.s"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/aidanw/work/4980/UDPtester/Client/src/test_data.c -o CMakeFiles/udp_tester_client.dir/test_data.c.s

# Object files for target udp_tester_client
udp_tester_client_OBJECTS = \
"CMakeFiles/udp_tester_client.dir/main.c.o" \
"CMakeFiles/udp_tester_client.dir/tcp_connection.c.o" \
"CMakeFiles/udp_tester_client.dir/udp_socket.c.o" \
"CMakeFiles/udp_tester_client.dir/test_data.c.o"

# External object files for target udp_tester_client
udp_tester_client_EXTERNAL_OBJECTS =

src/udp_tester_client: src/CMakeFiles/udp_tester_client.dir/main.c.o
src/udp_tester_client: src/CMakeFiles/udp_tester_client.dir/tcp_connection.c.o
src/udp_tester_client: src/CMakeFiles/udp_tester_client.dir/udp_socket.c.o
src/udp_tester_client: src/CMakeFiles/udp_tester_client.dir/test_data.c.o
src/udp_tester_client: src/CMakeFiles/udp_tester_client.dir/build.make
src/udp_tester_client: /usr/lib/libm.so
src/udp_tester_client: /usr/lib/libpthread.so
src/udp_tester_client: /usr/lib/libcrypt.so
src/udp_tester_client: /usr/lib/libgdbm.so
src/udp_tester_client: /usr/lib/libgdbm_compat.so
src/udp_tester_client: /usr/local/lib/libdc_error.so
src/udp_tester_client: /usr/local/lib/libdc_posix.so
src/udp_tester_client: /usr/local/lib/libdc_util.so
src/udp_tester_client: /usr/local/lib/libdc_application.so
src/udp_tester_client: /usr/local/lib/libconfig.so
src/udp_tester_client: src/CMakeFiles/udp_tester_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aidanw/work/4980/UDPtester/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable udp_tester_client"
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/udp_tester_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/udp_tester_client.dir/build: src/udp_tester_client
.PHONY : src/CMakeFiles/udp_tester_client.dir/build

src/CMakeFiles/udp_tester_client.dir/clean:
	cd /home/aidanw/work/4980/UDPtester/Client/build/src && $(CMAKE_COMMAND) -P CMakeFiles/udp_tester_client.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/udp_tester_client.dir/clean

src/CMakeFiles/udp_tester_client.dir/depend:
	cd /home/aidanw/work/4980/UDPtester/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aidanw/work/4980/UDPtester/Client /home/aidanw/work/4980/UDPtester/Client/src /home/aidanw/work/4980/UDPtester/Client/build /home/aidanw/work/4980/UDPtester/Client/build/src /home/aidanw/work/4980/UDPtester/Client/build/src/CMakeFiles/udp_tester_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/udp_tester_client.dir/depend
