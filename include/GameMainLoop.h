#ifndef GWENT_GAMEMAINLOOP_H
#define GWENT_GAMEMAINLOOP_H
#include "Board.h"
#include "Player.h"
#include "core_game.h"
#include "ViewBoard.h"



class GameMainLoop {
    Player & player_up;
    Player & player_down;
    core_game & game;
    ViewBoard & viewBoard;
public:
    GameMainLoop(core_game & game, Player & player_up, Player & player_down, ViewBoard & viewBoard);
    bool MainLoop();
    bool startingPlayerDown();
    bool startingPlayerUp();
};


#endif //GWENT_GAMEMAINLOOP_H
