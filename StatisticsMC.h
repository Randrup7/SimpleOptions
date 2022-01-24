#ifndef STATISTICSMC_H
#define STATISTICSMC_H

#include <vector>

class StatisticsMC
{
public:
    StatisticsMC() {}
    virtual StatisticsMC* clone() const = 0;

    virtual void DumpOneResult(double result) = 0;
    virtual std::vector<std::vector<double>> GetResultsSoFar() const = 0;
    
    virtual ~StatisticsMC(){}
};


class StatisticsMean : public StatisticsMC
{
private:
    double m_RunningSum;
    unsigned long m_PathsDone;
public:
    StatisticsMean();
    StatisticsMC* clone() const override;

    void DumpOneResult(double result) override;
    std::vector<std::vector<double>> GetResultsSoFar() const override;
    
};


#endif