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

    QLabel *lblCodeAdd;
    QLabel *lblDateAdd;
    QLabel *lblStockCodeAdd;
    QLabel *lblInvCodeAdd;
    QLabel *lblInvNumbAdd;
    QLabel *lblFIOAdd;
    QLabel *lblPosAdd;

    QLabel *lblCodeDel;

    QLabel *lblCodeEdit;
    QLabel *lblDateEdit;
    QLabel *lblStockCodeEdit;
    QLabel *lblInvCodeEdit;
    QLabel *lblInvNumbEdit;
    QLabel *lblFIOEdit;
    QLabel *lblPosEdit;

    QLineEdit *lnCodeAdd;
    QLineEdit *lnDateAdd;
    QLineEdit *lnStockCodeAdd;
    QLineEdit *lnInvCodeAdd;
    QLineEdit *lnInvNumbAdd;
    QLineEdit *lnFIOAdd;
    QLineEdit *lnPosAdd;

    QLineEdit *lnCodeDel;

    QLineEdit *lnCodeEdit;
    QLineEdit *lnDateEdit;
    QLineEdit *lnStockCodeEdit;
    QLineEdit *lnInvCodeEdit;
    QLineEdit *lnInvNumbEdit;
    QLineEdit *lnFIOEdit;
    QLineEdit *lnPosEdit;

signals:
    void AddInvInfo(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos);
    void DelInvInfo(int code);
    void EditInvInfo(int code, QString date, int codeStock, int codeInv, int numbInv, QString fio, QString pos);

public slots:

    void CheckLinesAdd();
    void CheckLinesDel();
    void CheckLinesEdit();
    void ClearLinesAdd();
    void ClearLinesDel();
    void ClearLinesEdit();
    void AddStatus(bool ok, QString status);
    void DelStatus(bool ok, QString status);
    void EditStatus(bool ok, QString status);
};

#endif // SALESINVOICEEDIT_H
