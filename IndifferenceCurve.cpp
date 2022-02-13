#include "IndifferenceCurve.h"

void IndifferenceCurve::valuesSums(std::vector<float>& out, const Good& good, const unsigned int maxGoods)
{
    out.push_back(good.valueForIndex(0));
    for (int i = 1; i < maxGoods; i++) {
        out.push_back(out.back() + good.valueForIndex(i));
    }
}

void IndifferenceCurve::calculatePoints(const std::vector<float>& valuesSumsGood1, const std::vector<float>& valuesSumsGood2)
{
    float staticValue = 0.f;
    if (valuesSumsGood1.back() > valuesSumsGood2.back()) {
        staticValue = valuesSumsGood2.back();
    }
    else {
        staticValue = valuesSumsGood1.back();
    }

    for (int i = 0; i < valuesSumsGood1.size() - 1; i++) {
        for (int j = 0; j < valuesSumsGood2.size() - 1; j++) {
            if (staticValue > valuesSumsGood1[i] + valuesSumsGood2[j] - epsilon && staticValue < valuesSumsGood1[i] + valuesSumsGood2[j] + epsilon) {
                points.push_back(std::make_pair(i, j));
            }
        }
    }
}

void IndifferenceCurve::calculate()
{
    std::vector<float> compilersValuesSums;
    std::vector<float> linkersValuesSums;

    valuesSums(compilersValuesSums, good1, maxGoods1);
    valuesSums(linkersValuesSums, good2, maxGoods2);

    calculatePoints(compilersValuesSums, linkersValuesSums);
}

std::ostream& operator<<(std::ostream& os, const IndifferenceCurve& c)
{
    os << "Budget Line maxGoods1;0 (x;y)" << std::endl 
        << c.maxGoods1 << ";0" << std::endl
        << "Budget Line 0;maxGoods2 (x;y)" << std::endl
        << "0;" << c.maxGoods2 << std::endl;
    os << "Indifference Curve Good1;Good2 (x;y)" << std::endl;
    for (auto& el : c.points) {
        os << el.first << ";" << el.second << std::endl;
    }
    return os;
}
