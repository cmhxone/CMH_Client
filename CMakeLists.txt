cmake_minimum_required(VERSION 3.23)
project(CMH_Client)

set(CMAKE_CXX_STANDARD 20)

set(SFML_STATIC_LIBRARIES TRUE)
# TODO: 윈도우/MacOS/Linux용 분리 필요함
# TODO: SFML 디렉토리 설정 환경변수로 빼자 -> README에 기록
set(SFML_DIR D:/SFML/Mingw_x64/lib/cmake/SFML)

set(CMAKE_CXX_FLAGS -static)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(CMH_Client main.cpp WindowBuilder/IWindowBuilder.h WindowBuilder/GameWindowBuilder.cpp WindowBuilder/GameWindowBuilder.h Window/IWindow.h Window/GameWindow.cpp Window/GameWindow.h)
target_link_libraries(CMH_Client sfml-system sfml-graphics sfml-audio)
