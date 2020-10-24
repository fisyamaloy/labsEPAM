#pragma once
#include <vector>
#include <cassert>

class Pile {
public:

	Card getCard(const int index) const {
		assert(index >= 0 && index < cards.size());
		return cards[index];
	}

	int getSize() const {
		return cards.size();
	}

	void addCard(Card card) {
		cards.push_back(card);
	}

protected:
	std::vector<Card> cards;
};