#pragma once
#include <iostream>
#include <vector>
#include "Taxi.h"
#include <cassert>
#include <algorithm>

namespace TF {
	void showAllTaxies(const std::vector<Taxi>& taxies) {
		for (auto& taxi : taxies) {
			std::cout << taxi << std::endl;
		}
		std::cout << "All taxies was displayed";
	}
	void pushTaxiToStart(std::vector<Taxi>& taxies, Taxi&& newTaxi) {
		taxies.insert(taxies.cbegin(), newTaxi);
	}
	void deleteTaxi(std::vector<Taxi>& taxies, const int position) {
		assert(position >= 0 && position < taxies.size());
		taxies.erase(taxies.cbegin() + position);
	}
	void insertTaxi(std::vector<Taxi>& taxies, Taxi&& newTaxi, const int position) {
		assert(position >= 0 && position < taxies.size());
		taxies.insert(taxies.cbegin() + position, newTaxi);
	}
	void callTaxi(std::vector<Taxi>& taxies, const int number) {
		assert(number >= 0 && number < taxies.size());
		auto it = std::find_if(taxies.begin(), taxies.end(), [number](Taxi& taxi) {
			return taxi.getNumber() == number;
		});
		(*it).enableBusy();
	}
	void releaseTaxi(std::vector<Taxi>& taxies, const int number) {
		assert(number >= 0 && number < taxies.size());
		auto it = std::find_if(taxies.begin(), taxies.end(), [number](Taxi& taxi) {
			return taxi.getNumber() == number;
		});
		(*it).disableBusy();
	}
	void showAllFreeTaxies(const std::vector<Taxi>& taxies) {
		std::cout << "ALL FREE TAXIES: " << std::endl;
		for (const Taxi& taxi : taxies) {
			if (!taxi.getBusy()) {
				std::cout << taxi << std::endl;
			}
		}
	}
	void showAllBusyTaxies(const std::vector<Taxi>& taxies) {
		std::cout << "ALL BUSY TAXIES: " << std::endl;
		for (const Taxi& taxi : taxies) {
			if (taxi.getBusy()) {
				std::cout << taxi << std::endl;
			}
		}
	}
}