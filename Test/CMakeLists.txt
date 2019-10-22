add_subdirectory(Scanner)
add_subdirectory(Lexer)

add_executable(MLogTest TestRunner.cpp)

target_link_libraries(MLogTest ScannerTest LexerTest gtest)