#include "OptionMC.h"
#include "Random.h"
#include <cmath>

double OptionMonteCarlo(const Option& option,
                        double spot,
                        const Parameters& vol,
                        const Parameters& r,
                        unsigned long trials)
{
    double expiry{ option.GetExpiry() };
    double variance{ vol.IntegralSquare(0.0, expiry) };
    double sqrtVariance{ sqrt(variance) };
    double itoCorrection{ -0.5 * variance };

    double movedSpot{ spot * exp(r.Integral(0.0, expiry) + itoCorrection) };
    double finalSpot;
    double payoffSum{ 0 };
    
    for (unsigned int i = 0; i < trials; i++)
    {
        double gauss{ GetOneGaussianByBoxMuller() };
        finalSpot = movedSpot * exp(sqrtVariance * gauss);
        double payoff_i{ option.OptionPayoff(finalSpot) };
        payoffSum += payoff_i;
    }
    
    return exp(-r.Integral(0.0, expiry)) * (payoffSum / trials);
}