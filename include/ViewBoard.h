#ifndef GWENT_VIEWBOARD_H
#define GWENT_VIEWBOARD_H
#include <iostream>
#include "Board.h"
#include "Player.h"


class ViewBoard {
    Board & board;
    Player & player_up;
    Player & player_down;
public:
    ViewBoard(Board& board,Player & player_up,Player & player_down);
    void view();
};


#endif //GWENT_VIEWBOARD_H
