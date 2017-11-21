#ifndef STOCKRECORDCARDVIEW_H
#define STOCKRECORDCARDVIEW_H

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

class StockRecordCardView : public QWidget
{
    Q_OBJECT
public:
    explicit StockRecordCardView(QWidget *parent = 0);
private:

    TextValidation valid;
    QLabel *lblName;
    QLabel *lblStock;
    QLineEdit *lnName;
    QLineEdit *lnStock;

    QPushButton *butSrch;

    QSqlQueryModel *model;
    QTableView *tableView;

signals:

public slots:

    void SetupModel();
    void CheckLines();
};

#endif // STOCKRECORDCARDVIEW_H
