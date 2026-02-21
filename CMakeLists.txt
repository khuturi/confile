cmake_minimum_required(VERSION 3.10)


project(container_state LANGUAGES C CXX VERSION 0.1.1)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(FileCommand
    src/ls.cc
    src/cat.cc
    src/file.cc
    src/grep.cc
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
add_library(FileCommandlib STATIC ${FileCommand})
target_include_directories(FileCommandlib PUBLIC ${PROJECT_SOURCE_DIR}/include)
add_executable(main src/main.cc)

target_link_libraries(main FileCommandlib)