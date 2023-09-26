cmake_minimum_required(VERSION 3.5)

project(implementations LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_SOURCE_DIR}/libraries)

set(SOURCE main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})

target_link_libraries(${PROJECT_NAME} PRIVATE
                                      libraries)

install(TARGETS implementations
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
