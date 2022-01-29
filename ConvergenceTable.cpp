#include "ConvergenceTable.h"

ConvergenceTable::ConvergenceTable(const Wrapper<IStatisticsMC>& Inner, unsigned long StoppingPoint = 2)
    : m_Inner{ Inner }, m_StoppingPoint{ StoppingPoint } {}

IStatisticsMC* ConvergenceTable::clone() const
{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::DumpOneResult(double result)
{
    m_Inner->DumpOneResult(result);
    m_PathsDone++;

    if (m_PathsDone == m_StoppingPoint)
    {
        m_StoppingPoint *= 2;

        std::vector<std::vector<double>> Result(m_Inner->GetResultsSoFar());

        for (unsigned long i = 0; i < Result.size(); i++)
        {
            Result[i].push_back(m_PathsDone);
            m_ResultsSoFar.push_back(Result[i]);
        }
    }
}

std::vector<std::vector<double>> ConvergenceTable::GetResultsSoFar() const
{
    std::vector<std::vector<double>> tmp(m_ResultsSoFar);

    if (m_PathsDone * 2 != m_StoppingPoint)
    {
        std::vector<std::vector<double>> Result(m_Inner->GetResultsSoFar());

        for (unsigned long i = 0; i < Result.size(); i++)
        {
            Result[i].push_back(m_PathsDone);
            tmp.push_back(Result[i]);
        }
    }
    return tmp;
}