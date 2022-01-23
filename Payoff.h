#ifndef PAYOFF_H
#define PAYOFF_H

// Defining interface Payoff class with virtual overloaded operator() and destructor
class IPayOff
{
public:
    IPayOff(){};
    
    virtual double operator()(double spot) const = 0;   // pure virtual
    virtual IPayOff* clone() const = 0;                 // pure virtual


    virtual ~IPayOff(){}
};


// Define a derived payoff class for call options
class PayOffCall : public IPayOff
{
private:
    double m_strike;
public:
    PayOffCall(double strike);
    
    virtual double operator()(double spot) const;
    virtual IPayOff* clone() const;

    virtual ~PayOffCall(){}
};


// Define a derived payoff class for put options
class PayOffPut : public IPayOff
{
private:
    double m_strike;
public:
    PayOffPut(double strike);

    virtual double operator()(double spot) const;
    virtual IPayOff* clone() const;

    virtual ~PayOffPut(){};
};

#endif