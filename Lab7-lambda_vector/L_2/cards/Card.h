#pragma once
#include "Suits.h"
#include "Ranks.h"
#include <string>

class Card {
public:
	Card() {
	
	}

	Card(int index) {
		suit = index / Constants::RANK_COUNT;
		rank = index % Constants::RANK_COUNT;
	}

	Card(int suit, int rank) {
		this->suit = suit;
		this->rank = rank;
	}

	constexpr int getSuit() {
		return suit;
	}

	constexpr int getRank() {
		return rank;
	}

	friend std::ostream& operator<<(std::ostream& os, const Card& const card);

private:
	int suit;
	int rank;
};

std::ostream& operator<<(std::ostream& os, const Card& const card) {
	auto getCaptureCardSuit = [](Card card) {
		switch (card.getSuit()) {
		case Suits::CHIRVA:
			return "Чирва";
		case Suits::CROSS:
			return "Крестя";
		case Suits::PIKA:
			return "Пика";
		case Suits::TAMBOURINE:
			return "Бубна";
		default:
			return "Unknown";
		}
	};

	std::string suit = getCaptureCardSuit(card);

	auto getCaptureCardRank = [](Card card) -> std::string {
		switch (card.getRank()) {
		case Ranks::ACE:
			return "Туз";
		case Ranks::KING:
			return "Король";
		case Ranks::QUEEN:
			return "Дама";
		case Ranks::JACKET:
			return "Валет";
		default:
			return std::to_string(card.getRank() + 1);
		}
	};

	std::string rank = getCaptureCardRank(card);

	os << rank << " " << suit << ", ";
	return os;
}


