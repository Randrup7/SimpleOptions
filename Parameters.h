#ifndef PARAMETERS_H
#define PARAMETERS_H

/*  This file declares the contents in all paramenter classes.
    IParameterInner is the base class for MC parameters class.
    Parameter will be the bridge class for the derived classes of IParameterInner.
        To handle the construction, copying and destruction to avoid writing the same code more times.
    
    The parameter classes will set the 'settings' for the MC simulation to allow for variability.
*/

// The abstract base class, parameters.
class IParametersInner
{
public:
    IParametersInner(){}

    virtual IParametersInner* clone() const = 0;                            // Pure virtual
    virtual double Integral(double time1, double time2) const = 0;          // Pure virtual
    virtual double IntegralSquare(double time1, double time2) const = 0;    // Pure virtual

    virtual ~IParametersInner(){}
};

// The bridge class for parameters to handle construction, copying and destruction.
class Parameters
{
private:
    IParametersInner* m_innerPtr;
public:
    Parameters(const Parameters& other);
    Parameters(const IParametersInner& otherInner);
    Parameters& operator=(const Parameters& otherInner);
    
    virtual ~Parameters();

    double Integral(double time1, double time2) const;
    double IntegralSquare(double time1, double time2) const;
    double Mean(double time1, double time2) const;
    double RMSE(double time1, double time2) const;
};

// Class for 
class ParametersConstant : public IParametersInner
{
private:
    double m_Constant;
    double m_ConstantSquare;
public:
    ParametersConstant(double constant);
    
    virtual IParametersInner* clone() const;
    virtual double Integral(double time1, double time2) const;
    virtual double IntegralSquare(double time1, double time2) const;
};

#endif