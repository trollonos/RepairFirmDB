#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE", "connection_name");
    db.setDatabaseName("D:/Qt projects/DataBaseRepairFirm/DataBaseRepairFirm/mytestdatabase.db");
    if(!db.open())
    {
        QMessageBox::critical(this, "Информация", db.lastError().text());
    }

    table = new QSqlTableModel(this, db);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    user = arg1;
}

void MainWindow::on_pushButton_clicked() // соединяемся с базой данных
{
    QString pass = ui->lineEdit->text();
    if ((user == "Администратор") && (pass == passAdmin))
    {
        ui->pushButton->setDisabled(true);
        ui->pushButton_9->setDisabled(false);

        ui->pushButton_2->setDisabled(false);
        ui->pushButton_3->setDisabled(false);
        ui->pushButton_4->setDisabled(false);

        ui->pushButton_8->setDisabled(false);
        ui->pushButton_7->setDisabled(false);
        ui->pushButton_6->setDisabled(false);
        ui->pushButton_5->setDisabled(false);

        ui->pushButton_10->setDisabled(false);
        ui->pushButton_11->setDisabled(false);
        ui->pushButton_12->setDisabled(false);

        table->setTable("details");
        table->setEditStrategy(QSqlTableModel::OnFieldChange); // Все изменения в модели таблицы автоматически применятся для изменения БД
        table->select();


        ui->tableView->setModel(table);


    }
    else if ((user == "Работник фирмы") && (pass == passWorker))
    {
        ui->pushButton->setDisabled(true);
        ui->pushButton_9->setDisabled(false);

        ui->pushButton_2->setDisabled(false);
        ui->pushButton_3->setDisabled(false);
        ui->pushButton_4->setDisabled(false);

        ui->pushButton_8->setDisabled(false);
        ui->pushButton_7->setDisabled(false);
        ui->pushButton_6->setDisabled(false);
        ui->pushButton_5->setDisabled(false);

        table->setTable("details");
        table->setEditStrategy(QSqlTableModel::OnManualSubmit); // Изменения не сохраняются
        table->select();

        ui->tableView->setModel(table);
    }
    else QMessageBox::critical(this, "Информация", "Неверный пароль. Попробуйте снова.");

}

void MainWindow::on_pushButton_9_clicked() //отсоединяемся от базы данных
{
    table->clear();

    ui->pushButton->setDisabled(false);
    ui->pushButton_9->setDisabled(true);


    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);

    ui->pushButton_8->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_5->setDisabled(true);

    ui->pushButton_10->setDisabled(true);
    ui->pushButton_11->setDisabled(true);
    ui->pushButton_12->setDisabled(true);

    if (user == "Администратор")
    {
        table->submitAll();
    }
}

void MainWindow::on_pushButton_2_clicked() // //открытие таблицы Изделия
{
    table->clear();
    table->setTable("products");
    currentTable = "products";
    if (user == "Администратор")
    {
        table->setEditStrategy(QSqlTableModel::OnFieldChange); // Все изменения в модели таблицы автоматически применятся для изменения БД
    }
    else
    {
        table->setEditStrategy(QSqlTableModel::OnManualSubmit); // Все изменения в модели таблицы автоматически применятся для изменения БД
    }
    table->select();
}

void MainWindow::on_pushButton_3_clicked() //открытие таблицы Узлы
{
    table->clear();
    table->setTable("components");
    currentTable = "components";
    if (user == "Администратор")
    {
        table->setEditStrategy(QSqlTableModel::OnFieldChange); // Все изменения в модели таблицы автоматически применятся для изменения БД
    }
    else
    {
        table->setEditStrategy(QSqlTableModel::OnManualSubmit); // Все изменения в модели таблицы автоматически применятся для изменения БД
    }
    table->select();
}

void MainWindow::on_pushButton_4_clicked() //открытие таблицы Детали
{
    table->clear();
    table->setTable("details");
    currentTable = "details";
    if (user == "Администратор")
    {
        table->setEditStrategy(QSqlTableModel::OnFieldChange); // Все изменения в модели таблицы автоматически применятся для изменения БД
    }
    else
    {
        table->setEditStrategy(QSqlTableModel::OnManualSubmit); // Все изменения в модели таблицы автоматически применятся для изменения БД
    }
    table->select();
}

void MainWindow::on_pushButton_10_clicked() //добавление строки
{
    table->insertRow(table->rowCount());
}

void MainWindow::on_pushButton_12_clicked() // применение изменений
{
    table->submitAll();
    table->select();
}

void MainWindow::on_pushButton_11_clicked() // удаление строки
{
    int rowToDelete = ui->tableView->currentIndex().row();
    if (rowToDelete >= 0)
    {
        table->removeRow(rowToDelete);
    }
    else
    {
        QMessageBox::warning(this, "Информация", "Не выбрана строка для удаления.");
    }
}

void MainWindow::on_pushButton_5_clicked() // запрос 1
{
    consumption *Q1 = new consumption();
    Q1->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    repair_details *Q2 = new repair_details();
    Q2->show();
}

void MainWindow::on_pushButton_7_clicked()
{
    min_consumption *Q3 = new min_consumption();
    Q3->show();
}

void MainWindow::on_pushButton_8_clicked()
{
    total_time *Q4 = new total_time();
    Q4->show();
}
