add_compile_definitions(_POSIX_C_SOURCE=200809L _XOPEN_SOURCE=700)

if(APPLE)
    add_definitions(-D_DARWIN_C_SOURCE)
endif()

find_program(LINT "clang-tidy")
IF(LINT)
    set(CMAKE_C_CLANG_TIDY "clang-tidy;-checks=*,-llvmlibc-restrict-system-libc-headers,-cppcoreguidelines-init-variables,-clang-analyzer-security.insecureAPI.strcpy,-concurrency-mt-unsafe,-android-cloexec-accept,-android-cloexec-dup,-google-readability-todo,-cppcoreguidelines-avoid-magic-numbers,-readability-magic-numbers,-cert-dcl03-c,-hicpp-static-assert,-misc-static-assert,-altera-struct-pack-align,-clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling;--quiet")
ENDIF()

# Make an executable
add_executable(udp_tester_server ${MAIN_SOURCE} ${COMMON_SOURCE_LIST} ${HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(udp_tester_server PRIVATE ../include)
target_include_directories(udp_tester_server PRIVATE /usr/include)
target_include_directories(udp_tester_server PRIVATE /usr/local/include)
target_link_directories(udp_tester_server PRIVATE /usr/lib)
target_link_directories(udp_tester_server PRIVATE /usr/local/lib)

# All users of this library will need at least C17
target_compile_features(udp_tester_server PUBLIC c_std_17)
target_compile_options(udp_tester_server PRIVATE -g)
target_compile_options(udp_tester_server PRIVATE -fstack-protector-all -ftrapv)
target_compile_options(udp_tester_server PRIVATE -Wpedantic -Wall -Wextra)
target_compile_options(udp_tester_server PRIVATE -Wdouble-promotion -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wnull-dereference -Winit-self -Wmissing-include-dirs -Wswitch-default -Wswitch-enum -Wunused-local-typedefs -Wstrict-overflow=5 -Wmissing-noreturn -Walloca -Wfloat-equal -Wdeclaration-after-statement -Wshadow -Wpointer-arith -Wabsolute-value -Wundef -Wexpansion-to-defined -Wunused-macros -Wno-endif-labels -Wbad-function-cast -Wcast-qual -Wwrite-strings -Wconversion -Wdangling-else -Wdate-time -Wempty-body -Wsign-conversion -Wfloat-conversion -Waggregate-return -Wstrict-prototypes -Wold-style-definition -Wmissing-prototypes -Wmissing-declarations -Wpacked -Wredundant-decls -Wnested-externs -Winline -Winvalid-pch -Wvariadic-macros -Wdisabled-optimization -Wstack-protector -Woverlength-strings)

find_library(LIBDC_ERROR dc_error REQUIRED)
find_library(LIBDC_POSIX dc_posix REQUIRED)
find_library(LIBDC_UTIL dc_util REQUIRED)
find_library(LIBDC_FSM dc_fsm REQUIRED)
find_library(LIBDC_APPLICATION dc_application REQUIRED)
find_library(LIBCONFIG config REQUIRED)
find_library(LIBM m)
find_library(LIBSOCKET socket)
find_library(LIB_PTHREAD pthread)
find_library(LIB_CRYPT crypt)
find_library(LIB_GDBM gdbm)
find_library(LIB_GDBM_COMPAT gdbm_compat)

if (LIBM)
    target_link_libraries(udp_tester_server PRIVATE ${LIBM})
endif ()

if (LIBSOCKET)
    target_link_libraries(udp_tester_server PRIVATE ${LIBSOCKET})
endif ()

if(LIB_PTHREAD)
    target_link_libraries(udp_tester_server PRIVATE ${LIB_PTHREAD})
endif()

if(LIB_CRYPT)
    target_link_libraries(udp_tester_server PRIVATE ${LIB_CRYPT})
endif()

if(LIB_GDBM)
    target_link_libraries(udp_tester_server PRIVATE ${LIB_GDBM})
endif()

if(LIB_GDBM_COMPAT)
    target_link_libraries(udp_tester_server PRIVATE ${LIB_GDBM_COMPAT})
endif()

target_link_libraries(udp_tester_server PRIVATE ${LIBDC_ERROR})
target_link_libraries(udp_tester_server PRIVATE ${LIBDC_POSIX})
target_link_libraries(udp_tester_server PRIVATE ${LIBDC_UTIL})
#target_link_libraries(udp_tester_server PRIVATE ${LIBDC_FSM})
target_link_libraries(udp_tester_server PRIVATE ${LIBDC_APPLICATION})
target_link_libraries(udp_tester_server PRIVATE ${LIBCONFIG})

set_target_properties(udp_tester_server PROPERTIES OUTPUT_NAME "udp_tester_server")
install(TARGETS udp_tester_server DESTINATION bin)

# IDEs should put the headers in a nice place
source_group(
        TREE "${PROJECT_SOURCE_DIR}/include"
        PREFIX "Header Files"
        FILES ${HEADER_LIST}
)

add_custom_target(
        format
        COMMAND clang-format
        -i
        ${HEADER_LIST}
        ${COMMON_SOURCE_LIST}
        ${MAIN_SOURCE}
)
