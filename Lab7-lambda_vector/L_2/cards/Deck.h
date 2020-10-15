#pragma once
#include "Constants.h"
#include "Card.h"
#include "Pile.h"
#include <ctime>

class Deck : Pile {
public:
    Deck() {
        for (int i = 0; i < Constants::PACK_COUNT; i++) {
            for (int j = 0; j < Constants::SUIT_COUNT; j++) {
                for (int k = 0; k < Constants::RANK_COUNT; k++) {
                    Card card(j, k);
                    addCard(card);
                }
            }
        }
    }

    void Shuffle() {
        srand(time(0));
        for (int i = 0; i < cards.size(); i++) {
            Card card = cards[i];
            int n = rand() % cards.size();
            cards[i] = cards[n];
            cards[n] = card;
        }
    }

    Card getCard() {
        Card card;
        if (cards.size() > 0) {
            card = cards[cards.size() - 1];
            cards.erase(cards.begin() + cards.size() - 1);
        }
        return card;
    }
};