#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserLoginForm)
{
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->UserName->toPlainText().trimmed();
    QString password = ui->Password->text();

    if (username == "testuser" && password == "password") {
        QMessageBox::information(this, "登录成功", "欢迎, " + username + "!");
    } else {
        QMessageBox::warning(this, "登录失败", "用户名或密码错误");
        ui->Password->clear();
        ui->UserName->setFocus();
    }
}

void MainWindow::on_ExitButton_clicked()
{
    this->close();
}
