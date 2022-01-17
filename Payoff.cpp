#include "Payoff.h"

// Defining the payoff constructor to simply assign member variables
Payoff::Payoff(double strike, OptionType type)
    : m_strike{ strike }, m_type{ type } {}

// Define the overloaded operator() to return the payoff (double) by input of spot price
double Payoff::operator()(double spot)
{
    switch (m_type)
    {
    case call:
        return (spot > m_strike ? (spot - m_strike) : 0.0);
    
    case put:
        return (spot < m_strike ? (m_strike - spot) : 0.0);
    
    default:
        throw ("Unknown option type");
    }
}