#include "core_game.h"
#include <iostream>
#include <algorithm>
#include <tuple>

core_game::core_game(Board &board,Player & player_down,Player & player_up) : board(board),player_up(player_up), player_down(player_down)
{}

int core_game::check_winner_of_round()
{
    if(player_down.sum_points()>player_up.sum_points())
    {
        std::cout<<"Runda wygrana przez gracza down"<<std::endl;
        if(player_down.player_deck()=="NorthernRealms")
            player_down.addaditional_cards(1);
        return 1;
    }
    else if(player_down.sum_points()==player_up.sum_points())
    {
        std::cout<<"Runda remisowa"<<std::endl;
        if(player_up.player_deck()=="Nilfgaard" && player_down.player_deck()=="Nilfgaard")
            return 0;
        else if(player_up.player_deck()=="Nilfgaard")
            return -1;
        else if(player_down.player_deck()=="Nilfgaard")
            return 1;
        else
            return 0;
    }
    else
    {
        std::cout<<"Runda wygrana przez gracza up"<<std::endl;
        if(player_up.player_deck()=="NorthernRealms")
            player_up.addaditional_cards(1);
        return -1;
    }
}

void core_game::number_of_won_rounds(int & check)
{
    if(check==1)
    {
        player_down.add_won_round();
    }
    else if(check==0)
    {
        player_down.add_won_round();
        player_up.add_won_round();
    }
    else
    {
        player_up.add_won_round();
    }

}
void core_game::clean_board() {
    for(auto & card : board.getFieldsCards("Close Combat","Up"))
    {
        player_up.addto_discard_pile(card);
    }
    for(auto & card : board.getFieldsCards("Siege","Up"))
    {
        player_up.addto_discard_pile(card);
    }
    for(auto & card : board.getFieldsCards("Ranged","Up"))
    {
        player_up.addto_discard_pile(card);
    }
    for(auto & card : board.getFieldsCards("Close Combat","Down"))
    {
        player_down.addto_discard_pile(card);
    }
    for(auto & card : board.getFieldsCards("Siege","Down"))
    {
        player_down.addto_discard_pile(card);
    }
    for(auto & card : board.getFieldsCards("Ranged","Down"))
    {
        player_down.addto_discard_pile(card);
    }
    for(auto & cards : board.getWeatherCards("Up"))
    {
        player_up.addto_discard_pile(cards);
    }
    for(auto & cards : board.getWeatherCards("Down"))
    {
        player_down.addto_discard_pile(cards);
    }
    std::vector<std::string> fields {"Close Combat","Ranged","Siege"};
    for(auto const & name : fields) {
        auto card1=board.getSpecialCards(name,"Up");
        if(card1!= nullptr)
        {
            player_up.addto_discard_pile(card1);
            board.add_Specialcard(name,"Up", nullptr);
        }
        auto card2=board.getSpecialCards(name,"Down");
        if(card2!= nullptr)
        {
            player_up.addto_discard_pile(card2);
            board.add_Specialcard(name,"Down", nullptr);
        }
    }
    board.del_Weathercards();
    board.clear_Fieldscards();
    player_up.reset_discard_pile();
    player_down.reset_discard_pile();
    auto discardpileup=player_up.getDiscardPile();
    auto discardpiledown=player_down.getDiscardPile();
    auto it1 = find_if(discardpileup.begin(), discardpileup.end(), [] (const std::shared_ptr<Card>& s) { return s->CardName() == "Krowa"; } );
    auto it2 = find_if(discardpiledown.begin(), discardpiledown.end(), [] (const std::shared_ptr<Card>& s) { return s->CardName() == "Krowa"; } );
    if(it1!=discardpileup.end())
    {
        (*it1)->ability("None","Up");
    }
    if(it2!=discardpiledown.end())
    {
        (*it2)->ability("None","Down");
    }
}

void core_game::clean_weather_clear_sky(std::shared_ptr<Card> card) {
    if(card->CardName()=="Czyste Niebo")
    {
        for(auto & cards : board.getWeatherCards("Up"))
        {
            player_up.addto_discard_pile(cards);
        }
        for(auto & cards : board.getWeatherCards("Down"))
        {
            player_down.addto_discard_pile(cards);
        }
        board.del_Weathercards();
    }
    else
    {
        return;
    }

}

