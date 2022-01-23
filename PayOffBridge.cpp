#include "PayOffBridge.h"

PayOffBridge::PayOffBridge(const PayOffBridge& other)
{
    m_payoffPtr = other.m_payoffPtr->clone();
}


PayOffBridge::PayOffBridge(const IPayOff& otherPayOff)
{
    m_payoffPtr = otherPayOff.clone();
}

PayOffBridge& PayOffBridge::operator=(const PayOffBridge& other)
{
    if (this != &other)
    {
        delete m_payoffPtr;
        m_payoffPtr = other.m_payoffPtr->clone();
    }
    
    return *this;
}

double PayOffBridge::operator()(double spot) const
{
    return m_payoffPtr->operator()(spot);
}

PayOffBridge::~PayOffBridge()
{
    delete m_payoffPtr;
}