add_executable(tcpclient "")
target_link_libraries(tcpclient PUBLIC util)
target_sources(tcpclient 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tcpechoclient.c
  )

target_include_directories(tcpclient 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS tcpclient DESTINATION bin)

add_executable(tcpserver "")
target_link_libraries(tcpserver PUBLIC util)
target_sources(tcpserver 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/tcpechoserver.c
  )

target_include_directories(tcpserver 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS tcpserver DESTINATION bin)
