#include "CardManager.h"
#include <algorithm>

CardManager::CardManager(std::string &deck_up, std::string &deck_down, Board & board): board(board)
{
    cards_up.reserve(200);
    cards_down.reserve(200);
    std::shared_ptr<TajemniczyElf> card1(new TajemniczyElf);
    cards_up.push_back(card1);
    std::shared_ptr<GeraltzRivii> card2(new GeraltzRivii);
    cards_up.push_back(card2);
    std::shared_ptr<TrzaskajacyMroz> card3(new TrzaskajacyMroz(board));
    cards_up.push_back(card3);
    std::shared_ptr<Ciri> card4(new Ciri);
    cards_up.push_back(card4);
    std::shared_ptr<RogDowodcy> card5(new RogDowodcy(board));
    cards_up.push_back(card5);
    std::shared_ptr<CzysteNiebo> card6(new CzysteNiebo);
    cards_up.push_back(card6);
    std::shared_ptr<Jaskier> card7(new Jaskier(board));
    cards_up.push_back(card7);
    std::shared_ptr<Manekin> card8(new Manekin);
    cards_up.push_back(card8);
    std::shared_ptr<Regis> card9(new Regis);
    cards_up.push_back(card9);
    std::shared_ptr<Mgla> card10(new Mgla(board));
    cards_up.push_back(card10);
    std::shared_ptr<Pozoga> card11(new Pozoga);
    cards_up.push_back(card11);
    std::shared_ptr<Deszcz> card12(new Deszcz(board));
    cards_up.push_back(card12);
    std::shared_ptr<Triss> card13(new Triss);
    cards_up.push_back(card13);
    std::shared_ptr<Vesemir> card14(new Vesemir);
    cards_up.push_back(card14);
    std::shared_ptr<Borch> card15(new Borch);
    cards_up.push_back(card15);
    std::shared_ptr<Yennefer> card16(new Yennefer);
    cards_up.push_back(card16);
    std::shared_ptr<Zoltan> card17(new Zoltan);
    cards_up.push_back(card17);
    std::shared_ptr<OlgierdvonEverec> card18(new OlgierdvonEverec(board));
    cards_up.push_back(card18);
    std::shared_ptr<GaunteroDim> card19(new GaunteroDim(board));
    cards_up.push_back(card19);
    std::shared_ptr<krowa> card20(new krowa(board));
    cards_up.push_back(card20);

    std::shared_ptr<TajemniczyElf> card111(new TajemniczyElf);
    cards_down.push_back(card111);
    std::shared_ptr<GeraltzRivii> card22(new GeraltzRivii);
    cards_down.push_back(card22);
    std::shared_ptr<TrzaskajacyMroz> card33(new TrzaskajacyMroz(board));
    cards_down.push_back(card33);
    std::shared_ptr<Ciri> card44(new Ciri);
    cards_down.push_back(card44);
    std::shared_ptr<RogDowodcy> card55(new RogDowodcy(board));
    cards_down.push_back(card55);
    std::shared_ptr<CzysteNiebo> card66(new CzysteNiebo);
    cards_down.push_back(card66);
    std::shared_ptr<Jaskier> card77(new Jaskier(board));
    cards_down.push_back(card77);
    std::shared_ptr<Manekin> card88(new Manekin);
    cards_down.push_back(card88);
    std::shared_ptr<Regis> card99(new Regis);
    cards_down.push_back(card9);
    std::shared_ptr<Mgla> card1010(new Mgla(board));
    cards_down.push_back(card1010);
    std::shared_ptr<Pozoga> card1111(new Pozoga);
    cards_down.push_back(card1111);
    std::shared_ptr<Deszcz> card1212(new Deszcz(board));
    cards_down.push_back(card1212);
    std::shared_ptr<Triss> card1313(new Triss);
    cards_down.push_back(card1313);
    std::shared_ptr<Vesemir> card1414(new Vesemir);
    cards_down.push_back(card1414);
    std::shared_ptr<Borch> card1515(new Borch);
    cards_down.push_back(card1515);
    std::shared_ptr<Yennefer> card1616(new Yennefer);
    cards_down.push_back(card1616);
    std::shared_ptr<Zoltan> card1717(new Zoltan);
    cards_down.push_back(card1717);
    std::shared_ptr<OlgierdvonEverec> card1818(new OlgierdvonEverec(board));
    cards_down.push_back(card1818);
    std::shared_ptr<GaunteroDim> card1919(new GaunteroDim(board));
    cards_down.push_back(card1919);
    std::shared_ptr<krowa> card2020(new krowa(board));
    cards_down.push_back(card2020);

    if(deck_up=="NorthernRealms")
    {

        std::shared_ptr<Balista> cardn1(new Balista);
        cards_up.push_back(cardn1);
        std::shared_ptr<BiednaPierdolonaPiechota> cardn2(new BiednaPierdolonaPiechota(board));
        cards_up.push_back(cardn2);
        std::shared_ptr<Detmold> cardn3(new Detmold);
        cards_up.push_back(cardn3);
        std::shared_ptr<Thyssen> cardn4(new Thyssen);
        cards_up.push_back(cardn4);
        std::shared_ptr<Filippa> cardn5(new Filippa);
        cards_up.push_back(cardn5);
        std::shared_ptr<JanNatalis> cardn6(new JanNatalis);
        cards_up.push_back(cardn6);
        std::shared_ptr<Katapulta> cardn7(new Katapulta(board));
        cards_up.push_back(cardn7);
        std::shared_ptr<KeiraMetz> cardn8(new KeiraMetz);
        cards_up.push_back(cardn8);
        std::shared_ptr<KomandosNiebieskichPasow> cardn9(new KomandosNiebieskichPasow(board));
        cards_up.push_back(cardn9);
        std::shared_ptr<KsiazeStennis> cardn10(new KsiazeStennis);
        cards_up.push_back(cardn10);
        std::shared_ptr<MedyczkaBurejChoragwi> cardn11(new MedyczkaBurejChoragwi);
        cards_up.push_back(cardn11);
        std::shared_ptr<MistrzOblezenKaedwen> cardn12(new MistrzOblezenKaedwen(board));
        cards_up.push_back(cardn12);
        std::shared_ptr<RedanskiPiechur> cardn13(new RedanskiPiechur);
        cards_up.push_back(cardn13);
        std::shared_ptr<RebaczezCrinfrid> cardn14(new RebaczezCrinfrid(board));
        cards_up.push_back(cardn14);
        std::shared_ptr<SabrinaGlevissig> cardn15(new SabrinaGlevissig);
        cards_up.push_back(cardn15);
        std::shared_ptr<ShealadeTancarville> cardn16(new ShealadeTancarville);
        cards_up.push_back(cardn16);
        std::shared_ptr<SheldonSkaggs> cardn17(new SheldonSkaggs);
        cards_up.push_back(cardn17);
        std::shared_ptr<Dijkstra> cardn18(new Dijkstra);
        cards_up.push_back(cardn18);
        std::shared_ptr<Talar> cardn19(new Talar);
        cards_up.push_back(cardn19);
        std::shared_ptr<Trebusz> cardn20(new Trebusz);
        cards_up.push_back(cardn20);
        std::shared_ptr<Roche> cardn21(new Roche);
        cards_up.push_back(cardn21);
        std::shared_ptr<Ves> cardn22(new Ves);
        cards_up.push_back(cardn22);
        std::shared_ptr<Wiezaobleznicza> cardn23(new Wiezaobleznicza);
        cards_up.push_back(cardn23);
        std::shared_ptr<Yarpen> cardn24(new Yarpen);
        cards_up.push_back(cardn24);
        std::shared_ptr<ZygfrydzDenesle> cardn25(new ZygfrydzDenesle);
        cards_up.push_back(cardn25);
    }
    else if(deck_up=="Nilfgaard")
    {
        std::shared_ptr<Albrich> cardn1(new Albrich);
        cards_up.push_back(cardn1);
        std::shared_ptr<Assire> cardn2(new Assire);
        cards_up.push_back(cardn2);
        std::shared_ptr<NilfgaardzkiLucznik> cardn3(new NilfgaardzkiLucznik);
        cards_up.push_back(cardn3);
        std::shared_ptr<Cahir> cardn4(new Cahir);
        cards_up.push_back(cardn4);
        std::shared_ptr<Cynthia> cardn5(new Cynthia);
        cards_up.push_back(cardn5);
        std::shared_ptr<WsparcieLucznikow> cardn6(new WsparcieLucznikow);
        cards_up.push_back(cardn6);
        std::shared_ptr<Fringilla> cardn7(new Fringilla);
        cards_up.push_back(cardn7);
        std::shared_ptr<Scorpion> cardn8(new Scorpion);
        cards_up.push_back(cardn8);
        std::shared_ptr<BrygadaImpera> cardn9(new BrygadaImpera(board));
        cards_up.push_back(cardn9);
        std::shared_ptr<Letho> cardn10(new Letho);
        cards_up.push_back(cardn10);
        std::shared_ptr<Menno> cardn11(new Menno);
        cards_up.push_back(cardn11);
        std::shared_ptr<Morteisen> cardn12(new Morteisen);
        cards_up.push_back(cardn12);
        std::shared_ptr<Morvran> cardn13(new Morvran);
        cards_up.push_back(cardn13);
        std::shared_ptr<Kawaleria> cardn14(new Kawaleria(board));
        cards_up.push_back(cardn14);
        std::shared_ptr<Puttkammer> cardn15(new Puttkammer);
        cards_up.push_back(cardn15);
        std::shared_ptr<Rainfarn> cardn16(new Rainfarn);
        cards_up.push_back(cardn16);
        std::shared_ptr<Renuald> cardn17(new Renuald);
        cards_up.push_back(cardn17);
        std::shared_ptr<Mangonela> cardn18(new Mangonela);
        cards_up.push_back(cardn18);
        std::shared_ptr<Shilard> cardn19(new Shilard);
        cards_up.push_back(cardn19);
        std::shared_ptr<Saper> cardn20(new Saper);
        cards_up.push_back(cardn20);
        std::shared_ptr<WsparcieObleznicze> cardn21(new WsparcieObleznicze);
        cards_up.push_back(cardn21);
        std::shared_ptr<Skellen> cardn22(new Skellen);
        cards_up.push_back(cardn22);
        std::shared_ptr<Sweers> cardn23(new Sweers);
        cards_up.push_back(cardn23);
        std::shared_ptr<Tibor> cardn24(new Tibor);
        cards_up.push_back(cardn24);
        std::shared_ptr<Vanhemar> cardn25(new Vanhemar);
        cards_up.push_back(cardn25);
        std::shared_ptr<Vattier> cardn245(new Vattier);
        cards_up.push_back(cardn245);
        std::shared_ptr<Vreemde> cardn2425(new Vreemde);
        cards_up.push_back(cardn2425);
        std::shared_ptr<Emisariusz> cardn22425(new Emisariusz(board));
        cards_up.push_back(cardn22425);
        std::shared_ptr<ZerrScorpion> cardn24225(new ZerrScorpion);
        cards_up.push_back(cardn24225);
    }

    if(deck_down=="NorthernRealms")
    {
        std::shared_ptr<Balista> cardn1(new Balista);
        cards_down.push_back(cardn1);
        std::shared_ptr<BiednaPierdolonaPiechota> cardn2(new BiednaPierdolonaPiechota(board));
        cards_down.push_back(cardn2);
        std::shared_ptr<Detmold> cardn3(new Detmold);
        cards_down.push_back(cardn3);
        std::shared_ptr<Thyssen> cardn4(new Thyssen);
        cards_down.push_back(cardn4);
        std::shared_ptr<Filippa> cardn5(new Filippa);
        cards_down.push_back(cardn5);
        std::shared_ptr<JanNatalis> cardn6(new JanNatalis);
        cards_down.push_back(cardn6);
        std::shared_ptr<Katapulta> cardn7(new Katapulta(board));
        cards_down.push_back(cardn7);
        std::shared_ptr<KeiraMetz> cardn8(new KeiraMetz);
        cards_down.push_back(cardn8);
        std::shared_ptr<KomandosNiebieskichPasow> cardn9(new KomandosNiebieskichPasow(board));
        cards_down.push_back(cardn9);
        std::shared_ptr<KsiazeStennis> cardn10(new KsiazeStennis);
        cards_down.push_back(cardn10);
        std::shared_ptr<MedyczkaBurejChoragwi> cardn11(new MedyczkaBurejChoragwi);
        cards_down.push_back(cardn11);
        std::shared_ptr<MistrzOblezenKaedwen> cardn12(new MistrzOblezenKaedwen(board));
        cards_down.push_back(cardn12);
        std::shared_ptr<RedanskiPiechur> cardn13(new RedanskiPiechur);
        cards_down.push_back(cardn13);
        std::shared_ptr<RebaczezCrinfrid> cardn14(new RebaczezCrinfrid(board));
        cards_down.push_back(cardn14);
        std::shared_ptr<SabrinaGlevissig> cardn15(new SabrinaGlevissig);
        cards_down.push_back(cardn15);
        std::shared_ptr<ShealadeTancarville> cardn16(new ShealadeTancarville);
        cards_down.push_back(cardn16);
        std::shared_ptr<SheldonSkaggs> cardn17(new SheldonSkaggs);
        cards_down.push_back(cardn17);
        std::shared_ptr<Dijkstra> cardn18(new Dijkstra);
        cards_down.push_back(cardn18);
        std::shared_ptr<Talar> cardn19(new Talar);
        cards_down.push_back(cardn19);
        std::shared_ptr<Trebusz> cardn20(new Trebusz);
        cards_down.push_back(cardn20);
        std::shared_ptr<Roche> cardn21(new Roche);
        cards_down.push_back(cardn21);
        std::shared_ptr<Ves> cardn22(new Ves);
        cards_down.push_back(cardn22);
        std::shared_ptr<Wiezaobleznicza> cardn23(new Wiezaobleznicza);
        cards_down.push_back(cardn23);
        std::shared_ptr<Yarpen> cardn24(new Yarpen);
        cards_down.push_back(cardn24);
        std::shared_ptr<ZygfrydzDenesle> cardn25(new ZygfrydzDenesle);
        cards_down.push_back(cardn25);
    }
    else if(deck_down=="Nilfgaard")
    {
        std::shared_ptr<Albrich> cardn1(new Albrich);
        cards_down.push_back(cardn1);
        std::shared_ptr<Assire> cardn2(new Assire);
        cards_down.push_back(cardn2);
        std::shared_ptr<NilfgaardzkiLucznik> cardn3(new NilfgaardzkiLucznik);
        cards_down.push_back(cardn3);
        std::shared_ptr<Cahir> cardn4(new Cahir);
        cards_down.push_back(cardn4);
        std::shared_ptr<Cynthia> cardn5(new Cynthia);
        cards_down.push_back(cardn5);
        std::shared_ptr<WsparcieLucznikow> cardn6(new WsparcieLucznikow);
        cards_down.push_back(cardn6);
        std::shared_ptr<Fringilla> cardn7(new Fringilla);
        cards_down.push_back(cardn7);
        std::shared_ptr<Scorpion> cardn8(new Scorpion);
        cards_down.push_back(cardn8);
        std::shared_ptr<BrygadaImpera> cardn9(new BrygadaImpera(board));
        cards_down.push_back(cardn9);
        std::shared_ptr<Letho> cardn10(new Letho);
        cards_down.push_back(cardn10);
        std::shared_ptr<Menno> cardn11(new Menno);
        cards_down.push_back(cardn11);
        std::shared_ptr<Morteisen> cardn12(new Morteisen);
        cards_down.push_back(cardn12);
        std::shared_ptr<Morvran> cardn13(new Morvran);
        cards_down.push_back(cardn13);
        std::shared_ptr<Kawaleria> cardn14(new Kawaleria(board));
        cards_down.push_back(cardn14);
        std::shared_ptr<Puttkammer> cardn15(new Puttkammer);
        cards_down.push_back(cardn15);
        std::shared_ptr<Rainfarn> cardn16(new Rainfarn);
        cards_down.push_back(cardn16);
        std::shared_ptr<Renuald> cardn17(new Renuald);
        cards_down.push_back(cardn17);
        std::shared_ptr<Mangonela> cardn18(new Mangonela);
        cards_down.push_back(cardn18);
        std::shared_ptr<Shilard> cardn19(new Shilard);
        cards_down.push_back(cardn19);
        std::shared_ptr<Saper> cardn20(new Saper);
        cards_down.push_back(cardn20);
        std::shared_ptr<WsparcieObleznicze> cardn21(new WsparcieObleznicze);
        cards_down.push_back(cardn21);
        std::shared_ptr<Skellen> cardn22(new Skellen);
        cards_down.push_back(cardn22);
        std::shared_ptr<Sweers> cardn23(new Sweers);
        cards_down.push_back(cardn23);
        std::shared_ptr<Tibor> cardn24(new Tibor);
        cards_down.push_back(cardn24);
        std::shared_ptr<Vanhemar> cardn25(new Vanhemar);
        cards_down.push_back(cardn25);
        std::shared_ptr<Vattier> cardn245(new Vattier);
        cards_down.push_back(cardn245);
        std::shared_ptr<Vreemde> cardn2425(new Vreemde);
        cards_down.push_back(cardn2425);
        std::shared_ptr<Emisariusz> cardn22425(new Emisariusz(board));
        cards_down.push_back(cardn22425);
        std::shared_ptr<ZerrScorpion> cardn24225(new ZerrScorpion);
        cards_down.push_back(cardn24225);
    }

}

