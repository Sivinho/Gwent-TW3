#include "NilfgaardDeck.h"
#include <algorithm>

Albrich::Albrich(): UnitCard(2,2,"Albrich","Ranged"," ") {}
int Albrich::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Albrich::clone() {
    std::shared_ptr<Albrich> card(new Albrich);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Albrich::ability(std::string ,std::string ) {
}

Assire::Assire(): UnitCard(6,6,"Assire var Anahid","Ranged"," ") {}
int Assire::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Assire::clone() {
    std::shared_ptr<Assire> card(new Assire);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Assire::ability(std::string ,std::string ) {
}

NilfgaardzkiLucznik::NilfgaardzkiLucznik(): UnitCard(10,10,"Nilfgaardzki lucznik","Ranged"," ") {}
int NilfgaardzkiLucznik::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> NilfgaardzkiLucznik::clone() {
    std::shared_ptr<NilfgaardzkiLucznik> card(new NilfgaardzkiLucznik);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void NilfgaardzkiLucznik::ability(std::string ,std::string ) {
}


Cahir::Cahir(): UnitCard(6,6,"Cahir","Close Combat"," ") {}
int Cahir::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Cahir::clone() {
    std::shared_ptr<Cahir> card(new Cahir);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Cahir::ability(std::string ,std::string ) {
}


Cynthia::Cynthia(): UnitCard(4,4,"Cynthia","Ranged"," ") {}
int Cynthia::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Cynthia::clone() {
    std::shared_ptr<Cynthia> card(new Cynthia);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Cynthia::ability(std::string ,std::string ) {
}

WsparcieLucznikow::WsparcieLucznikow(): UnitCard(1,1,"Wsparcie Lucznikow","Ranged","Medic") {}
int WsparcieLucznikow::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> WsparcieLucznikow::clone() {
    std::shared_ptr<WsparcieLucznikow> card(new WsparcieLucznikow);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void WsparcieLucznikow::ability(std::string ,std::string ) {
}

Fringilla::Fringilla(): UnitCard(6,6,"Fringilla Vigo","Ranged"," ") {}
int Fringilla::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Fringilla::clone() {
    std::shared_ptr<Fringilla> card(new Fringilla);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Fringilla::ability(std::string ,std::string ) {
}

Scorpion::Scorpion(): UnitCard(10,10,"Wielki Ognisty Skorpion","Siege"," ") {}
int Scorpion::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Scorpion::clone() {
    std::shared_ptr<Scorpion> card(new Scorpion);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Scorpion::ability(std::string ,std::string ) {
}


BrygadaImpera::BrygadaImpera(Board & board): UnitCard(3,3,"Brygada Impera","Close Combat","Tight Bond"), board(board) {}
int BrygadaImpera::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> BrygadaImpera::clone() {
    std::shared_ptr<BrygadaImpera> card(new BrygadaImpera(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void BrygadaImpera::ability(std::string ,std::string side) {
    int i = 0;
    int j = 0;
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->CardName() == "Brygada Impera")
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

Letho::Letho(): HeroCard(10,"Letho z Gulety","Close Combat","Hero") {}
int Letho::GetPoints(int ) { return points;}
std::shared_ptr<Card> Letho::clone() {
    std::shared_ptr<Letho> card(new Letho);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Letho::ability(std::string ,std::string ) {
}

Menno::Menno(): HeroCard(10,"Menno Coehoorn","Close Combat","Medic") {}
int Menno::GetPoints(int ) { return points;}
std::shared_ptr<Card> Menno::clone() {
    std::shared_ptr<Menno> card(new Menno);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Menno::ability(std::string ,std::string ) {
}

Morteisen::Morteisen(): UnitCard(3,3,"Morteisen","Close Combat"," ") {}
int Morteisen::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Morteisen::clone() {
    std::shared_ptr<Morteisen> card(new Morteisen);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Morteisen::ability(std::string ,std::string ) {
}

Morvran::Morvran(): HeroCard(10,"Morvran Voorhis","Siege","Hero") {}
int Morvran::GetPoints(int ) { return points;}
std::shared_ptr<Card> Morvran::clone() {
    std::shared_ptr<Morvran> card(new Morvran);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Morvran::ability(std::string ,std::string ) {
}

Kawaleria::Kawaleria(Board & board): UnitCard(2,2,"Kawaleria Nauzicaa","Close Combat","Tight Bond"), board(board) {}
int Kawaleria::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Kawaleria::clone() {
    std::shared_ptr<Kawaleria> card(new Kawaleria(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Kawaleria::ability(std::string ,std::string side) {
    int i = 0;
    int j = 0;
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->CardName() == "Kawaleria Nauzicaa")
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

Puttkammer::Puttkammer(): UnitCard(3,3,"Puttkammer","Ranged"," ") {}
int Puttkammer::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Puttkammer::clone() {
    std::shared_ptr<Puttkammer> card(new Puttkammer);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Puttkammer::ability(std::string ,std::string ) {
}

Rainfarn::Rainfarn(): UnitCard(4,4,"Rainfarn","Close Combat"," ") {}
int Rainfarn::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Rainfarn::clone() {
    std::shared_ptr<Rainfarn> card(new Rainfarn);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Rainfarn::ability(std::string ,std::string ) {
}


Renuald::Renuald(): UnitCard(5,5,"Renuald","Ranged"," ") {}
int Renuald::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Renuald::clone() {
    std::shared_ptr<Renuald> card(new Renuald);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Renuald::ability(std::string ,std::string ) {
}

Mangonela::Mangonela(): UnitCard(3,3,"Zdezolowana Mangonela","Siege"," ") {}
int Mangonela::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Mangonela::clone() {
    std::shared_ptr<Mangonela> card(new Mangonela);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Mangonela::ability(std::string ,std::string ) {
}

Shilard::Shilard(): UnitCard(7,7,"Shilard","Close Combat","Spy") {}
int Shilard::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Shilard::clone() {
    std::shared_ptr<Shilard> card(new Shilard);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Shilard::ability(std::string ,std::string ) {
}

Saper::Saper(): UnitCard(6,6,"Saper","Siege"," ") {}
int Saper::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Saper::clone() {
    std::shared_ptr<Saper> card(new Saper);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Saper::ability(std::string ,std::string ) {
}

WsparcieObleznicze::WsparcieObleznicze(): UnitCard(0,0,"Wsparcie Obleznicze","Ranged","Medic") {}
int WsparcieObleznicze::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> WsparcieObleznicze::clone() {
    std::shared_ptr<WsparcieObleznicze> card(new WsparcieObleznicze);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void WsparcieObleznicze::ability(std::string ,std::string ) {
}

Skellen::Skellen(): UnitCard(9,9,"Skellen","Close Combat","Spy") {}
int Skellen::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Skellen::clone() {
    std::shared_ptr<Skellen> card(new Skellen);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Skellen::ability(std::string ,std::string ) {
}

Sweers::Sweers(): UnitCard(2,2,"Sweers","Ranged"," ") {}
int Sweers::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Sweers::clone() {
    std::shared_ptr<Sweers> card(new Sweers);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Sweers::ability(std::string ,std::string ) {
}


Tibor::Tibor(): HeroCard(10,"Tibor Eggebracht","Ranged","Hero") {}
int Tibor::GetPoints(int ) { return points;}
std::shared_ptr<Card> Tibor::clone() {
    std::shared_ptr<Tibor> card(new Tibor);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Tibor::ability(std::string ,std::string ) {
}


Vanhemar::Vanhemar(): UnitCard(4,4,"Vanhemar","Ranged"," ") {}
int Vanhemar::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Vanhemar::clone() {
    std::shared_ptr<Vanhemar> card(new Vanhemar);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Vanhemar::ability(std::string ,std::string ) {
}

Vattier::Vattier(): UnitCard(4,4,"Vattier de Rideaux","Close Combat","Spy") {}
int Vattier::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Vattier::clone() {
    std::shared_ptr<Vattier> card(new Vattier);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Vattier::ability(std::string ,std::string ) {
}

Vreemde::Vreemde(): UnitCard(2,2,"Vreemde","Close Combat"," ") {}
int Vreemde::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Vreemde::clone() {
    std::shared_ptr<Vreemde> card(new Vreemde);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Vreemde::ability(std::string ,std::string ) {
}

Emisariusz::Emisariusz(Board & board): UnitCard(5,5,"Mlody Emisariusz","Close Combat","Tight Bond"), board(board) {}
int Emisariusz::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Emisariusz::clone() {
    std::shared_ptr<Emisariusz> card(new Emisariusz(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Emisariusz::ability(std::string ,std::string side) {
    int i = 0;
    int j = 0;
    for (auto &s: board.getFieldsCards(type, side)) {
        if (s->CardName() == "Mlody Emisariusz")
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

ZerrScorpion::ZerrScorpion(): UnitCard(5,5,"Zerrikanski Ognisty Skorpion","Siege"," ") {}
int ZerrScorpion::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> ZerrScorpion::clone() {
    std::shared_ptr<ZerrScorpion> card(new ZerrScorpion);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void ZerrScorpion::ability(std::string ,std::string ) {
}
