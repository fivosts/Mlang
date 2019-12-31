
add_executable(MLogTest 
				TestRunner.cpp
				Scanner.cpp
				Lexer.cpp
				Parser.cpp
				${PROJECT_SOURCE_DIR}/Source/ASTNode/ASTNode.cpp
				${PROJECT_SOURCE_DIR}/Source/Lexer/Lexer.cpp
				${PROJECT_SOURCE_DIR}/Source/Parser/Parser.cpp
				)

## CXX_FLAGS
target_compile_options (MLogTest PRIVATE -std=c++17 -O3 -Wall -Wextra -Werror)

if (LLVM)
	target_compile_options (MLogTest PRIVATE -emit-llvm)
ENDIF (LLVM)

## Pre-processor definitions
target_compile_definitions(MLogTest PRIVATE MODEL_PATH="${PROJECT_SOURCE_DIR}/Models/")

if (SCDBG)
	target_compile_definitions(MLogTest PRIVATE SCDBG)
ENDIF(SCDBG)

if (TOKDBG)
	target_compile_definitions(MLogTest PRIVATE TOKDBG)
ENDIF(TOKDBG)

if (LEXDBG)
	target_compile_definitions(MLogTest PRIVATE LEXDBG)
ENDIF(LEXDBG)

if (PARDBG)
	target_compile_definitions(MLogTest PRIVATE PARDBG)
ENDIF(PARDBG)

if (SEMDBG)
	target_compile_definitions(MLogTest PRIVATE SEMDBG)
ENDIF(SEMDBG)

if (CODEDBG)
	target_compile_definitions(MLogTest PRIVATE CODEDBG)
ENDIF(CODEDBG)

## Library linking
target_link_libraries(MLogTest gtest pthread)

include_directories(${PROJECT_SOURCE_DIR}/Source/ASTNode)
include_directories(${PROJECT_SOURCE_DIR}/Source/Scanner)
include_directories(${PROJECT_SOURCE_DIR}/Source/Lexer)
include_directories(${PROJECT_SOURCE_DIR}/Source/Parser)
include_directories(${PROJECT_SOURCE_DIR}/Source/Util)
