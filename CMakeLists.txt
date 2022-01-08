cmake_minimum_required(VERSION 3.20)
project(CPlusPlus&Algorithm)

#设置库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#设置可执行程序路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
#设置子目录
set(SUB_DIR_LIST "DataStructure")

set(CMAKE_CXX_STANDARD 11)




foreach(SUB_DIR ${SUB_DIR_LIST})
    #遍历源文件
    aux_source_directory(src/${SUB_DIR} SRC_LIST)
    #安装头文件至系统目录
    #install(DIRECTORY src/${SUB_DIR} DESTINATION ${INSTALL_PATH_INCLUDE} FILES_MATCHING PATTERN "*.h")
endforeach()

#引用头文件路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)


add_executable(CPlusPlus_Algorithm main.cpp)
