#ifndef GWENT_PLAYER_H
#define GWENT_PLAYER_H
#include "Card.h"
#include <vector>
#include "CardManager.h"

class Player {
    std::string name;
    int number_of_won_rounds=0;
    std::vector<std::shared_ptr<Card>> cards_in_hand;
    std::vector<std::shared_ptr<Card>> discard_pile;
    CardManager & mgr;
    std::string & deck;
    Board & board;
    bool check=true;
    void swap_cards();
    void view_cards();
public:
    Player(std::string side,std::vector<std::shared_ptr<Card>> randomcards, CardManager & mgr,std::string & deck, Board & board);
    std::shared_ptr<Card> choose_card();
    void addaditional_cards(int i);
    void addCard(std::shared_ptr<Card> card);
    void deleteCard(std::shared_ptr<Card> card);
    bool Pass();
    int countCards();
    void addto_discard_pile(std::shared_ptr<Card> card);
    std::vector<std::shared_ptr<Card>> getDiscardPile();
    void reset_discard_pile();
    void deleteCard_from_dispile(std::shared_ptr<Card> card);
    std::string player_deck();
    int GetNumber_of_won_rounds();
    void add_won_round();
    int sum_points();
};


#endif //GWENT_PLAYER_H
