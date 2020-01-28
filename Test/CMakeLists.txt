
add_executable(MlangTest 
				TestRunner.cpp
				Scanner.cpp
				Lexer.cpp
				Parser.cpp
				)

## CXX_FLAGS
target_compile_options (MlangTest PRIVATE -std=c++17 -O3 -Wall -Wextra -Werror)

if (LLVM)
	target_compile_options (MlangTest PRIVATE -emit-llvm)
ENDIF (LLVM)

## Pre-processor definitions
target_compile_definitions(MlangTest PRIVATE MODEL_PATH="${PROJECT_SOURCE_DIR}/Models/")

if (SCDBG)
	target_compile_definitions(MlangTest PRIVATE SCDBG)
ENDIF(SCDBG)

if (TOKDBG)
	target_compile_definitions(MlangTest PRIVATE TOKDBG)
ENDIF(TOKDBG)

if (LEXDBG)
	target_compile_definitions(MlangTest PRIVATE LEXDBG)
ENDIF(LEXDBG)

if (PARDBG)
	target_compile_definitions(MlangTest PRIVATE PARDBG)
ENDIF(PARDBG)

if (SEMDBG)
	target_compile_definitions(MlangTest PRIVATE SEMDBG)
ENDIF(SEMDBG)

if (CODEDBG)
	target_compile_definitions(MlangTest PRIVATE CODEDBG)
ENDIF(CODEDBG)

## Library linking
target_link_libraries(MlangTest MlangSource 
								gtest 
								pthread)
