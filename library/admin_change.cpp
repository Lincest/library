#include "admin_change.h"
#include "ui_admin_change.h"
#include<QSqlQueryModel>
#include<QMessageBox>
#include"admin.h"
#pragma execution_character_set("utf-8")//设置中文= =
admin_change::admin_change(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin_change)
{
    ui->setupUi(this);
}

admin_change::~admin_change()
{
    delete ui;
}

void admin_change::on_pushButton_exit_clicked()
{
    close();
}

void admin_change::on_pushButton_enter_clicked()
{
    QString name,number,book,date,password;
    name=ui->lineEdit_name->text();
    number=ui->lineEdit_number->text();
    book=ui->lineEdit_book->text();
    date=ui->lineEdit_date->text();
    password=ui->lineEdit_password->text();

    if(ui->radioButton_add->isChecked())
    {
        QString sql1;
        sql1="select count (*) from student where name='"+name+"'";
        QSqlQueryModel *model1=new QSqlQueryModel;
        model1->setQuery(sql1);
        QModelIndex index1=model1->index(0,0);
        if(index1.data()!=0)
        {
            QMessageBox::about(NULL,"警告","系统中已有这位学生");
        }
        else
        {
            QString sql2;
            QSqlQueryModel *model2=new QSqlQueryModel;
            sql2="insert into student values ('"+name+"','"+number+"','"+book+"','"+date+"','"+password+"')";
            model2->setQuery(sql2);
            admin ad;
            ad.init();
            QMessageBox::about(NULL,"提示","系统信息添加成功");
        }

    }
    else if(ui->radioButton_change->isChecked())
    {
        QString sql1;
        sql1="select count (*) from student where number='"+number+"'";
        QSqlQueryModel *model1=new QSqlQueryModel;
        model1->setQuery(sql1);
        QModelIndex index1=model1->index(0,0);
        if(index1.data()==0)
        {
            QMessageBox::about(NULL,"警告","系统中没有这位学生");
        }
        else
        {
            QString sql2;
            QSqlQueryModel *model2=new QSqlQueryModel;
            sql2="update student set name ='"+name+"',book='"+book+"',date='"+date+"',password='"+password+"' where number='"+number+"'";
            model2->setQuery(sql2);
            QMessageBox::about(NULL,"提示","系统信息修改成功");
        }

    }
    else
    {
        QMessageBox::about(NULL,"警告","请选择你要进行的操作");//两个radio btn必须要选择一个
    }
}
