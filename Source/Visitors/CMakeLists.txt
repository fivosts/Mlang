target_include_directories(MlangSource PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_sources(MlangSource PUBLIC ASTVisitor.cpp)
add_subdirectory(SemAnalyzer)
