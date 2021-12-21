#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>
#include <QTableView>
#include <memory>
#include "dataview.h"

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

    void on_viewTypeTable(bool checked);
    void on_viewTypeBar(bool checked);

private:
    QFileSystemModel *dirModel;
    QTreeView *treeView;
    DataView *dataView;
};

#endif // MAINWINDOW_H
