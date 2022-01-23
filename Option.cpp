#include "Option.h"

// Constructor of the vanilla option. List member initialisation of inputs as PayOffBridge handles construction.
Option::Option(const PayOffBridge& payoff, double expiry) 
    : m_payoff{ payoff } , m_expiry{ expiry } 
{    
}

// Get function that returns the expiry.
const double Option::GetExpiry() const { return m_expiry; }

// Get function that returns the option payoff using the pointer to the payoff class.
const double Option::OptionPayoff(double spot) const { return m_payoff(spot); }
