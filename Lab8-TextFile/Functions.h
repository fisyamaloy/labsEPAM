#pragma once

#include "Data.h"
#include <vector>

void dataLoad(std::vector<Data>& people, const std::string fileName);
void dataInput(std::vector<Data>& people, const std::string fileName);
void dataAppend(std::vector<Data>& people, const std::string fileName);
void dataSortByLastName(std::vector<Data>& people);
void dataSortByAge(std::vector<Data>& people);

void outputPeopleWhoWasBornInGivenMonth(std::vector<Data>& people, int givenMonth);
void outputTheMostOlderMan(std::vector<Data>& people);
void outputAllLastsNamesWhichStartWithGivenLetter(std::vector<Data>& people, char firstLetterOfLastsNames);
