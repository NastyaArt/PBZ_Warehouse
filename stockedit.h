#ifndef STOCKEDIT_H
#define STOCKEDIT_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "textvalidation.h"

class StockEdit : public QWidget
{
    Q_OBJECT
public:
    explicit StockEdit(QWidget *parent = 0);
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
    QLabel *lblPhoneAdd;

    QLabel *lblCodeDel;

    QLabel *lblCodeEdit;
    QLabel *lblNameEdit;
    QLabel *lblPhoneEdit;

    QLineEdit *lnCodeAdd;
    QLineEdit *lnNameAdd;
    QLineEdit *lnPhoneAdd;
    QLineEdit *lnCodeDel;
    QLineEdit *lnCodeEdit;
    QLineEdit *lnNameEdit;
    QLineEdit *lnPhoneEdit;

signals:
    void AddStockInfo(int code, QString name, QString phone);
    void DelStockInfo(int code);
    void EditStockInfo(int code, QString name, QString phone);

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

#endif // STOCKEDIT_H
