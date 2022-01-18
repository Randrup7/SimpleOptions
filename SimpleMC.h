#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include "Payoff.h"

double SimpleMonteCarlo(const IPayOff& payoff,
                        double expiry,
                        double spot,
                        double vol,
                        double r,
                        unsigned long trials);

#endif
