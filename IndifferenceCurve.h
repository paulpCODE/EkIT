#pragma once

#include "Point.h"
#include "File.h"
#include "Good.h"
#include <vector>

class IndifferenceCurve
{
	std::vector<Point> points;

	const Good good1;
	const Good good2;
	const unsigned int budget;
	const float epsilon;
	
	const unsigned int maxGoods1;
	const unsigned int maxGoods2;

	IndifferenceCurve(const IndifferenceCurve&) = delete;
	const IndifferenceCurve& operator = (const IndifferenceCurve&) = delete;

	void valuesSums(std::vector<float>& out, const Good& good, const unsigned int maxGoods);
	void calculatePoints(const std::vector<float>& valuesSumsGood1, const std::vector<float>& valuesSumsGood2);
	void calculate();

public:
	IndifferenceCurve(unsigned int budget, Good& good1, Good& good2, float epsilon) :
		budget(budget), good1(good1), good2(good2), epsilon(epsilon), 
		maxGoods1(budget / good1.price()), maxGoods2(budget / good2.price()) {
		calculate();
	}

	std::vector<Point>& getPoints();
	friend std::ostream& operator << (std::ostream& os, const IndifferenceCurve& c);
};


inline std::vector<Point>& IndifferenceCurve::getPoints() {
	return points;
}
