#include "OptionMC.h"
#include "Option.h"
#include "StatisticsMC.h"
#include "ConvergenceTable.h"
#include <iostream>
#include <chrono>

int main()
{
    auto start = std::chrono::steady_clock::now();

    PayOffCall callPayOff(200.0);
    Option callOption(callPayOff, 2.0);

    ParametersConstant vol(0.2);
    ParametersConstant rate(0.02);

    StatisticsMean gatherer{};
    ConvergenceTable gatherer2{ gatherer, 2 };

    OptionMonteCarlo(callOption, 100.0, vol, rate, 1000000, gatherer2);

    std::vector<std::vector<double>> Results = gatherer2.GetResultsSoFar();

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}
