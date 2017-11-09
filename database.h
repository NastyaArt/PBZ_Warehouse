#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QtSql>

class Database: public QObject
{
    Q_OBJECT
public:
    Database();

private:


signals:
    void AddStatusInv(bool ok, QString status);
    void DelStatusInv(bool ok, QString status);
    void EditStatusInv(bool ok, QString status);
    void AddStatusStock(bool ok, QString status);
    void DelStatusStock(bool ok, QString status);
    void EditStatusStock(bool ok, QString status);
    void AddStatusPurch(bool ok, QString status);
    void DelStatusPurch(bool ok, QString status);
    void EditStatusPurch(bool ok, QString status);
    void AddStatusSales(bool ok, QString status);
    void DelStatusSales(bool ok, QString status);
    void EditStatusSales(bool ok, QString status);

public slots:

    void AddInventory(int code, QString name, QString type);
    void DelInventory(int code);
    void EditInventory(int code, QString name, QString type);
    void AddStock(int code, QString name, QString phone);
    void DelStock(int code);
    void EditStock(int code, QString name, QString phone);
    void AddPurchase(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos);
    void DelPurchase(int code);
    void EditPurchase(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos);
    void AddSales(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos);
    void DelSales(int code);
    void EditSales(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos);


    void SetConnectionWithDatabase();
};

#endif // DATABASE_H
