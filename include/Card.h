#ifndef GWENT_CARD_H
#define GWENT_CARD_H
#include <string>
#include <memory>


class Card
{
protected:
    int points,default_points;
    std::string name;
    std::string type;
    std::string ability_type;
    bool isSpecial;
    bool isHero;
    bool isWeather;
public:
    Card();
    Card(int points,int default_points, const std::string & name, std::string type,std::string ability_type,bool isSpecial,bool isHero , bool isWeather);
    Card(int points, std::string name, std::string type,std::string ability_type,bool isSpecial,bool isHero , bool isWeather);
    Card(std::string name, std::string type,std::string ability_type,bool isSpecial,bool isHero , bool isWeather);
    Card(std::string name, std::string ability_type,bool isSpecial,bool isHero , bool isWeather);
    bool isSpecialCard();
    bool isHeroCard();
    std::string CardName();
    void SetPoints(int points);
    bool isWeatherCard();
    std::string GetType();
    std::string getAbilityType();
    virtual int GetPoints(int x)=0;
    virtual std::shared_ptr<Card> clone()=0;
    virtual void ability(std::string type, std::string side)=0;

};


#endif //GWENT_CARD_H
