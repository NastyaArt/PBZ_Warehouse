#include "database.h"

Database::Database()
{

}

void Database::SetConnectionWithDatabase()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("SQL Server");
    db.setUserName("root");
    db.setPassword("root");

    if (!db.open()) {
        qDebug() << db.lastError().text();
        emit ConnectionError();
        return;
    } else {
        qDebug("Success");
    }
}

void Database::AddInventory(int code, QString name, QString type)
{
    QSqlQuery query;
    query.prepare("INSERT INTO inventory (code, name, type)"
                  "VALUES (:code, :name, :type)");
    query.bindValue(":code", code);
    query.bindValue(":name", name);
    query.bindValue(":type", type);
    if (query.exec())
        emit AddStatusInv(true, "Выполнено успешно");
    else emit AddStatusInv(false, query.lastError().text());
}

void Database::DelInventory(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM inventory WHERE code = ?");
    query.addBindValue(code);
    if (query.exec())
        emit DelStatusInv(true, "Выполнено успешно");
    else emit DelStatusInv(false, query.lastError().text());
}

void Database::EditInventory(int code, QString name, QString type)
{
    if (name!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE inventory SET name = ? WHERE code = ?");
        query.addBindValue(name);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusInv(false, query.lastError().text());
            return;
        }
    }
    if (type!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE inventory SET type = ? WHERE code = ?");
        query.addBindValue(type);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusInv(false, query.lastError().text());
            return;
        }
    }
    emit EditStatusInv(true, "Выполнено успешно");
}

void Database::AddStock(int code, QString name, QString phone)
{
    QSqlQuery query;
    query.prepare("INSERT INTO stocks (code, name, phone)"
                  "VALUES (:code, :name, :phone)");
    query.bindValue(":code", code);
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    if (query.exec())
        emit AddStatusStock(true, "Выполнено успешно");
    else emit AddStatusStock(false, query.lastError().text());
}

void Database::DelStock(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM stocks WHERE code = ?");
    query.addBindValue(code);
    if (query.exec())
        emit DelStatusStock(true, "Выполнено успешно");
    else emit DelStatusStock(false, query.lastError().text());
}

void Database::EditStock(int code, QString name, QString phone)
{
    if (name!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE stocks SET name = ? WHERE code = ?");
        query.addBindValue(name);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusStock(false, query.lastError().text());
            return;
        }
    }
    if (phone!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE stocks SET phone = ? WHERE code = ?");
        query.addBindValue(phone);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusStock(false, query.lastError().text());
            return;
        }
    }
    emit EditStatusStock(true, "Выполнено успешно");
}

void Database::AddPurchase(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos)
{
    QSqlQuery query;
    query.prepare("INSERT INTO purchase (code, codeStock, codeInventory, numberOfInventory, workerName, workerPosition, date)"
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(code);
    query.addBindValue(codeStock);
    query.addBindValue(codeInv);
    query.addBindValue(numbInv);
    query.addBindValue(fio);
    query.addBindValue(pos);
    query.addBindValue(date);
    if (query.exec())
        emit AddStatusPurch(true, "Выполнено успешно");
    else emit AddStatusPurch(false, query.lastError().text());
}

void Database::DelPurchase(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM purchase WHERE code = ?");
    query.addBindValue(code);
    if (query.exec())
        emit DelStatusPurch(true, "Выполнено успешно");
    else emit DelStatusPurch(false, query.lastError().text());
}

void Database::EditPurchase(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos)
{
    if (date!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE purchase SET date = ? WHERE code = ?");
        query.addBindValue(date);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusPurch(false, query.lastError().text());
            return;
        }
    }
    if (codeStock!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE purchase SET codeStock = ? WHERE code = ?");
        query.addBindValue(codeStock);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusPurch(false, query.lastError().text());
            return;
        }
    }
    if (codeInv!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE purchase SET codeInventory = ? WHERE code = ?");
        query.addBindValue(codeInv);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusPurch(false, query.lastError().text());
            return;
        }
    }
    if (numbInv!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE purchase SET numberOfInventory = ? WHERE code = ?");
        query.addBindValue(numbInv);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusPurch(false, query.lastError().text());
            return;
        }
    }
    if (fio!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE purchase SET workerName = ? WHERE code = ?");
        query.addBindValue(fio);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusPurch(false, query.lastError().text());
            return;
        }
    }
    if (pos!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE purchase SET workerPosition = ? WHERE code = ?");
        query.addBindValue(pos);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusPurch(false, query.lastError().text());
            return;
        }
    }
    emit EditStatusPurch(true, "Выполнено успешно");
}

void Database::AddSales(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos)
{
    QSqlQuery query;
    query.prepare("INSERT INTO sales (code, codeStock, codeInventory, numberOfInventory, workerName, workerPosition, date)"
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(code);
    query.addBindValue(codeStock);
    query.addBindValue(codeInv);
    query.addBindValue(numbInv);
    query.addBindValue(fio);
    query.addBindValue(pos);
    query.addBindValue(date);
    if (query.exec())
        emit AddStatusSales(true, "Выполнено успешно");
    else emit AddStatusSales(false, query.lastError().text());
}

void Database::DelSales(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM sales WHERE code = ?");
    query.addBindValue(code);
    if (query.exec())
        emit DelStatusSales(true, "Выполнено успешно");
    else emit DelStatusSales(false, query.lastError().text());
}

void Database::EditSales(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos)
{
    if (date!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE sales SET date = ? WHERE code = ?");
        query.addBindValue(date);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusSales(false, query.lastError().text());
            return;
        }
    }
    if (codeStock!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE sales SET codeStock = ? WHERE code = ?");
        query.addBindValue(codeStock);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusSales(false, query.lastError().text());
            return;
        }
    }
    if (codeInv!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE sales SET codeInventory = ? WHERE code = ?");
        query.addBindValue(codeInv);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusSales(false, query.lastError().text());
            return;
        }
    }
    if (numbInv!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE sales SET numberOfInventory = ? WHERE code = ?");
        query.addBindValue(numbInv);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusSales(false, query.lastError().text());
            return;
        }
    }
    if (fio!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE sales SET workerName = ? WHERE code = ?");
        query.addBindValue(fio);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusSales(false, query.lastError().text());
            return;
        }
    }
    if (pos!=NULL)
    {
        QSqlQuery query;
        query.prepare("UPDATE sales SET workerPosition = ? WHERE code = ?");
        query.addBindValue(pos);
        query.addBindValue(code);
        if (!query.exec()){
            emit EditStatusSales(false, query.lastError().text());
            return;
        }
    }
    emit EditStatusSales(true, "Выполнено успешно");
}
