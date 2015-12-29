#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql>
#include <QDebug>

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
