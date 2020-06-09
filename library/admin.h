#ifndef ADMIN_H
#define ADMIN_H
#include"admin_change.h"
#include <QMainWindow>
#include"dele.h"
namespace Ui {
class admin;
}

class admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit admin(QWidget *parent = 0);
    ~admin();
    void init();
private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_show_clicked();

    void on_pushButton_change_clicked();

    void on_pushButton_del_clicked();
    void find();

    void on_pushButton_order_clicked();

private:
    Ui::admin *ui;
    admin_change *adminc;
    dele *del;
};

#endif // ADMIN_H
