cmake_minimum_required(VERSION 3.20)
project(CPlusPlus_Algorithm)

#设置库文件路径
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#设置可执行程序路径
#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#设置子目录
set(SUB_DIR_LIST "DataStructure" "algorithm" "cpp")
set(CMAKE_CXX_STANDARD 17)

ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src/IPC_MultiThread)
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src/algorithm)
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src/leetcode/editor/cn)
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src/stl)
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/src/cpp)

#查找源文件
foreach(SUB_DIR ${SUB_DIR_LIST})
    aux_source_directory(src/${SUB_DIR} SRC_LIST)
endforeach()

#引用头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

#编译静态库
add_library(${CMAKE_PROJECT_NAME}_static STATIC ${SRC_LIST})
set_target_properties(${CMAKE_PROJECT_NAME}_static PROPERTIES OUTPUT_NAME "${CMAKE_PROJECT_NAME}")

add_executable(CPlusPlus_Algorithm src/algorithm/main.cpp)

#链接静态库
target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_static ${LINK_LIB_LIST})
