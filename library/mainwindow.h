#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"student.h"
#include <QMainWindow>
#include"admin.h"

#include<student.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_regist_clicked();

    void on_pushButton_login_clicked();


private:
    Ui::MainWindow *ui;
    student *stu;
    admin *adm;
    QString inputName;
    QString inputNumber;
    QString inputPassword;
};

#endif // MAINWINDOW_H
