#ifndef DELE_H
#define DELE_H

#include <QMainWindow>

namespace Ui {
class dele;
}

class dele : public QMainWindow
{
    Q_OBJECT

public:
    explicit dele(QWidget *parent = 0);
    ~dele();

private slots:
    void on_pushButton_exit_clicked();

    void on_pushButton_dele_clicked();

private:
    Ui::dele *ui;
};

#endif // DELE_H
