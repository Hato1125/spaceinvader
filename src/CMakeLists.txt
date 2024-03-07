add_executable(${PROJECT_NAME})
add_sources(${PROJECT_NAME} PRIVATE)
target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES} Boost::headers libsweet_engine.a)
