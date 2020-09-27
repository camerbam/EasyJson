set(lib_name EasyJson)
set(folder ${lib_name})
############################################
set(include_srcs
  include/${lib_name}/JsonArray.hpp
  include/${lib_name}/JsonObject.hpp
  include/${lib_name}/JsonValue.hpp
  )
source_group("include/${lib_name}" FILES ${include_srcs})
list(APPEND ${lib_name}_libsrcs ${include_srcs})
############################################
set(src_srcs
  src/JsonArray.cpp
  src/JsonObject.cpp
  src/JsonValue.cpp
  )
source_group("src" FILES ${src_srcs})
list(APPEND ${lib_name}_libsrcs ${src_srcs})
############################################
add_library(${lib_name} ${${lib_name}_libsrcs})
target_include_directories(${lib_name} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  )
set_property(TARGET ${lib_name} PROPERTY FOLDER ${lib_name})
install(TARGETS ${lib_name} DESTINATION bin)
