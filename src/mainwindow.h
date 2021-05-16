#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql>
#include <QSqlDatabase>
#include <QFileInfo>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFileDialog>
#include <QSqlTableModel>

#include "consumption.h"
#include "repair_details.h"
#include "min_consumption.h"
#include "total_time.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString user = "Администратор";
    QString passAdmin = "admin";
    QString passWorker = "user";
    QString currentTable = "details";
    QSqlDatabase db;
    QSqlQuery qry;
    QSqlTableModel *table;

private slots:
    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