void core_game::universal_abilities() {
    std::vector<std::shared_ptr<Card>> Up=board.getWeatherCards("Up");
    std::vector<std::shared_ptr<Card>> Down=board.getWeatherCards("Down");
    auto it1 = find_if(Up.begin(), Up.end(), [] (const std::shared_ptr<Card>& s) { return s->CardName() == "Trzaskajacy Mroz"; } );
    auto it2 = find_if(Down.begin(), Down.end(), [] (const std::shared_ptr<Card>& s) { return s->CardName() == "Trzaskajacy Mroz"; } );
    if(it1!=Up.end())
    {
        (*it1)->ability("None","None");
    }
    else if(it2!=Down.end())
    {
        (*it2)->ability("None","None");
    }
    auto it3 = find_if(Up.begin(), Up.end(), [] (const std::shared_ptr<Card>& s) { return s->CardName() == "Deszcz"; } );
    auto it4 = find_if(Down.begin(), Down.end(), [] (const std::shared_ptr<Card>& s) { return s->CardName() == "Deszcz"; } );
    if(it3!=Up.end() )
    {
        (*it3)->ability("None","None");
    }
    else if(it4!=Down.end())
    {
        (*it4)->ability("None","None");
    }
    auto it5 = find_if(Up.begin(), Up.end(), [] (const std::shared_ptr<Card>& s) { return s->CardName() == "Mgla"; } );
    auto it6 = find_if(Down.begin(), Down.end(), [] (const std::shared_ptr<Card>& s) { return s->CardName() == "Mgla"; } );
    if(it5!=Up.end() )
    {
        (*it5)->ability("None","None");
    }
    else if(it6!=Down.end())
    {
        (*it6)->ability("None","None");
    }
}

void core_game::cards_abilities(std::shared_ptr<Card> card, std::string side){
    std::vector<std::string> fields {"Close Combat","Ranged","Siege"};
    def_state();
    universal_abilities();
    for(auto & types : fields)
    {
        for(auto s: board.getFieldsCards(types,"Up"))
        {
            if(s->getAbilityType()=="Spawn")
                continue;
            s->ability("None","Up");
        }
        if(board.getSpecialCards(types,"Up")!=nullptr)
        {
            board.getSpecialCards(types,"Up")->ability(types,"Up");
        }

    }
    for(auto & types : fields)
    {
        for(auto s: board.getFieldsCards(types,"Down")) {
            if (s->getAbilityType()=="Spawn")
                continue;
            s->ability("None","Down");
        }
        if(board.getSpecialCards(types,"Down")!=nullptr)
        {
            board.getSpecialCards(types,"Down")->ability(types,"Down");
        }
    }
    if(card->getAbilityType()=="Manekin")
    {
        decoy(card,side);
    }
    else if(card->getAbilityType()=="Scorch")
    {
        scorch(card,side);
    }
    else if(card->getAbilityType()=="Spy" && side=="Up")
    {
        player_up.addaditional_cards(2);
    }
    else if(card->getAbilityType()=="Spy" && side=="Down")
    {
        player_down.addaditional_cards(2);
    }
    else if(card->getAbilityType()=="Medic")
    {
        medic(side);
    }
    def_state();
    universal_abilities();
    for(auto & types : fields)
    {
        for(auto s: board.getFieldsCards(types,"Up"))
        {
            if(s->getAbilityType()=="Spawn")
                continue;
            s->ability("None","Up");
        }
        if(board.getSpecialCards(types,"Up")!=nullptr)
        {
            board.getSpecialCards(types,"Up")->ability(types,"Up");
        }

    }
    for(auto & types : fields)
    {
        for(auto s: board.getFieldsCards(types,"Down")) {
            if (s->getAbilityType()=="Spawn")
                continue;
            s->ability("None","Down");
        }
        if(board.getSpecialCards(types,"Down")!=nullptr)
        {
            board.getSpecialCards(types,"Down")->ability(types,"Down");
        }
    }


}
void core_game::decoy(std::shared_ptr<Card> card, std::string side)
{
    int i=0;
    std::vector<std::string> fields {"Close Combat","Ranged","Siege"};
    for(auto & row: fields)
    {
        for(auto & s: board.getFieldsCards(row,side))
        {
            if(s->isHeroCard())
                i=i+1;
        }
    }
    int a=board.getFieldsCards("Close Combat",side).size()+board.getFieldsCards("Ranged",side).size()+board.getFieldsCards("Siege",side).size();
    if(a==0 || a==i)
    {
        if(side=="Up")
        {
            player_up.addCard(card);
            std::cout<<"Na planszy nie ma kart badz sa tylko karty bohaterow, wybierz inna karte z reki"<<std::endl;
            std::shared_ptr<Card> playup_card=player_up.choose_card();
            clean_weather_clear_sky(playup_card);
            def_state();
            universal_abilities();
            cards_abilities(playup_card,"Up");
        }
        else
        {
            player_down.addCard(card);
            std::cout<<"Na planszy nie ma kart badz sa tylko karty bohaterow, wybierz inna karte z reki"<<std::endl;
            std::shared_ptr<Card> playup_card=player_down.choose_card();
            clean_weather_clear_sky(playup_card);
            def_state();
            universal_abilities();
            cards_abilities(playup_card,"Down");
        }

    }
    else
    {
        std::cout<<"Wybierz karte z pola bitwy aby ja zastapic"<<std::endl;
        std::string karta;
        std::shared_ptr<Card> temp;
        while(true)
        {
            std::getline(std::cin, karta);
            temp=board.getFieldCard(side,karta);
            if(temp==nullptr)
            {
                std::cout<<"Nie ma takiej karty na planszy lub wybrales karte bohatera! Sprobuj ponownie"<<std::endl;
            }
            else if(temp->GetType()=="Agile")
            {
                auto temp1=board.getFieldsCards("Close Combat",side);
                auto it1=std::find(temp1.begin(),temp1.end(),temp);
                if(it1!=temp1.end())
                {
                    system("cls");
                    board.del_Fieldcard("Close Combat",side,temp);
                    board.add_Fieldcard("Close Combat",side,card);
                    break;
                }
                else
                {
                    system("cls");
                    board.del_Fieldcard("Ranged",side,temp);
                    board.add_Fieldcard("Ranged",side,card);
                    break;
                }
            }
            else if(!temp->isHeroCard())
            {
                system("cls");
                board.del_Fieldcard(temp->GetType(),side,temp);
                board.add_Fieldcard(temp->GetType(),side,card);
                break;
            }
            else
            {
                std::cout<<"Nie ma takiej karty na planszy lub wybrales karte bohatera! Sprobuj ponownie"<<std::endl;
            }
        }
        if(side=="Up")
        {
            player_up.addCard(temp);
        }
        else if(side=="Down")
        {
            player_down.addCard(temp);
        }

    }
}

