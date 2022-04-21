cmake_minimum_required(VERSION 3.19)
project(StudyCPP)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_EXE_LINKER_FLAGS "-static")
add_executable(StudyCPP Day1/Student.cpp Day1/Student.h Day1/T9.cpp)
target_link_libraries (StudyCPP -static gcc stdc++ -dynamic) # 要么set(CMAKE_EXE_LINKER_FLAGS "-static") 要么target_link_libraries(),否则可执行文件会缺静态库
