#include "dele.h"
#include "ui_dele.h"
#include<QMessageBox>
#include<QSqlQueryModel>
#pragma execution_character_set("utf-8")//设置中文= =
dele::dele(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dele)
{
    ui->setupUi(this);
}

dele::~dele()
{
    delete ui;
}

void dele::on_pushButton_exit_clicked()
{
    close();
}

void dele::on_pushButton_dele_clicked()
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QSqlQueryModel *model2=new QSqlQueryModel;
    QString number,sql,sql2;
    number=ui->lineEdit_name->text();
    sql2="select count (*) from student where number='"+number+"'";
    model2->setQuery(sql2);
    QModelIndex index1=model2->index(0,0);

    if(index1.data()==0)
    {
        QMessageBox::about(NULL,"警告","系统中并无此人");
    }
    else
    {
        sql="delete from student where number='"+number+"'";
        model->setQuery(sql);
        QMessageBox::about(NULL,"提示","删除成功");
    }
}
