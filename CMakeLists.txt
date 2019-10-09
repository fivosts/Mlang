cmake_minimum_required(VERSION 3.10.2)

project(MLOG, 
        VERSION 1.0.0
        DESCRIPTION "Source to source compiler for machine learning models"
        LANGUAGES C CXX)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(Source)
# add_subdirectory(Test) # TODO
