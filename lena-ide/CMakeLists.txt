
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

# Используем pkg-config для поиска glfw
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

add_executable(lena-ide ${LENA_SRC_FILES})

# Подключаем заголовки GLFW
target_include_directories(lena-ide
    PUBLIC include/
    PRIVATE ${GLFW_INCLUDE_DIRS}
)

# Подключаем библиотеки GLFW
target_link_libraries(lena-ide
    PRIVATE ${GLFW_LIBRARIES}
)

# Можно добавить это, чтобы компилятор тоже знал про флаги pkg-config
target_compile_options(lena-ide PRIVATE ${GLFW_CFLAGS_OTHER})


