#include "NorthernRealmsDeck.h"
#include <algorithm>

Balista::Balista(): UnitCard(6,6,"Balista","Siege"," ") {}
int Balista::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Balista::clone() {
    std::shared_ptr<Balista> card(new Balista);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Balista::ability(std::string ,std::string ) {
}


BiednaPierdolonaPiechota::BiednaPierdolonaPiechota(Board & board): UnitCard(1,1,"Biedna Pierdolona Piechota","Close Combat","Tight Bond"), board(board) {}
int BiednaPierdolonaPiechota::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> BiednaPierdolonaPiechota::clone() {
    std::shared_ptr<BiednaPierdolonaPiechota> card(new BiednaPierdolonaPiechota(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void BiednaPierdolonaPiechota::ability(std::string ,std::string side) {
    int i = 0;
    int j = 0;
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->CardName() == "Biedna Pierdolona Piechota")
            i = i + 1;
    }
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->getAbilityType() == "Morale boost")
            j = j + 1;
    }
    auto temp=board.getFieldsCards(type, side);
    auto it2=find_if(temp.begin(),temp.end(),[](const std::shared_ptr<Card> &s) { return s->CardName() == "Jaskier" ; });
    if (i > 1 && j==0)
    {
        this->SetPoints(GetPoints(1)+(i-1)*points);
    }
    else if(i>=1 && j>0 && board.getSpecialCards(type,side)==nullptr && it2==temp.end())
    {
        this->SetPoints(GetPoints(1)+(i-1)*default_points+j);
    }
    else if(i>=1 && j>0 && (board.getSpecialCards(type,side)!=nullptr || it2!=temp.end()))
    {
        this->SetPoints(GetPoints(1)+(i-1)*default_points+j*2);
    }

}


