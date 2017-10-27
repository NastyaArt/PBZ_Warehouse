#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>

#include "inventoryedit.h"
#include "stockedit.h"
#include "salesinvoiceedit.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    InventoryEdit *invEdit;
    StockEdit *stockEdit;
    SalesInvoiceEdit *salesEdit;

    QGroupBox *group;

    QPushButton *butInventory;
    QPushButton *butStock;
    QPushButton *butPurchase;
    QPushButton *butSales;

};

#endif // MAINWINDOW_H
