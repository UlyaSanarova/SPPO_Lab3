#include "diagramitem.h"

DiagramItem::DiagramItem(QWidget *parent)
{
    m_view = std::make_shared<QChartView>(parent);
    m_chart = new QChart();
    m_view->setChart(m_chart);
}

void DiagramItem::setData(const QList<QPair<QString, double>> &data)
{
    setupLegend(m_chart->legend());
    m_chart->removeAllSeries();
    //setupChart(m_chart, data);
    auto series = newSeries(data);
    m_chart->addSeries(series);
    setupAxis(series);
}

QWidget *DiagramItem::getView() const
{
    return m_view.get();
}

void DiagramItem::setupLegend(QLegend *legend)
{
    legend->setAlignment(Qt::AlignRight);
    legend->show();
}

void DiagramItem::setupAxis(QAbstractSeries *series)
{
}
