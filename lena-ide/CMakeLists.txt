
cmake_minimum_required(VERSION 3.10)
project ( 
    "Lena IDE" 
    VERSION 1.0 
    DESCRIPTION "Lena Project Integrated development environment for competitive programming."
    LANGUAGES CXX C
)

set(LENA_SRC_FILES
    src/main.cpp
)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

add_executable(lena-ide ${LENA_SRC_FILES})

target_include_directories(lena-ide
    PUBLIC include/
    PRIVATE ${GLFW_INCLUDE_DIRS}
)

target_link_libraries(lena-ide
    PRIVATE ${GLFW_LIBRARIES}
)

target_compile_options(lena-ide PRIVATE ${GLFW_CFLAGS_OTHER})

