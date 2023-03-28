#ifndef GWENT_UNITCARD_H
#define GWENT_UNITCARD_H
#include "Card.h"

class UnitCard: public Card {
public:
    UnitCard(int points,int default_points, std::string name, std::string type,std::string ability_type);
};


#endif //GWENT_UNITCARD_H
