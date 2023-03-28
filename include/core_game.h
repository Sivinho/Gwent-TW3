#ifndef GWENT_CORE_GAME_H
#define GWENT_CORE_GAME_H
#include "Board.h"
#include "Player.h"



class core_game
{
    Board & board;
    Player & player_up;
    Player & player_down;
    void decoy(std::shared_ptr<Card> card ,std::string side);
    void scorch(std::shared_ptr<Card> card,std::string side);
    void medic(std::string side);
    void def_state();
    void universal_abilities();
public:
    core_game(Board &board,Player & player_up,Player & player_down);
    int check_winner_of_round();
    void clean_board();
    void number_of_won_rounds(int & check);
    void clean_weather_clear_sky(std::shared_ptr<Card> card);
    void cards_abilities(std::shared_ptr<Card> card,std::string side);
};


#endif //GWENT_CORE_GAME_H
