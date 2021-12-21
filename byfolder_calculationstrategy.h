#ifndef BYFOLDER_CALCULATIONSTRATEGY_H
#define BYFOLDER_CALCULATIONSTRATEGY_H

#include "calculationstrategy.h"

class ByFolder_CalculationStrategy : public CalculationStrategy
{
public:
    ByFolder_CalculationStrategy() = default;

protected:
    void calculate(QList<QPair<QString, qint64>> &result, const QList<QFileInfo> &files) const override;
};

#endif // BYFOLDER_CALCULATIONSTRATEGY_H
