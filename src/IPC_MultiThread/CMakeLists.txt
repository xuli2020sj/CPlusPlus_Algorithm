cmake_minimum_required(VERSION 3.20)
project(IPC_MultiThread)
include_directories(.)


add_executable(A condition_variable.cpp)
add_executable(B multi_thread.cpp)
