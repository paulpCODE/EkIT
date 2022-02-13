#include <iostream>
#include "IndifferenceCurve.h"
#include "DemandCurve.h"
#include "File.h"

int main()
{
    std::vector<unsigned int> maxPrices = { 10, 20, 12, 32, 24, 34, 23, 23, 24, 43, 23, 43, 23, 31, 35, 34, 12, 54, 45, 34, 23, 34 };

    DemandCurve c(maxPrices);
    std::cout << c;
    Files::writeToOutputTxt(c);
}
