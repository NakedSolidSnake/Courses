add_executable(multicastSender "")

target_link_libraries(multicastSender PUBLIC util )
target_sources(multicastSender 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/multicastSender.c
  )

target_include_directories(multicastSender 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS multicastSender DESTINATION bin)

add_executable(multicastReceiver "")

target_link_libraries(multicastReceiver PUBLIC util )
target_sources(multicastReceiver
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/multicastReceiver.c
  )

target_include_directories(multicastReceiver
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS multicastReceiver DESTINATION bin)

