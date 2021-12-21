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
    dirModel->setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::Hidden | QDir::System | QDir::NoSymLinks);
    dirModel->setRootPath(homePath);

    treeView = new QTreeView();
    treeView->setModel(dirModel);
    treeView->expandAll();
    auto selectionModel = treeView->selectionModel();
    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &MainWindow::on_selectionChangedSlot);

    dataView = new DataView();
    dataView->setPath(homePath);

    auto splitter = new QSplitter(parent);
    splitter->addWidget(treeView);
    splitter->addWidget(dataView);
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

    menu = new QMenu(QString("View type"), menuBar());
    auto viewTypeActions = new QActionGroup(menu);
    auto viewTypeAction = viewTypeActions->addAction("Table");
    viewTypeAction->setCheckable(true);
    viewTypeAction->setChecked(true);
    connect(viewTypeAction, &QAction::toggled, this, &MainWindow::on_viewTypeTable);
    viewTypeAction = viewTypeActions->addAction("Bar diagram");
    viewTypeAction->setCheckable(true);
    connect(viewTypeAction, &QAction::toggled, this, &MainWindow::on_viewTypeBar);
    viewTypeAction = viewTypeActions->addAction("Pie diagram");
    viewTypeAction->setCheckable(true);
    connect(viewTypeAction, &QAction::toggled, this, &MainWindow::on_viewTypePie);
    menu->addActions(viewTypeActions->actions());
    menuBar()->addMenu(menu);

    QItemSelection toggleSelection;
    auto homeIndex = dirModel->index(homePath);
    toggleSelection.select(homeIndex, homeIndex);
    selectionModel->select(toggleSelection, QItemSelectionModel::Toggle);

    on_calculationStrategyByFolder(true);
    on_viewTypeTable(true);
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
    dataView->setPath(path);
}

void MainWindow::on_calculationStrategyByFolder(bool checked)
{
    if (checked) {
        dataView->setStrategy(std::make_shared<ByFolder_CalculationStrategy>());
    }
}

void MainWindow::on_calculationStrategyByFileType(bool checked)
{
    if (checked) {
        dataView->setStrategy(std::make_shared<ByFileType_CalculationStrategy>());
    }
}

void MainWindow::on_viewTypeTable(bool checked)
{
    if (checked) {
        dataView->setType(DataView::TypeTable);
    }
}

void MainWindow::on_viewTypeBar(bool checked)
{
    if (checked) {
        dataView->setType(DataView::TypeBar);
    }
}

void MainWindow::on_viewTypePie(bool checked)
{
    if (checked) {
        dataView->setType(DataView::TypePie);
    }
}
