#include "bardiagramitem.h"

BarDiagramItem::BarDiagramItem(QWidget *parent)
{
    m_view = std::make_shared<QChartView>(parent);
}

void BarDiagramItem::setData(const QList<QPair<QString, double>> &data)
{
    auto chart = new QChart();
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->show();
    auto series = new QBarSeries(chart);
    for (const auto &p : data) {
        if (p.second == 0)
            continue;
        QString s;
        if (p.second < 0.01) {
            s = QString("< 0.01");
        } else {
            s = QString::number(p.second, 'f', 2);
        }
        auto set = new QBarSet(p.first + ": " + s + "%", series);
        set->append(p.second);
        series->append(set);
    }
    chart->addSeries(series);

    auto y = new QValueAxis();
    y->setRange(0, 100);
    chart->addAxis(y, Qt::AlignLeft);
    series->attachAxis(y);

    m_view->setChart(chart);
}

QWidget *BarDiagramItem::getView() const
{
    return m_view.get();
}
