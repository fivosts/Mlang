include_directories(ASTNodes)
include_directories(Lexer)
include_directories(Util)
add_executable(MLog
				main.cpp
				Lexer/Lexer.cpp
				Parser/Parser.cpp)

target_compile_options (MLog PRIVATE -std=c++17 -O3 -Wall -Wextra -Werror)
