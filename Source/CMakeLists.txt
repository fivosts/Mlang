include_directories(ASTNode)
include_directories(Lexer)
include_directories(Parser)
include_directories(SemAnalysis)
include_directories(Util)
add_executable(MLog
				main.cpp
				Lexer/Lexer.cpp
				Parser/Parser.cpp
				ASTNode/ASTNode.cpp
				Util/Except.cpp)

target_compile_options (MLog PRIVATE -std=c++17 -O3 -Wall -Wextra -Werror)

if (LLVM)
	target_compile_options (MLog PRIVATE -emit-llvm)
ENDIF (LLVM)
