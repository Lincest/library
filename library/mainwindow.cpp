#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QSqlQueryModel>
#include<QDebug>
#include<QMessageBox>

#pragma execution_character_set("utf-8")//设置中文= =
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stu=new student;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_exit_clicked()
{
    close();
}

void MainWindow::on_pushButton_regist_clicked()
{
    QString sql1,sql2;
    QString sql3;

    inputName=ui->lineEdit_name->text();
    inputNumber=ui->lineEdit_number->text();
    inputPassword=ui->lineEdit_password->text();
    QSqlQueryModel *model1=new QSqlQueryModel;
    sql1="select count (*) from student where number='"+inputNumber+"'"; //0 or not
    model1->setQuery(sql1);
    QModelIndex index1=model1->index(0,0);
    if(index1.data()==0 && inputPassword.size()!=0 )
    {
        QMessageBox::about(NULL,"提示","用户注册成功");
        sql3="insert into student(name,password,number) values('"+inputName+"','"+inputPassword+"','"+inputNumber+"')";
        QSqlQueryModel *model=new QSqlQueryModel;
        model->setQuery(sql3);
    }
    else if(index1.data()!=0)
    {
        QMessageBox::about(NULL,"提示","用户已经存在");
    }
}

void MainWindow::on_pushButton_login_clicked()
{
    QString sql1,sql2,sql3;

    QString inputName=ui->lineEdit_name->text();
    QString inputNumber=ui->lineEdit_number->text();
    QString inputPassword=ui->lineEdit_password->text();
    QSqlQueryModel *model1=new QSqlQueryModel;
    QSqlQueryModel *model2=new QSqlQueryModel;
    QSqlQueryModel *model3=new QSqlQueryModel;
    sql1="select count (*) from student where number='"+inputNumber+"'";
    model1->setQuery(sql1);
    QModelIndex index1=model1->index(0,0);
    sql2="select password from student where name ='"+inputName+"'";
    model2->setQuery(sql2);
    QModelIndex index2=model2->index(0,0);
    if(ui->checkBox_admin->isChecked())
    {
        if(inputName=="admin"&&inputPassword=="roccoshi")
        {
            QMessageBox::about(NULL,"提示","管理员登陆成功");
            adm=new admin;
            adm->show();

        }
        else
        {
            QMessageBox::about(NULL,"提示","学号姓名或密码错误");
        }
    }
    else
    {
        if(index1.data()!=0&&inputPassword==index2.data()){ // 检查学号与密码
            sql3="select name from student where number ='"+inputNumber+"'";
            model3->setQuery(sql3);
            QModelIndex index3=model3->index(0,0);
            if(index3.data()==inputName){   // 如果名字输入正确了
                QMessageBox::about(NULL,"提示","用户登录成功");
                stu->stuName=inputName; // 将登陆的学生信息读取出来
                stu->stuNumber=inputNumber;
                stu->stuPassword=inputPassword;
                stu->show();
                stu->init();
            //!!!!!!特别注意
            //! 构造函数会将类成员赋初值，所以必须在这里进行赋值和各种操作，而在student类中再去读取这个窗口的数据，是很难实现的
            }
            else    // 名字错误了
                QMessageBox::about(NULL,"警告","姓名与学号不匹配");
        }
        else
        {
            QMessageBox::about(NULL,"提示","学号或密码错误");

        }
    }
}

