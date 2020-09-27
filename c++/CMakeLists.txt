############################################
# google test
file(MAKE_DIRECTORY googleTest_bld)
include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
set(STAGE_DIR ${CMAKE_CURRENT_BINARY_DIR}/googleTest)
if(WIN32)
  set(CONFIGURE_GEN ${CMAKE_GENERATOR})  
else()
  set(CONFIGURE_GEN "")
endif()
set(CONFIGURE_CMD
  -DCMAKE_INSTALL_PREFIX:PATH=${STAGE_DIR}
  )
set(BUILD_CMD ${CMAKE_COMMAND} --build <BINARY_DIR>)  
set(INSTALL_CMD ${BUILD_CMD})
ExternalProject_Add(googleTest DEPENDS
  URL https://github.com/google/googletest/archive/release-1.10.0.tar.gz
  URL_MD5 ecd1fa65e7de707cd5c00bdac56022cd
  CMAKE_GENERATOR ${CONFIGURE_GEN} CMAKE_ARGS ${CONFIGURE_CMD}
  BUILD_COMMAND ${BUILD_CMD}
  INSTALL_COMMAND ${INSTALL_CMD} INSTALL_DIR ${NULL_DIR}
  )  
ExternalProject_Get_Property(googleTest SOURCE_DIR)
set(gTestInclude ${SOURCE_DIR}/googletest/include)
ExternalProject_Get_Property(googleTest BINARY_DIR)
message(STATUS ${BINARY_DIR})
############################################
add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(timing)
