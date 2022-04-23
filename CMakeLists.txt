cmake_minimum_required(VERSION 3.19)
project(StudyCPP)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(StudyCPP  Day2/T5.cpp)
target_link_libraries (StudyCPP -static) # 要么set(CMAKE_EXE_LINKER_FLAGS "-static") 要么target_link_libraries(),否则可执行文件会缺静态库
#target_link_libraries (StudyCPP -static gcc stdc++ -dynamic) # 要么set(CMAKE_EXE_LINKER_FLAGS "-static") 要么target_link_libraries(),否则可执行文件会缺静态库