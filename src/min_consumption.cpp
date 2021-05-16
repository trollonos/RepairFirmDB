#include "min_consumption.h"
#include "ui_min_consumption.h"

min_consumption::min_consumption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::min_consumption)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE", "connection_name_1");
    db.setDatabaseName("C:/sqlite/mytestdatabase.db");
    db.open();

    table = new QSqlQueryModel;
}

min_consumption::~min_consumption()
{
    delete ui;
}

void min_consumption::on_pushButton_clicked()
{
    sign = ui->lineEdit->text();

    QString str_qry = "SELECT DISTINCT sign_of_detail, type, consumption FROM details WHERE sign_of_detail = '";
    str_qry += sign;
    str_qry += "' ORDER BY consumption";

    table->clear();
    table->setQuery(str_qry, db);
    ui->tableView->setModel(table);

}

void min_consumption::on_pushButton_2_clicked()
{
    QWidget::close();
}
