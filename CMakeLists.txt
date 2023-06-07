cmake_minimum_required(VERSION 3.20)

project(example)

add_executable(example)
target_sources(example
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/date.cpp
    ${CMAKE_CURRENT_LIST_DIR}/date.h
    ${CMAKE_CURRENT_LIST_DIR}/icalendar.cpp
    ${CMAKE_CURRENT_LIST_DIR}/icalendar.h
    ${CMAKE_CURRENT_LIST_DIR}/types.cpp
    ${CMAKE_CURRENT_LIST_DIR}/types.h
    ${CMAKE_CURRENT_LIST_DIR}/example.c
)
set_property(TARGET example PROPERTY CXX_STANDARD 23)
set_source_files_properties(example.c PROPERTIES LANGUAGE CXX)
