#include "mainwindow.h"
#include <QApplication>
#include<QDebug>
#include<QSqlDatabase>
#include <QCoreApplication>
bool opendatabase();
int main(int argc, char *argv[])
{
    opendatabase();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
bool opendatabase()
{
    QCoreApplication::addLibraryPath("./plugins");
    //QString path = QCoreApplication::applicationDirPath();
    QSqlDatabase mydb=QSqlDatabase::addDatabase("QSQLITE");
    //mydb.setDatabaseName("E:\\Projects\\manage\\student\\student\\student.db");//平时debug正常用
    mydb.setDatabaseName("./student.db");//release用
    if(mydb.open())
    {
        qDebug()<<"open success";
        return true;
    }
    else
    {
        qDebug()<<"open failed";
        return false;
    }
}
