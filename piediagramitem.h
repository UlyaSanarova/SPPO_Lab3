#ifndef PIEDIAGRAMITEM_H
#define PIEDIAGRAMITEM_H

#include "tableviewmodel.h"
#include "dataviewitem.h"
#include <QtCharts/QPieSlice>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

using namespace QtCharts;

class PieDiagramItem : public DataViewItem
{
public:
    PieDiagramItem(QWidget *parent = nullptr);

    void setData(const QList<QPair<QString, double>> &data) override;

    QWidget *getView() const override;

private:
    std::shared_ptr<QChartView> m_view;
};

#endif // PIEDIAGRAMITEM_H
