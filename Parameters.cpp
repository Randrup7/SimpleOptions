#include "Parameters.h"

// To define for Parameters (bridge)
Parameters::Parameters(const Parameters& other)
{
    m_innerPtr = other.m_innerPtr->clone();
}

Parameters::Parameters(const IParametersInner& otherInner)
{
    m_innerPtr = otherInner.clone();
}

Parameters& Parameters::operator=(const Parameters& otherInner)
{
    if (this != &otherInner)
    {
        delete m_innerPtr;
        m_innerPtr = otherInner.m_innerPtr->clone();
    }
    
    return *this;
}
    
Parameters::~Parameters()
{
    delete m_innerPtr;
    m_innerPtr = nullptr;
}

double Parameters::Integral(double time1, double time2) const
{
    return m_innerPtr->Integral(time1, time2);
}

double Parameters::IntegralSquare(double time1, double time2) const
{
    return m_innerPtr->IntegralSquare(time1, time2);
}

double Parameters::Mean(double time1, double time2) const
{
    return Integral(time1, time2) / (time1 - time2);
}

double Parameters::RMSE(double time1, double time2) const
{
    return IntegralSquare(time1, time2) / (time1 - time2);
}

// To define for ParametersConstant
ParametersConstant::ParametersConstant(double constant)
    : m_Constant{ constant }, m_ConstantSquare{ constant * constant } {}
    
IParametersInner* ParametersConstant::clone() const
{
    return new ParametersConstant(*this);
}

double ParametersConstant::Integral(double time1, double time2) const
{
    return (time2 - time1) * m_Constant;
}

double ParametersConstant::IntegralSquare(double time1, double time2) const
{
    return (time2 - time1) * m_ConstantSquare;
}