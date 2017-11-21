#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QtSql>
#include <QMessageBox>

#include "database.h"
#include "inventoryedit.h"
#include "stockedit.h"
#include "purchaseinvoiceedit.h"
#include "salesinvoiceedit.h"
#include "allstocksview.h"
#include "numofinventoryview.h"
#include "purchandsalesview.h"
#include "stockrecordcardview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Database *base;
    InventoryEdit *invEdit;
    StockEdit *stockEdit;
    PurchaseInvoiceEdit *purchEdit;
    SalesInvoiceEdit *salesEdit;

private:
    Ui::MainWindow *ui;

    AllStocksView *stocksView;
    NumOfInventoryView *numInvView;
    PurchAndSalesView *purchSalesView;
    StockRecordCardView * stockRecCardView;

    QGroupBox *groupEdit;
    QGroupBox *groupQuery;
    QGroupBox *groupAll;

    QPushButton *butInventory;
    QPushButton *butStock;
    QPushButton *butPurchase;
    QPushButton *butSales;

    QPushButton *butStocksView;
    QPushButton *butNumInvView;
    QPushButton *butPurchSalesView;
    QPushButton *butStockRecCardView;

public slots:
    void ConnectionError();

};

#endif // MAINWINDOW_H
