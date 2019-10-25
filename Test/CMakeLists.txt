add_executable(MLogTest 
				TestRunner.cpp
				Scanner.cpp
				Lexer.cpp
				${PROJECT_SOURCE_DIR}/Source/Lexer/Lexer.cpp)

add_compile_definitions(MODEL_PATH="${PROJECT_SOURCE_DIR}/Models/")
target_link_libraries(MLogTest ${PROJECT_SOURCE_DIR}/Tools/GoogleTest/libgtest.a pthread)

include_directories(${PROJECT_SOURCE_DIR}/Source/ASTNodes)
include_directories(${PROJECT_SOURCE_DIR}/Source/Scanner)
include_directories(${PROJECT_SOURCE_DIR}/Source/Lexer)
include_directories(${PROJECT_SOURCE_DIR}/Source/Util)
