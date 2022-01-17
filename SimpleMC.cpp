#include "SimpleMC.h"
#include <cmath>

double SimpleMonteCarlo(const Payoff& payoff,
                        double expiry,
                        double spot,
                        double vol,
                        double r,
                        unsigned long trials)
{
    double variance{ vol * vol * expiry };
    double sqrtVariance{ sqrt(variance) };
    double itoCorrection{ -0.5 * variance };

    double movedSpot{ spot * exp(r * expiry + itoCorrection) };
    double finalSpot;
    double payoffSum{ 0 };
    
    for (unsigned int i = 0; i < trials; i++)
    {
        double gauss{ 1.0 };
        finalSpot = movedSpot * exp(sqrtVariance * gauss);
        double payoff_i{ payoff(finalSpot) };
        payoffSum += payoff_i;
    }
    
    return exp(-r * expiry) * (payoffSum / trials);
}