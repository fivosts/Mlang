include_directories(ASTNodes)
include_directories(Lexer)
include_directories(Util)
add_library(Lexer 
            Lexer/Lexer.cpp)
add_executable(MLog main.cpp)
