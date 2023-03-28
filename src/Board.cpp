#include "Board.h"
#include <algorithm>
#include <limits>

Board::Board() {
    std::vector<std::shared_ptr<Card>> temp1;
    temp1.reserve(20);
    FieldforCards.insert({{"Close Combat", "Up"}, temp1});
    std::vector<std::shared_ptr<Card>> temp2;
    temp2.reserve(20);
    FieldforCards.insert({{"Close Combat", "Down"}, temp2});
    std::vector<std::shared_ptr<Card>> temp3;
    temp3.reserve(20);
    FieldforCards.insert({{"Ranged", "Up"}, temp3});
    std::vector<std::shared_ptr<Card>> temp4;
    temp4.reserve(20);
    FieldforCards.insert({{"Ranged", "Down"}, temp4});
    std::vector<std::shared_ptr<Card>> temp5;
    temp5.reserve(20);
    FieldforCards.insert({{"Siege", "Down"}, temp5});
    std::vector<std::shared_ptr<Card>> temp6;
    temp6.reserve(20);
    FieldforCards.insert({{"Siege", "Up"}, temp6});
    std::vector<std::shared_ptr<Card>> temp7;
    temp7.reserve(4);
    FieldforWeatherCards.insert({"Up",temp7});
    std::vector<std::shared_ptr<Card>> temp8;
    temp8.reserve(4);
    FieldforWeatherCards.insert({"Down",temp8});
    FieldforSpecialCards.insert({{"Close Combat","Up"}, nullptr});
    FieldforSpecialCards.insert({{"Close Combat","Down"}, nullptr});
    FieldforSpecialCards.insert({{"Ranged","Up"}, nullptr});
    FieldforSpecialCards.insert({{"Ranged","Down"}, nullptr});
    FieldforSpecialCards.insert({{"Siege","Up"}, nullptr});
    FieldforSpecialCards.insert({{"Siege","Down"}, nullptr});
}

std::vector<std::shared_ptr<Card>> Board::getFieldsCards(const std::string& Type, std::string side) const
{
    return FieldforCards.at({Type,side});
}

void Board::add_Fieldcard(std::string Type, std::string Side, std::shared_ptr<Card> card)
{
    FieldforCards.at({Type,Side}).push_back(card);
}

void Board::del_Fieldcard(std::string Type, std::string Side, std::shared_ptr<Card> card)
{
    auto temp=FieldforCards.at({Type,Side});
    auto it= std::find(temp.begin(),temp.end(),card);
    FieldforCards.at({Type,Side}).erase(it);
}

void Board::del_Weathercards()
{
    FieldforWeatherCards.at("Up").clear();
    FieldforWeatherCards.at("Down").clear();
}

void Board::clear_Fieldscards()
{
    FieldforCards.at({"Close Combat","Up"}).clear();
    FieldforCards.at({"Close Combat","Down"}).clear();
    FieldforCards.at({"Siege","Down"}).clear();
    FieldforCards.at({"Siege","Up"}).clear();
    FieldforCards.at({"Ranged","Down"}).clear();
    FieldforCards.at({"Ranged","Up"}).clear();
}

void Board::add_card(std::string Type, std::string Side, std::shared_ptr<Card> card) {

    if(card->getAbilityType()=="Spy")
    {
        if(Side=="Up")
        {
            FieldforCards.at({Type,"Down"}).push_back(card);
        }
        else
        {
            FieldforCards.at({Type,"Up"}).push_back(card);
        }

    }
    else if(!card->isWeatherCard() && !card->isSpecialCard() && card->GetType()!="Agile")
    {
        FieldforCards.at({Type,Side}).push_back(card);
    }
    else if(card->isWeatherCard())
    {
        if(card->CardName()=="Czyste Niebo")
            return;
        FieldforWeatherCards.at(Side).push_back(card);
    }
    else if(card->CardName()=="Rog Dowodcy")
    {
        std::cout<<"Podaj rzad w ktorym chcesz uzyc tej karty: [Close Combat, Siege, Ranged]"<<std::endl;
        std::string choice;
        std::getline(std::cin, choice);
        while(choice!="Close Combat" && choice!="Ranged" && choice!="Siege")
        {
            std::cout<<"Podales zly rzad, sprobuj ponownie!"<<std::endl;
            std::getline(std::cin, choice);
        }
        FieldforSpecialCards.at({choice,Side})=card;
    }
    else if(card->CardName()=="Manekin" || card->CardName()=="Pozoga")
    {
       return;
    }
    else if(card->CardName()=="Olgierd von Everec")
    {
        std::string type1;
        std::cout<<"Do ktorego wiersza chcesz wlozyc karte? [Close Combat, Ranged]"<<std::endl;
        std::getline(std::cin, type1);
        //std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        while(type1!="Close Combat" && type1!="Ranged")
        {
            std::cout<<"Podales zla wartosc, sprobuj ponownie!"<<std::endl;
            std::getline(std::cin, type1);
            //std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        }
        system("cls");
        FieldforCards.at({type1,Side}).push_back(card);
    }

}

std::vector<std::shared_ptr<Card>> Board::getWeatherCards(std::string side) const
{
    return FieldforWeatherCards.at(side);
}

void Board::add_Specialcard(std::string Type, std::string Side, std::shared_ptr<Card> card) {

    FieldforSpecialCards.at({Type,Side})=card;
}

std::shared_ptr<Card> Board::getSpecialCards(std::string Type,std::string side) const {

    return FieldforSpecialCards.at({Type,side});
}

std::shared_ptr<Card> Board::getFieldCard(std::string side,std::string name) {
    if(name=="Olgierd von Everec")
    {
        int i=0;
        std::string type1;
        auto temp1=FieldforCards.at({"Close Combat",side});
        auto temp2=FieldforCards.at({"Ranged",side});
        auto it1 = find_if(temp1.begin(), temp1.end(), [name] (const std::shared_ptr<Card>& s) { return s->CardName() == name; } );
        auto it2 = find_if(temp2.begin(), temp2.end(), [name] (const std::shared_ptr<Card>& s) { return s->CardName() == name; } );
        if(it1!=temp1.end())
        {
            type1="Close Combat";
            i++;
        }
        if(it2!=temp2.end())
        {
            type1="Ranged";
            i++;
        }
        if(i==1 && type1=="Close Combat")
        {
            return *it1;
        }
        else if(i==1 && type1=="Ranged")
        {
            return *it2;
        }
        else if(i==2)
        {
            std::cout<<"Z ktorego wiersza wybierasz karte? [Close Combat, Ranged]";
            std::getline(std::cin, type1);
            //std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            while(type1!="Close Combat" && type1!="Ranged")
            {
                std::cout<<"Podales zla wartosc, sprobuj ponownie!"<<std::endl;
                std::getline(std::cin, type1);
                //std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            }
            if(type1=="Close Combat")
                return *it1;
            else
                return *it2;
        }
    }
    else
    {
        std::vector<std::string> fields {"Close Combat","Ranged","Siege"};
        for(auto const & row : fields) {
            auto tempik=FieldforCards.at({row,side});
            auto it = find_if(tempik.begin(), tempik.end(), [name] (const std::shared_ptr<Card>& s) { return s->CardName() == name; } );
            if(it!=tempik.end())
            {
                return *it;
            }
        }
    }

    return nullptr;

}

