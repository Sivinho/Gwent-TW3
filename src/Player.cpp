#include "Player.h"
#include <iostream>
#include <algorithm>
#include <limits>


void Player::view_cards()
{
    std::cout<<std::endl;
    std::cout<<std::endl;
    std::cout<<"Player "<<name<<" : karty do wyboru:"<<std::endl;
    for(auto const &cards :cards_in_hand)
    {
        if(cards->isWeatherCard() || cards->isSpecialCard())
        std::cout<<cards->CardName()<<" ";
        else
        std::cout<<cards->CardName()<<"-"<<cards->GetPoints(0)<<"  ";
    }
    std::cout<<std::endl;
}

std::shared_ptr<Card> Player::choose_card()
{
        view_cards();
        swap_cards();
        std::string karta;
        std::vector<std::shared_ptr<Card>>::iterator it;
        while(true)
        {
            std::cout<<"Podaj karte do polozenia na planszy: "<<std::endl;
            std::getline(std::cin, karta);
            it = find_if(cards_in_hand.begin(), cards_in_hand.end(), [&karta] (const std::shared_ptr<Card>& s) { return s->CardName() == karta; } );
            if(it!=cards_in_hand.end())
            {
                if((*it)->getAbilityType()=="Manekin" || (*it)->GetType()=="Agile" || (*it)->getAbilityType()=="Medic")
                {
                    break;
                }
                else
                {
                    system("cls");
                    break;
                }
            }
            else
            {
                std::cout<<"Podales zla karte, sprobuj ponownie"<<std::endl;
            }
        }
        auto card=*it;
        if(card->CardName()=="Czyste Niebo" || card->CardName()=="Pozoga")
            discard_pile.push_back(card);
        cards_in_hand.erase(it);
        board.add_card(card->GetType(),name,card);
        return card;
}

Player::Player(std::string side,std::vector<std::shared_ptr<Card>> cards_in_hand,  CardManager & mgr, std::string & deck, Board & board): name(side),cards_in_hand(cards_in_hand),  mgr(mgr), deck(deck), board(board)
{}

void Player::deleteCard(std::shared_ptr<Card> card)
{
    auto it= std::find(cards_in_hand.begin(),cards_in_hand.end(),card);
    cards_in_hand.erase(it);
}

void Player::deleteCard_from_dispile(std::shared_ptr<Card> card) {
    auto it= std::find(discard_pile.begin(),discard_pile.end(),card);
    discard_pile.erase(it);

}

bool Player::Pass() {
    std::cout<<"Player "<<name<<": ";
    std::cout<<"Pass? Wpisz tak lub nie"<<std::endl;
    std::string choice;
    std::cin>>choice;
    std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    while(choice!="Tak" && choice!="Nie" && choice!="nie" && choice!="tak")
    {
        std::cout<<"Podales zla wartosc, sprobuj ponownie!"<<std::endl;
        std::cin>>choice;
        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    }
    system("cls");
    if(choice=="tak" || choice=="Tak")
        return true;
    else
        return false;
}

int Player::countCards() {
    return cards_in_hand.size();
}

void Player::addto_discard_pile(std::shared_ptr<Card> card) {
    discard_pile.push_back(card);

}

void Player::swap_cards() {
    if(check)
    {
        std::cout<<std::endl;
        std::cout<<"Chcesz wymienic dwie karty na losowe z talii? Tak, Nie"<<std::endl;
        std::string x;
        std::cin>>x;
        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        while(x!="Tak" && x!="Nie" && x!="nie" && x!="tak")
        {
            std::cout<<"Podales zla wartosc, sprobuj ponownie!"<<std::endl;
            std::cin>>x;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(x=="Nie" || x=="nie")
        {
            check=false;
            //std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            return;
        }
        else if(x=="Tak" || x=="tak")
        {
            check=false;
            std::cout<<"Ile kart chcesz wymienic z kart posiadanych? Wpisz 1 lub 2"<<std::endl;
            std::string a;
            std::cin>>a;
            std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            while(a!="1" && a!="2")
            {
                std::cout<<"Podales zla wartosc, sprobuj ponownie!"<<std::endl;
                std::cin>>a;
                std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            }
            int num=std::stoi(a);
            std::string choice;
            for(int i =0;i<num;i++)
            {
                std::cout<<"Podaj nazwe karty"<<std::endl;
                std::vector<std::shared_ptr<Card>>::iterator it1;
                while(true) {
                    std::getline(std::cin, choice);
                    it1 = find_if(cards_in_hand.begin(), cards_in_hand.end(),[&choice](const std::shared_ptr<Card> &s) { return s->CardName() == choice; });
                    if (it1 != cards_in_hand.end()) {
                        break;
                    } else {
                        std::cout << "Podales zla karte, sprobuj ponownie" << std::endl;
                    }
                }
                cards_in_hand.erase(it1);
            }
            addaditional_cards(num);
            view_cards();
        }
    }
    else
    {
        return;
    }
}

std::vector<std::shared_ptr<Card>> Player::getDiscardPile() {
    return discard_pile;
}

void Player::reset_discard_pile() {
    for(auto & s:discard_pile)
    {
        if(s->isHeroCard() || s->isWeatherCard() || s->isSpecialCard())
            continue;
        s->SetPoints(s->GetPoints(0));
    }
}

void Player::addCard(std::shared_ptr<Card> card) {

    cards_in_hand.push_back(card);
}

void Player::addaditional_cards(int i) {
    auto additional=mgr.RandomCards(i,name);
    for(int x=0;x<i;x++)
    {
        cards_in_hand.push_back(additional[x]);
    }
}

std::string Player::player_deck() {
   return deck;
}

int Player::GetNumber_of_won_rounds() {
    return number_of_won_rounds;
}

void Player::add_won_round() {
    number_of_won_rounds++;
}

int Player::sum_points() {
    int sum_of_points=0;
    std::vector<std::string> fields {"Close Combat","Ranged","Siege"};
    for(auto const & name1 : fields)
    {
        const std::vector<std::shared_ptr<Card>> row=board.getFieldsCards(name1,name);
        for(auto const & cards : row)
        {
            int points=cards->GetPoints(1);
            sum_of_points+=points;
        }
    }
    return sum_of_points;
}