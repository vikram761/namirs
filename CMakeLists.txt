cmake_minimum_required(VERSION 3.28.0)

project("namirs")
set(CMAKE_CXX_STANDARD 17)

set(SOURCES 
  src/main.cpp
  src/helper.cpp
  src/train.cpp
  src/data_table.cpp
)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(TOML_PLUS_PLUS ${CMAKE_CURRENT_SOURCE_DIR}/vendor/tomlplusplus)


add_library(tomlplusplus STATIC ${TOML_PLUS_PLUS}/src/toml.cpp)
include_directories(${TOML_PLUS_PLUS}/include)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} tomlplusplus)
