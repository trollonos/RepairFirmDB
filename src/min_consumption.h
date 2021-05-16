#ifndef MIN_CONSUMPTION_H
#define MIN_CONSUMPTION_H

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
class min_consumption;
}

class min_consumption : public QWidget
{
    Q_OBJECT

public:
    explicit min_consumption(QWidget *parent = nullptr);
    ~min_consumption();

    QSqlDatabase db;
    QSqlQueryModel *table;

    QString sign;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::min_consumption *ui;
};

#endif // MIN_CONSUMPTION_H
