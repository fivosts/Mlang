
add_executable(MLogTest 
				TestRunner.cpp
				Scanner.cpp
				Lexer.cpp
				Parser.cpp
				${PROJECT_SOURCE_DIR}/Source/Lexer/Lexer.cpp
				${PROJECT_SOURCE_DIR}/Source/Parser/Parser.cpp
				)

target_compile_options (MLog PRIVATE -std=c++17 -O3 -Wall -Wextra -Werror)
target_compile_definitions(MLogTest PRIVATE MODEL_PATH="${PROJECT_SOURCE_DIR}/Models/")

if (LEXDBG)
	target_compile_definitions(MLogTest PRIVATE LEXDBG)
ENDIF(LEXDBG)

target_link_libraries(MLogTest gtest pthread)

include_directories(${PROJECT_SOURCE_DIR}/Source/ASTNodes)
include_directories(${PROJECT_SOURCE_DIR}/Source/Scanner)
include_directories(${PROJECT_SOURCE_DIR}/Source/Lexer)
include_directories(${PROJECT_SOURCE_DIR}/Source/Parser)
include_directories(${PROJECT_SOURCE_DIR}/Source/Util)
