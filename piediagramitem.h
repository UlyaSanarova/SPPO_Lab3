#ifndef PIEDIAGRAMITEM_H
#define PIEDIAGRAMITEM_H

#include "diagramitem.h"
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>

using namespace QtCharts;

class PieDiagramItem : public DiagramItem
{
public:
    PieDiagramItem(QWidget *parent = nullptr);

protected:
    //void setupChart(QChart *chart, const QList<QPair<QString, double>> &data) override;

    QAbstractSeries *newSeries(const QList<QPair<QString, double>> &data) const override;
};

#endif // PIEDIAGRAMITEM_H
