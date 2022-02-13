#pragma once
#include <iostream>
#include <vector>
#include <map>
class SupplyCurve
{
	std::vector<std::pair<unsigned int, unsigned int>> pricesAndSupply;
	std::map<unsigned int, unsigned int> pricesAndCounters;

	void calculatePricesAndCounters(const std::vector<unsigned int>& minPrices);
	void calculateSupply();

	SupplyCurve(const SupplyCurve&) = delete;
	const SupplyCurve& operator = (const SupplyCurve&) = delete;
public:
	SupplyCurve(const std::vector<unsigned int>& minPrices);

	friend std::ostream& operator << (std::ostream& os, const SupplyCurve& dc);
};

