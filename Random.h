#ifndef RANDOM_H
#define RANDOM_H

#include <array>

class IRandom
{
private:
    unsigned long m_Dimensionality;
public:
    IRandom(unsigned long Dimensionality);

    const unsigned long GetDimensionality() const { return m_Dimensionality; }
    virtual IRandom* clone() const = 0;
    virtual void GetUniforms(std::array& variates) = 0;
    virtual void Skip(unsigned long numberOfPaths) = 0;
    virtual void SetSeed(unsigned long Seed) = 0;
    virtual void Reset() = 0;

    virtual void GetGaussians(std::array& variates);
    virtual void ResetDimensionality(unsigned long newDimensionality);

    virtual ~IRandom();
};

class Random_MT : public IRandom
{
private:
    unsigned long m_InitialSeed;
    double m_Reciprocal;
public:
    Random_MT(unsigned long Demensionality, unsigned long Seed = 1);

    IRandom* clone() const override;
    void GetUniforms(std::array& variates) override;
    void Skip(unsigned long numberOfPaths) override;
    void SetSeed(unsigned long Seed) override;
    void Reset() override;

    

    ~Random_MT();
};


double GetOneGaussianBySummation();
double GetOneGaussianByBoxMuller();

#endif