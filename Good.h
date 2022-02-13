#pragma once

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

inline float Good::valueForIndex(unsigned int index) const
{
    float value = m_value - index * m_deltaValue;
    return value < 0 ? 0 : value;
}

inline unsigned int Good::price() const
{
    return m_price;
}