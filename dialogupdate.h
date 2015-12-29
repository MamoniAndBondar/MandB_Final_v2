#ifndef DIALOGUPDATE_H
#define DIALOGUPDATE_H

#include <QDialog>

namespace Ui {
class DialogUpdate;
}

class DialogUpdate : public QDialog
{
    Q_OBJECT

public:
    explicit DialogUpdate(QWidget *parent = 0);
    ~DialogUpdate();

    QString Up_1();
    QString Up_2();
    QString Up_3();

private:
    Ui::DialogUpdate *ui;
};

#endif // DIALOGUPDATE_H
