cmake_minimum_required(VERSION 3.16)

project(Brick-Breaker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(
    SRC_FILES

    main.cpp    
)

include_directories(
    resources/
    src/
    src/background
    src/ball
    src/paddle
    src/brick
    src/entity
    src/game
    src/interaction
)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)
link_libraries(brickBreaker sfml-system sfml-window sfml-graphics)

add_executable(${PROJECT_NAME} ${SRC_FILES})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)