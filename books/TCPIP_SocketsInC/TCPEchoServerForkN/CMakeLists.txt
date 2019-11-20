add_executable(tcpEchoServerForkN "")

target_link_libraries(tcpEchoServerForkN PUBLIC util servertcp)
target_sources(tcpEchoServerForkN 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tcpEchoServerForkN.c
  )

target_include_directories(tcpEchoServerForkN 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS tcpEchoServerForkN DESTINATION bin)

