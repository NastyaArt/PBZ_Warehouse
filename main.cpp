#include "mainwindow.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Database base;


    w.setWindowTitle("Учет инвентаря на складах предприятия");
   // w.showMaximized();
    w.show();

    QObject::connect(w.invEdit, SIGNAL(AddInvInfo(int, QString, QString)), &base, SLOT(AddInventory(int, QString, QString)));
    QObject::connect(w.invEdit, SIGNAL(DelInvInfo(int)), &base, SLOT(DelInventory(int)));
    QObject::connect(w.invEdit, SIGNAL(EditInvInfo(int, QString, QString)), &base, SLOT(EditInventory(int, QString, QString)));

    QObject::connect(w.stockEdit, SIGNAL(AddStockInfo(int, QString, QString)), &base, SLOT(AddStock(int, QString, QString)));
    QObject::connect(w.stockEdit, SIGNAL(DelStockInfo(int)), &base, SLOT(DelStock(int)));
    QObject::connect(w.stockEdit, SIGNAL(EditStockInfo(int, QString, QString)), &base, SLOT(EditStock(int, QString, QString)));

    QObject::connect(w.purchEdit, SIGNAL(AddPurchInfo(int, QString, int, int, int, QString, QString)), &base, SLOT(AddPurchase(int, QString, int, int, int, QString, QString)));
    QObject::connect(w.purchEdit, SIGNAL(DelPurchInfo(int)), &base, SLOT(DelPurchase(int)));
    QObject::connect(w.purchEdit, SIGNAL(EditPurchInfo(int, QString, int, int, int, QString, QString)), &base, SLOT(EditPurchase(int, QString, int, int, int, QString, QString)));

    QObject::connect(w.salesEdit, SIGNAL(AddSalesInfo(int, QString, int, int, int, QString, QString)), &base, SLOT(AddSales(int, QString, int, int, int, QString, QString)));
    QObject::connect(w.salesEdit, SIGNAL(DelSalesInfo(int)), &base, SLOT(DelSales(int)));
    QObject::connect(w.salesEdit, SIGNAL(EditSalesInfo(int, QString, int, int, int, QString, QString)), &base, SLOT(EditSales(int, QString, int, int, int, QString, QString)));


    QObject::connect(&base, SIGNAL(AddStatusInv(bool, QString)), w.invEdit, SLOT(AddStatus(bool, QString)));
    QObject::connect(&base, SIGNAL(DelStatusInv(bool, QString)), w.invEdit, SLOT(DelStatus(bool, QString)));
    QObject::connect(&base, SIGNAL(EditStatusInv(bool, QString)), w.invEdit, SLOT(EditStatus(bool, QString)));

    QObject::connect(&base, SIGNAL(AddStatusStock(bool, QString)), w.stockEdit, SLOT(AddStatus(bool, QString)));
    QObject::connect(&base, SIGNAL(DelStatusStockv(bool, QString)), w.stockEdit, SLOT(DelStatus(bool, QString)));
    QObject::connect(&base, SIGNAL(EditStatusStock(bool, QString)), w.stockEdit, SLOT(EditStatus(bool, QString)));

    QObject::connect(&base, SIGNAL(AddStatusPurch(bool, QString)), w.purchEdit, SLOT(AddStatus(bool, QString)));
    QObject::connect(&base, SIGNAL(DelStatusPurch(bool, QString)), w.purchEdit, SLOT(DelStatus(bool, QString)));
    QObject::connect(&base, SIGNAL(EditStatusPurch(bool, QString)), w.purchEdit, SLOT(EditStatus(bool, QString)));

    QObject::connect(&base, SIGNAL(AddStatusSales(bool, QString)), w.salesEdit, SLOT(AddStatus(bool, QString)));
    QObject::connect(&base, SIGNAL(DelStatusSales(bool, QString)), w.salesEdit, SLOT(DelStatus(bool, QString)));
    QObject::connect(&base, SIGNAL(EditStatusSales(bool, QString)), w.salesEdit, SLOT(EditStatus(bool, QString)));

    return a.exec();
}
