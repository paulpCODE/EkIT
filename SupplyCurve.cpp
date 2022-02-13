#include "SupplyCurve.h"

void SupplyCurve::calculatePricesAndCounters(const std::vector<unsigned int>& minPrices)
{
	for (auto minPrice : minPrices) {
		if (pricesAndCounters.find(minPrice) == pricesAndCounters.end()) {
			pricesAndCounters.insert(std::make_pair(minPrice, 1));
		}
		else {
			pricesAndCounters.at(minPrice)++;
		}
	}
}

void SupplyCurve::calculateSupply()
{
	unsigned int supply = 0;
	for (auto it = pricesAndCounters.begin(); it != pricesAndCounters.end(); it++) {
		supply += it->second;
		pricesAndSupply.push_back(std::make_pair(it->first, supply));
	}
}

SupplyCurve::SupplyCurve(const std::vector<unsigned int>& minPrices)
{
	calculatePricesAndCounters(minPrices);
	calculateSupply();
}

std::ostream& operator << (std::ostream& os, const SupplyCurve& dc) {
	os << "Price:" << std::endl;
	for (auto& el : dc.pricesAndSupply) {
		os << el.first << std::endl;
	}
	os << "Supply:" << std::endl;
	for (auto& el : dc.pricesAndSupply) {
		os << el.second << std::endl;
	}
	return os;
}
