cmake_minimum_required(VERSION 3.16)

project(Brick-Breaker)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(
    SRC_FILES
    src/background/background.cpp
    src/ball/ball.cpp
    src/brick/brick.cpp
    src/entity/entityManager.cpp
    src/game/game.cpp
    src/paddle/paddle.cpp
    src/interaction/entitesInteraction.cpp
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
link_libraries(sfml-system sfml-window sfml-graphics)

add_executable(${PROJECT_NAME} ${SRC_FILES})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)