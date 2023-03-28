#include "GameMainLoop.h"
#include <random>



GameMainLoop::GameMainLoop(core_game &game, Player &player_up, Player &player_down, ViewBoard& viewBoard): player_up(player_up),player_down(player_down),game(game), viewBoard(viewBoard) {}

bool GameMainLoop::MainLoop() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 1);
    int los=distr(gen);
    if(los==1)
    {
        bool draw=startingPlayerDown();
        return draw;
    }
    else
    {
        bool draw=startingPlayerUp();
        return draw;
    }

}

bool GameMainLoop::startingPlayerDown() {
    system("cls");
    int check,flag;
    while(true)
    {
        if(player_up.countCards()==0 && player_down.countCards()==0)
        {
            check=game.check_winner_of_round();
            game.number_of_won_rounds(check);
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }
        }
        if(player_down.Pass())
        {
            viewBoard.view();
            while(!player_up.Pass())
            {
                if(player_up.countCards()==0)
                    break;
                viewBoard.view();
                std::shared_ptr<Card> playup_card=player_up.choose_card();
                game.clean_weather_clear_sky(playup_card);
                game.cards_abilities(playup_card,"Up");
                if(player_up.countCards()==0)
                    break;
            }
            check=game.check_winner_of_round();
            game.clean_board();
            game.number_of_won_rounds(check);
            viewBoard.view();
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }
            continue;
        }
        else if(player_down.countCards()!=0)
        {
            viewBoard.view();
            std::shared_ptr<Card> playdown_card=player_down.choose_card();
            game.clean_weather_clear_sky(playdown_card);
            game.cards_abilities(playdown_card,"Down");
            viewBoard.view();

        }
        if(player_up.countCards()==0 && player_down.countCards()==0)
        {
            check=game.check_winner_of_round();
            game.number_of_won_rounds(check);
            viewBoard.view();
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }
        }
        if(player_up.Pass()) {
            viewBoard.view();
            while (!player_down.Pass()) {
                if(player_down.countCards()==0)
                    break;
                viewBoard.view();
                std::shared_ptr<Card> playdown_card = player_down.choose_card();
                game.clean_weather_clear_sky(playdown_card);
                game.cards_abilities(playdown_card,"Down");
                if(player_down.countCards()==0)
                    break;
            }
            check=game.check_winner_of_round();
            game.clean_board();
            game.number_of_won_rounds(check);
            viewBoard.view();
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }

            continue;
        }
        else if(player_up.countCards()!=0)
        {
            viewBoard.view();
            std::shared_ptr<Card> playup_card=player_up.choose_card();
            game.clean_weather_clear_sky(playup_card);
            game.cards_abilities(playup_card,"Up");
            viewBoard.view();
        }
        if(player_up.countCards()==0 && player_down.countCards()==0)
        {
            check=game.check_winner_of_round();
            game.number_of_won_rounds(check);
            viewBoard.view();
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }
        }
    }
}

bool GameMainLoop::startingPlayerUp() {
    system("cls");
    int check,flag;
    while(true)
    {
        if(player_up.countCards()==0 && player_down.countCards()==0)
        {
            check=game.check_winner_of_round();
            game.number_of_won_rounds(check);
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }
        }
        if(player_up.Pass()) {
            viewBoard.view();
            while (!player_down.Pass()) {
                if(player_down.countCards()==0)
                    break;
                viewBoard.view();
                std::shared_ptr<Card> playdown_card = player_down.choose_card();
                game.clean_weather_clear_sky(playdown_card);
                game.cards_abilities(playdown_card,"Down");
                if(player_down.countCards()==0)
                    break;
            }
            check=game.check_winner_of_round();
            game.clean_board();
            game.number_of_won_rounds(check);
            viewBoard.view();
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }

            continue;
        }
        else if(player_up.countCards()!=0)
        {
            viewBoard.view();
            std::shared_ptr<Card> playup_card=player_up.choose_card();
            game.clean_weather_clear_sky(playup_card);
            game.cards_abilities(playup_card,"Up");
            viewBoard.view();
        }
        if(player_up.countCards()==0 && player_down.countCards()==0)
        {
            check=game.check_winner_of_round();
            game.number_of_won_rounds(check);
            viewBoard.view();
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }
        }
        if(player_down.Pass())
        {
            viewBoard.view();
            while(!player_up.Pass())
            {
                if(player_up.countCards()==0)
                    break;
                viewBoard.view();
                std::shared_ptr<Card> playup_card=player_up.choose_card();
                game.clean_weather_clear_sky(playup_card);
                game.cards_abilities(playup_card,"Up");
                if(player_up.countCards()==0)
                    break;
            }
            check=game.check_winner_of_round();
            game.clean_board();
            game.number_of_won_rounds(check);
            viewBoard.view();
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }
            continue;
        }
        else if(player_down.countCards()!=0)
        {
            viewBoard.view();
            std::shared_ptr<Card> playdown_card=player_down.choose_card();
            game.clean_weather_clear_sky(playdown_card);
            game.cards_abilities(playdown_card,"Down");
            viewBoard.view();

        }
        if(player_up.countCards()==0 && player_down.countCards()==0)
        {
            check=game.check_winner_of_round();
            game.number_of_won_rounds(check);
            viewBoard.view();
            if(player_up.GetNumber_of_won_rounds()==2 && player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Remis!! :<"<<std::endl;
                flag = getc(stdin);
                return true;
            }
            else if(player_down.GetNumber_of_won_rounds()==2)
            {
                std::cout<<"Gracz down wygral !";
                flag = getc(stdin);
                return false;
            }
            else if(player_up.GetNumber_of_won_rounds()==2 )
            {
                std::cout<<"Gracz up wygral !";
                flag = getc(stdin);
                return false;
            }
        }
    }


}