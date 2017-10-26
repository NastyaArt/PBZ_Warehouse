#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>

#include "inventoryedit.h"
#include "stockedit.h"

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

    QGroupBox *group;

    QPushButton *butInventory;
    QPushButton *butStock;
    QPushButton *butPurchaseInv;
    QPushButton *butSalesInv;

};

#endif // MAINWINDOW_H
