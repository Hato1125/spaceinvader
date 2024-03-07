macro(add_sources target_name access)
  file(GLOB_RECURSE SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/**.cpp)
  target_sources(${target_name} ${access} ${SOURCES})
endmacro()
