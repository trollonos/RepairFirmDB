#ifndef REPAIR_DETAILS_H
#define REPAIR_DETAILS_H

#include <QWidget>
#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFileDialog>
#include <QSqlTableModel>

namespace Ui {
class repair_details;
}

class repair_details : public QWidget
{
    Q_OBJECT

public:
    explicit repair_details(QWidget *parent = nullptr);
    ~repair_details();

    QSqlDatabase db;
    QSqlQueryModel *table;

    QString type = "Лист";

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::repair_details *ui;
};

#endif // REPAIR_DETAILS_H
