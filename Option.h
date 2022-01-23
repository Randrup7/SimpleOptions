#ifndef OPTION_H
#define OPTION_H

#include "PayOffBridge.h"

class Option
{
private:
    PayOffBridge m_payoff;
    double m_expiry;
public:
    Option(const PayOffBridge& payoff, double expiry);

    const double GetExpiry() const;
    const double OptionPayoff(double spot) const;
};

#endif