cmake_minimum_required(VERSION 3.14)
project(tcp_client)

set(CMAKE_CXX_STANDARD 14)
include_directories(include)
include_directories(/usr/local/Cellar/spdlog/1.3.1/include/)

add_executable(tcp_client src/main.cpp src/TCP_ConnectionHandler.cpp include/TCP_ConnectionHandler.h src/MessageWriter_TCP.cpp include/MessageWriter_TCP.h)