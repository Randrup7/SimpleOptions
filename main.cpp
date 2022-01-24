#include "OptionMC.h"
#include "Option.h"
#include "StatisticsMC.h"
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

    OptionMonteCarlo(callOption, 100.0, vol, rate, 1000000, gatherer);

    std::vector<std::vector<double>> Results = gatherer.GetResultsSoFar();

    for (unsigned long i = 0; i < Results.size(); i++)
    {
        for (unsigned long j = 0; j < Results.size(); j++)
        {
            std::cout << Results[i][j] << " ";
        }
        std::cout << "\n";
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

    return 0;
}
