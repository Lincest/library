#ifndef ADMIN_CHANGE_H
#define ADMIN_CHANGE_H

#include <QMainWindow>

namespace Ui {
class admin_change;
}

class admin_change : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin_change(QWidget *parent = 0);
    ~admin_change();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_enter_clicked();

private:
    Ui::admin_change *ui;
};

#endif // ADMIN_CHANGE_H
