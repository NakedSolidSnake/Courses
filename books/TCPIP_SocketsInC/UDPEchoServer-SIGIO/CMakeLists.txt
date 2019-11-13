add_executable(UDPEchoServer-SIGIO "")
target_link_libraries(UDPEchoServer-SIGIO PUBLIC util)
target_sources(UDPEchoServer-SIGIO 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/UDPEchoServer-SIGIO.c
  )
target_include_directories(UDPEchoServer-SIGIO
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS UDPEchoServer-SIGIO DESTINATION bin)
