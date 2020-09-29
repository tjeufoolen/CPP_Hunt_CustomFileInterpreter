cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME "CPPLS1_Eindopdracht")

project(${PROJECT_NAME})

set(SRC_DIR "src")
set(SOURCE "main.cpp")
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)
target_link_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/lib/curl")