void core_game::scorch(std::shared_ptr<Card> card,std::string side) {
    if(card->CardName()=="Borch Trzy Kawki")
    {
        std::vector<std::pair<std::string,std::shared_ptr<Card>>> maxval ;
        int i=0;
        int sum=0;
        if(side=="Down")
        {
            for(auto const & s: board.getFieldsCards("Close Combat","Up"))
            {
                sum+=s->GetPoints(1);
            }
            if(sum>9)
            {
                for(auto cards: board.getFieldsCards("Close Combat","Up"))
                {
                    if(cards->isHeroCard())
                        continue;
                    else if(cards->GetPoints(1)>i)
                    {
                        maxval.clear();
                        i=cards->GetPoints(1);
                        maxval.emplace_back(std::make_pair("Up",cards));
                    }
                    else if(cards->GetPoints(1)==i)
                    {
                        maxval.emplace_back(std::make_pair("Up",cards));
                    }
                }
            }
        }
        else
        {
            for(auto const & s: board.getFieldsCards("Close Combat","Down"))
            {
                sum+=s->GetPoints(1);
            }
            if(sum>9)
            {
                for(auto cards: board.getFieldsCards("Close Combat","Down"))
                {
                    if(cards->isHeroCard())
                        continue;
                    else if(cards->GetPoints(1)>i)
                    {
                        maxval.clear();
                        i=cards->GetPoints(1);
                        maxval.emplace_back(std::make_pair("Down",cards));
                    }
                    else if(cards->GetPoints(1)==i)
                    {
                        maxval.emplace_back(std::make_pair("Down",cards));
                    }
                }
            }
        }
        for(auto s: maxval)
        {
            if(s.first =="Up")
            {
                player_up.addto_discard_pile(s.second);
                board.del_Fieldcard("Close Combat",s.first,s.second);
            }
            else if(s.first =="Down")
            {
                player_down.addto_discard_pile(s.second);
                board.del_Fieldcard("Close Combat",s.first,s.second);
            }
            else return;
        }
    }
    else
    {
        std::vector<std::tuple<std::string,std::string,std::shared_ptr<Card>>> maxval ;
        int i=0;
        std::vector<std::string> fields {"Close Combat","Ranged","Siege"};

        for(auto & s:fields)
        {
            for(auto cards: board.getFieldsCards(s,"Up"))
            {
                if(cards->isHeroCard())
                    continue;
                else if(cards->GetPoints(1)>i)
                {
                    maxval.clear();
                    i=cards->GetPoints(1);
                    maxval.emplace_back(std::make_tuple(s,"Up",cards));
                }
                else if(cards->GetPoints(1)==i)
                {
                    maxval.emplace_back(std::make_tuple(s,"Up",cards));
                }
            }
            for(auto cards: board.getFieldsCards(s,"Down"))
            {
                if(cards->isHeroCard())
                    continue;
                else if(cards->GetPoints(1)>i)
                {
                    maxval.clear();
                    i=cards->GetPoints(1);
                    maxval.emplace_back(std::make_tuple(s,"Down",cards));
                }
                else if(cards->GetPoints(1)==i)
                {
                    maxval.emplace_back(std::make_tuple(s,"Down",cards));
                }
            }
        }
        for(auto s: maxval)
        {
            if(std::get<1>(s)=="Up")
            {
                player_up.addto_discard_pile(std::get<2>(s));
                board.del_Fieldcard(std::get<0>(s),std::get<1>(s),std::get<2>(s));
            }
            else if(std::get<1>(s)=="Down")
            {
                player_down.addto_discard_pile(std::get<2>(s));
                board.del_Fieldcard(std::get<0>(s),std::get<1>(s),std::get<2>(s));
            }
            else return;
        }
    }
}

