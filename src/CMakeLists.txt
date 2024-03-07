add_executable(${PROJECT_NAME})
add_sources(${PROJECT_NAME} PRIVATE)
target_link_libraries(${PROJECT_NAME} PRIVATE
  ${Boost_LIBRARIES}
  Boost::headers
  SDL2::SDL2
  SDL2_image::SDL2_image
  SDL2_ttf::SDL2_ttf
  libsweet_engine.a
)
