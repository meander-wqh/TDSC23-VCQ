# cmake_minimum_required(VERSION 3.17)
# project(Puncturable_PRF)

# set(CMAKE_CXX_STANDARD 14)
# FIND_PACKAGE(OpenSSL REQUIRED)

# add_executable(main main.cpp ./GGM/GGMNode.h ./GGM/GGMTree.cpp ./GGM/GGMTree.h ./GGM/Utils.c ./GGM/Utils.h Punc_PRF.cpp Punc_PRF.h)

# TARGET_LINK_LIBRARIES(main OpenSSL::Crypto)


cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 14)
FIND_PACKAGE(OpenSSL REQUIRED)

project(Puncturable_PRF_LIB)
aux_source_directory(./ SRC)          # ./   表示当前 cmakelist.txt所在目录下
aux_source_directory(./GGM/ SRC)          # ./   表示当前 cmakelist.txt所在目录下


include_directories(${HEAD_PATH})      # 定义依赖的头文件的搜索路径
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
add_library(${Puncturable_PRF_LIB} STATIC ${SRC})
TARGET_LINK_LIBRARIES(${Puncturable_PRF_LIB} OpenSSL::Crypto)