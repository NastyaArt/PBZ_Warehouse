#include "allstocksview.h"

AllStocksView::AllStocksView(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600, 500);

    setWindowTitle("Просмотр всех складов предприятия");

    tableView = new QTableView();

    QHBoxLayout *layAll = new QHBoxLayout;
    layAll->addWidget(tableView);

    setLayout(layAll);

    SetupModel();

}

void AllStocksView::SetupModel()
{
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM stocks ORDER BY name");
    tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,"Код склада");
    model->setHeaderData(1,Qt::Horizontal,"Наименование склада");
    model->setHeaderData(2,Qt::Horizontal,"Телефон склада");

    // Разрешаем выделение строк
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    tableView->resizeColumnsToContents();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);




}
