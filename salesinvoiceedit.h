#ifndef SALESINVOICEEDIT_H
#define SALESINVOICEEDIT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "textvalidation.h"

class SalesInvoiceEdit : public QWidget
{
    Q_OBJECT
public:
    explicit SalesInvoiceEdit(QWidget *parent = 0);

private:
    TextValidation valid;

    QGroupBox *groupAdd;
    QGroupBox *groupDel;
    QGroupBox *groupEdit;

    QPushButton *butAdd;
    QPushButton *butDel;
    QPushButton *butEdit;

    QLabel *lblNumberAdd;
    QLabel *lblDateAdd;
    QLabel *lblStockNumbAdd;
    QLabel *lblCodeTMCAdd;
    QLabel *lblSalNumbAdd;
    QLabel *lblFIOAdd;
    QLabel *lblPosAdd;

    QLabel *lblNumberDel;

    QLabel *lblNumberEdit;
    QLabel *lblDateEdit;
    QLabel *lblStockNumbEdit;
    QLabel *lblCodeTMCEdit;
    QLabel *lblSalNumbEdit;
    QLabel *lblFIOEdit;
    QLabel *lblPosEdit;

    QLineEdit *lnNumberAdd;
    QLineEdit *lnDateAdd;
    QLineEdit *lnStockNumbAdd;
    QLineEdit *lnCodeTMCAdd;
    QLineEdit *lnSalNumbAdd;
    QLineEdit *lnFIOAdd;
    QLineEdit *lnPosAdd;

    QLineEdit *lnNumberDel;

    QLineEdit *lnNumberEdit;
    QLineEdit *lnDateEdit;
    QLineEdit *lnStockNumbEdit;
    QLineEdit *lnCodeTMCEdit;
    QLineEdit *lnSalNumbEdit;
    QLineEdit *lnFIOEdit;
    QLineEdit *lnPosEdit;

signals:

public slots:

    void CheckLinesAdd();
    void CheckLinesDel();
    void CheckLinesEdit();
    void ClearLinesAdd();
    void ClearLinesDel();
    void ClearLinesEdit();
};

#endif // SALESINVOICEEDIT_H
