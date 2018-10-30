cmake_minimum_required(VERSION 3.10)
project(darkest_light)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")
set(SFML_STATIC_LIBRARIES TRUE)
set(CMAKE_FIND_FRAMEWORK NEVER)
find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(darkest_light main.cpp Classes/Definitions/bonus.cpp Classes/Declarations/bonus.h Classes/Definitions/controller.cpp Classes/Declarations/controller.h Classes/Definitions/ennemies.cpp Classes/Declarations/ennemies.h Classes/Definitions/model.cpp Classes/Declarations/model.h Classes/Definitions/movableElement.cpp Classes/Declarations/movableElement.h Classes/Definitions/obstacle.cpp Classes/Declarations/obstacle.h Classes/Definitions/player.cpp Classes/Declarations/player.h Classes/Definitions/position.cpp Classes/Declarations/position.h Classes/Definitions/view.cpp Classes/Declarations/view.h)

target_link_libraries(darkest_light sfml-system sfml-window sfml-graphics sfml-audio)