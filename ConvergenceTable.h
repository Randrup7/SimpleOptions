#ifndef CONVERGENCETABLE_H
#define CONVERGENCETABLE_H

#include "StatisticsMC.h"
#include "Wrapper.h"

class ConvergenceTable : public IStatisticsMC
{
private:
    Wrapper<IStatisticsMC> m_Inner;
    std::vector<std::vector<double>> m_ResultsSoFar;
    unsigned long m_StoppingPoint;
    unsigned long m_PathsDone{ 0 };
public:
    ConvergenceTable(const Wrapper<IStatisticsMC>& Inner, unsigned long StoppingPoint);

    IStatisticsMC* clone() const override;
    void DumpOneResult(double result) override;
    std::vector<std::vector<double>> GetResultsSoFar() const override;
};

#endif