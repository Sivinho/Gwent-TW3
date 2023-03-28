#include "Card.h"

Card::Card() {};
Card::Card(int points, int default_points, const std::string & name, std::string type, std::string ability_type, bool isWeather, bool isSpecial, bool isHero): points(points),default_points(default_points) ,name(name), type(type), ability_type(ability_type), isSpecial(isSpecial),isHero(isHero),isWeather(isWeather) {};
Card::Card(int points, std::string name, std::string type, std::string ability_type, bool isWeather, bool isSpecial, bool isHero): points(points),name(name), type(type), ability_type(ability_type), isSpecial(isSpecial),isHero(isHero),isWeather(isWeather) {};
Card::Card(std::string name, std::string type, std::string ability_type, bool isWeather, bool isSpecial, bool isHero): name(name), type(type),ability_type(ability_type), isSpecial(isSpecial),isHero(isHero),isWeather(isWeather) {};
Card::Card(std::string name, std::string ability_type, bool isWeather, bool isSpecial, bool isHero): name(name), ability_type(ability_type), isSpecial(isSpecial),isHero(isHero),isWeather(isWeather) {};

bool Card::isSpecialCard() {return isSpecial;}
bool Card::isHeroCard() {return isHero;}
std::string Card::CardName() {return name;}
void Card::SetPoints(int changepoints) {points=changepoints;};
bool Card::isWeatherCard() {return isWeather;}
std::string Card::GetType() {return type;}
std::string Card::getAbilityType() {return ability_type;};
