#include "Board.h"
#include "CardManager.h"
#include "core_game.h"
#include "InputController.h"
#include "ViewBoard.h"
#include "GameMainLoop.h"


int main()
{
    bool draw;
    do
    {
        InputController inctrl;
        std::string deck_up=inctrl.deck_choice("Up");
        std::string deck_down=inctrl.deck_choice("Down");
        Board board;
        CardManager mgr(deck_up,deck_down,board);
        Player playerdown("Down",mgr.RandomCards(10,"Down"),mgr,deck_down,board);
        Player playerup("Up",mgr.RandomCards(10,"Up"),mgr,deck_up,board);
        ViewBoard viewBoard(board,playerup,playerdown);
        core_game game(board,playerup,playerdown);
        GameMainLoop mainLoop(game,playerup,playerdown,viewBoard);
        draw=mainLoop.MainLoop();
    }while(draw);

 return 0;
}