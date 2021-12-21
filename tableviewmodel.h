#ifndef TABLEVIEWMODEL_H
#define TABLEVIEWMODEL_H

#include <QAbstractTableModel>
#include "calculationstrategy.h"

class TableViewModel : public QAbstractTableModel
{
public:
    TableViewModel(QObject *parent = nullptr);

    int columnCount(const QModelIndex &parent) const override;

    int rowCount(const QModelIndex &parent) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    QVariant data(const QModelIndex &index, int role) const override;

    void setStrategy(const std::shared_ptr<CalculationStrategy> &strategy);

    std::shared_ptr<CalculationStrategy> getStrategy() const;

    void setPath(const QString &path);

    QString getPath() const;

    void reload();

private:
    std::shared_ptr<CalculationStrategy> m_calculationStrategy;
    QString m_path;
    QList<QPair<QString, double>> m_data;
};

#endif // TABLEVIEWMODEL_H
