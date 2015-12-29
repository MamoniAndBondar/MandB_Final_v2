#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>
#include <QTableView>
#include "dialog.h"
#include "dialogdel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("mydatabase.sqlite");
    if (!sdb.open()) {
            qDebug() << "Что-то пошло не так! БД не подключилась!";
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QSqlTableModel model;
    model.setTable("compromising");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    ui->tableView->setModel(&model);
    ui->tableView->show();
}

void MainWindow::on_actionAdd_triggered()
{
    Dialog dlg(this);
    if (dlg.exec()==QDialog::Accepted)
    {
        qDebug() << dlg.Line_1();
        qDebug() << dlg.Line_2();
        qDebug() << dlg.Line_3();
        qDebug() << dlg.Line_4();
        qDebug() << dlg.Line_5();
        qDebug() << dlg.Line_6();
        qDebug() << dlg.Line_7();
        qDebug() << dlg.Line_8();
        QSqlQuery my_query;
        my_query.prepare("INSERT INTO my_table (ID, Family, Name, Second_Name, Sex, Age, Height, Weight)"
                                      "VALUES (:ID, :Family, :Name, :Second_Name, :Sex, :Age, :Height, :Weight);");
        my_query.bindValue(":ID", dlg.Line_1());
        my_query.bindValue(":Family", dlg.Line_2());
        my_query.bindValue(":Name", dlg.Line_3());
        my_query.bindValue(":Second_Name", dlg.Line_4());
        my_query.bindValue(":Sex", dlg.Line_5());
        my_query.bindValue(":Age", dlg.Line_6());
        my_query.bindValue(":Height", dlg.Line_7());
        my_query.bindValue(":Weight", dlg.Line_8());
        my_query.exec();
    }
}

void MainWindow::on_actionDel_triggered()
{
    DialogDel dlg(this);
    if (dlg.exec()==QDialog::Accepted)
    {
        QSqlQuery del_query;
        //del_query.prepare("DELETE FROM my_table WHERE rowid=2");

        QString str_del = "DELETE FROM my_table WHERE rowid=%1 ";
        QString str = str_del.arg(dlg.Del());
        qDebug() << str;
        bool b = del_query.exec(str);
    }
}
