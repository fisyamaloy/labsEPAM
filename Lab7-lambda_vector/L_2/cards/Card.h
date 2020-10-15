#pragma once
#include "Constants.h"
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

	int getIndex() {
		return suit * Constants::RANK_COUNT + rank;
	}

	int getSuit() {
		return suit;
	}

	int getRank() {
		return rank;
	}

	friend std::ostream& operator<<(std::ostream& os, const Card& card);

private:
	int suit;
	int rank;
};

std::ostream& operator<<(std::ostream& os, const Card& card) {
	auto getCaptureCardSuit = [](Card card) {
		switch (card.getSuit()) {
		case Suits::CHIRVA:
			return "�����";
		case Suits::CROSS:
			return "������";
		case Suits::PIKA:
			return "����";
		case Suits::TAMBOURINE:
			return "�����";
		}
	};

	std::string suit = getCaptureCardSuit(card);

	auto getCaptureCardRank = [](Card card) -> std::string {
		switch (card.getRank()) {
		case Ranks::ACE:
			return "���";
		case Ranks::KING:
			return "������";
		case Ranks::QUEEN:
			return "����";
		case Ranks::JACKET:
			return "�����";
		default:
			return std::to_string(card.getRank() + 1);
		}
	};

	std::string rank = getCaptureCardRank(card);

	os << rank << " " << suit << ", ";
	return os;
}

