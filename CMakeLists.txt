cmake_minimum_required(VERSION 3.23)
project(CMH_Client)

set(CMAKE_CXX_STANDARD 20)

message(${CMAKE_HOST_SYSTEM_NAME})
message($ENV{SFML_CMAKE_DIR})

if (UNIX)
    set(SFML_STATIC_LIBRARIES FALSE)
elseif (WIN32)
    set(SFML_DIR "$ENV{SFML_CMAKE_DIR}")
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_CXX_FLAGS -static)
endif ()

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio REQUIRED)

configure_file(application.properties application.properties COPYONLY)

add_executable(CMH_Client main.cpp WindowBuilder/IWindowBuilder.h WindowBuilder/GameWindowBuilder.cpp WindowBuilder/GameWindowBuilder.h Window/IWindow.h Window/GameWindow.cpp Window/GameWindow.h Socket/ISocket.h Socket/TcpSocket.cpp Socket/TcpSocket.h SocketBuilder/ISocketBuilder.h SocketBuilder/TcpSocketBuilder.cpp SocketBuilder/TcpSocketBuilder.h PropertyReader/PropertyReader.cpp PropertyReader/PropertyReader.h)
target_link_libraries(CMH_Client sfml-system sfml-window sfml-graphics sfml-network sfml-audio)
