#include "ViewBoard.h"


ViewBoard::ViewBoard(Board &board, Player &player_up, Player &player_down): board(board),player_up(player_up),player_down(player_down){}

void ViewBoard::view() {

    std::cout<<"Uzyte karty pogody: ";
    for(auto const &cards :board.getWeatherCards("Up"))
    {
        std::cout<<cards->CardName()<<" ";
    }
    for(auto const &cards :board.getWeatherCards("Down"))
    {
        std::cout<<cards->CardName()<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Ilosc rund wygranych przez gracza up: "<<player_up.GetNumber_of_won_rounds()<<std::endl;
    std::cout<<"Sila kart gracza up: "<<player_up.sum_points()<<std::endl;
    std::cout<<"Ilosc kart gracza up: "<<player_up.countCards()<<std::endl;
    std::cout<<std::endl;


    if(board.getSpecialCards("Siege","Up")!= nullptr)
    {
        std::cout<<board.getSpecialCards("Siege","Up")->CardName()<<" ";
    }
    std::cout<<"Jednostki obleznicze gracza up: ";
    for(auto const &cards :board.getFieldsCards("Siege","Up"))
    {
        if(cards->getAbilityType()=="Manekin")
            std::cout<<cards->CardName()<<"  ";
        else
            std::cout<<cards->CardName()<<"-"<<cards->GetPoints(1)<<"  ";
    }
    std::cout<<std::endl;


    if(board.getSpecialCards("Ranged","Up")!= nullptr)
    {
        std::cout<<board.getSpecialCards("Ranged","Up")->CardName()<<" ";
    }
    std::cout<<"Jednostki strzeleckie gracza up: ";
    for(auto const &cards : board.getFieldsCards("Ranged","Up"))
    {
        if(cards->getAbilityType()=="Manekin")
            std::cout<<cards->CardName()<<"  ";
        else
            std::cout<<cards->CardName()<<"-"<<cards->GetPoints(1)<<"  ";
    }
    std::cout<<std::endl;


    if(board.getSpecialCards("Close Combat","Up")!= nullptr)
    {
        std::cout<<board.getSpecialCards("Close Combat","Up")->CardName()<<" ";
    }
    std::cout<<"Jednostki walki w zwarciu gracza up: ";
    for(auto const &cards : board.getFieldsCards("Close Combat","Up"))
    {
        if(cards->getAbilityType()=="Manekin")
            std::cout<<cards->CardName()<<"  ";
        else
            std::cout<<cards->CardName()<<"-"<<cards->GetPoints(1)<<"  ";
    }
    std::cout<<std::endl;


    if(board.getSpecialCards("Close Combat","Down")!= nullptr)
    {
        std::cout<<board.getSpecialCards("Close Combat","Down")->CardName()<<" ";
    }
    std::cout<<"Jednostki walki w zwarciu gracza down: ";
    for(auto const &cards : board.getFieldsCards("Close Combat","Down"))
    {
        if(cards->getAbilityType()=="Manekin")
            std::cout<<cards->CardName()<<"  ";
        else
            std::cout<<cards->CardName()<<"-"<<cards->GetPoints(1)<<"  ";
    }
    std::cout<<std::endl;

    if(board.getSpecialCards("Ranged","Down")!= nullptr)
    {
        std::cout<<board.getSpecialCards("Ranged","Down")->CardName()<<" ";
    }
    std::cout<<"Jednostki strzeleckie gracza down: ";
    for(auto const &cards : board.getFieldsCards("Ranged","Down"))
    {
        if(cards->getAbilityType()=="Manekin")
            std::cout<<cards->CardName()<<"  ";
        else
            std::cout<<cards->CardName()<<"-"<<cards->GetPoints(1)<<"  ";
    }
    std::cout<<std::endl;

    if(board.getSpecialCards("Siege","Down")!= nullptr)
    {
        std::cout<<board.getSpecialCards("Siege","Down")->CardName()<<" ";
    }
    std::cout<<"Jednostki obleznicze gracza down: ";
    for(auto const &cards :board.getFieldsCards("Siege","Down"))
    {
        if(cards->getAbilityType()=="Manekin")
            std::cout<<cards->CardName()<<"  ";
        else
            std::cout<<cards->CardName()<<"-"<<cards->GetPoints(1)<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Ilosc kart gracza down: "<<player_down.countCards()<<std::endl;
    std::cout<<"Sila kart gracza down: "<<player_down.sum_points()<<std::endl;
    std::cout<<"Ilosc rund wygranych przez gracza down: "<<player_down.GetNumber_of_won_rounds()<<std::endl;

}