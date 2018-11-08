cmake_minimum_required(VERSION 3.6)
project(unix_socket_client/server CXX)
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -s -DNDEBUG -march=native")

set(client_src_files)
set(server_src_files)
file(GLOB client_src_files src/client/*.cpp)
file(GLOB server_src_files src/server/*.cpp)

add_executable(unix_socket_client ${client_src_files})
add_executable(unix_socket_server ${server_src_files})

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(unix_socket_client Boost::system)
target_link_libraries(unix_socket_server Boost::system)
