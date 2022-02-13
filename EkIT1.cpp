#include <iostream>
#include <random>
#include "DemandCurve.h"
#include "SupplyCurve.h"
#include "File.h"


void getRandomIntInRange(int rangeFrom, int rangeTo, unsigned int amountOfNumbers, std::vector<unsigned int>& outVector)
{
    if (rangeFrom > rangeTo) {
        return;
    }

    std::random_device random_device;
    std::mt19937 random_engine(random_device());
    std::uniform_int_distribution<int> distribution(rangeFrom, rangeTo);

    for (size_t i = 0; i < amountOfNumbers; ++i)
    {
        outVector.push_back(unsigned int(distribution(random_engine)));
    }
}


int main()
{
    std::vector<unsigned int> pricesForDemand;
    std::vector<unsigned int> pricesForSupply;

    getRandomIntInRange(50, 70, 26, pricesForDemand);
    getRandomIntInRange(70, 100, 10, pricesForDemand);
    getRandomIntInRange(100, 125, 4, pricesForDemand);

    getRandomIntInRange(50, 70, 2, pricesForSupply);
    getRandomIntInRange(70, 100, 13, pricesForSupply);
    getRandomIntInRange(100, 125, 25, pricesForSupply);
    

    DemandCurve dc(pricesForDemand);
    SupplyCurve sc(pricesForSupply);

    std::cout << dc;
    Files::oFile("tempfiles\\demandCurve.txt") << dc;
    std::cout << sc;
    Files::oFile("tempfiles\\supplyCurve.txt") << sc;
}
