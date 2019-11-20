add_executable(broadcastSender "")

target_link_libraries(broadcastSender PUBLIC util servertcp)
target_sources(broadcastSender 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/broadcastSender.c
  )

target_include_directories(broadcastSender 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS broadcastSender DESTINATION bin)


add_executable(broadcastReceiver "")

target_link_libraries(broadcastReceiver PUBLIC util servertcp)
target_sources(broadcastReceiver 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/broadcastReceiver.c
  )

target_include_directories(broadcastReceiver 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/lib/include
  )
install(TARGETS broadcastReceiver DESTINATION bin)

