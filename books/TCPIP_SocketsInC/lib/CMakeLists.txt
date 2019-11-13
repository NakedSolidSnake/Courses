add_library(util "")

target_sources(util 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/source/util/util.c
  )

target_include_directories(util 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
  )

add_library(servertcp "")

target_link_libraries(servertcp PUBLIC util)

target_sources(servertcp 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/source/servertcp/servertcp.c
  )

target_include_directories(servertcp 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
  )
