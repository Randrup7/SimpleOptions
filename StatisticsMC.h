#ifndef STATISTICSMC_H
#define STATISTICSMC_H

#include <vector>

class IStatisticsMC
{
public:
    IStatisticsMC() {}
    virtual IStatisticsMC* clone() const = 0;

    virtual void DumpOneResult(double result) = 0;
    virtual std::vector<std::vector<double>> GetResultsSoFar() const = 0;
    
    virtual ~IStatisticsMC(){}
};


class StatisticsMean : public IStatisticsMC
{
private:
    double m_RunningSum;
    unsigned long m_PathsDone;
public:
    StatisticsMean();
    IStatisticsMC* clone() const override;

    void DumpOneResult(double result) override;
    std::vector<std::vector<double>> GetResultsSoFar() const override;
    
};


#endif