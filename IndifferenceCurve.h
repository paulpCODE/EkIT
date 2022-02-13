#pragma once
#include <iostream>
#include <vector>

class IndifferenceCurve
{
public:
	class Good
	{
		const unsigned int m_price;
		const float m_value;
		const float m_deltaValue;

		const Good& operator = (const Good& g) = delete;
	public:
		Good(unsigned int price, float value, float deltaValue) : m_price(price), m_value(value), m_deltaValue(deltaValue) {}
		Good(const Good& g) : m_price(g.m_price), m_value(g.m_value), m_deltaValue(g.m_deltaValue) {}


		float valueForIndex(unsigned int index) const;
		unsigned int price() const;
	};

private:
	std::vector<std::pair<unsigned int, unsigned int>> points;

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

	std::vector<std::pair<unsigned int, unsigned int>>& getPoints();
	friend std::ostream& operator << (std::ostream& os, const IndifferenceCurve& c);
};

inline float IndifferenceCurve::Good::valueForIndex(unsigned int index) const
{
	float value = m_value - index * m_deltaValue;
	return value < 0 ? 0 : value;
}

inline unsigned int IndifferenceCurve::Good::price() const
{
	return m_price;
}

inline std::vector<std::pair<unsigned int, unsigned int>>& IndifferenceCurve::getPoints() {
	return points;
}


