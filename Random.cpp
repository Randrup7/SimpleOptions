#include "Random.h"
#include <cstdlib>
#include <cmath>

IRandom::IRandom(unsigned long Dimensionality)
    : m_Dimensionality{ Dimensionality } {}

void IRandom::GetGaussians(std::array& variates)
{
    GetUniforms(variates);

    for (unsigned long i = 0; i < m_Dimensionality; i++)
    {
        // variates[i] = some inverse cummulative normal distribution function
    }
    
}

void IRandom::ResetDimensionality(unsigned long newDimensionality)
{
    m_Dimensionality = newDimensionality;
}


Random_MT::Random_MT(unsigned long Demensionality, unsigned long Seed = 1)
{

}

IRandom* Random_MT::clone() const
{

}

void Random_MT::GetUniforms(std::array& variates)
{
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_real_distribution<> dis(0,1.0);
}

void Random_MT::Skip(unsigned long numberOfPaths)
{

}

void Random_MT::SetSeed(unsigned long Seed)
{

}

void Random_MT::Reset()
{

}






double GetOneGaussianBySummation()
{
    double result=0;
    for (unsigned long j=0; j < 12; j++)
    {
        result += rand()/static_cast<double>(RAND_MAX);
        result -= 6.0;
    }
    return result;
}


double GetOneGaussianByBoxMuller()
{
    double result;
    double x;
    double y;
    double sizeSquared;
    do
    {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        sizeSquared = x * x + y * y;
    }
    while
        (sizeSquared >= 1.0);

    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);
    
    return result;
}