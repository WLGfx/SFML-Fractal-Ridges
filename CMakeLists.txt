cmake_minimum_required(VERSION 3.0.0)
project(sfml-noise VERSION 0.1.0)

include(CTest)
enable_testing()

add_library(Libs
    main.cpp
    noise_test.cpp
)

target_link_libraries(Libs
    -lpthread
    -lsfml-graphics
    -lsfml-window
    -lsfml-system
)

add_executable(sfml-noise main.cpp)
target_link_libraries(sfml-noise Libs)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
