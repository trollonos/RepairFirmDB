#ifndef CONSUMPTION_H
#define CONSUMPTION_H

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
class consumption;
}

class consumption : public QWidget
{
    Q_OBJECT

public:
    explicit consumption(QWidget *parent = nullptr);
    ~consumption();
    QString sign;
    QString component;
    QString type = "Лист";

    QSqlDatabase db;
    QSqlQueryModel *table;

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::consumption *ui;
};

#endif // CONSUMPTION_H
