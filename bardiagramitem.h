#ifndef BARDIAGRAMITEM_H
#define BARDIAGRAMITEM_H

#include "tableviewmodel.h"
#include "dataviewitem.h"
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

using namespace QtCharts;

class BarDiagramItem : public DataViewItem
{
public:
    BarDiagramItem(QWidget *parent = nullptr);

    void setData(const QList<QPair<QString, double>> &data) override;

    QWidget *getView() const override;

private:
    std::shared_ptr<QChartView> m_view;
};

#endif // BARDIAGRAMITEM_H
