#include "inventoryedit.h"

InventoryEdit::InventoryEdit(QWidget *parent) : QWidget(parent)
{

    setWindowTitle("Рабочий инвентарь");

    groupAdd = new QGroupBox("Добавление инвентаря");
    groupDel = new QGroupBox("Удаление инвентаря");
    groupEdit = new QGroupBox("Редактирование инвентаря(ключ - код инвентаря)");

    butAdd = new QPushButton("Добавить");
    butDel = new QPushButton("Удалить");
    butEdit = new QPushButton("Изменить");

    lblCodeAdd = new QLabel("Код инвентаря");
    lblNameAdd = new QLabel("Наименование инвентаря");
    lblTypeAdd = new QLabel("Тип инвентаря");
    lblCodeDel = new QLabel("Код инвентаря");
    lblCodeEdit = new QLabel("Код инвентаря");
    lblNameEdit = new QLabel("Наименование инвентаря");
    lblTypeEdit = new QLabel("Тип инвентаря");

    lnCodeAdd = new QLineEdit;
    lnNameAdd = new QLineEdit;
    lnTypeAdd = new QLineEdit;
    lnCodeDel = new QLineEdit;
    lnCodeEdit = new QLineEdit;
    lnNameEdit = new QLineEdit;
    lnTypeEdit = new QLineEdit;

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(lblCodeAdd);
    lay1->addWidget(lnCodeAdd);
    QHBoxLayout *lay2 = new QHBoxLayout;
    lay2->addWidget(lblNameAdd);
    lay2->addWidget(lnNameAdd);
    QHBoxLayout *lay3 = new QHBoxLayout;
    lay3->addWidget(lblTypeAdd);
    lay3->addWidget(lnTypeAdd);

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
    lay7->addWidget(lblTypeEdit);
    lay7->addWidget(lnTypeEdit);

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

void InventoryEdit::CheckLinesAdd()
{
    if (lnCodeAdd->text()==NULL || lnNameAdd->text()==NULL || lnTypeAdd->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу (база должна выслать статус выполения)
    emit AddInvInfo(lnCodeAdd->text().toInt(), lnNameAdd->text(), lnTypeAdd->text());

}

void InventoryEdit::CheckLinesDel()
{
    if (lnCodeDel->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeDel->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу (база должна выслать статус выполения)
    emit DelInvInfo(lnCodeAdd->text().toInt());

}

void InventoryEdit::CheckLinesEdit()
{
    if ((lnCodeEdit->text()!=NULL && (lnNameEdit->text()!=NULL || lnTypeEdit->text()!=NULL))!=true){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить поле <b>Код инвентаря</b> и хотя бы еще одно поле!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу (база должна выслать статус выполения)
    emit EditInvInfo(lnCodeAdd->text().toInt(), lnNameAdd->text(), lnTypeAdd->text());
}

void InventoryEdit::ClearLinesAdd()
{
    lnCodeAdd->clear();
    lnNameAdd->clear();
    lnTypeAdd->clear();
}

void InventoryEdit::ClearLinesDel()
{
    lnCodeDel->clear();
}

void InventoryEdit::ClearLinesEdit()
{
    lnCodeEdit->clear();
    lnNameEdit->clear();
    lnTypeEdit->clear();
}

void InventoryEdit::AddStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Добавление инвентаря", status, QMessageBox::Ok);
        ClearLinesAdd();
        return;
    }
    else
        QMessageBox::information(this, "Добавление инвентаря", status, QMessageBox::Ok);
}

void InventoryEdit::DelStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Удаление инвентаря", status, QMessageBox::Ok);
        ClearLinesDel();
        return;
    }
    else
        QMessageBox::information(this, "Удаление инвентаря", status, QMessageBox::Ok);
}

void InventoryEdit::EditStatus(bool ok, QString status)
{
    if (ok==true){
        QMessageBox::information(this, "Редактирование инвентаря", status, QMessageBox::Ok);
        ClearLinesEdit();
        return;
    }
    else
        QMessageBox::information(this, "Редактирование инвентаря", status, QMessageBox::Ok);
}

