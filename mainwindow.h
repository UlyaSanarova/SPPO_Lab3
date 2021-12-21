#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include <memory>
#include "calculationstrategy.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected);

    void on_calculationStrategyByFolder(bool checked);
    void on_calculationStrategyByFileType(bool checked);

private:
    QFileSystemModel *fileModel;
    QFileSystemModel *dirModel;
    QTreeView *treeView;
    QTableView *tableView;
    std::shared_ptr<CalculationStrategy> calculationStrategy;
};

#endif // MAINWINDOW_H
