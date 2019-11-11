add_library(util "")

target_sources(util 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/source/util/util.c
  )

target_include_directories(util 
  PUBLIC 
  ${CMAKE_CURRENT_LIST_DIR}/include
  )
