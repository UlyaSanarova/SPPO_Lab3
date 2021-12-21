#ifndef DATAVIEW_H
#define DATAVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include "dataviewitem.h"
#include "calculationstrategy.h"

class DataView : public QWidget
{
public:
    DataView(QWidget *parent = nullptr);

    ~DataView();

    enum Type
    {
        TypeNone,
        TypeTable,
        TypeBar,
        TypePie
    };

    void setType(Type type);

    Type getType() const;

    void setStrategy(const std::shared_ptr<CalculationStrategy> &strategy);

    std::shared_ptr<CalculationStrategy> getStrategy() const;

    void setPath(const QString &path);

    QString getPath() const;

    void reload();

private:
    void setItem(const std::shared_ptr<DataViewItem> &item);

    QVBoxLayout *m_layout;
    Type m_type;
    std::shared_ptr<DataViewItem> m_item;

    std::shared_ptr<CalculationStrategy> m_strategy;
    QString m_path;
    QList<QPair<QString, double>> m_data;
};

#endif // DATAVIEW_H
