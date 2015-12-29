#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    int Line_1();
    QString Line_2();
    QString Line_3();
    QString Line_4();
    QString Line_5();
    int Line_6();
    int Line_7();
    int Line_8();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
