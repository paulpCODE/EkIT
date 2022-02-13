#include <iostream>
#include "IndifferenceCurve.h"
#include "DemandCurve.h"

int main()
{
    Good compiler(250, 50.f, 0.2f);
    Good ide(350, 70.f, 0.4f);

    DemandCurve c(ide.price() + 200, ide.price() - 200, ide.price(), 0.005, 2, 5);
    std::cout << c;
    Files::writeToOutputTxt(c);
}
