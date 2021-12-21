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
#include <QMenu>
#include <QMenuBar>
#include <QDebug>
#include "treeviewmodel.h"
#include "byfolder_calculationstrategy.h"
#include "byfiletype_calculationstrategy.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setGeometry(100, 100, 800, 600);
    setStatusBar(new QStatusBar(this));
    statusBar()->showMessage("Choosen Path: ");

    auto homePath = QDir::homePath();

    dirModel = new TreeViewModel(this);
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

    auto menu = new QMenu(QString("Calculation strategy"), menuBar());
    auto calculationStrategyActions = new QActionGroup(menu);
    auto calculationStrategyAction = calculationStrategyActions->addAction("By folder");
    calculationStrategyAction->setCheckable(true);
    calculationStrategyAction->setChecked(true);
    connect(calculationStrategyAction, &QAction::toggled, this, &MainWindow::on_calculationStrategyByFolder);
    calculationStrategyAction = calculationStrategyActions->addAction("By file type");
    calculationStrategyAction->setCheckable(true);
    connect(calculationStrategyAction, &QAction::toggled, this, &MainWindow::on_calculationStrategyByFileType);
    menu->addActions(calculationStrategyActions->actions());
    menuBar()->addMenu(menu);

    QItemSelection toggleSelection;
    auto homeIndex = dirModel->index(homePath);
    toggleSelection.select(homeIndex, homeIndex);
    selectionModel->select(toggleSelection, QItemSelectionModel::Toggle);

    on_calculationStrategyByFolder(true);
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

void MainWindow::on_calculationStrategyByFolder(bool checked)
{
    if (checked) {
        calculationStrategy.reset(new ByFolder_CalculationStrategy);
        qDebug() << "MainWindow::on_calculationStrategyByFolder";
    }
}

void MainWindow::on_calculationStrategyByFileType(bool checked)
{
    if (checked) {
        calculationStrategy.reset(new ByFileType_CalculationStrategy);
        qDebug() << "MainWindow::on_calculationStrategyByFileType";
    }
}
