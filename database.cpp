#include "database.h"

Database::Database()
{
    SetConnectionWithDatabase();
}


void Database::SetConnectionWithDatabase()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("SQL Server");
    db.setUserName("root");
    db.setPassword("root");
//    bool ok = db.open();
  //  QMessageBox::information(this, "Подключение", QString::number(ok), QMessageBox::Ok);

    if (!db.open()) {
        qDebug() << db.lastError().text();
    } else {
        qDebug("success");
    }
    QSqlQuery query;
    query.exec("create table person (id int primary key, "
                  "firstname varchar(20), lastname varchar(20))");
    query.exec("insert into person values(101, 'Danny', 'Young')");
}

void Database::AddInventory(int code, QString name, QString type)
{
    emit AddStatusInv(true, "Выполнено успешно");

}

void Database::DelInventory(int code)
{
    emit DelStatusInv(true, "Выполнено успешно");

}

void Database::EditInventory(int code, QString name, QString type)
{
    emit EditStatusInv(true, "Выполнено успешно");

}

void Database::AddStock(int code, QString name, QString phone)
{
    emit AddStatusStock(true, "Выполнено успешно");

}

void Database::DelStock(int code)
{
    emit DelStatusStock(true, "Выполнено успешно");

}

void Database::EditStock(int code, QString name, QString phone)
{
    emit EditStatusStock(true, "Выполнено успешно");

}

void Database::AddPurchase(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos)
{
    emit AddStatusPurch(true, "Выполнено успешно");

}

void Database::DelPurchase(int code)
{
    emit DelStatusPurch(true, "Выполнено успешно");

}

void Database::EditPurchase(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos)
{
    emit EditStatusPurch(true, "Выполнено успешно");

}

void Database::AddSales(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos)
{
    emit AddStatusSales(true, "Выполнено успешно");

}

void Database::DelSales(int code)
{
    emit DelStatusSales(true, "Выполнено успешно");

}

void Database::EditSales(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos)
{
    emit EditStatusSales(true, "Выполнено успешно");

}
