#include "dialogupdate.h"
#include "ui_dialogupdate.h"

DialogUpdate::DialogUpdate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogUpdate)
{
    ui->setupUi(this);
}

DialogUpdate::~DialogUpdate()
{
    delete ui;
}

QString DialogUpdate::Up_1()
{
    return ui->lineEdit->text();
}

QString DialogUpdate::Up_2()
{
    return ui->lineEdit_2->text();
}

QString DialogUpdate::Up_3()
{
    return ui->lineEdit_3->text();
}
