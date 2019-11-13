add_executable(tcpEchoServerFork "")

target_link_libraries(tcpEchoServerFork PUBLIC util servertcp)
target_sources(tcpEchoServerFork 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tcpEchoServerFork.c
  )

target_include_directories(tcpEchoServerFork 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS tcpEchoServerFork DESTINATION bin)

