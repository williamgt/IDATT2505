cmake_minimum_required(VERSION 3.1)

project(oblig_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -lglut -lGLU -lGL")

add_executable(oblig_3 main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(oblig_3 ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
