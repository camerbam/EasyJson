cmake_minimum_required(VERSION 3.15.0)
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
# Rapidjson
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
file(MAKE_DIRECTORY rapidjson_bld)
ExternalProject_Add(rapidjson 
  URL https://github.com/Tencent/rapidjson/archive/v1.1.0.tar.gz
  URL_MD5 badd12c511e081fec6c89c43a7027bce
  DOWNLOAD_DIR rapidjson_dwn
  SOURCE_DIR "" CONFIGURE_COMMAND ""
  BINARY_DIR ""
  BUILD_COMMAND ${CMAKE_COMMAND} -E copy_directory
    <SOURCE_DIR>/include thirdParty/rapidjson_v1.1.0
  INSTALL_DIR "" INSTALL_COMMAND ""
  )
############################################
set(lib_name EasyJsonLib)
set(folder ${lib_name})
############################################
set(include_srcs
  include/EasyJson.hpp
  )
source_group("include" FILES ${include_srcs})
list(APPEND ${lib_name}_libsrcs ${include_srcs})
############################################
set(src_srcs
  src/EasyJson.cpp
  )
source_group("src" FILES ${src_srcs})
list(APPEND ${lib_name}_libsrcs ${src_srcs})
############################################
add_library(${lib_name} ${${lib_name}_libsrcs})
#target_link_libraries(${lib_name} PRIVATE rapidjson)
set_property(TARGET ${lib_name} PROPERTY FOLDER ${lib_name})
install(TARGETS ${lib_name} DESTINATION "")
