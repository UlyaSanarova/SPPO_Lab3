#include "byfiletype_calculationstrategy.h"
#include <QDir>

QString getFileExtension(const QString &fileName)
{
    auto index = fileName.lastIndexOf('.');
    if (index < 0)
        return QString();
    return fileName.right(fileName.length() - index);
}

void ByFileType_CalculationStrategy::calculate(QList<QPair<QString, qint64>> &result, const QList<QFileInfo> &files) const
{
    std::map<QString, qint64> types;
    calculate(types, files);
    for (const auto &p : types) {
        result += qMakePair(p.first, p.second);
    }
}

void ByFileType_CalculationStrategy::calculate(std::map<QString, qint64> &result, const QList<QFileInfo> &files) const
{
    for (const auto &file : files) {
        if (file.isDir()) {
            QDir dir(file.absoluteFilePath());
            calculate(result, listFiles(dir));
        } else {
            result[getFileExtension(file.fileName())] += file.size();
        }
    }
}
