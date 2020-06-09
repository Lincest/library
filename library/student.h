#ifndef STUDENT_H
#define STUDENT_H

#include <QMainWindow>

namespace Ui {
class student;
}

class student : public QMainWindow
{
    Q_OBJECT

public:
    explicit student(QWidget *parent = 0);
    ~student();
    void init();
    QString stuName;
    QString stuNumber;
    QString stuPassword;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_borrow_clicked();

    void on_pushButton_return_clicked();

    void on_pushButton_refresh_clicked();

private:
    Ui::student *ui;

};

#endif // STUDENT_H
