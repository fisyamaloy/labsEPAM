#pragma once

class Constants {
public:
    constexpr static int RANK_COUNT = 13; // количество карт одной масти
    constexpr static int SUIT_COUNT = 4;
    constexpr static int PACK_COUNT = 2;
    constexpr static int CARDS_FOR_ONE_PLAYER = 13;

    constexpr static int getPartsAmount() {
        return Constants::PACK_COUNT* Constants::RANK_COUNT* Constants::SUIT_COUNT / Constants::CARDS_FOR_ONE_PLAYER;
    }
};