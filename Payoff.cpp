#include "Payoff.h"

//////// Define PayOffCall functions ////////

// Defining the payoff constructor to simply assign member variables
PayOffCall::PayOffCall(double strike)
    : m_strike{ strike } 
{
}

// Define the overloaded operator() to return the payoff (double) by input of spot price
double PayOffCall::operator()(double spot) const
{
    return (spot > m_strike ? (spot - m_strike) : 0.0);
}

// Copy function to return a IPayOff* to a PayOffCall object identical to the object being called
IPayOff* PayOffCall::clone() const
{
    return new PayOffCall(*this);
}


//////// Define PayOffPut functions ////////

// Defining the payoff constructor to simply assign member variables
PayOffPut::PayOffPut(double strike)
    : m_strike{ strike } {}


double PayOffPut::operator()(double spot) const
{
    return (spot < m_strike ? (m_strike - spot) : 0.0);
}

// Copy function to return a IPayOff* to a PayOffPut object identical to the object being called
IPayOff* PayOffPut::clone() const
{
    return new PayOffPut(*this);
}