#include "repair_details.h"
#include "ui_repair_details.h"

repair_details::repair_details(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::repair_details)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE", "connection_name_1");
    db.setDatabaseName("C:/sqlite/mytestdatabase.db");
    db.open();

    table = new QSqlQueryModel;
}

repair_details::~repair_details()
{
    delete ui;
}

void repair_details::on_comboBox_activated(const QString &arg1)
{
    type = arg1;
}

void repair_details::on_pushButton_clicked()
{
    QString str_qry = "SELECT name_of_component AS [Узел], Count(ID_of_detail) AS [Кол-во изношенных деталей] FROM components LEFT JOIN details ON components.ID_of_component = details.ID_of_component WHERE type = '";
    str_qry += type;
    str_qry += "' AND percent_now >= percent_max GROUP BY name_of_component ORDER BY Count(ID_of_detail) DESC";

    table->clear();
    table->setQuery(str_qry, db);
    ui->tableView->setModel(table);
}

void repair_details::on_pushButton_2_clicked()
{
    QWidget::close();
}
