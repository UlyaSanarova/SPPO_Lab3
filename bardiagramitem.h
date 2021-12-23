#ifndef BARDIAGRAMITEM_H
#define BARDIAGRAMITEM_H

#include "diagramitem.h"
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

using namespace QtCharts;

class BarDiagramItem : public DiagramItem
{
public:
    BarDiagramItem(QWidget *parent = nullptr);

protected:
    //void setupChart(QChart *chart, const QList<QPair<QString, double>> &data) override;

    QAbstractSeries *newSeries(const QList<QPair<QString, double>> &data) const override;

    void setupAxis(QAbstractSeries *series) override;

private:
    QValueAxis *m_axis;
};

#endif // BARDIAGRAMITEM_H
