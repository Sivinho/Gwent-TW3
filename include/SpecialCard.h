#ifndef GWENT_SPECIALCARD_H
#define GWENT_SPECIALCARD_H
#include "Card.h"

class SpecialCard: public Card {
public:
    SpecialCard(std::string name, std::string ability_type);
};


#endif //GWENT_SPECIALCARD_H
