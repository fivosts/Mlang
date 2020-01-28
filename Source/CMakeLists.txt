add_executable(Mlang
				main.cpp
				Lexer/Lexer.cpp
				Parser/Parser.cpp
				ASTNode/ASTNode.cpp
				Util/Except.cpp)

target_compile_options (Mlang PRIVATE -std=c++17 -O3 -Wall -Wextra -Werror)

if (LLVM)
	target_compile_options (Mlang PRIVATE -emit-llvm)
ENDIF (LLVM)

add_subdirectory(ASTNode)
add_subdirectory(Lexer)
add_subdirectory(Parser)
add_subdirectory(Util)
add_subdirectory(Visitors)
