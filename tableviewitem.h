#ifndef TABLEVIEWITEM_H
#define TABLEVIEWITEM_H

#include "tableviewmodel.h"
#include "dataviewitem.h"
#include <QTableView>

class TableViewItem : public DataViewItem
{
public:
    TableViewItem(QWidget *parent = nullptr);

    void setData(const QList<QPair<QString, double>> &data) override;

    QWidget *getView() const override;

private:
    std::shared_ptr<QTableView> m_view;
    TableViewModel *m_model;
};

#endif // TABLEVIEWITEM_H