Detmold::Detmold(): UnitCard(6,6,"Detmold","Ranged"," ") {}
int Detmold::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Detmold::clone() {
    std::shared_ptr<Detmold> card(new Detmold);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Detmold::ability(std::string ,std::string ) {
}


Thyssen::Thyssen(): HeroCard(10,"Esterad Thyssen","Close Combat","Hero") {}
int Thyssen::GetPoints(int ) { return points;}
std::shared_ptr<Card> Thyssen::clone() {
    std::shared_ptr<Thyssen> card(new Thyssen);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Thyssen::ability(std::string ,std::string ) {
}


Filippa::Filippa(): HeroCard(10,"Filippa Eilhart","Ranged","Hero") {}
int Filippa::GetPoints(int ) { return points;}
std::shared_ptr<Card> Filippa::clone() {
    std::shared_ptr<Filippa> card(new Filippa);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Filippa::ability(std::string ,std::string ) {
}

JanNatalis::JanNatalis(): HeroCard(10,"Jan Natalis", "Close Combat","Hero") {}
int JanNatalis::GetPoints(int ) { return points;}
std::shared_ptr<Card> JanNatalis::clone() {
    std::shared_ptr<JanNatalis> card(new JanNatalis);
    std::shared_ptr<Card> card1=card;
    return card1;
}

void JanNatalis::ability(std::string ,std::string ) {
}


Katapulta::Katapulta(Board & board): UnitCard(8,8,"Katapulta","Siege","Tight Bond"), board(board) {}
int Katapulta::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Katapulta::clone() {
    std::shared_ptr<Katapulta> card(new Katapulta(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Katapulta::ability(std::string ,std::string side) {
    int i = 0;
    int j = 0;
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->CardName() == "Katapulta")
            i = i + 1;
    }
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->getAbilityType() == "Morale boost")
            j = j + 1;
    }
    auto temp=board.getFieldsCards(type, side);
    auto it2=find_if(temp.begin(),temp.end(),[](const std::shared_ptr<Card> &s) { return s->CardName() == "Jaskier" ; });
    if (i > 1 && j==0)
    {
        this->SetPoints(GetPoints(1)+(i-1)*points);
    }
    else if(i>=1 && j>0 && board.getSpecialCards(type,side)==nullptr && it2==temp.end())
    {
        this->SetPoints(GetPoints(1)+(i-1)*default_points+j);
    }
    else if(i>=1 && j>0 && (board.getSpecialCards(type,side)!=nullptr || it2!=temp.end()))
    {
        this->SetPoints(GetPoints(1)+(i-1)*default_points+j*2);
    }

}


KeiraMetz::KeiraMetz(): UnitCard(5,5,"Keira Metz","Ranged"," ") {}
int KeiraMetz::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> KeiraMetz::clone() {
    std::shared_ptr<KeiraMetz> card(new KeiraMetz);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void KeiraMetz::ability(std::string ,std::string ) {
}


KomandosNiebieskichPasow::KomandosNiebieskichPasow(Board & board): UnitCard(4,4,"Komandos Niebieskich Pasow","Close Combat","Tight Bond"), board(board) {}
int KomandosNiebieskichPasow::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> KomandosNiebieskichPasow::clone() {
    std::shared_ptr<KomandosNiebieskichPasow> card(new KomandosNiebieskichPasow(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void KomandosNiebieskichPasow::ability(std::string ,std::string side) {
    int i = 0;
    int j = 0;
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->CardName() == "Komandos Niebieskich Pasow")
            i = i + 1;
    }
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->getAbilityType() == "Morale boost")
            j = j + 1;
    }
    auto temp=board.getFieldsCards(type, side);
    auto it2=find_if(temp.begin(),temp.end(),[](const std::shared_ptr<Card> &s) { return s->CardName() == "Jaskier" ; });
    if (i > 1 && j==0)
    {
           this->SetPoints(GetPoints(1)+(i-1)*points);
    }
    else if(i>=1 && j>0 && board.getSpecialCards(type,side)==nullptr && it2==temp.end())
    {
           this->SetPoints(GetPoints(1)+(i-1)*default_points+j);
    }
    else if(i>=1 && j>0 && (board.getSpecialCards(type,side)!=nullptr || it2!=temp.end()))
    {
            this->SetPoints(GetPoints(1)+(i-1)*default_points+j*2);
    }

}


KsiazeStennis::KsiazeStennis(): UnitCard(5,5,"Ksiaze Stennis","Close Combat", "Spy") {}
int KsiazeStennis::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> KsiazeStennis::clone() {
    std::shared_ptr<KsiazeStennis> card(new KsiazeStennis);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void KsiazeStennis::ability(std::string ,std::string ) {
}


MedyczkaBurejChoragwi::MedyczkaBurejChoragwi(): UnitCard(5,5,"Medyczka Burej Choragwi","Siege","Medic") {}
int MedyczkaBurejChoragwi::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> MedyczkaBurejChoragwi::clone() {
    std::shared_ptr<MedyczkaBurejChoragwi> card(new MedyczkaBurejChoragwi);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void MedyczkaBurejChoragwi::ability(std::string ,std::string ) {
}


MistrzOblezenKaedwen::MistrzOblezenKaedwen(Board & board): UnitCard(1,1,"Mistrz Oblezen z Kaedwen","Siege","Morale boost"), board(board) {}
int MistrzOblezenKaedwen::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> MistrzOblezenKaedwen::clone() {
    std::shared_ptr<MistrzOblezenKaedwen> card(new MistrzOblezenKaedwen(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void MistrzOblezenKaedwen::ability(std::string ,std::string side) {
    for(auto & s: board.getFieldsCards(type, side))
    {
        if(s.get()==this || s->isHeroCard() || s->isSpecialCard() || s->getAbilityType()=="Tight Bond")
            continue;
        s->SetPoints(s->GetPoints(1)+1);
    }
}


RedanskiPiechur::RedanskiPiechur(): UnitCard(1,1,"Redanski Piechur","Close Combat"," ") {}
int RedanskiPiechur::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> RedanskiPiechur::clone() {
    std::shared_ptr<RedanskiPiechur> card(new RedanskiPiechur);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void RedanskiPiechur::ability(std::string ,std::string ) {
}


RebaczezCrinfrid::RebaczezCrinfrid(Board & board): UnitCard(5,5,"Rebacze z Crinfrid","Ranged","Tight Bond"), board(board) {}
int RebaczezCrinfrid::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> RebaczezCrinfrid::clone() {
    std::shared_ptr<RebaczezCrinfrid> card(new RebaczezCrinfrid(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void RebaczezCrinfrid::ability(std::string ,std::string side) {
    int i = 0;
    int j = 0;
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->CardName() == "Rebacze z Crinfrid")
            i = i + 1;
    }
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->getAbilityType() == "Morale boost")
            j = j + 1;
    }
    auto temp=board.getFieldsCards(type, side);
    auto it2=find_if(temp.begin(),temp.end(),[](const std::shared_ptr<Card> &s) { return s->CardName() == "Jaskier" ; });
    if (i > 1 && j==0)
    {
        this->SetPoints(GetPoints(1)+(i-1)*points);
    }
    else if(i>=1 && j>0 && board.getSpecialCards(type,side)==nullptr && it2==temp.end())
    {
        this->SetPoints(GetPoints(1)+(i-1)*default_points+j);
    }
    else if(i>=1 && j>0 && (board.getSpecialCards(type,side)!=nullptr || it2!=temp.end()))
    {
        this->SetPoints(GetPoints(1)+(i-1)*default_points+j*2);
    }

}


SabrinaGlevissig::SabrinaGlevissig(): UnitCard(4,4,"Sabrina Glevissig","Ranged"," ") {}
int SabrinaGlevissig::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> SabrinaGlevissig::clone() {
    std::shared_ptr<SabrinaGlevissig> card(new SabrinaGlevissig);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void SabrinaGlevissig::ability(std::string ,std::string ) {
}


ShealadeTancarville::ShealadeTancarville(): UnitCard(5,5,"Sheala de Tancarville","Ranged"," ") {}
int ShealadeTancarville::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> ShealadeTancarville::clone() {
    std::shared_ptr<ShealadeTancarville> card(new ShealadeTancarville);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void ShealadeTancarville::ability(std::string ,std::string ) {
}


SheldonSkaggs::SheldonSkaggs(): UnitCard(4,4,"Sheldon Skaggs", "Ranged"," ") {}
int SheldonSkaggs::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> SheldonSkaggs::clone() {
    std::shared_ptr<SheldonSkaggs> card(new SheldonSkaggs);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void SheldonSkaggs::ability(std::string ,std::string ) {
}


Dijkstra::Dijkstra(): UnitCard(4,4,"Sigismund Dijkstra","Close Combat","Spy") {}
int Dijkstra::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Dijkstra::clone() {
    std::shared_ptr<Dijkstra> card(new Dijkstra);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Dijkstra::ability(std::string ,std::string ) {
}


Talar::Talar(): UnitCard(1,1,"Talar","Siege","Spy") {}
int Talar::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Talar::clone() {
    std::shared_ptr<Talar> card(new Talar);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Talar::ability(std::string ,std::string ) {
}


Trebusz::Trebusz(): UnitCard(6,6,"Trebusz","Siege"," ") {}
int Trebusz::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Trebusz::clone() {
    std::shared_ptr<Trebusz> card(new Trebusz);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Trebusz::ability(std::string ,std::string ) {
}


Roche::Roche(): HeroCard(10,"Vernon Roche", "Close Combat", "Hero") {}
int Roche::GetPoints(int ) { return points;}
std::shared_ptr<Card> Roche::clone() {
    std::shared_ptr<Roche> card(new Roche);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Roche::ability(std::string ,std::string ) {
}


Ves::Ves(): UnitCard(5,5,"Ves","Close Combat"," ") {}
int Ves::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Ves::clone() {
    std::shared_ptr<Ves> card(new Ves);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Ves::ability(std::string ,std::string ) {
}


Wiezaobleznicza::Wiezaobleznicza(): UnitCard(6,6,"Wieza Obleznicza", "Siege"," ") {}
int Wiezaobleznicza::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Wiezaobleznicza::clone() {
    std::shared_ptr<Wiezaobleznicza> card(new Wiezaobleznicza);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Wiezaobleznicza::ability(std::string ,std::string ) {
}


Yarpen::Yarpen(): UnitCard(2,2,"Yarpen Zigrin","Close Combat"," ") {}
int Yarpen::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Yarpen::clone() {
    std::shared_ptr<Yarpen> card(new Yarpen);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Yarpen::ability(std::string ,std::string ) {
}


ZygfrydzDenesle::ZygfrydzDenesle(): UnitCard(5,5,"Zygfryd z Denesle","Close Combat"," ") {}
int ZygfrydzDenesle::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> ZygfrydzDenesle::clone() {
    std::shared_ptr<ZygfrydzDenesle> card(new ZygfrydzDenesle);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void ZygfrydzDenesle::ability(std::string ,std::string ) {
}