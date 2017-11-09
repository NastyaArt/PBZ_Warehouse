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

    QLabel *lblNumbAdd;
    QLabel *lblNameAdd;
    QLabel *lblPhoneAdd;

    QLabel *lblNumbDel;

    QLabel *lblNumbEdit;
    QLabel *lblNameEdit;
    QLabel *lblPhoneEdit;

    QLineEdit *lnNumbAdd;
    QLineEdit *lnNameAdd;
    QLineEdit *lnPhoneAdd;
    QLineEdit *lnNumbDel;
    QLineEdit *lnNumbEdit;
    QLineEdit *lnNameEdit;
    QLineEdit *lnPhoneEdit;

signals:

public slots:

    void CheckLinesAdd();
    void CheckLinesDel();
    void CheckLinesEdit();
    void ClearLinesAdd();
    void ClearLinesDel();
    void ClearLinesEdit();
};

#endif // STOCKEDIT_H
