cmake_minimum_required(VERSION 3.23)

set(project "lab2")
project(${project})

set(CMAKE_CXX_STANDARD 17)

set(${project}_SOURCES
        main.cpp)

add_subdirectory(planet)
add_subdirectory(bus)

set(${project}_SOURCE_LIST
        ${${project}_SOURCES})

add_executable(${project}
        ${${project}_SOURCE_LIST})


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/planetsIn.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/planetsOut.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/busIn.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/busOut.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

target_link_libraries(${project} planet)
target_link_libraries(${project} bus)
