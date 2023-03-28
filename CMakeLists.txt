cmake_minimum_required(VERSION 3.12)
project(Gwent)

set(CMAKE_CXX_STANDARD 17)


add_library(Gwent_lib src/core_game.cpp src/Card.cpp src/Board.cpp src/CardManager.cpp src/NeutralCards.cpp src/NilfgaardDeck.cpp src/NorthernRealmsDeck.cpp src/Player.cpp src/UnitCard.cpp src/WeatherCard.cpp src/HeroCard.cpp src/SpecialCard.cpp src/InputController.cpp src/ViewBoard.cpp src/GameMainLoop.cpp)
target_include_directories(Gwent_lib PUBLIC include)

add_executable(Gwent src/main.cpp)
target_link_libraries(Gwent Gwent_lib)







