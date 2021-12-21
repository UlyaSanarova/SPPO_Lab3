#include "dataview.h"
#include <QTableView>
#include "tableviewitem.h"
#include "bardiagramitem.h"
#include "piediagramitem.h"

DataView::DataView(QWidget *parent) : QWidget(parent), m_type(TypeNone)
{
    m_layout = new QVBoxLayout(this);
    setLayout(m_layout);
}

DataView::~DataView()
{
    setType(TypeNone);
}

void DataView::setType(Type type)
{
    if (m_type != type) {
        m_type = type;
        setItem(nullptr);
        switch (m_type) {
        case TypeTable:
            setItem(std::make_shared<TableViewItem>(this));
            break;
        case TypeBar:
            setItem(std::make_shared<BarDiagramItem>(this));
            break;
        case TypePie:
            setItem(std::make_shared<PieDiagramItem>(this));
            break;
        }
    }
}

DataView::Type DataView::getType() const
{
    return m_type;
}

void DataView::setStrategy(const std::shared_ptr<CalculationStrategy> &strategy)
{
    if (m_strategy != strategy) {
        m_strategy = strategy;
        reload();
    }
}

std::shared_ptr<CalculationStrategy> DataView::getStrategy() const
{
    return m_strategy;
}

void DataView::setPath(const QString &path)
{
    if (m_path != path) {
        m_path = path;
        reload();
    }
}

QString DataView::getPath() const
{
    return m_path;
}

void DataView::reload()
{
    if (m_strategy) {
        m_data = m_strategy->calculate(m_path);
    }
    if (m_item) {
        m_item->setData(m_data);
    }
}

void DataView::setItem(const std::shared_ptr<DataViewItem> &item)
{
    if (m_item) {
        m_layout->removeWidget(m_item->getView());
        m_item.reset();
    }
    if (item) {
        m_item = item;
        m_layout->addWidget(m_item->getView());
        m_item->setData(m_data);
    }
}
