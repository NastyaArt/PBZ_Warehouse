#ifndef PURCHANDSALESVIEW_H
#define PURCHANDSALESVIEW_H

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
#include <QtSql>
#include "textvalidation.h"

class PurchAndSalesView : public QWidget
{
    Q_OBJECT
public:
    explicit PurchAndSalesView(QWidget *parent = 0);

private:
    TextValidation valid;

    QLabel *lblName;
    QLineEdit *lnName;

    QPushButton *butSrch;

    QSqlQueryModel *model;
    QTableView *tableView;

signals:

public slots:

    void SetupModel();
    void CheckLines();
};

#endif // PURCHANDSALESVIEW_H
