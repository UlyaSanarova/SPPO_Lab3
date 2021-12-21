#include "mainwindow.h"
#include <QSplitter>
#include <QListView>
#include <QTreeView>
#include <QTextEdit>
#include <QFileSystemModel>
#include <QItemSelectionModel>
#include <QVBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setGeometry(100, 100, 800, 600);
    setStatusBar(new QStatusBar(this));
    statusBar()->showMessage("Choosen Path: ");

    auto homePath = QDir::homePath();

    dirModel = new QFileSystemModel(this);
    dirModel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dirModel->setRootPath(homePath);

    fileModel = new QFileSystemModel(this);
    fileModel->setFilter(QDir::NoDotAndDotDot | QDir::Files);
    fileModel->setRootPath(homePath);

    treeView = new QTreeView();
    treeView->setModel(dirModel);
    treeView->expandAll();
    auto selectionModel = treeView->selectionModel();
    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &MainWindow::on_selectionChangedSlot);

    tableView = new QTableView();
    tableView->setModel(fileModel);

    auto splitter = new QSplitter(parent);
    splitter->addWidget(treeView);
    splitter->addWidget(tableView);
    setCentralWidget(splitter);

    QItemSelection toggleSelection;
    auto homeIndex = dirModel->index(homePath);
    toggleSelection.select(homeIndex, homeIndex);
    selectionModel->select(toggleSelection, QItemSelectionModel::Toggle);
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_selectionChangedSlot(const QItemSelection &selected, const QItemSelection &deselected)
{
    auto indexes = selected.indexes();
    if (indexes.isEmpty())
        return;

    auto path = dirModel->filePath(indexes.first());
    statusBar()->showMessage("Choosen Path: " + path);
    tableView->setRootIndex(fileModel->setRootPath(path));
}
