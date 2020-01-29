add_library(MlangSource STATIC)

add_executable(Mlang main.cpp)

target_link_libraries(Mlang MlangSource)


target_compile_options (Mlang PRIVATE -std=c++17 -O3 -Wall -Wextra -Werror)

if (LLVM)
	target_compile_options (Mlang PRIVATE -emit-llvm)
ENDIF (LLVM)

add_subdirectory(ASTNode)
add_subdirectory(Lexer)
add_subdirectory(Parser)
add_subdirectory(Util)
add_subdirectory(Visitors)
