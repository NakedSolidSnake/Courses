add_executable(signal "")
target_link_libraries(signal PUBLIC util)
target_sources(signal 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/sigaction.c
  )
target_include_directories(signal 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS signal DESTINATION bin)
