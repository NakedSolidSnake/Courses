add_executable(tcpEchoServerSelect "")

target_link_libraries(tcpEchoServerSelect PUBLIC util servertcp)
target_sources(tcpEchoServerSelect 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tcpEchoServerSelect.c
  )

target_include_directories(tcpEchoServerSelect 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS tcpEchoServerSelect DESTINATION bin)
