#include "student_change.h"
#include "ui_student_change.h"
#include<QSqlQueryModel>
#include<QMessageBox>
#include "admin.h"
student_change::student_change(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student_change)
{
    ui->setupUi(this);
}

student_change::~student_change()
{
    delete ui;
}

void student_change::on_pushButton_enter_clicked()
{
    QString name,number,book,date,password,passwordJudge,nameJudge,numberJudge;
    name=ui->lineEdit_name->text();
    number=ui->lineEdit_number->text();
    book=ui->lineEdit_book->text();
    date=ui->lineEdit_date->text();
    password=ui->lineEdit_password->text();
    passwordJudge=this->password;
    nameJudge=this->name;
    numberJudge=this->number;
    if(password!=passwordJudge || name!=nameJudge || number!=numberJudge)
        QMessageBox::about(NULL,"警告","信息不正确!请检查个人信息");
    else{
        QString sql2;
        QSqlQueryModel *model2=new QSqlQueryModel;
        sql2="insert into student values ('"+name+"','"+number+"','"+book+"','"+date+"','"+password+"')";
        model2->setQuery(sql2);
        admin ad;
        ad.init();
        QMessageBox::about(NULL,"提示","系统信息添加成功");
    }
    close();
}
