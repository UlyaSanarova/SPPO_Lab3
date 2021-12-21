#ifndef TREEVIEWMODEL_H
#define TREEVIEWMODEL_H

#include <QFileSystemModel>

class TreeViewModel : public QFileSystemModel
{
public:
    TreeViewModel(QObject *parent = nullptr);

    int columnCount(const QModelIndex &parent) const override;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // TREEVIEWMODEL_H
