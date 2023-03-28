#ifndef GWENT_BOARD_H
#define GWENT_BOARD_H
#include <vector>
#include "Card.h"
#include <map>
#include <utility>
#include <string>
#include <iostream>




class Board
{
    std::map<std::pair<std::string,std::string>,std::vector<std::shared_ptr<Card>>> FieldforCards;
    std::map<std::pair<std::string,std::string>,std::shared_ptr<Card>> FieldforSpecialCards;
    std::map<std::string,std::vector<std::shared_ptr<Card>>> FieldforWeatherCards;

public:

    Board();
    void add_Fieldcard(std::string Type, std::string Side, std::shared_ptr<Card> card);
    void del_Fieldcard(std::string Type, std::string Side, std::shared_ptr<Card> card);
    void add_Specialcard(std::string Type, std::string Side, std::shared_ptr<Card> card);
    void clear_Fieldscards();
    void del_Weathercards();
    std::vector<std::shared_ptr<Card>> getFieldsCards(const std::string& Type, std::string side) const;
    void add_card(std::string Type, std::string Side, std::shared_ptr<Card> card);
    std::vector<std::shared_ptr<Card>> getWeatherCards(std::string side) const;
    std::shared_ptr<Card> getSpecialCards(std::string Type,std::string side) const;
    std::shared_ptr<Card> getFieldCard(std::string side,std::string name);
};


#endif //GWENT_BOARD_H
