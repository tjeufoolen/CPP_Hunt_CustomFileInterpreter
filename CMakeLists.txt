cmake_minimum_required(VERSION 3.17)

set(PROJECT_NAME "CPPLS1_Eindopdracht")

project(${PROJECT_NAME})

set(SRC_DIR "src")
set(SOURCE "main.cpp")
set(CMAKE_EXE_LINKER_FLAGS "-lcurl")
set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp src/wrappers/curlwrapper.cpp src/wrappers/curlwrapper.h src/program.cpp src/program.h src/utils/Logger.cpp src/utils/Logger.h src/exceptions/NotImplementedException.h)
target_include_directories(${PROJECT_NAME} PUBLIC
        ${SRC_DIR}
        )
