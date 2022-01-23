#ifndef OPTIONMC_H
#define OPTIONMC_H

#include "Option.h"
#include "Parameters.h"

double OptionMonteCarlo(const Option& option,
                        double spot,
                        const Parameters& vol,
                        const Parameters& r,
                        unsigned long trials);

#endif
