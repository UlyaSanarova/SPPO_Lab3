#include "tableviewmodel.h"

TableViewModel::TableViewModel(QObject *parent) : QAbstractTableModel(parent)
{
}

int TableViewModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

int TableViewModel::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

QVariant TableViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
            case 0:
                return QVariant(QString("File name"));

            case 1:
                return QVariant(QString("Size (in %)"));
            }
        } else {
            return QVariant(QString::number(section + 1));
        }
    }
    return QVariant();
}

QVariant TableViewModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && index.row() < m_data.size() && index.column() < 2 && role == Qt::DisplayRole) {
        auto p = m_data[index.row()];
        switch (index.column()) {
        case 0:
            return QVariant(p.first);

        case 1:
            if (p.second < 0.01)
                return QVariant(QString("< 0.01"));
            return QVariant(QString::number(p.second, 'f', 2));
        }
    }
    return QVariant();
}

void TableViewModel::setStrategy(const std::shared_ptr<CalculationStrategy> &strategy)
{
    m_calculationStrategy = strategy;
    reload();
}

std::shared_ptr<CalculationStrategy> TableViewModel::getStrategy() const
{
    return m_calculationStrategy;
}

void TableViewModel::setPath(const QString &path)
{
    if (m_path != path) {
        m_path = path;
        reload();
    }
}

QString TableViewModel::getPath() const
{
    return m_path;
}

void TableViewModel::reload()
{
    if (m_calculationStrategy) {
        beginResetModel();
        m_data = m_calculationStrategy->calculate(m_path);
        endResetModel();
    }
}
