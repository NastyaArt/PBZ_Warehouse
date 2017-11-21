#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QList<QToolBar *> toolbars = this->findChildren<QToolBar *>();
    for (int i = 0; i < toolbars.length(); i++)
        toolbars.at(i)->hide();

    invEdit = new InventoryEdit;
    stockEdit = new StockEdit;
    purchEdit = new PurchaseInvoiceEdit;
    salesEdit = new SalesInvoiceEdit;

    groupEdit = new QGroupBox("Добавить/Удалить/Изменить:");
    groupQuery  = new QGroupBox("Выполнить запрос");
    groupAll  = new QGroupBox;

    butInventory = new QPushButton("Рабочий инвентарь");
    butStock = new QPushButton("Склад");
    butPurchase = new QPushButton("Приходная накладная");
    butSales = new QPushButton("Расходная накладная");

    butStocksView = new QPushButton("Просмотреть все склады предприятия");
    butNumInvView = new QPushButton("Просмотреть количество заданного инвентаря на заданном складе");
    butPurchSalesView = new QPushButton("Просмотреть приходы и расходы инвентаря на всех складах предприятия");
    butStockRecCardView = new QPushButton("Просмотреть карточки складского учета");

    QVBoxLayout *layButEdit = new QVBoxLayout;
    layButEdit->addWidget(butInventory);
    layButEdit->addWidget(butStock);
    layButEdit->addWidget(butPurchase);
    layButEdit->addWidget(butSales);
    layButEdit->setAlignment(Qt::AlignTop);

    groupEdit->setFixedSize(200, 150);
    groupEdit->setLayout(layButEdit);

    QVBoxLayout *layButQuery = new QVBoxLayout;
    layButQuery->addWidget(butStocksView);
    layButQuery->addWidget(butNumInvView);
    layButQuery->addWidget(butPurchSalesView);
    layButQuery->addWidget(butStockRecCardView);
    layButQuery->setAlignment(Qt::AlignTop);

    groupQuery->setFixedSize(500, 150);
    groupQuery->setLayout(layButQuery);

    QHBoxLayout *layAll = new QHBoxLayout;
    layAll->addWidget(groupEdit);
    layAll->addWidget(groupQuery);
    layAll->setAlignment(Qt::AlignTop);

    groupAll->setLayout(layAll);
    setCentralWidget(groupAll);

    stocksView = new AllStocksView();
    numInvView = new NumOfInventoryView();
    purchSalesView = new PurchAndSalesView();
    stockRecCardView = new StockRecordCardView();


    connect (butInventory, SIGNAL(clicked()), invEdit, SLOT(show()));
    connect (butStock, SIGNAL(clicked()), stockEdit, SLOT(show()));
    connect (butPurchase, SIGNAL(clicked()), purchEdit, SLOT(show()));
    connect (butSales, SIGNAL(clicked()), salesEdit, SLOT(show()));

    connect (butStocksView, SIGNAL(clicked()), stocksView, SLOT(show()));
    connect (butNumInvView, SIGNAL(clicked()), numInvView, SLOT(show()));
    connect (butPurchSalesView, SIGNAL(clicked()), purchSalesView, SLOT(show()));
    connect (butStockRecCardView, SIGNAL(clicked()), stockRecCardView, SLOT(show()));

}

void MainWindow::ConnectionError()
{
    QMessageBox::warning(this, "Подключение к базе данных", "Ошибка подключения!", QMessageBox::Ok);
    setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


