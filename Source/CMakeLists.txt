include_directories(ASTNodes)
include_directories(Lexer)
include_directories(Util)
add_executable(MLog
				main.cpp
				Lexer/Lexer.cpp)
