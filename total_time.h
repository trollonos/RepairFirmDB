#ifndef TOTAL_TIME_H
#define TOTAL_TIME_H

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
class total_time;
}

class total_time : public QWidget
{
    Q_OBJECT

public:
    explicit total_time(QWidget *parent = nullptr);
    ~total_time();

    QSqlDatabase db;
    QSqlQueryModel *table;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::total_time *ui;
};

#endif // TOTAL_TIME_H
