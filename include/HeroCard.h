#ifndef GWENT_HEROCARD_H
#define GWENT_HEROCARD_H
#include "Card.h"

class HeroCard: public Card{
public:
    HeroCard(int points, std::string name, std::string type,std::string ability_type);
};


#endif //GWENT_HEROCARD_H
