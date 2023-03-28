#ifndef GWENT_NEUTRALCARDS_H
#define GWENT_NEUTRALCARDS_H
#include "HeroCard.h"
#include "UnitCard.h"
#include "WeatherCard.h"
#include "SpecialCard.h"
#include "Board.h"


class TajemniczyElf : public HeroCard
{
public:
    TajemniczyElf();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;

};

class GeraltzRivii : public HeroCard
{
public:
    GeraltzRivii();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class TrzaskajacyMroz : public WeatherCard
{
    Board & board;
public:
    explicit TrzaskajacyMroz(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Ciri : public HeroCard
{
public:
    Ciri();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class RogDowodcy : public SpecialCard
{
    Board & board;
public:
    explicit RogDowodcy(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class CzysteNiebo : public WeatherCard
{
public:
    explicit CzysteNiebo();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Jaskier : public UnitCard
{
    Board & board;
public:
    explicit Jaskier(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Manekin : public SpecialCard
{
public:
    Manekin();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Regis : public UnitCard
{
public:
    Regis();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Mgla : public WeatherCard
{
    Board & board;
public:
    explicit Mgla(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Pozoga : public SpecialCard
{
public:
    Pozoga();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Deszcz: public WeatherCard
{
    Board & board;
public:
    explicit Deszcz(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Triss : public HeroCard
{
public:
    Triss();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Vesemir: public UnitCard
{
public:
    Vesemir();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Borch : public UnitCard
{
public:
    Borch();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Yennefer: public HeroCard
{
public:
    Yennefer();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class Zoltan : public UnitCard
{
public:
    Zoltan();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class OlgierdvonEverec : public UnitCard
{
    Board& board;
public:
    explicit OlgierdvonEverec(Board& board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class GaunteroDim : public UnitCard
{
    Board & board;
public:
    explicit GaunteroDim(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class GaunteroDimCien : public UnitCard
{
    Board & board;
public:
    explicit GaunteroDimCien(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class krowa : public UnitCard
{
    Board & board;
public:
    explicit krowa(Board & board);
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;
};

class BydleceSilyZbrojne : public UnitCard
{
public:
    BydleceSilyZbrojne();
    int GetPoints(int x) override;
    std::shared_ptr<Card> clone() override;
    void ability(std::string type1, std::string side) override;

};

#endif //GWENT_NEUTRALCARDS_H
