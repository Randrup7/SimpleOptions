#include "SimpleMC.h"
#include "Payoff.h"
#include <iostream>

int main()
{
    const PayOffCall callPayOff(200.0);
    double price = SimpleMonteCarlo(callPayOff, 2.0, 100.0, 0.2, 0.02, 1000000);

    std::cout << price << "\n";

    return 0;
}