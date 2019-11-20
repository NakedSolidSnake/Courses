cmake_minimum_required(VERSION 3.2.0)

set(CMAKE_C_FLAGS "-D_GNU_SOURCE  -D_POSIX_C_SOURCE -Wall -std=c99")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_BUILD_TYPE Debug)


add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/lib)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/TCPEcho)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/UDPEcho)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Signal)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/UDPEchoServer-SIGIO)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/UDPEchoClient-Timeout)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/TCPEchoServerFork)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/TCPEchoServerThread)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/TCPEchoServerForkN)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/TCPEchoServerSelect)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Broadcast)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/Multicast)

