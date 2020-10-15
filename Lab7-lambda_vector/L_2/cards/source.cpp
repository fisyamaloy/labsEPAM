#include <iostream>
#include "Deck.h"

int main() {
    setlocale(LC_ALL, "ru");

    Deck deck;
    deck.Shuffle();
    Pile* piles;
    Pile pile;
    int partsAmount = Constants::PACK_COUNT * Constants::RANK_COUNT * Constants::SUIT_COUNT / Constants::CARDS_FOR_ONE_PLAYER;

    piles = new Pile[partsAmount];
    for (int i = 0; i < partsAmount; i++) {
        Pile pile;
        for (int j = 0; j < Constants::CARDS_FOR_ONE_PLAYER; j++) {
            pile.addCard(deck.getCard());
        }
        piles[i] = pile;
    }

    for (int i = 0; i < partsAmount; i++) {
        for (int j = 0; j < Constants::CARDS_FOR_ONE_PLAYER; j++) {
            Card card = piles[i].getCard(j);
            std::cout << card;
        }

        std::cout << std::endl;
        std::cout << "==========================================================" << std::endl;
    }
    
    delete[] piles;
}