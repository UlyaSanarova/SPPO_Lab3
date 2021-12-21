#include "piediagramitem.h"

PieDiagramItem::PieDiagramItem(QWidget *parent)
{
    m_view = std::make_shared<QChartView>(parent);
}

void PieDiagramItem::setData(const QList<QPair<QString, double>> &data)
{
    auto chart = new QChart();
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->legend()->show();
    auto series = new QPieSeries(chart);
    for (const auto &p : data) {
        if (p.second == 0)
            continue;
        QString s;
        if (p.second < 0.01) {
            s = QString("< 0.01");
        } else {
            s = QString::number(p.second, 'f', 2);
        }
        auto slice = series->append(p.first + ": " + s + "%", p.second);
        slice->setLabelVisible();
    }
    series->setPieSize(0.75);
    chart->addSeries(series);

    m_view->setChart(chart);
}

QWidget *PieDiagramItem::getView() const
{
    return m_view.get();
}