void core_game::def_state() {
    std::vector<std::string> fields {"Close Combat","Ranged","Siege"};
        for(auto & types : fields)
        {
            for(auto s: board.getFieldsCards(types,"Up"))
            {
                if(s->isHeroCard() || s->isSpecialCard())
                    continue;
                s->SetPoints(s->GetPoints(0));
            }
        }
        for(auto & types : fields)
        {
            for(auto s: board.getFieldsCards(types,"Down"))
            {
                if(s->isHeroCard() || s->isSpecialCard())
                    continue;
                s->SetPoints(s->GetPoints(0));
            }
        }
}
void core_game::medic(std::string side) {
    if(side=="Down")
    {
        int i=0;
        for(auto & s: player_down.getDiscardPile())
        {
            if(s->isHeroCard() || s->isSpecialCard() || s->isWeatherCard())
                continue;
            i=i+1;
            std::cout<<s->CardName()<<"-"<<s->GetPoints(1)<<"  ";
        }
        if(i>0)
        {
            std::string karta;
            std::vector<std::shared_ptr<Card>>::iterator it;
            auto discard = player_down.getDiscardPile();
            std::shared_ptr<Card> card;
            std::cout<<std::endl;
            while(true)
            {
                std::cout<<"Podaj karte do przywrocenia na plansze ze stosu kart odrzuconych lub nie wybieraj karty wpisujac 0: "<<std::endl;
                std::getline(std::cin, karta);
                if(karta=="0")
                {
                    system("cls");
                    return;
                }
                it = find_if(discard.begin(), discard.end(), [&karta] (const std::shared_ptr<Card>& s) { return (s->CardName() == karta && !s->isHeroCard() && !s->isSpecialCard() && !s->isWeatherCard()); } );
                if(it!=discard.end())
                {
                    system("cls");
                    card=*it;
                    break;
                }
                else
                {
                    std::cout<<"Podales zla wartosc, sprobuj ponownie"<<std::endl;
                }
            }
            board.add_card(card->GetType(),"Down",card);
            def_state();
            universal_abilities();
            cards_abilities(card,"Down");
            player_down.deleteCard_from_dispile(card);
        }
    }
    else
    {
        int i=0;
        for(auto & s: player_up.getDiscardPile())
        {
            if(s->isHeroCard() || s->isSpecialCard() || s->isWeatherCard())
                continue;
            i=i+1;
            std::cout<<s->CardName()<<"-"<<s->GetPoints(1)<<"  ";
        }
        if(i>0)
        {
            std::string karta;
            std::vector<std::shared_ptr<Card>>::iterator it;
            auto discard = player_up.getDiscardPile();
            std::shared_ptr<Card> card;
            std::cout<<std::endl;
            while(true)
            {
                std::cout<<"Podaj karte do przywrocenia na plansze ze stosu kart odrzuconych lub nie wybieraj karty wpisujac 0: "<<std::endl;
                std::getline(std::cin, karta);
                if(karta=="0")
                    return;
                it = find_if(discard.begin(), discard.end(), [&karta] (const std::shared_ptr<Card>& s) { return (s->CardName() == karta && !s->isHeroCard() && !s->isSpecialCard() && !s->isWeatherCard()); } );
                if(it!=discard.end())
                {
                    card=*it;
                    break;
                }
                else
                {
                    std::cout<<"Podales zla karte, sprobuj ponownie"<<std::endl;
                }
            }
            board.add_card(card->GetType(),"Up",card);
            def_state();
            universal_abilities();
            cards_abilities(card,"Up");
            player_up.deleteCard_from_dispile(card);
        }
    }

}