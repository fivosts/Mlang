
add_executable(MLogTest TestRunner.cpp)

add_subdirectory(Scanner)
add_subdirectory(Lexer)

target_link_libraries(MLogTest ${PROJECT_SOURCE_DIR}/Tools/GoogleTest/libgtest.a pthread)
