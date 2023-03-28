#ifndef GWENT_NILFGAARDDECK_H
#define GWENT_NILFGAARDDECK_H
#include "UnitCard.h"
#include "HeroCard.h"
#include "Board.h"

class Albrich : public UnitCard
{
public:
    Albrich();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Assire : public UnitCard
{
public:
    Assire();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class NilfgaardzkiLucznik : public UnitCard
{
public:
    NilfgaardzkiLucznik();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Cahir : public UnitCard
{
public:
    Cahir();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};


class Cynthia : public UnitCard
{
public:
    Cynthia();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class WsparcieLucznikow : public UnitCard
{
public:
    WsparcieLucznikow();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Fringilla : public UnitCard
{
public:
    Fringilla();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Scorpion : public UnitCard
{
public:
    Scorpion();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class BrygadaImpera : public UnitCard
{
    Board & board;
public:
    explicit BrygadaImpera(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Letho : public HeroCard
{
public:
    Letho();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Menno : public HeroCard
{
public:
    Menno();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Morteisen : public UnitCard
{
public:
    Morteisen();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Morvran : public HeroCard
{
public:
    Morvran();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Kawaleria : public UnitCard
{
    Board & board;
public:
    explicit Kawaleria(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Puttkammer : public UnitCard
{
public:
    Puttkammer();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Rainfarn : public UnitCard
{
public:
    Rainfarn();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Renuald : public UnitCard
{
public:
    Renuald();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};


class Mangonela : public UnitCard
{
public:
    Mangonela();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Shilard : public UnitCard
{
public:
    Shilard();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Saper : public UnitCard
{
public:
    Saper();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class WsparcieObleznicze : public UnitCard
{
public:
    WsparcieObleznicze();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Skellen : public UnitCard
{
public:
    Skellen();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Sweers : public UnitCard
{
public:
    Sweers();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Tibor : public HeroCard
{
public:
    Tibor();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};


class Vanhemar : public UnitCard
{
public:
    Vanhemar();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Vattier : public UnitCard
{
public:
    Vattier();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Vreemde : public UnitCard
{
public:
    Vreemde();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};


class Emisariusz : public UnitCard
{
    Board & board;
public:
    explicit Emisariusz(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class ZerrScorpion : public UnitCard
{
public:
    ZerrScorpion();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

#endif //GWENT_NILFGAARDDECK_H
