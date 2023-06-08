cmake_minimum_required(VERSION 3.20)

project(icalendarlib)

add_library(icalendarlib)
target_sources(icalendarlib
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/icalendar.h
    ${CMAKE_CURRENT_LIST_DIR}/icalendar_ext_c.h
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/date.cpp
    ${CMAKE_CURRENT_LIST_DIR}/date.h
    ${CMAKE_CURRENT_LIST_DIR}/icalendar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icalendar_ext_c.cpp
    ${CMAKE_CURRENT_LIST_DIR}/types.cpp
    ${CMAKE_CURRENT_LIST_DIR}/types.h
)
set_property(TARGET icalendarlib PROPERTY CXX_STANDARD 23)

add_executable(example)
target_sources(example
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/example.c
)
target_link_libraries(example icalendarlib)
set_property(TARGET example PROPERTY C_STANDARD 23)
