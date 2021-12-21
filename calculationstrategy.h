#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QList>
#include <QPair>
#include <QString>
#include <QFileInfo>

class CalculationStrategy
{
public:
    CalculationStrategy() = default;

    virtual ~CalculationStrategy() = default;

    QList<QPair<QString, double>> calculate(const QString &path) const;

protected:
    QList<QFileInfo> listFiles(const QDir &dir) const;

    virtual void calculate(QList<QPair<QString, qint64>> &result, const QList<QFileInfo> &files) const = 0;
};

#endif // CALCULATIONSTRATEGY_H
