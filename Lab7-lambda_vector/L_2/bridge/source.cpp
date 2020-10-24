#include <iostream>
#include "Deck.h"

Deck deck;

Pile*& getPilesFor13Cards(const int partsAmount) {
    Pile* piles = new Pile[partsAmount];
    for (int i = 0; i < partsAmount; i++) {
        Pile pile;
        for (int j = 0; j < Constants::CARDS_FOR_ONE_PLAYER; j++) {
            pile.addCard(deck.getCard());
        }
        piles[i] = pile;
    }

    return piles;
}

void displayPiles(const Pile* const & piles, const int partsAmount) {
    for (int i = 0; i < partsAmount; i++) {
        for (int j = 0; j < Constants::CARDS_FOR_ONE_PLAYER; j++) {
            Card card = piles[i].getCard(j);
            std::cout << card;
        }

        std::cout << std::endl;
        std::cout << "==========================================================" << std::endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    deck.Shuffle();

    constexpr int partsAmount = Constants::getPartsAmount();
    Pile* piles = getPilesFor13Cards(partsAmount);
    displayPiles(piles, partsAmount);

    delete[] piles;
}