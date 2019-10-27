cmake_minimum_required(VERSION 3.12)

project(MLOG, 
        VERSION 1.0.0
        DESCRIPTION "Source to source compiler for machine learning models"
        LANGUAGES C CXX)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # TODO on clang
    message("Using Clang")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # TODO on GCC
    message("Using GCC")
else()
    message(FATAL_ERROR "Unknown compiler " ${CMAKE_CXX_COMPILER_ID} ". Aborting.")
endif()

OPTION(LEXDBG "Select ON to print lexing result" OFF)

# if (LEXDBG)
#     set(LEXDBG ON CACHE BOOL "Select ON to print lexing result")
# else()
#     set(LEXDBG OFF CACHE BOOL "Select ON to print lexing result")
# ENDIF(LEXDBG)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(Source)
add_subdirectory(Test)

# TODO compiler flags
# TODO if/else branch on compiler type -> LLVM bytecode and flags
# If else rel/dbg -> O3 vs O0 etc.

########################################
############# GoogleTest ###############
########################################

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# Now simply link against gtest or gtest_main as needed. Eg
# add_executable(example example.cpp)
# target_link_libraries(example gtest_main)
# add_test(NAME example_test COMMAND example)
