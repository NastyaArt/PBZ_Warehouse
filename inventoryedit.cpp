#include "inventoryedit.h"

InventoryEdit::InventoryEdit(QWidget *parent) : QWidget(parent)
{

    setWindowTitle("Рабочий инвентарь");

    groupAdd = new QGroupBox("Добавление инвентаря");
    groupDel = new QGroupBox("Удаление инвентаря");
    groupEdit = new QGroupBox("Редактирование инвентаря");

    butAdd = new QPushButton("Добавить");
    butDel = new QPushButton("Удалить");
    butEdit = new QPushButton("Изменить");

    lblNameAdd = new QLabel("Наименование инвентаря");
    lblTipeAdd = new QLabel("Тип инвентаря");
    lblStockAdd = new QLabel("Номер склада");
    lblNameDel = new QLabel("Наименование инвентаря");
    lblNameEdit = new QLabel("Наименование инвентаря");
    lblTipeEdit = new QLabel("Тип инвентаря");
    lblStockEdit = new QLabel("Номер склада");

    lnNameAdd = new QLineEdit;
    lnTipeAdd = new QLineEdit;
    lnStockAdd = new QLineEdit;
    lnNameDel = new QLineEdit;
    lnNameEdit = new QLineEdit;
    lnTipeEdit = new QLineEdit;
    lnStockEdit = new QLineEdit;

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(lblNameAdd);
    lay1->addWidget(lnNameAdd);
    QHBoxLayout *lay2 = new QHBoxLayout;
    lay2->addWidget(lblTipeAdd);
    lay2->addWidget(lnTipeAdd);
    QHBoxLayout *lay3 = new QHBoxLayout;
    lay3->addWidget(lblStockAdd);
    lay3->addWidget(lnStockAdd);

    QVBoxLayout *layAdd = new QVBoxLayout;
    layAdd->addLayout(lay1);
    layAdd->addLayout(lay2);
    layAdd->addLayout(lay3);
    layAdd->addWidget(butAdd);

    groupAdd->setLayout(layAdd);

    QHBoxLayout *lay4 = new QHBoxLayout;
    lay4->addWidget(lblNameDel);
    lay4->addWidget(lnNameDel);

    QVBoxLayout *layDel = new QVBoxLayout;
    layDel->addLayout(lay4);
    layDel->addWidget(butDel);

    groupDel->setLayout(layDel);

    QHBoxLayout *lay5 = new QHBoxLayout;
    lay5->addWidget(lblNameEdit);
    lay5->addWidget(lnNameEdit);
    QHBoxLayout *lay6 = new QHBoxLayout;
    lay6->addWidget(lblTipeEdit);
    lay6->addWidget(lnTipeEdit);
    QHBoxLayout *lay7 = new QHBoxLayout;
    lay7->addWidget(lblStockEdit);
    lay7->addWidget(lnStockEdit);

    QVBoxLayout *layEdit = new QVBoxLayout;
    layEdit->addLayout(lay5);
    layEdit->addLayout(lay6);
    layEdit->addLayout(lay7);
    layEdit->addWidget(butEdit);

    groupEdit->setLayout(layEdit);

    QVBoxLayout *layAll = new QVBoxLayout;
    layAll->addWidget(groupAdd);
    layAll->addWidget(groupDel);
    layAll->addWidget(groupEdit);

    setLayout(layAll);
}

