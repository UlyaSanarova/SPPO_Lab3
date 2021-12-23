#include "piediagramitem.h"

PieDiagramItem::PieDiagramItem(QWidget *parent) : DiagramItem(parent)
{
}

//void PieDiagramItem::setupChart(QChart *chart, const QList<QPair<QString, double>> &data)
QAbstractSeries *PieDiagramItem::newSeries(const QList<QPair<QString, double>> &data) const
{
    auto series = new QPieSeries();
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
    return series;
}
