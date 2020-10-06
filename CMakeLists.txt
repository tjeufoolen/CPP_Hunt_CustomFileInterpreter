cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME "CPPLS1_Eindopdracht")

project(${PROJECT_NAME})

set(SRC_DIR "src")
set(SOURCE "main.cpp")
set(CMAKE_EXE_LINKER_FLAGS "-lcurl")
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES ${SRC_DIR}/*.cpp ${SRC_DIR}/*.h)

add_executable(${PROJECT_NAME} main.cpp ${SOURCE_FILES} src/expressions/functions/FunctionExpression.cpp src/expressions/functions/FunctionExpression.h src/expressions/functions/ReturnExpression.cpp src/expressions/functions/ReturnExpression.h)
target_include_directories(${PROJECT_NAME} PUBLIC ${SRC_DIR})
