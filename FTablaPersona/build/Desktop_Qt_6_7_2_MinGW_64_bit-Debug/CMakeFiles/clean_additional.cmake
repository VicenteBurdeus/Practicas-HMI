# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\FTablaPersona_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\FTablaPersona_autogen.dir\\ParseCache.txt"
  "FTablaPersona_autogen"
  )
endif()
