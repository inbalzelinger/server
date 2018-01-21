cmake_minimum_required(VERSION 3.8)
project(server)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98 -pthread")

set(SOURCE_FILES main.cpp Server.cpp Server.h StartGame.cpp StartGame.h GameManeger.cpp GameManeger.h TwoClientsGame.cpp TwoClientsGame.h ListGames.cpp ListGames.h Join.cpp Join.h Play.cpp Play.h CommandManager.cpp CommandManager.h Command.h Task.h ThreadPool.cpp ThreadPool.h)
add_executable(server ${SOURCE_FILES})