#include "DemandCurve.h"

void DemandCurve::calculate()
{
	float demandCoefficient = 0.f;
	float x = m_demandCoefficientDelta;
	for (int y = m_maxParam - 1; y > m_minParam; y -= m_epsilon) {
		demandCoefficient = (m_maxParam - y) * m_demandCoefficientDelta;
		x = x + demandCoefficient;
		points.push_back(Point(x, y));
	}
}

DemandCurve::DemandCurve(int maxParam, int minParam, float demandCoefficientDelta, int epsilon) :
	m_maxParam(maxParam), m_minParam(minParam),
	m_demandCoefficientDelta(demandCoefficientDelta),
	m_epsilon(epsilon) {
	calculate();
}

std::ostream& operator << (std::ostream& os, const DemandCurve& dc) {
	os << "DemandCurve from: " << dc.m_maxParam << " to: " << dc.m_minParam << std::endl;
	os << "Delta: " << dc.m_demandCoefficientDelta << " Epsilon: " << dc.m_epsilon << std::endl;
	os << "CURVE x;y" << std::endl;
	for (auto& el : dc.points) {
		os << el << std::endl;
	}
	return os;
}
