#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::Line_1()
{
    return ui->lineEdit->text().toInt();
}

QString Dialog::Line_2()
{
    return ui->lineEdit_2->text();
}

QString Dialog::Line_3()
{
    return ui->lineEdit_3->text();
}

QString Dialog::Line_4()
{
    return ui->lineEdit_4->text();
}

QString Dialog::Line_5()
{
    return ui->lineEdit_5->text();
}

int Dialog::Line_6()
{
    return ui->lineEdit_6->text().toInt();
}

int Dialog::Line_7()
{
    return ui->lineEdit_7->text().toInt();
}

int Dialog::Line_8()
{
    return ui->lineEdit_8->text().toInt();
}

