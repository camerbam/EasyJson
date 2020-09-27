cmake_minimum_required(VERSION 3.18.0)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/dist CACHE PATH
  "Locaction for installation"
  FORCE)
if(CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_CONFIGURATION_TYPES Debug Release)
  set(CMAKE_BUILD_TYPE "${CMAKE_CONFIGURATION_TYPES}" CACHE STRING
    "Choose the type to build, options are: Debug Release" FORCE)
endif()
project(EasyJson)
set(CMAKE_CXX_STANDARD 17)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
############################################
add_subdirectory(c++)
add_subdirectory(Javascript)
