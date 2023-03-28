#include "NeutralCards.h"
#include <algorithm>

TajemniczyElf::TajemniczyElf(): HeroCard(0,"Tajemniczy Elf","Close Combat","Spy") {}
int TajemniczyElf::GetPoints(int ) { return points;}
std::shared_ptr<Card> TajemniczyElf::clone() {
    std::shared_ptr<TajemniczyElf> card(new TajemniczyElf);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void TajemniczyElf::ability(std::string ,std::string ) {
}


GeraltzRivii::GeraltzRivii(): HeroCard(15,"Geralt z Rivii","Close Combat","Hero") {}
int GeraltzRivii::GetPoints(int ) { return points;}
std::shared_ptr<Card> GeraltzRivii::clone() {
    std::shared_ptr<GeraltzRivii> card(new GeraltzRivii);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void GeraltzRivii::ability(std::string ,std::string ) {
}



TrzaskajacyMroz::TrzaskajacyMroz(Board &board) : WeatherCard("Trzaskajacy Mroz","Close Combat"), board{board} {}
int TrzaskajacyMroz::GetPoints(int ) {return 0;}
std::shared_ptr<Card> TrzaskajacyMroz::clone() {
    std::shared_ptr<TrzaskajacyMroz> card(new TrzaskajacyMroz(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void TrzaskajacyMroz::ability(std::string , std::string ) {

    for(auto & cards: board.getFieldsCards(type,"Up"))
    {
        if(cards->isHeroCard() || cards->isSpecialCard())
        {
            continue;
        }
        cards->SetPoints(1);
    }
    for(auto & cards: board.getFieldsCards(type,"Down"))
    {
        if(cards->isHeroCard() || cards->isSpecialCard())
        {
            continue;
        }
        cards->SetPoints(1);
    }

}

Ciri::Ciri(): HeroCard(15,"Ciri","Close Combat","Hero") {}
int Ciri::GetPoints(int ) { return points;}
std::shared_ptr<Card> Ciri::clone() {
    std::shared_ptr<Ciri> card(new Ciri);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Ciri::ability(std::string ,std::string ) {
}


RogDowodcy::RogDowodcy(Board& board): SpecialCard("Rog Dowodcy","Commander's Horn"),board{board}{}
int RogDowodcy::GetPoints(int ) {return 0;}
std::shared_ptr<Card> RogDowodcy::clone() {
    std::shared_ptr<RogDowodcy> card(new RogDowodcy(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void RogDowodcy::ability(std::string type1,std::string side) {
        auto row=board.getSpecialCards(type1,side);
        if(row!= nullptr)
        {
            for(auto & cards: board.getFieldsCards(type1,side))
            {
                if(cards->isHeroCard() || cards->isSpecialCard())
                    continue;
                cards->SetPoints(cards->GetPoints(1)*2);
            }
        }
}




CzysteNiebo::CzysteNiebo() : WeatherCard("Czyste Niebo", "None"){}
int CzysteNiebo::GetPoints(int ) {return 0;}
std::shared_ptr<Card> CzysteNiebo::clone() {
    std::shared_ptr<CzysteNiebo> card(new CzysteNiebo);
    std::shared_ptr<Card> card1=card;
    return card1;
}

void CzysteNiebo::ability(std::string ,std::string ) {
}

Jaskier::Jaskier(Board & board): UnitCard(2,2,"Jaskier","Close Combat","Commander's Horn"),board{board}{};
int Jaskier::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Jaskier::clone() {
    std::shared_ptr<Jaskier> card(new Jaskier(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Jaskier::ability(std::string type1, std::string side) {
    if(board.getSpecialCards(type,side)==nullptr)
    {
        auto temp=board.getFieldsCards(type,side);
        auto it1 = find_if(temp.begin(),temp.end(),[this](const std::shared_ptr<Card> &s) { return s.get() == this; });
        auto it2=find_if(temp.begin(),it1,[](const std::shared_ptr<Card> &s) { return s->CardName() == "Jaskier" ; });
        if(it2==it1)
        {
            for(auto & cards: board.getFieldsCards(type,side))
            {
                if(cards.get()==this || cards->isHeroCard() || cards->isSpecialCard())
                {
                    continue;
                }
                cards->SetPoints(cards->GetPoints(1)*2);
            }
        }
        else
        {
            (*it2)->SetPoints((*it2)->GetPoints(1)*2);
        }

    }
    else
        return;
}



Manekin::Manekin(): SpecialCard("Manekin","Manekin") {}
int Manekin::GetPoints(int ) {return 0;}
std::shared_ptr<Card> Manekin::clone() {
    std::shared_ptr<Manekin> card(new Manekin);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Manekin::ability(std::string , std::string ) {
}


Regis::Regis(): UnitCard(5,5,"Regis","Close Combat"," ") {}
int Regis::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Regis::clone() {
    std::shared_ptr<Regis> card(new Regis);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Regis::ability(std::string ,std::string ) {
}




Mgla::Mgla(Board &board) : WeatherCard("Mgla","Ranged"), board{board}{}
int Mgla::GetPoints(int ) {return 0;}
std::shared_ptr<Card> Mgla::clone() {
    std::shared_ptr<Mgla> card(new Mgla(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Mgla::ability(std::string ,std::string ) {
    for(auto & cards: board.getFieldsCards(type,"Up"))
    {
        if(cards->isHeroCard() || cards->CardName()=="Krowa" || cards->isSpecialCard())
        {
            continue;
        }
        cards->SetPoints(1);
    }
    for(auto & cards: board.getFieldsCards(type,"Down"))
    {
        if(cards->isHeroCard() || cards->CardName()=="Krowa" || cards->isSpecialCard())
        {
            continue;
        }
        cards->SetPoints(1);
    }

}

Deszcz::Deszcz(Board &board) : WeatherCard("Deszcz","Siege"), board{board}{}
int Deszcz::GetPoints(int ) {return 0;}
std::shared_ptr<Card> Deszcz::clone() {
    std::shared_ptr<Deszcz> card(new Deszcz(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Deszcz::ability(std::string , std::string ) {

    for(auto & cards: board.getFieldsCards(type,"Up"))
    {
        if(cards->isHeroCard() || cards->isSpecialCard() || cards->CardName()=="Wsparcie Obleznicze")
        {
            continue;
        }
        cards->SetPoints(1);
    }
    for(auto & cards: board.getFieldsCards(type,"Down"))
    {
        if(cards->isHeroCard() || cards->isSpecialCard() || cards->CardName()=="Wsparcie Obleznicze")
        {
            continue;
        }
        cards->SetPoints(1);
    }

}


Pozoga::Pozoga(): SpecialCard("Pozoga","Scorch") {}
int Pozoga::GetPoints(int ) {return 0;}
std::shared_ptr<Card> Pozoga::clone() {
    std::shared_ptr<Pozoga> card(new Pozoga);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Pozoga::ability(std::string , std::string ) {
}




Triss::Triss(): HeroCard(7,"Triss","Close Combat","Hero") {}
int Triss::GetPoints(int ) { return points;}
std::shared_ptr<Card> Triss::clone() {
    std::shared_ptr<Triss> card(new Triss);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Triss::ability(std::string ,std::string ) {
}



Vesemir::Vesemir(): UnitCard(6,6,"Vesemir","Close Combat"," "){}
int Vesemir::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Vesemir::clone() {
    std::shared_ptr<Vesemir> card(new Vesemir);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Vesemir::ability(std::string ,std::string ) {
}



Borch::Borch(): UnitCard(7,7,"Borch Trzy Kawki","Close Combat","Scorch") {}
int Borch::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Borch::clone() {
    std::shared_ptr<Borch> card(new Borch);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Borch::ability(std::string ,std::string ) {
}




Yennefer::Yennefer(): HeroCard(7,"Yennefer","Ranged","Medic") {}
int Yennefer::GetPoints(int ) { return points;}
std::shared_ptr<Card> Yennefer::clone() {
    std::shared_ptr<Yennefer> card(new Yennefer);
    std::shared_ptr<Card> card1 = card;
    return card1;
}
void Yennefer::ability(std::string ,std::string ) {
}






Zoltan::Zoltan(): UnitCard(5,5,"Zoltan Chivay","Close Combat"," ") {}
int Zoltan::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> Zoltan::clone() {
    std::shared_ptr<Zoltan> card(new Zoltan);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void Zoltan::ability(std::string , std::string ) {
}





OlgierdvonEverec::OlgierdvonEverec(Board& board): UnitCard(6,6,"Olgierd von Everec","Agile","Morale boost"), board(board) {}
int OlgierdvonEverec::GetPoints(int x) {if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> OlgierdvonEverec::clone() {
    std::shared_ptr<OlgierdvonEverec> card(new OlgierdvonEverec(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void OlgierdvonEverec::ability(std::string ,std::string side) {
    auto temp1=board.getFieldsCards("Close Combat", side);
    auto temp2=board.getFieldsCards("Ranged", side);
    auto it1 = find_if(temp1.begin(),temp1.end(),[this](const std::shared_ptr<Card> &s) { return s.get() == this; });
    auto it2 = find_if(temp2.begin(), temp2.end(),[this](const std::shared_ptr<Card> &s) { return s.get() == this; });
    if(it1!=temp1.end())
    {
        for(auto & s: board.getFieldsCards("Close Combat", side))
        {
            if(s.get()==this || s->isHeroCard() || s->isSpecialCard() || s->getAbilityType()=="Tight Bond")
                continue;
            s->SetPoints(s->GetPoints(1)+1);
        }
    }
    else if(it2!=temp2.end())
    {
        for(auto & s: board.getFieldsCards("Ranged", side))
        {
            if(s.get()==this || s->isHeroCard() || s->isSpecialCard() || s->getAbilityType()=="Tight Bond")
                continue;
            s->SetPoints(s->GetPoints(1)+1);
        }
    }

}
GaunteroDim::GaunteroDim(Board &board) : UnitCard(2,2,"Gaunter o'Dim","Siege","Muster"), board{board}{}
int GaunteroDim::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> GaunteroDim::clone() {
    std::shared_ptr<GaunteroDim> card(new GaunteroDim(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void GaunteroDim::ability(std::string ,std::string side) {

    for(int i=0;i<3;i++)
    {
        std::shared_ptr<GaunteroDimCien> card1(new GaunteroDimCien(board));
        board.add_Fieldcard(card1->GetType(),side,card1);
    }
}

GaunteroDimCien::GaunteroDimCien(Board &board) : UnitCard(4,4,"Gaunter o'Dim: Cien","Ranged","Muster"), board{board}{}
int GaunteroDimCien::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> GaunteroDimCien::clone() {
    std::shared_ptr<GaunteroDimCien> card(new GaunteroDimCien(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void GaunteroDimCien::ability(std::string ,std::string side) {

    for(int i=0;i<3;i++)
    {
        std::shared_ptr<GaunteroDimCien> card1(new GaunteroDimCien(board));
        board.add_Fieldcard(card1->GetType(),side,card1);
    }

}




krowa::krowa(Board &board) : UnitCard(0,0,"Krowa","Ranged","Spawn"), board{board}{}
int krowa::GetPoints(int ) { return points;}
std::shared_ptr<Card> krowa::clone() {
    std::shared_ptr<krowa> card(new krowa(board));
    std::shared_ptr<Card> card1=card;
    return card1;
}
void krowa::ability(std::string , std::string side) {

    if(side=="Up")
    {
        std::shared_ptr<BydleceSilyZbrojne> card(new BydleceSilyZbrojne);
        board.add_Fieldcard(card->GetType(),"Up",card);
    }
    else if(side=="Down")
    {
        std::shared_ptr<BydleceSilyZbrojne> card(new BydleceSilyZbrojne);
        board.add_Fieldcard(card->GetType(),"Down",card);
    }
}

BydleceSilyZbrojne::BydleceSilyZbrojne(): UnitCard(8,8,"Bydlece Sily Zbrojne","Close Combat"," ") {}
int BydleceSilyZbrojne::GetPoints(int x) { if(x==0){return default_points;}else{return points;}}
std::shared_ptr<Card> BydleceSilyZbrojne::clone() {
    std::shared_ptr<BydleceSilyZbrojne> card(new BydleceSilyZbrojne);
    std::shared_ptr<Card> card1=card;
    return card1;
}
void BydleceSilyZbrojne::ability(std::string , std::string ) {
}