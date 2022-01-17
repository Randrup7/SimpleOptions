#ifndef PAYOFF_H
#define PAYOFF_H

// Defining the Payoff class with forward declared constructor and member function.
class Payoff
{
public:
    enum OptionType
    {
        call,
        put
    };

    Payoff(double strike, OptionType type);
    double operator()(double spot) const;

private:
    double m_strike;
    OptionType m_type;
};

#endif 