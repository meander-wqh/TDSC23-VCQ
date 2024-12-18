cmake_minimum_required(VERSION 3.0)
project(TDSC23-VCQ)
# 定义变量
# 静态库生成的路径
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib) #lib子目录不需要自己去创建，如果lib目录没有，会自动创建
# 测试程序生成的路径
set(EXEC_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin) #bin 也会自动创建
# 头文件目录
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
# 静态库的名字
set(Puncturable_PRF_LIB Puncturable_PRF)
# 可执行程序的名字
set(VCQ VCQ)
# 添加子目录
add_subdirectory(Puncturable_PRF)
add_subdirectory(VCQ)