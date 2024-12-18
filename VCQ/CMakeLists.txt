cmake_minimum_required(VERSION 3.0)
project(VCQ)
aux_source_directory(./ SRC)       # 搜索的还是当前cmakelist目录下的源文件
include_directories(${HEAD_PATH})
# include_directories(${HEAD_PATH})
link_directories(${LIB_PATH})
link_libraries(${Puncturable_PRF_LIB})
set(EXECUTABLE_OUTPUT_PATH ${EXEC_PATH})
add_executable(${VCQ} ${SRC})
