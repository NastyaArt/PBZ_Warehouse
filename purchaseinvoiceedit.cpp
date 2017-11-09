#include "purchaseinvoiceedit.h"

PurchaseInvoiceEdit::PurchaseInvoiceEdit(QWidget *parent) : QWidget(parent)
{

    setWindowTitle("Приходная накладная");

    groupAdd = new QGroupBox("Добавление приходной");
    groupDel = new QGroupBox("Удаление приходной");
    groupEdit = new QGroupBox("Редактирование приходной(ключ - номер приходной)");

    butAdd = new QPushButton("Добавить");
    butDel = new QPushButton("Удалить");
    butEdit = new QPushButton("Изменить");

    lblNumberAdd = new QLabel("Номер приходной");
    lblDateAdd = new QLabel("Дата");
    lblStockNumbAdd = new QLabel("Код склада");
    lblCodeTMCAdd = new QLabel("Код инвентаря");
    lblSalNumbAdd = new QLabel("Количество инвентаря");
    lblFIOAdd = new QLabel("ФИО работника");
    lblPosAdd = new QLabel("Должность работника");

    lblNumberDel = new QLabel("Номер приходной");

    lblNumberEdit = new QLabel("Номер приходной");
    lblDateEdit = new QLabel("Дата");
    lblStockNumbEdit = new QLabel("Код склада");
    lblCodeTMCEdit = new QLabel("Код инвентаря");
    lblSalNumbEdit = new QLabel("Количество инвентаря");
    lblFIOEdit = new QLabel("ФИО работника");
    lblPosEdit = new QLabel("Должность работника");

    lnNumberAdd = new QLineEdit;
    lnDateAdd = new QLineEdit;
    lnStockNumbAdd = new QLineEdit;
    lnCodeTMCAdd = new QLineEdit;
    lnSalNumbAdd = new QLineEdit;
    lnFIOAdd = new QLineEdit;
    lnPosAdd = new QLineEdit;

    lnNumberDel = new QLineEdit;

    lnNumberEdit = new QLineEdit;
    lnDateEdit = new QLineEdit;
    lnStockNumbEdit = new QLineEdit;
    lnCodeTMCEdit = new QLineEdit;
    lnSalNumbEdit = new QLineEdit;
    lnFIOEdit = new QLineEdit;
    lnPosEdit = new QLineEdit;

    QHBoxLayout *lay11 = new QHBoxLayout;
    lay11->addWidget(lblNumberAdd);
    lay11->addWidget(lnNumberAdd);
    QHBoxLayout *lay12 = new QHBoxLayout;
    lay12->addWidget(lblDateAdd);
    lay12->addWidget(lnDateAdd);
    QHBoxLayout *lay13 = new QHBoxLayout;
    lay13->addWidget(lblStockNumbAdd);
    lay13->addWidget(lnStockNumbAdd);
    QHBoxLayout *lay14 = new QHBoxLayout;
    lay14->addWidget(lblCodeTMCAdd);
    lay14->addWidget(lnCodeTMCAdd);
    QHBoxLayout *lay15 = new QHBoxLayout;
    lay15->addWidget(lblSalNumbAdd);
    lay15->addWidget(lnSalNumbAdd);
    QHBoxLayout *lay16 = new QHBoxLayout;
    lay16->addWidget(lblFIOAdd);
    lay16->addWidget(lnFIOAdd);
    QHBoxLayout *lay17 = new QHBoxLayout;
    lay17->addWidget(lblPosAdd);
    lay17->addWidget(lnPosAdd);

    QVBoxLayout *layAdd = new QVBoxLayout;
    layAdd->addLayout(lay11);
    layAdd->addLayout(lay12);
    layAdd->addLayout(lay13);
    layAdd->addLayout(lay14);
    layAdd->addLayout(lay15);
    layAdd->addLayout(lay16);
    layAdd->addLayout(lay17);
    layAdd->addWidget(butAdd);

    groupAdd->setLayout(layAdd);

    QHBoxLayout *lay21 = new QHBoxLayout;
    lay21->addWidget(lblNumberDel);
    lay21->addWidget(lnNumberDel);

    QVBoxLayout *layDel = new QVBoxLayout;
    layDel->addLayout(lay21);
    layDel->addWidget(butDel);

    groupDel->setLayout(layDel);

    QHBoxLayout *lay31 = new QHBoxLayout;
    lay31->addWidget(lblNumberEdit);
    lay31->addWidget(lnNumberEdit);
    QHBoxLayout *lay32 = new QHBoxLayout;
    lay32->addWidget(lblDateEdit);
    lay32->addWidget(lnDateEdit);
    QHBoxLayout *lay33 = new QHBoxLayout;
    lay33->addWidget(lblStockNumbEdit);
    lay33->addWidget(lnStockNumbEdit);
    QHBoxLayout *lay34 = new QHBoxLayout;
    lay34->addWidget(lblCodeTMCEdit);
    lay34->addWidget(lnCodeTMCEdit);
    QHBoxLayout *lay35 = new QHBoxLayout;
    lay35->addWidget(lblSalNumbEdit);
    lay35->addWidget(lnSalNumbEdit);
    QHBoxLayout *lay36 = new QHBoxLayout;
    lay36->addWidget(lblFIOEdit);
    lay36->addWidget(lnFIOEdit);
    QHBoxLayout *lay37 = new QHBoxLayout;
    lay37->addWidget(lblPosEdit);
    lay37->addWidget(lnPosEdit);

    QVBoxLayout *layEdit = new QVBoxLayout;
    layEdit->addLayout(lay31);
    layEdit->addLayout(lay32);
    layEdit->addLayout(lay33);
    layEdit->addLayout(lay34);
    layEdit->addLayout(lay35);
    layEdit->addLayout(lay36);
    layEdit->addLayout(lay37);
    layEdit->addWidget(butEdit);

    groupEdit->setLayout(layEdit);

    QVBoxLayout *layAll = new QVBoxLayout;
    layAll->addWidget(groupAdd);
    layAll->addWidget(groupDel);
    layAll->addWidget(groupEdit);

    setLayout(layAll);

    //переделать: отправлять сигнал с инфой в базу, а потом уже очищать
    connect (butAdd, SIGNAL(clicked()), this, SLOT(CheckLinesAdd()));
    connect (butDel, SIGNAL(clicked()), this, SLOT(CheckLinesDel()));
    connect (butEdit, SIGNAL(clicked()), this, SLOT(CheckLinesEdit()));
}

