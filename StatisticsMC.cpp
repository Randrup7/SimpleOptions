#include "StatisticsMC.h"

StatisticsMean::StatisticsMean()
    : m_PathsDone{0}, m_RunningSum{0.0} {}

StatisticsMC* StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}

void StatisticsMean::DumpOneResult(double result)
{
    m_PathsDone++;
    m_RunningSum += result;
}

std::vector<std::vector<double>> StatisticsMean::GetResultsSoFar() const
{
    std::vector<std::vector<double>> Results(1);

    Results[0].resize(1);
    Results[0][0] = m_RunningSum / m_PathsDone;

    return Results;
}