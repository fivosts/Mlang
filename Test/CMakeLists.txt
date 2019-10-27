
add_executable(MLogTest 
				TestRunner.cpp
				Scanner.cpp
				Lexer.cpp
				${PROJECT_SOURCE_DIR}/Source/Lexer/Lexer.cpp)

target_compile_definitions(MLogTest
				PRIVATE MODEL_PATH="${PROJECT_SOURCE_DIR}/Models/")

if (LEXDBG)
	target_compile_definitions(MLogTest PRIVATE LEXDBG)
ENDIF(LEXDBG)

target_link_libraries(MLogTest gtest pthread)

include_directories(${PROJECT_SOURCE_DIR}/Source/ASTNodes)
include_directories(${PROJECT_SOURCE_DIR}/Source/Scanner)
include_directories(${PROJECT_SOURCE_DIR}/Source/Lexer)
include_directories(${PROJECT_SOURCE_DIR}/Source/Util)
