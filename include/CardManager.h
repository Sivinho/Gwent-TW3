#ifndef GWENT_CARDMANAGER_H
#define GWENT_CARDMANAGER_H
#include <vector>
#include "NeutralCards.h"
#include <random>
#include <memory>
#include "NorthernRealmsDeck.h"
#include "NilfgaardDeck.h"
#include "Board.h"


class CardManager
{
    std::vector<std::shared_ptr<Card>> cards_up;
    std::vector<std::shared_ptr<Card>> cards_down;
    std::vector<std::shared_ptr<Card>> used_cards_down;
    std::vector<std::shared_ptr<Card>> used_cards_up;
    Board & board;
public:
    CardManager(std::string &deck_up, std::string &deck_down, Board & board);
    std::vector<std::shared_ptr<Card>> RandomCards(int n, std::string side);
};


#endif //GWENT_CARDMANAGER_H
