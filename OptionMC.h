#ifndef OPTIONMC_H
#define OPTIONMC_H

#include "Option.h"
#include "Parameters.h"
#include "StatisticsMC.h"

void OptionMonteCarlo(const Option& option,
                        double spot,
                        const Parameters& vol,
                        const Parameters& r,
                        unsigned long trials,
                        IStatisticsMC& gatherer);

#endif
