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


    // QRegExp fio = ("[А-ЯЁа-яё]+\\s[А-ЯЁ]\\.[А-ЯЁ]\\.");
   //fio.exactMatch (lines->at(i)->text())==false

signals:

public slots:

    void ClearLinesAdd();
    void ClearLinesDel();
    void ClearLinesEdit();
};

#endif // INVENTORYEDIT_H
