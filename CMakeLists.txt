cmake_minimum_required(VERSION 3.23)
project(CMH_Client)

set(CMAKE_CXX_STANDARD 20)

message(${CMAKE_HOST_SYSTEM_NAME})

if (${CMAKE_HOST_SYSTEM_NAME} EQUAL "Linux")
    set(SFML_STATIC_LIBRARIES FALSE)
elseif (${CMAKE_HOST_SYSTEM_NAME} EQUAL "Windows")
    set(SFML_DIR ${SFML_CMAKE_DIR})
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_CXX_FLAGS -static)
endif ()

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

add_executable(CMH_Client main.cpp WindowBuilder/IWindowBuilder.h WindowBuilder/GameWindowBuilder.cpp WindowBuilder/GameWindowBuilder.h Window/IWindow.h Window/GameWindow.cpp Window/GameWindow.h Socket/ISocket.h Socket/TcpSocket.cpp Socket/TcpSocket.h SocketBuilder/ISocketBuilder.h SocketBuilder/TcpSocketBuilder.cpp SocketBuilder/TcpSocketBuilder.h)
target_link_libraries(CMH_Client sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
