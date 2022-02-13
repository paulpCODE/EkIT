#include "DemandCurve.h"

void DemandCurve::calculatePricesAndCounters(const std::vector<unsigned int>& maxPrices)
{
	for (auto maxPrice : maxPrices) {
		if (pricesAndCounters.find(maxPrice) == pricesAndCounters.end()) {
			pricesAndCounters.insert(std::make_pair(maxPrice, 1));
		}
		else {
			pricesAndCounters.at(maxPrice)++;
		}
	}
}

void DemandCurve::calculateDemand()
{
	unsigned int demand = 0;
	for (auto it = --pricesAndCounters.end(); it != --pricesAndCounters.begin(); it--) {
		demand += it->second;
		pricesAndDemand.push_back(std::make_pair(it->first, demand));
	}
}

DemandCurve::DemandCurve(const std::vector<unsigned int>& maxPrices) {
	calculatePricesAndCounters(maxPrices);
	calculateDemand();
}

std::ostream& operator << (std::ostream& os, const DemandCurve& dc) {
	os << "Price:" << std::endl;
	for (auto& el : dc.pricesAndDemand) {
		os << el.first << std::endl;
	}
	os << "Demand:" << std::endl;
	for (auto& el : dc.pricesAndDemand) {
		os << el.second << std::endl;
	}
	return os;
}
