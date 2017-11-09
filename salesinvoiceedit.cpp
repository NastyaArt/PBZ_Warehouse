#include "salesinvoiceedit.h"

SalesInvoiceEdit::SalesInvoiceEdit(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Расходная накладная");

    groupAdd = new QGroupBox("Добавление расходной");
    groupDel = new QGroupBox("Удаление расходной");
    groupEdit = new QGroupBox("Редактирование расходной(ключ - номер расходной)");

    butAdd = new QPushButton("Добавить");
    butDel = new QPushButton("Удалить");
    butEdit = new QPushButton("Изменить");

    lblCodeAdd = new QLabel("Номер расходной");
    lblDateAdd = new QLabel("Дата");
    lblStockCodeAdd = new QLabel("Код склада");
    lblInvCodeAdd = new QLabel("Код инвентаря");
    lblInvNumbAdd = new QLabel("Количество инвентаря");
    lblFIOAdd = new QLabel("ФИО работника");
    lblPosAdd = new QLabel("Должность работника");

    lblCodeDel = new QLabel("Номер расходной");

    lblCodeEdit = new QLabel("Номер расходной");
    lblDateEdit = new QLabel("Дата");
    lblStockCodeEdit = new QLabel("Код склада");
    lblInvCodeEdit = new QLabel("Код инвентаря");
    lblInvNumbEdit = new QLabel("Количество инвентаря");
    lblFIOEdit = new QLabel("ФИО работника");
    lblPosEdit = new QLabel("Должность работника");

    lnCodeAdd = new QLineEdit;
    lnDateAdd = new QLineEdit;
    lnStockCodeAdd = new QLineEdit;
    lnInvCodeAdd = new QLineEdit;
    lnInvNumbAdd = new QLineEdit;
    lnFIOAdd = new QLineEdit;
    lnPosAdd = new QLineEdit;

    lnCodeDel = new QLineEdit;

    lnCodeEdit = new QLineEdit;
    lnDateEdit = new QLineEdit;
    lnStockCodeEdit = new QLineEdit;
    lnInvCodeEdit = new QLineEdit;
    lnInvNumbEdit = new QLineEdit;
    lnFIOEdit = new QLineEdit;
    lnPosEdit = new QLineEdit;

    QHBoxLayout *lay11 = new QHBoxLayout;
    lay11->addWidget(lblCodeAdd);
    lay11->addWidget(lnCodeAdd);
    QHBoxLayout *lay12 = new QHBoxLayout;
    lay12->addWidget(lblDateAdd);
    lay12->addWidget(lnDateAdd);
    QHBoxLayout *lay13 = new QHBoxLayout;
    lay13->addWidget(lblStockCodeAdd);
    lay13->addWidget(lnStockCodeAdd);
    QHBoxLayout *lay14 = new QHBoxLayout;
    lay14->addWidget(lblInvCodeAdd);
    lay14->addWidget(lnInvCodeAdd);
    QHBoxLayout *lay15 = new QHBoxLayout;
    lay15->addWidget(lblInvNumbAdd);
    lay15->addWidget(lnInvNumbAdd);
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
    lay21->addWidget(lblCodeDel);
    lay21->addWidget(lnCodeDel);

    QVBoxLayout *layDel = new QVBoxLayout;
    layDel->addLayout(lay21);
    layDel->addWidget(butDel);

    groupDel->setLayout(layDel);

    QHBoxLayout *lay31 = new QHBoxLayout;
    lay31->addWidget(lblCodeEdit);
    lay31->addWidget(lnCodeEdit);
    QHBoxLayout *lay32 = new QHBoxLayout;
    lay32->addWidget(lblDateEdit);
    lay32->addWidget(lnDateEdit);
    QHBoxLayout *lay33 = new QHBoxLayout;
    lay33->addWidget(lblStockCodeEdit);
    lay33->addWidget(lnStockCodeEdit);
    QHBoxLayout *lay34 = new QHBoxLayout;
    lay34->addWidget(lblInvCodeEdit);
    lay34->addWidget(lnInvCodeEdit);
    QHBoxLayout *lay35 = new QHBoxLayout;
    lay35->addWidget(lblInvNumbEdit);
    lay35->addWidget(lnInvNumbEdit);
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

void SalesInvoiceEdit::CheckLinesAdd()
{
    if (lnCodeAdd->text()==NULL || lnDateAdd->text()==NULL || lnStockCodeAdd->text()==NULL
            || lnInvCodeAdd->text()==NULL || lnInvNumbAdd->text()==NULL
            || lnFIOAdd->text()==NULL || lnPosAdd->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Номер расходной</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (valid.IsDate(lnDateAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Дата</b> необходимо указать дату в формате YYYY-MM-DD!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnStockCodeAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код склада</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnInvCodeAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnInvNumbAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Количество инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (valid.IsFIO(lnFIOAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>ФИО работника</b> необходимо указать фамилию в формате Фамилия И.О.!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу(база должна выслать статус выполения)
    emit AddSalesInfo(lnCodeAdd->text().toInt(), lnDateAdd->text(), lnStockCodeAdd->text().toInt(), lnInvCodeAdd->text().toInt(), lnInvNumbAdd->text().toInt(), lnFIOAdd->text(), lnPosAdd->text());
    }

void SalesInvoiceEdit::CheckLinesDel()
{
    if (lnCodeDel->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeDel->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Номер расходной</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу(база должна выслать статус выполения)
    emit DelSalesInfo(lnCodeDel->text().toInt());
}

void SalesInvoiceEdit::CheckLinesEdit()
{
    if ((lnCodeEdit->text()!=NULL && (lnDateEdit->text()!=NULL || lnStockCodeEdit->text()!=NULL
            || lnInvCodeEdit->text()!=NULL || lnInvNumbEdit->text()!=NULL
            || lnFIOEdit->text()!=NULL || lnPosEdit->text()!=NULL))!=true){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить поле <b>Номер расходной</b> и хотя бы еще одно поле!", QMessageBox::Ok);
        return;
    }
    if (lnCodeEdit->text()!=NULL && valid.IsNumber(lnCodeEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Номер расходной</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (lnDateEdit->text()!=NULL && valid.IsDate(lnDateEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Дата</b> необходимо указать дату в формате YYYY-MM-DD!", QMessageBox::Ok);
        return;
    }
    if (lnStockCodeEdit->text()!=NULL && valid.IsNumber(lnStockCodeEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код склада</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (lnInvCodeEdit->text()!=NULL && valid.IsNumber(lnInvCodeEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (lnInvNumbEdit->text()!=NULL && valid.IsNumber(lnInvNumbEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Количество инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    if (lnFIOEdit->text()!=NULL && valid.IsFIO(lnFIOEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>ФИО работника</b> необходимо указать фамилию в формате Фамилия И.О.!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу(база должна выслать статус выполения)
    emit EditSalesInfo(lnCodeEdit->text().toInt(), lnDateEdit->text(), lnStockCodeEdit->text().toInt(), lnInvCodeEdit->text().toInt(), lnInvNumbEdit->text().toInt(), lnFIOEdit->text(), lnPosEdit->text());
}

void SalesInvoiceEdit::ClearLinesAdd()
{
    lnCodeAdd->clear();
    lnDateAdd->clear();
    lnStockCodeAdd->clear();
    lnInvCodeAdd->clear();
    lnInvNumbAdd->clear();
    lnFIOAdd->clear();
    lnPosAdd->clear();
}

void SalesInvoiceEdit::ClearLinesDel()
{
    lnCodeDel->clear();
}

void SalesInvoiceEdit::ClearLinesEdit()
{
    lnCodeEdit->clear();
    lnDateEdit->clear();
    lnStockCodeEdit->clear();
    lnInvCodeEdit->clear();
    lnInvNumbEdit->clear();
    lnFIOEdit->clear();
    lnPosEdit->clear();
}

void SalesInvoiceEdit::AddStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Добавление расходной", status, QMessageBox::Ok);
        ClearLinesAdd();
        return;
    }
    else
        QMessageBox::information(this, "Добавление расходной", status, QMessageBox::Ok);
}

void SalesInvoiceEdit::DelStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Удаление расходной", status, QMessageBox::Ok);
        ClearLinesDel();
        return;
    }
    else
        QMessageBox::information(this, "Удаление расходной", status, QMessageBox::Ok);
}

void SalesInvoiceEdit::EditStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Редактирование расходной", status, QMessageBox::Ok);
        ClearLinesEdit();
        return;
    }
    else
        QMessageBox::information(this, "Редактирование расходной", status, QMessageBox::Ok);
}

