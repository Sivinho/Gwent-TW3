#ifndef GWENT_NORTHERNREALMSDECK_H
#define GWENT_NORTHERNREALMSDECK_H
#include "UnitCard.h"
#include "HeroCard.h"
#include "Board.h"


class Balista : public UnitCard
{
public:
    Balista();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class BiednaPierdolonaPiechota : public UnitCard
{
    Board & board;
public:
    explicit BiednaPierdolonaPiechota(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Detmold : public UnitCard
{
public:
    Detmold();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Thyssen : public HeroCard
{
public:
    Thyssen();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};


class Filippa : public HeroCard
{
public:
    Filippa();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class JanNatalis : public HeroCard
{
public:
    JanNatalis();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Katapulta : public UnitCard
{
    Board & board;
public:
    explicit Katapulta(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class KeiraMetz : public UnitCard
{
public:
    KeiraMetz();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class KomandosNiebieskichPasow : public UnitCard
{
    Board & board;
public:
    explicit KomandosNiebieskichPasow(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class KsiazeStennis : public UnitCard
{
public:
    KsiazeStennis();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class MedyczkaBurejChoragwi: public UnitCard
{
public:
    MedyczkaBurejChoragwi();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class MistrzOblezenKaedwen : public UnitCard
{
    Board & board;
public:
    explicit MistrzOblezenKaedwen(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class RedanskiPiechur : public UnitCard
{
public:
    RedanskiPiechur();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class RebaczezCrinfrid : public UnitCard
{
    Board & board;
public:
    explicit RebaczezCrinfrid(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class SabrinaGlevissig : public UnitCard
{
public:
    SabrinaGlevissig();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class ShealadeTancarville : public UnitCard
{
public:
    ShealadeTancarville();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};


class SheldonSkaggs : public UnitCard
{
public:
    SheldonSkaggs();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Dijkstra : public UnitCard
{
public:
    Dijkstra();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Talar : public UnitCard
{
public:
    Talar();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Trebusz : public UnitCard
{
public:
    Trebusz();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Roche : public HeroCard
{
public:
    Roche();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Ves : public UnitCard
{
public:
    Ves();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Wiezaobleznicza : public UnitCard
{
public:
    Wiezaobleznicza();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class Yarpen : public UnitCard
{
public:
    Yarpen();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};

class ZygfrydzDenesle : public UnitCard
{
public:
    ZygfrydzDenesle();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1,std::string side) override;
};
#endif //GWENT_NORTHERNREALMSDECK_H
