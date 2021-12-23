#ifndef DIAGRAMITEM_H
#define DIAGRAMITEM_H

#include "dataviewitem.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLegend>

using namespace QtCharts;

class DiagramItem : public DataViewItem
{
public:
    DiagramItem(QWidget *parent = nullptr);

    void setData(const QList<QPair<QString, double>> &data) override;

    QWidget *getView() const override;

protected:
    virtual void setupLegend(QLegend *legend);

    //virtual void setupChart(QChart *chart, const QList<QPair<QString, double>> &data) = 0;

    virtual QAbstractSeries *newSeries(const QList<QPair<QString, double>> &data) const = 0;

    virtual void setupAxis(QAbstractSeries *series);

private:
    std::shared_ptr<QChartView> m_view;

protected:
    QChart *m_chart;
};

#endif // DIAGRAMITEM_H
