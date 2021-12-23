#include "bardiagramitem.h"

BarDiagramItem::BarDiagramItem(QWidget *parent) : DiagramItem(parent)
{
    m_axis = new QValueAxis();
    m_axis->setRange(0, 100);
}

//void BarDiagramItem::setupChart(QChart *chart, const QList<QPair<QString, double>> &data)
QAbstractSeries *BarDiagramItem::newSeries(const QList<QPair<QString, double>> &data) const
{
    auto series = new QBarSeries();
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
    return series;
}

void BarDiagramItem::setupAxis(QAbstractSeries *series)
{
    m_chart->removeAxis(m_axis);
    m_chart->addAxis(m_axis, Qt::AlignLeft);
    series->attachAxis(m_axis);
}
