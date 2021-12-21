#include "calculationstrategy.h"
#include <QDir>

QList<QPair<QString, double>> CalculationStrategy::calculate(const QString &path) const
{
    QList<QPair<QString, double>> result;
    QFileInfo info(path);
    if (!info.isDir())
        return result;
    QDir dir(info.absoluteFilePath());
    QList<QPair<QString, qint64>> sizeList;
    calculate(sizeList, listFiles(dir));
    if (sizeList.empty())
        return result;

    qint64 all = 0;
    for (const auto &p : sizeList) {
        result += qMakePair(p.first, double(p.second) * 100.0);
        all += p.second;
    }
    if (all != 0) {
        for (auto &p : result) {
            p.second /= double(all);
        }
    }

    return result;
}

QList<QFileInfo> CalculationStrategy::listFiles(const QDir &dir) const
{
    return dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks);
}
