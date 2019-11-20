add_executable(tcpEchoServerThread "")

target_link_libraries(tcpEchoServerThread PUBLIC util servertcp pthread)
target_sources(tcpEchoServerThread 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tcpEchoServerThread.c
  )

target_include_directories(tcpEchoServerThread 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS tcpEchoServerThread DESTINATION bin)

