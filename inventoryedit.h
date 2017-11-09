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
    QLabel *lblTypeAdd;

    QLabel *lblCodeDel;

    QLabel *lblCodeEdit;
    QLabel *lblNameEdit;
    QLabel *lblTypeEdit;

    QLineEdit *lnCodeAdd;
    QLineEdit *lnNameAdd;
    QLineEdit *lnTypeAdd;

    QLineEdit *lnCodeDel;

    QLineEdit *lnCodeEdit;
    QLineEdit *lnNameEdit;
    QLineEdit *lnTypeEdit;

signals:
    void AddInvInfo(int code, QString name, QString type);
    void DelInvInfo(int code);
    void EditInvInfo(int code, QString name, QString type);

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

#endif // INVENTORYEDIT_H
