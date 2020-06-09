#ifndef STUDENT_CHANGE_H
#define STUDENT_CHANGE_H

#include <QMainWindow>

namespace Ui {
class student_change;
}

class student_change : public QMainWindow
{
    Q_OBJECT

public:
    explicit student_change(QWidget *parent = nullptr);
    ~student_change();
    QString password;
    QString name;
    QString number;
    void setPassword(QString x, QString y,QString z){
        this->password = x;
        this->name = y;
        this->number = z;
    };

private slots:
    void on_pushButton_enter_clicked();

private:
    Ui::student_change *ui;
};

#endif // STUDENT_CHANGE_H
