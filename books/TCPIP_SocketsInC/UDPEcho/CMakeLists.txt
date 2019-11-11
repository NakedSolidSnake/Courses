
add_executable(udpclient "")
target_link_libraries(udpclient PUBLIC util)
target_sources(udpclient 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/udpechoclient.c
  )

target_include_directories(udpclient 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS udpclient DESTINATION bin)

add_executable(udpserver "")
target_link_libraries(udpserver PUBLIC util)
target_sources(udpserver 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/udpechoserver.c
  )

target_include_directories(udpserver 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS udpserver DESTINATION bin)
