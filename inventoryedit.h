#ifndef INVENTORYEDIT_H
#define INVENTORYEDIT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

class InventoryEdit : public QWidget
{
    Q_OBJECT
public:
    explicit InventoryEdit(QWidget *parent = 0);

private:

    QGroupBox *groupAdd;
    QGroupBox *groupDel;
    QGroupBox *groupEdit;

    QPushButton *butAdd;
    QPushButton *butDel;
    QPushButton *butEdit;

    QLabel *lblNameAdd;
    QLabel *lblTipeAdd;
    QLabel *lblStockAdd;
    QLabel *lblNameDel;
    QLabel *lblNameEdit;
    QLabel *lblTipeEdit;
    QLabel *lblStockEdit;

    QLineEdit *lnNameAdd;
    QLineEdit *lnTipeAdd;
    QLineEdit *lnStockAdd;
    QLineEdit *lnNameDel;
    QLineEdit *lnNameEdit;
    QLineEdit *lnTipeEdit;
    QLineEdit *lnStockEdit;

signals:

public slots:
};

#endif // INVENTORYEDIT_H
