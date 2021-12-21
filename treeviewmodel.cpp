#include "treeviewmodel.h"

TreeViewModel::TreeViewModel(QObject *parent) : QFileSystemModel(parent)
{
}

int TreeViewModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant TreeViewModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal && section == 0)
        return QVariant(QString("Dir name"));
    return QFileSystemModel::headerData(section, orientation, role);
}
