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
    lblTipeAdd = new QLabel("Тип инвентаря");
    lblCodeDel = new QLabel("Код инвентаря");
    lblCodeEdit = new QLabel("Код инвентаря");
    lblNameEdit = new QLabel("Наименование инвентаря");
    lblTipeEdit = new QLabel("Тип инвентаря");

    lnCodeAdd = new QLineEdit;
    lnNameAdd = new QLineEdit;
    lnTipeAdd = new QLineEdit;
    lnCodeDel = new QLineEdit;
    lnCodeEdit = new QLineEdit;
    lnNameEdit = new QLineEdit;
    lnTipeEdit = new QLineEdit;

    QHBoxLayout *lay1 = new QHBoxLayout;
    lay1->addWidget(lblCodeAdd);
    lay1->addWidget(lnCodeAdd);
    QHBoxLayout *lay2 = new QHBoxLayout;
    lay2->addWidget(lblNameAdd);
    lay2->addWidget(lnNameAdd);
    QHBoxLayout *lay3 = new QHBoxLayout;
    lay3->addWidget(lblTipeAdd);
    lay3->addWidget(lnTipeAdd);

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
    lay7->addWidget(lblTipeEdit);
    lay7->addWidget(lnTipeEdit);

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
    if (lnCodeAdd->text()==NULL || lnNameAdd->text()==NULL || lnTipeAdd->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeAdd->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу
    QMessageBox::information(this, "Добавление инвентаря", "Добавлено успешно!", QMessageBox::Ok);
    ClearLinesAdd();
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
    //отправка инфы в базу
    QMessageBox::information(this, "Удаление инвентаря", "Удалено успешно!", QMessageBox::Ok);
    ClearLinesDel();
}

void InventoryEdit::CheckLinesEdit()
{
    if ((lnCodeEdit->text()!=NULL && (lnNameEdit->text()!=NULL || lnTipeEdit->text()!=NULL))!=true){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить поле <b>Код инвентаря</b> и хотя бы еще одно поле!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnCodeEdit->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Код инвентаря</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }
    //отправка инфы в базу
    QMessageBox::information(this, "Редактирование инвентаря", "Отредактировано успешно!", QMessageBox::Ok);
    ClearLinesEdit();
}

void InventoryEdit::ClearLinesAdd()
{
    lnCodeAdd->clear();
    lnNameAdd->clear();
    lnTipeAdd->clear();
}

void InventoryEdit::ClearLinesDel()
{
    lnCodeDel->clear();
}

void InventoryEdit::ClearLinesEdit()
{
    lnCodeEdit->clear();
    lnNameEdit->clear();
    lnTipeEdit->clear();
}

