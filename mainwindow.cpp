#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>
#include <QTableView>
#include "dialog.h"
#include "dialogdel.h"
#include "dialogupdate.h"

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
    /*QTableView view;
    QSqlTableModel model;
    model.setTable("my_table");
    model.select();
    model.setEditStrategy(QSqlTableModel::OnFieldChange);

    view.setModel(&model);
    view.show();
    view.setFocus();
    //ui->tableView->setModel(&model);
    //ui->tableView->show();*/

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("my_table");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Family"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));

    QTableView *view = new QTableView;
    view->setModel(model);
    //view->hidenColumn(0);
    view->show();
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

void MainWindow::on_actionUpdate_triggered()
{
    DialogUpdate dlg(this);
    if (dlg.exec()==QDialog::Accepted)
    {
        QSqlQuery up_query;

        QString str_del = "UPDATE my_table SET %1=%3 WHERE rowid=%2; ";
        QString str = str_del.arg(dlg.Up_1()).arg(dlg.Up_2()).arg(dlg.Up_3());
        qDebug() << str;
        bool b = up_query.exec(str);

    }
}
