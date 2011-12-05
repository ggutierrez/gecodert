project(GecodeRT)
cmake_minimum_required(VERSION 2.8)

# Add path for some modules
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake-support"
  )

set(PACKAGE_VERSION "0.1")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE)
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

##########################################################################
# Compiler information
##########################################################################
if(CMAKE_COMPILER_IS_GNUCC)
  execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion
    OUTPUT_VARIABLE GCC_VERSION)
  message(STATUS "GCC version ${GCC_VERSION}")
else()
  message(WARNING "Compiler: ${CMAKE_CXX_COMPILER_ID} is unsupported")
endif()
##########################################################################
# System information
##########################################################################
message(STATUS "Building for architecture: ${CMAKE_SYSTEM}")
##########################################################################
# Default compiler flags
##########################################################################
add_definitions("-Wall -Wextra -std=c++0x")
##########################################################################
# Gecode
##########################################################################
find_package(Gecode REQUIRED
  COMPONENTS kernel support int set driver flatzinc gist minimodel search)
include_directories(GECODE_INCLUDE_DIR)
##########################################################################
# This project products
##########################################################################
include_directories(${CMAKE_SOURCE_DIR})

set(SOURCES
  gecodert/gecodert.cpp
  gecodert/int/distinct.cpp
  gecodert/int/rel.cpp
  )

add_library(gecodert ${SOURCES})
target_link_libraries(gecodert ${GECODE_LIBRARIES})

##########################################################################
# Examples
##########################################################################
set(EXAMPLES money testInt testBool testSet)
foreach(example ${EXAMPLES})
  add_executable(${example} examples/${example}.cpp)
  target_link_libraries(${example} gecodert)
endforeach()
