set(exe_name EasyJsonTest)
set(folder ${exe_name})
############################################
set(main_srcs
  main.cpp
  )
source_group("main" FILES ${main_srcs})
list(APPEND ${exe_name}_libsrcs ${main_srcs})
############################################
add_executable(${exe_name} ${${exe_name}_libsrcs})
set_property(TARGET ${exe_name} PROPERTY FOLDER ${exe_name})
install(TARGETS ${exe_name} DESTINATION "test")
