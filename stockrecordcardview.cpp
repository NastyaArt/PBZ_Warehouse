#include "stockrecordcardview.h"

StockRecordCardView::StockRecordCardView(QWidget *parent) : QWidget(parent)
{
    setFixedSize(600, 500);

    setWindowTitle("Карточка складского учета");

    lblName = new QLabel("Наименование инвентаря: ");
    lblStock = new QLabel("Номер склада: ");
    lnName = new QLineEdit;
    lnStock = new QLineEdit;

    butSrch = new QPushButton("Поиск");

    tableView = new QTableView();

    QHBoxLayout *layInput = new QHBoxLayout;
    layInput->addWidget(lblName);
    layInput->addWidget(lnName);
    layInput->addWidget(lblStock);
    layInput->addWidget(lnStock);

    QVBoxLayout *layAll = new QVBoxLayout;
    layAll->addLayout(layInput);
    layAll->addWidget(butSrch);
    layAll->addWidget(tableView);

    setLayout(layAll);

    connect (butSrch, SIGNAL(clicked()), this, SLOT(CheckLines()));
}

void StockRecordCardView::SetupModel()
{

    model = new QSqlQueryModel(this);
    model->setQuery("SELECT result.date, result.type, result.numberOfInventory, result.workerName, result.workerPosition"
                    "FROM (SELECT 'Приход' AS type, date, numberOfInventory, codeStock, codeInventory,  workerName, workerPosition"
                    "FROM purchase"
                    "UNION"
                    "SELECT 'Расход' AS type, date, numberOfInventory, codeStock, codeInventory,  workerName, workerPosition"
                    "FROM sales"
                    "ORDER BY date) result"
                    "INNER JOIN inventory ON inventory.code=result.codeInventory"
                    "WHERE inventory.name=" + lnName->text() +"AND result.codeStock=" + lnStock->text());
    tableView->setModel(model);

    model->setHeaderData(0,Qt::Horizontal,"Дата");
    model->setHeaderData(1,Qt::Horizontal,"Тип накладной");
    model->setHeaderData(2,Qt::Horizontal,"Количество инвентаря");
    model->setHeaderData(3,Qt::Horizontal,"ФИО работника");
    model->setHeaderData(4,Qt::Horizontal,"Должность работника");


    // Разрешаем выделение строк
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем режим выделения лишь одно строки в таблице
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    // Устанавливаем размер колонок по содержимому
    tableView->resizeColumnsToContents();
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void StockRecordCardView::CheckLines()
{
    if (lnName->text()==NULL || lnStock->text()==NULL){
        QMessageBox::information(this, "Ввод данных", "Необходимо заполнить все поля!", QMessageBox::Ok);
        return;
    }
    if (valid.IsNumber(lnStock->text())==false){
        QMessageBox::information(this, "Ввод данных", "В поле <b>Номер склада</b> необходимо указать целое положительное число!", QMessageBox::Ok);
        return;
    }

    SetupModel();
}

