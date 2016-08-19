cmake_minimum_required(VERSION 3.5)
project(jiajiao)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES 2727xiandaoqiuyao_dfs.cpp)
#set(SOURCE_FILES main.cpp)
add_executable(jiajiao ${SOURCE_FILES})
add_executable(main main.cpp)
