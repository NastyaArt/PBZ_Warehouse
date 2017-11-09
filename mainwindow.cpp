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

    group = new QGroupBox("Добавить/Удалить/Изменить:");

    butInventory = new QPushButton("Рабочий инвентарь");
    butStock = new QPushButton("Склад");
    butPurchase = new QPushButton("Приходная накладная");
    butSales = new QPushButton("Расходная накладная");

    QVBoxLayout *layBut = new QVBoxLayout;
    layBut->addWidget(butInventory);
    layBut->addWidget(butStock);
    layBut->addWidget(butPurchase);
    layBut->addWidget(butSales);

    layBut->setAlignment(Qt::AlignTop);

    group->setFixedSize(200, 150);

    group->setLayout(layBut);

    setCentralWidget(group);

    connect (butInventory, SIGNAL(clicked()), invEdit, SLOT(show()));
    connect (butStock, SIGNAL(clicked()), stockEdit, SLOT(show()));
    connect (butPurchase, SIGNAL(clicked()), purchEdit, SLOT(show()));
    connect (butSales, SIGNAL(clicked()), salesEdit, SLOT(show()));

   // SetConnectionWithDatabase();
}

void MainWindow::SetConnectionWithDatabase()
{

 /*   QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL3");
    db.setHostName("127.0.0.1");
    db.setPort(3311);
    db.setDatabaseName("stocks");
    db.setUserName("root");
    db.setPassword("root");
    bool ok = db.open();
    QMessageBox::information(this, "Подключение", QString::number(ok), QMessageBox::Ok);
    */
}


MainWindow::~MainWindow()
{
    delete ui;
}


