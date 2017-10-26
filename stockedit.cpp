#include "stockedit.h"

StockEdit::StockEdit(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Склады");

    groupAdd = new QGroupBox("Добавление склада");
    groupDel = new QGroupBox("Удаление склада");
    groupEdit = new QGroupBox("Редактирование склада");

    butAdd = new QPushButton("Добавить");
    butDel = new QPushButton("Удалить");
    butEdit = new QPushButton("Изменить");

    lblNumbAdd = new QLabel("Номер склада");
    lblNameAdd = new QLabel("Наименование склада");
    lblPhoneAdd = new QLabel("Телефон склада");
    lblNumbDel = new QLabel("Номер склада");
    lblNumbEdit = new QLabel("Номер склада");
    lblNameEdit = new QLabel("Наименование склада");
    lblPhoneEdit = new QLabel("Телефон склада");

    lnNumbAdd = new QLineEdit;
    lnNameAdd = new QLineEdit;
    lnPhoneAdd = new QLineEdit;
    lnNumbDel = new QLineEdit;
    lnNumbEdit = new QLineEdit;
    lnNameEdit = new QLineEdit;
    lnPhoneEdit = new QLineEdit;

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(lblNumbAdd);
    lay1->addWidget(lnNumbAdd);
    QHBoxLayout *lay2 = new QHBoxLayout;
    lay2->addWidget(lblNameAdd);
    lay2->addWidget(lnNameAdd);
    QHBoxLayout *lay3 = new QHBoxLayout;
    lay3->addWidget(lblPhoneAdd);
    lay3->addWidget(lnPhoneAdd);

    QVBoxLayout *layAdd = new QVBoxLayout;
    layAdd->addLayout(lay1);
    layAdd->addLayout(lay2);
    layAdd->addLayout(lay3);
    layAdd->addWidget(butAdd);

    groupAdd->setLayout(layAdd);

    QHBoxLayout *lay4 = new QHBoxLayout;
    lay4->addWidget(lblNumbDel);
    lay4->addWidget(lnNumbDel);

    QVBoxLayout *layDel = new QVBoxLayout;
    layDel->addLayout(lay4);
    layDel->addWidget(butDel);

    groupDel->setLayout(layDel);

    QHBoxLayout *lay5 = new QHBoxLayout;
    lay5->addWidget(lblNumbEdit);
    lay5->addWidget(lnNumbEdit);
    QHBoxLayout *lay6 = new QHBoxLayout;
    lay6->addWidget(lblNameEdit);
    lay6->addWidget(lnNameEdit);
    QHBoxLayout *lay7 = new QHBoxLayout;
    lay7->addWidget(lblPhoneEdit);
    lay7->addWidget(lnPhoneEdit);

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

