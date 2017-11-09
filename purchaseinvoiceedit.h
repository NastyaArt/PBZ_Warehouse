#ifndef PURCHASEINVOICEEDIT_H
#define PURCHASEINVOICEEDIT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

class PurchaseInvoiceEdit : public QWidget
{
    Q_OBJECT
public:
    explicit PurchaseInvoiceEdit(QWidget *parent = 0);
private:

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

    void ClearLinesAdd();
    void ClearLinesDel();
    void ClearLinesEdit();
};

#endif // PURCHASEINVOICEEDIT_H
