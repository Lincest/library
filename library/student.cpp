#include "student.h"
#include "ui_student.h"
#include<QDebug>
#include<QSqlQueryModel>
#include<QMessageBox>
#include<student_change.h>
#pragma execution_character_set("utf-8")//设置中文= =
student::student(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::student)
{
    ui->setupUi(this);

}

student::~student()
{
    delete ui;
}

void student::on_pushButton_clicked()
{
    close();
}
void student::init()
{
    qDebug()<<stuName;
    QString sql_stu;
    //sql_stu="select name as 姓名 ,number as 学号,class as 专业 ,EnterTime as 年级, GPA as 绩点,password as 密码  from student where name='"+stuName+"'";
    sql_stu = "select name as 姓名 ,number as 学号,book as 书名 ,date as 日期, password as 密码  from student where number='"+stuNumber+"'";

    QSqlQueryModel *modelx=new QSqlQueryModel;
    modelx->setQuery(sql_stu);
    ui->tableView->setModel(modelx);
}

void student::on_pushButton_borrow_clicked()
{
    student_change *studentc=new student_change;
    studentc->setPassword(stuPassword,stuName,stuNumber);
    studentc->show();
}



void student::on_pushButton_return_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QSqlQueryModel *model2=new QSqlQueryModel;
    QString name,sql,sql2,number,bookname;
    number=stuNumber;
    bookname=ui->lineEdit_bookname->text();
    sql2="select count (*) from student where number='"+number+"'and book='"+bookname+"'";
    model2->setQuery(sql2);
    QModelIndex index1=model2->index(0,0);

    if(index1.data()==0)
    {
        QMessageBox::about(NULL,"警告","并未借阅此书");
    }
    else
    {
        sql="delete from student where number='"+number+"'and book='"+bookname+"'";
        model->setQuery(sql);
        QMessageBox::about(NULL,"提示",bookname+" 还书成功");
    }
}


void student::on_pushButton_refresh_clicked()
{
    // 在用户提交借书或者还书申请后更新信息并显示
    QSqlQueryModel *model1=new QSqlQueryModel;
    QString sql1;
    sql1 = "select name as 姓名 ,number as 学号,book as 书名 ,date as 日期, password as 密码  from student where number='"+stuNumber+"'";
    model1->setQuery(sql1);
    ui->tableView->setModel(model1);
}
