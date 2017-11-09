#include "stockedit.h"

StockEdit::StockEdit(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Склады");

    groupAdd = new QGroupBox("Добавление склада");
    groupDel = new QGroupBox("Удаление склада");
    groupEdit = new QGroupBox("Редактирование склада(ключ - номер склада)");

    butAdd = new QPushButton("Добавить");
    butDel = new QPushButton("Удалить");
    butEdit = new QPushButton("Изменить");

    lblCodeAdd = new QLabel("Номер склада");
    lblNameAdd = new QLabel("Наименование склада");
    lblPhoneAdd = new QLabel("Телефон склада");
    lblCodeDel = new QLabel("Номер склада");
    lblCodeEdit = new QLabel("Номер склада");
    lblNameEdit = new QLabel("Наименование склада");
    lblPhoneEdit = new QLabel("Телефон склада");

    lnCodeAdd = new QLineEdit;
    lnNameAdd = new QLineEdit;
    lnPhoneAdd = new QLineEdit;
    lnCodeDel = new QLineEdit;
    lnCodeEdit = new QLineEdit;
    lnNameEdit = new QLineEdit;
    lnPhoneEdit = new QLineEdit;

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(lblCodeAdd);
    lay1->addWidget(lnCodeAdd);
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
    lay4->addWidget(lblCodeDel);
    lay4->addWidget(lnCodeDel);

    QVBoxLayout *layDel = new QVBoxLayout;
    layDel->addLayout(lay4);
    layDel->addWidget(butDel);

    groupDel->setLayout(layDel);

    QHBoxLayout *lay5 = new QHBoxLayout;
    lay5->addWidget(lblCodeEdit);
    lay5->addWidget(lnCodeEdit);
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

    //переделать: отправлять сигнал с инфой в базу, а потом уже очищать
    connect (butAdd, SIGNAL(clicked()), this, SLOT(CheckLinesAdd()));
    connect (butDel, SIGNAL(clicked()), this, SLOT(CheckLinesDel()));
    connect (butEdit, SIGNAL(clicked()), this, SLOT(CheckLinesEdit()));
}

void StockEdit::CheckLinesAdd()
{
    if (lnCodeAdd->text()==NULL || lnNameAdd->text()==NULL || lnPhoneAdd->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Номер склада</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (valid.IsPhone(lnPhoneAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Телефон склада</b> необходимо указать телефон в формате XXX-XX-XX!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу(база должна выслать статус выполения)
    emit AddStockInfo(lnCodeAdd->text().toInt(), lnNameAdd->text(), lnPhoneAdd->text());
}

void StockEdit::CheckLinesDel()
{
    if (lnCodeDel->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeDel->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Номер склада</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу(база должна выслать статус выполения)
    emit DelStockInfo(lnCodeAdd->text().toInt());
}

void StockEdit::CheckLinesEdit()
{
    if ((lnCodeEdit->text()!=NULL && (lnNameEdit->text()!=NULL || lnPhoneEdit->text()!=NULL))!=true){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить поле <b>Номер склада</b> и хотя бы еще одно поле!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Номер склада</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (lnPhoneEdit->text()!=NULL && valid.IsPhone(lnPhoneEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Телефон склада</b> необходимо указать телефон в формате XXX-XX-XX!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу(база должна выслать статус выполения)
    emit EditStockInfo(lnCodeAdd->text().toInt(), lnNameAdd->text(), lnPhoneAdd->text());
}

void StockEdit::ClearLinesAdd()
{
    lnCodeAdd->clear();
    lnNameAdd->clear();
    lnPhoneAdd->clear();
}

void StockEdit::ClearLinesDel()
{
    lnCodeDel->clear();
}

void StockEdit::ClearLinesEdit()
{
    lnCodeEdit->clear();
    lnNameEdit->clear();
    lnPhoneEdit->clear();
}

void StockEdit::AddStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Добавление склада", status, QMessageBox::Ok);
        ClearLinesAdd();
        return;
    }
    else
        QMessageBox::information(this, "Добавление склада", status, QMessageBox::Ok);
}

void StockEdit::DelStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Удаление склада", status, QMessageBox::Ok);
        ClearLinesDel();
        return;
    }
    else
        QMessageBox::information(this, "Удаление склада", status, QMessageBox::Ok);
}

void StockEdit::EditStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Редактирование склада", status, QMessageBox::Ok);
        ClearLinesEdit();
        return;
    }
    else
        QMessageBox::information(this, "Редактирование склада", status, QMessageBox::Ok);
}

