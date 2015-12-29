#include "dialogdel.h"
#include "ui_dialogdel.h"

DialogDel::DialogDel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDel)
{
    ui->setupUi(this);
}

DialogDel::~DialogDel()
{
    delete ui;
}

int DialogDel::Del()
{
    return ui->lineEdit->text().toInt();
}