std::vector<std::shared_ptr<Card>> CardManager::RandomCards(int x, std::string side) {
    std::vector<std::shared_ptr<Card>> randomcards;
    int los;
    if(side=="Down")
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(0, cards_down.size()-1); // define the range
        for(int n=0; n<x; n++) {
            los=distr(gen);
            if(std::find(used_cards_down.begin(), used_cards_down.end(), cards_down[los] )==used_cards_down.end())
            {
                randomcards.push_back(cards_down[los]);
                used_cards_down.push_back(cards_down[los]);
            }
            else
            {
                randomcards.push_back(cards_down[los]->clone());
            }
        }
        return randomcards;
    }
    else
    {
        std::random_device rd; // obtain a random number from hardware
        std::mt19937 gen(rd()); // seed the generator
        std::uniform_int_distribution<> distr(0, cards_up.size()-1); // define the range
        for(int n=0; n<x; n++) {
            los=distr(gen);
            if(std::find(used_cards_up.begin(), used_cards_up.end(), cards_up[los] )==used_cards_up.end())
            {
                randomcards.push_back(cards_up[los]);
                used_cards_up.push_back(cards_down[los]);
            }
            else
            {
                randomcards.push_back(cards_up[los]->clone());
            }
        }

    }
    return randomcards;

}