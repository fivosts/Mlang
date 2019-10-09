cmake_minimum_required(VERSION 3.10.2)

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

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_subdirectory(Source)
# add_subdirectory(Test) # TODO

# TODO compiler flags
# TODO if/else branch on compiler type -> LLVM bytecode and flags
# If else rel/dbg -> O3 vs O0 etc.
