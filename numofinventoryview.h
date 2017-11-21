#ifndef NUMOFINVENTORYVIEW_H
#define NUMOFINVENTORYVIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QTableView>
#include "textvalidation.h"

class NumOfInventoryView : public QWidget
{
    Q_OBJECT
public:
    explicit NumOfInventoryView(QWidget *parent = 0);
private:
    TextValidation valid;
    QLabel *lblType;
    QLabel *lblStock;
    QLineEdit *lnType;
    QLineEdit *lnStock;

    QPushButton *butSrch;

    QSqlQueryModel *model;
    QTableView *tableView;

signals:

public slots:

    void SetupModel();
    void CheckLines();
};

#endif // NUMOFINVENTORYVIEW_H
