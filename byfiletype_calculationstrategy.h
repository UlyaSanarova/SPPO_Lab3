#ifndef BYFILETYPE_CALCULATIONSTRATEGY_H
#define BYFILETYPE_CALCULATIONSTRATEGY_H

#include "calculationstrategy.h"
#include <map>

class ByFileType_CalculationStrategy : public CalculationStrategy
{
public:
    ByFileType_CalculationStrategy() = default;

protected:
    void calculate(QList<QPair<QString, qint64>> &result, const QList<QFileInfo> &files) const override;

    void calculate(std::map<QString, qint64> &result, const QList<QFileInfo> &files) const;
};

#endif // BYFILETYPE_CALCULATIONSTRATEGY_H
