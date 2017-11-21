#ifndef ALLSTOCKSVIEW_H
#define ALLSTOCKSVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QtSql>
#include <QTableView>

class AllStocksView : public QWidget
{
    Q_OBJECT
public:
    explicit AllStocksView(QWidget *parent = 0);
private:
    QSqlQueryModel *model;
    QTableView *tableView;

signals:

public slots:
    void SetupModel();
};

#endif // ALLSTOCKSVIEW_H
