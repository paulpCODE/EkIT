#pragma once
#include <vector>
#include "Point.h"

class DemandCurve
{
	std::vector<Point> points;
	const int m_maxParam;
	const int m_minParam;
	const int m_epsilon;
	const float m_demandCoefficientDelta;


	void calculate();
public:
	DemandCurve(int maxParam, int minParam, float demandCoefficientDelta = 0.1f, int epsilon = 1);

	friend std::ostream& operator << (std::ostream& os, const DemandCurve& dc);
};