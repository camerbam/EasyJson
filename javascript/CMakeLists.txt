set(folder Javascript)
set(exe_name lodashTiming)
############################################
set(javascript_srcs
  lodash.js
  )
source_group("lodash" FILES ${javascript_srcs})
list(APPEND ${exe_name}_libsrcs ${javascript_srcs})
############################################
