#pragma once
#include <vector>
#include "Constants.h"
#include "Card.h"
#include <cassert>

class Pile {
public:
	Card getCard(const int index) {
		assert(index >= 0 && index < cards.size());
		return cards[index];
	}

	int getSize() {
		return cards.size();
	}

	void addCard(Card card) {
		cards.push_back(card);
	}

protected:
	std::vector<Card> cards;
};