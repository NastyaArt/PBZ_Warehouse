#include "numofinventoryview.h"

NumOfInventoryView::NumOfInventoryView(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600, 500);

    setWindowTitle("Просмотр количества инвентаря на заданном складе");

    lblType = new QLabel("Тип инвентаря: ");
    lblStock = new QLabel("Номер склада: ");
    lnType = new QLineEdit;
    lnStock = new QLineEdit;

    butSrch = new QPushButton("Поиск");

    tableView = new QTableView();

    QHBoxLayout *layInput = new QHBoxLayout;
    layInput->addWidget(lblType);
    layInput->addWidget(lnType);
    layInput->addWidget(lblStock);
    layInput->addWidget(lnStock);

    QVBoxLayout *layAll = new QVBoxLayout;
    layAll->addLayout(layInput);
    layAll->addWidget(butSrch);
    layAll->addWidget(tableView);

    setLayout(layAll);

    connect (butSrch, SIGNAL(clicked()), this, SLOT(CheckLines()));
}

void NumOfInventoryView::SetupModel()
{
    model = new QSqlQueryModel(this);
    model->setQuery("SELECT inventory.name, purch.numberPurchase, IFNULL(sal.numberSales,0) AS numberSales, purch.numberPurchase-IFNULL(sal.numberSales,0) AS number "
                    "FROM inventory "
                    "JOIN (SELECT codeInventory, SUM(numberOfInventory) AS numberPurchase FROM purchase WHERE codeStock=" + lnStock->text() + "  GROUP BY codeInventory) purch ON inventory.code=purch.codeInventory "
                    "LEFT JOIN (SELECT codeInventory, SUM(numberOfInventory) AS numberSales FROM sales WHERE codeStock=" + lnStock->text() + "  GROUP BY codeInventory) sal ON inventory.code=sal.codeInventory "
                    "WHERE  inventory.type= '" + lnType->text() +"' ");
    tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,"Наименование инвентаря");
    model->setHeaderData(1,Qt::Horizontal,"Приход");
    model->setHeaderData(2,Qt::Horizontal,"Расход");
    model->setHeaderData(3,Qt::Horizontal,"Остаток");

    // Разрешаем выделение строк
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    tableView->resizeColumnsToContents();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void NumOfInventoryView::CheckLines()
{
    if (lnType->text()==NULL || lnStock->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnStock->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Номер склада</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }

    SetupModel();
}
