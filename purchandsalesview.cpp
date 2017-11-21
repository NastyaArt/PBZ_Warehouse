#include "purchandsalesview.h"

PurchAndSalesView::PurchAndSalesView(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600, 500);

    setWindowTitle("Просмотр приходов и расходов на всех складах предприятия");

    lblName = new QLabel("Наименование инвентаря: ");
    lnName = new QLineEdit;

    butSrch = new QPushButton("Поиск");

    tableView = new QTableView();

    QHBoxLayout *layInput = new QHBoxLayout;
    layInput->addWidget(lblName);
    layInput->addWidget(lnName);

    QVBoxLayout *layAll = new QVBoxLayout;
    layAll->addLayout(layInput);
    layAll->addWidget(butSrch);
    layAll->addWidget(tableView);

    setLayout(layAll);

    connect (butSrch, SIGNAL(clicked()), this, SLOT(CheckLines()));
}

void PurchAndSalesView::SetupModel()
{

    model = new QSqlQueryModel(this);
    model->setQuery("SELECT result.type, result.date, result.numberOfInventory, stocks.name "
                    "FROM (SELECT 'Приход' AS type, date, numberOfInventory, codeStock, codeInventory "
                    "FROM purchase "
                    "UNION "
                    "SELECT 'Расход' AS type, date, numberOfInventory, codeStock, codeInventory "
                    "FROM sales "
                    "ORDER BY date) result "
                    "INNER JOIN inventory ON inventory.code=result.codeInventory "
                    "INNER JOIN stocks ON stocks.code=result.codeStock "
                    "WHERE inventory.name= '" + lnName->text() + "'");
    tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,"Тип накладной");
    model->setHeaderData(1,Qt::Horizontal,"Дата");
    model->setHeaderData(2,Qt::Horizontal,"Количество инвентаря");
    model->setHeaderData(3,Qt::Horizontal,"Наименование склада");

    // Разрешаем выделение строк
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    tableView->resizeColumnsToContents();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void PurchAndSalesView::CheckLines()
{
    if (lnName->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    SetupModel();
}

