#include "consumption.h"
#include "ui_consumption.h"

consumption::consumption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::consumption)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE", "connection_name_1");
    db.setDatabaseName("C:/sqlite/mytestdatabase.db");
    db.open();

    table = new QSqlQueryModel;
}

consumption::~consumption()
{
    delete ui;
}

void consumption::on_comboBox_activated(const QString &arg1)
{
    type = arg1;
}

void consumption::on_pushButton_2_clicked()
{
    sign = ui->lineEdit->text();
    component = ui->lineEdit_2->text();

    QString str_qry = "SELECT SUM(consumption) AS 'Расход материала на заменяемые детали' FROM details WHERE sign_of_detail = '";
    str_qry += sign;
    str_qry += "' AND type = '";
    str_qry += type;
    str_qry += "' AND ID_of_component =  (SELECT ID_of_component FROM components WHERE name_of_component = '";
    str_qry += component;
    str_qry += "');";

    table->clear();
    table->setQuery(str_qry, db);
    ui->tableView->setModel(table);


}

void consumption::on_pushButton_clicked()
{
    QWidget::close();
}
