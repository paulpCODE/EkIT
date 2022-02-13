#pragma once
#include <iostream>
#include <vector>
#include <map>

class DemandCurve
{
	std::vector<std::pair<unsigned int, unsigned int>> pricesAndDemand;
	std::map<unsigned int, unsigned int> pricesAndCounters;

	void calculatePricesAndCounters(const std::vector<unsigned int>& maxPrices);
	void calculateDemand();

	DemandCurve(const DemandCurve&) = delete;
	const DemandCurve& operator = (const DemandCurve&) = delete;
public:
	DemandCurve(const std::vector<unsigned int>& maxPrices);

	friend std::ostream& operator << (std::ostream& os, const DemandCurve& dc);
};