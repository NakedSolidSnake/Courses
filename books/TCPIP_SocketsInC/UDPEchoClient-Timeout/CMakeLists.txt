add_executable(UDPEchoClient-Timeout "")
target_link_libraries(UDPEchoClient-Timeout PUBLIC util)
target_sources(UDPEchoClient-Timeout 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/UDPEchoClient-Timeout.c
  )
target_include_directories(UDPEchoClient-Timeout
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS UDPEchoClient-Timeout DESTINATION bin)
