#include "byfolder_calculationstrategy.h"
#include <QFileInfo>
#include <QDir>

void ByFolder_CalculationStrategy::calculate(QList<QPair<QString, qint64>> &result, const QList<QFileInfo> &files) const
{
    quint64 currentDir = 0;
    for (const auto &file : files) {
        if (file.isDir()) {
            QList<QPair<QString, qint64>> subdir;
            QDir dir(file.absoluteFilePath());
            calculate(subdir, listFiles(dir));
            qint64 sum = 0;
            for (const auto &p : subdir) {
                sum += p.second;
            }
            result += qMakePair(file.fileName(), sum);
        } else {
            currentDir += file.size();
        }
    }
    result.push_front(qMakePair(QString("."), currentDir));
}
