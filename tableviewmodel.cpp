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

void TableViewModel::setData(const QList<QPair<QString, double>> &data)
{
    beginResetModel();
    m_data = data;
    endResetModel();
}
