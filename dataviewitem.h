#ifndef DATAVIEWITEM_H
#define DATAVIEWITEM_H

#include <QWidget>
#include <QList>
#include <QPair>
#include <QString>

class DataViewItem {
public:
    virtual ~DataViewItem() = default;

    virtual void setData(const QList<QPair<QString, double>> &data) = 0;

    virtual QWidget *getView() const = 0;
};

#endif // DATAVIEWITEM_H
