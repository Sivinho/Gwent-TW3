#include "InputController.h"
#include <iostream>

std::string InputController::deck_choice(const std::string & side) {

    std::cout<<"Gracz "<<side<<std::endl;
    std::cout<<"Wybierz talie: [Krolestwa Polnocy, Cesarstwo Nilfgaardu]"<<std::endl;
    std::string deck;
    std::getline(std::cin, deck);
    while(deck!="Krolestwa Polnocy" && deck!="Cesarstwo Nilfgaardu")
    {
        std::cout<<"Podales zla talie! Sprobuj ponownie"<<std::endl;
        std::getline(std::cin, deck);
    }
    if(deck=="Krolestwa Polnocy")
        return "NorthernRealms";
    else
        return "Nilfgaard";
}
