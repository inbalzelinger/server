cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Server.cpp Server.h StartGame.cpp StartGame.h ServerReversiLogic.cpp ServerReversiLogic.h TwoClientsGame.cpp TwoClientsGame.h ListGames.cpp ListGames.h Join.cpp Join.h Play.cpp Play.h Close.cpp Close.h CommandManager.cpp CommandManager.h Command.h)
add_executable(server ${SOURCE_FILES})