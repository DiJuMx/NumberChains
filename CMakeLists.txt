cmake_minimum_required( VERSION 3.0 )
project(numberChains C)
set( CMAKE_EXPORT_COMPILE_COMMANDS 1 )
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/bin")

include_directories(include)
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)
