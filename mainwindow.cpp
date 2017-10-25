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

    group = new QGroupBox("Добавить/Удалить/Изменить:");

    butInventory = new QPushButton("Рабочий инвентарь");
    butStock = new QPushButton("Склад");
    butPurchaseInv = new QPushButton("Приходная накладная");
    butSalesInv = new QPushButton("Расходная накладная");

    QVBoxLayout *layBut = new QVBoxLayout;
    layBut->addWidget(butInventory);
    layBut->addWidget(butStock);
    layBut->addWidget(butPurchaseInv);
    layBut->addWidget(butSalesInv);

    layBut->setAlignment(Qt::AlignTop);

    group->setFixedSize(200, 150);

    group->setLayout(layBut);

    setCentralWidget(group);

    connect (butInventory, SIGNAL(clicked()), invEdit, SLOT(show()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
