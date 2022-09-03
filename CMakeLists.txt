cmake_minimum_required(VERSION 3.23)
project(CMH_Client)

set(CMAKE_CXX_STANDARD 20)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/SFML/Mingw_x64/lib/cmake/SFML)

set(CMAKE_CXX_FLAGS -static)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(CMH_Client main.cpp WindowBuilder/IWindowBuilder.h WindowBuilder/GameWindowBuilder.cpp WindowBuilder/GameWindowBuilder.h Window/IWindow.h Window/GameWindow.cpp Window/GameWindow.h)
target_link_libraries(CMH_Client sfml-system sfml-graphics sfml-audio)
