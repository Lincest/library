#include "admin.h"
#include "ui_admin.h"
#include<QSqlQueryModel>

#pragma execution_character_set("utf-8") // 设置中文
admin::admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    init();
    connect(ui->lineEdit_findname,SIGNAL(textChanged(QString)),this,SLOT(find()));//将字符变化的事件，与某函数连接
}

admin::~admin()
{
    delete ui;
}
void admin::init()//不需要多解释
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql = "select name as 姓名 ,number as 学号,book as 书名 ,date as 日期, password as 密码  from student";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void admin::on_pushButton_exit_clicked()
{
    close();
}

void admin::on_pushButton_show_clicked()//没什么需要解释的
{
    QSqlQueryModel *model=new QSqlQueryModel;
    QString sql;
    sql = "select name as 姓名 ,number as 学号,book as 书名 ,date as 日期, password as 密码  from student";
    model->setQuery(sql);
    ui->tableView->setModel(model);
}

void admin::on_pushButton_change_clicked()
{
    adminc=new admin_change;
    adminc->show();
}

void admin::on_pushButton_del_clicked()
{
    del=new dele;
    del->show();
}
void admin::find()//需要connect函数进行连接，每当输入框文本发生变化，就执行一边这个函数，而不需要手动点击什么按钮了
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString find,sql0;
    find=ui->lineEdit_findname->text();
    sql0 = "select name as 姓名 ,number as 学号,book as 书名 ,date as 日期, password as 密码  from student where name LIKE '%"+find+"%'";
    modell->setQuery(sql0);
    ui->tableView->setModel(modell);

}
void admin::on_pushButton_order_clicked()//根据combobox显示的文字执行不同的语句
{
    QSqlQueryModel *modell=new QSqlQueryModel;
    QString find,sql0;
    sql0="select name as 姓名 ,number as 学号,book as 书名 ,date as 日期, password as 密码  from student order by date";
    modell->setQuery(sql0);
    ui->tableView->setModel(modell);
}


