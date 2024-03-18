macro(copy_directory src dst)
  file(COPY ${src} DESTINATION ${dst})
endmacro()
