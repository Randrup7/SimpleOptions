#ifndef PAYOFFBRIDGE_H
#define PAYOFFBRIDGE_H

#include "Payoff.h"

class PayOffBridge
{
private:
    IPayOff* m_payoffPtr;
public:
    PayOffBridge(const PayOffBridge& other);
    PayOffBridge(const IPayOff& otherPayOff);

    PayOffBridge& operator=(const PayOffBridge& other);

    double operator()(double spot) const;
    
    ~PayOffBridge();
};

#endif