#include "total_time.h"
#include "ui_total_time.h"

total_time::total_time(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::total_time)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE", "connection_name_1");
    db.setDatabaseName("C:/sqlite/mytestdatabase.db");
    db.open();

    table = new QSqlQueryModel;
}

total_time::~total_time()
{
    delete ui;
}

void total_time::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text();

    QString str_qry = "SELECT name_of_product, SUM(time) AS [Время полного ремонта] FROM products LEFT JOIN components ON products.ID_of_product = components.ID_of_product LEFT JOIN details ON components.ID_of_component = details.ID_of_component WHERE name_of_product = '";
    str_qry += name;
    str_qry += "'";

    table->clear();
    table->setQuery(str_qry, db);
    ui->tableView->setModel(table);
}

void total_time::on_pushButton_2_clicked()
{
    QWidget::close();
}
