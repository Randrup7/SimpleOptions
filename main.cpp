#include "SimpleMC.h"
#include <iostream>

int main()
{
    Payoff pay(200, Payoff::put);
    double answ = SimpleMonteCarlo(pay, 2.0, 100.0, 0.2, 0.02, 1000000);

    std::cout << answ << "\n";
}