void PurchaseInvoiceEdit::CheckLinesAdd()
{
    lnNumberAdd->clear();
    lnDateAdd->clear();
    lnStockNumbAdd->clear();
    lnCodeTMCAdd->clear();
    lnSalNumbAdd->clear();
    lnFIOAdd->clear();
    lnPosAdd->clear();
}

void PurchaseInvoiceEdit::CheckLinesDel()
{
    lnNumberDel->clear();
}

void PurchaseInvoiceEdit::CheckLinesEdit()
{
    lnNumberEdit->clear();
    lnDateEdit->clear();
    lnStockNumbEdit->clear();
    lnCodeTMCEdit->clear();
    lnSalNumbEdit->clear();
    lnFIOEdit->clear();
    lnPosEdit->clear();
}

void PurchaseInvoiceEdit::ClearLinesAdd()
{
    lnNumberAdd->clear();
    lnDateAdd->clear();
    lnStockNumbAdd->clear();
    lnCodeTMCAdd->clear();
    lnSalNumbAdd->clear();
    lnFIOAdd->clear();
    lnPosAdd->clear();
}

void PurchaseInvoiceEdit::ClearLinesDel()
{
    lnNumberDel->clear();
}

void PurchaseInvoiceEdit::ClearLinesEdit()
{
    lnNumberEdit->clear();
    lnDateEdit->clear();
    lnStockNumbEdit->clear();
    lnCodeTMCEdit->clear();
    lnSalNumbEdit->clear();
    lnFIOEdit->clear();
    lnPosEdit->clear();
}
