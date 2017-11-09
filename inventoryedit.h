#ifndef INVENTORYEDIT_H
#define INVENTORYEDIT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "textvalidation.h"

class InventoryEdit : public QWidget
{
    Q_OBJECT
public:
    explicit InventoryEdit(QWidget *parent = 0);

private:

    TextValidation valid;

    QGroupBox *groupAdd;
    QGroupBox *groupDel;
    QGroupBox *groupEdit;

    QPushButton *butAdd;
    QPushButton *butDel;
    QPushButton *butEdit;

    QLabel *lblCodeAdd;
    QLabel *lblNameAdd;
    QLabel *lblTipeAdd;

    QLabel *lblCodeDel;

    QLabel *lblCodeEdit;
    QLabel *lblNameEdit;
    QLabel *lblTipeEdit;

    QLineEdit *lnCodeAdd;
    QLineEdit *lnNameAdd;
    QLineEdit *lnTipeAdd;

    QLineEdit *lnCodeDel;

    QLineEdit *lnCodeEdit;
    QLineEdit *lnNameEdit;
    QLineEdit *lnTipeEdit;

signals:

public slots:

    void CheckLinesAdd();
    void CheckLinesDel();
    void CheckLinesEdit();
    void ClearLinesAdd();
    void ClearLinesDel();
    void ClearLinesEdit();
};

#endif // INVENTORYEDIT_H
