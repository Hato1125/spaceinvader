cmake_minimum_required(VERSION 3.9)

project(spaceinvader)
set(VERSION 0.0.0)
set(LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Boost 1.80 REQUIRED COMPONENTS
  log
  log_setup
)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories("${Boost_INCLUDE_DIRS}")
include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/library)
link_directories("${Boost_LIBRARY_DIR}")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/module)
include(add_sources)
include(add_include_dirs)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  add_compile_options(-O1)
  add_subdirectory(src)
else()
  add_compile_options(-O0)
  add_subdirectory(src)
endif()
