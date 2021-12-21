#include "tableviewitem.h"

TableViewItem::TableViewItem(QWidget *parent)
{
    m_view = std::make_shared<QTableView>(parent);
    m_model = new TableViewModel(parent);
    m_view->setModel(m_model);
}

void TableViewItem::setData(const QList<QPair<QString, double>> &data)
{
    m_model->setData(data);
}

QWidget *TableViewItem::getView() const
{
    return m_view.get();
}
