#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <iostream>
#include <QDebug>
#include <QObject>
#include <QMessageBox>
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->accountLabel->setGeometry(50,150,60,40);
    ui->pwdLabel->setGeometry(50,250,60,40);
    ui->accountEdit->setGeometry(100,157,260,26);
    ui->pwdEdit->setGeometry(100,257,260,26);
    ui->pwdEdit->setEchoMode(QLineEdit::Password);
    ui->loginButton->setGeometry(80,330,60,40);
    ui->quitButton->setGeometry(280,330,60,40);
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(quitClick()));
}

void MainWindow::loginClick(){
    std::cout << "点击了登录" << std::endl;
    if(MainWindow::checkInputContent()){
        LoginDialog *login = new LoginDialog(this);
        login->show();
    }else{
        QMessageBox::warning(this,QObject::tr("警告信息"),QObject::tr("出现错误，登录停止"),QMessageBox::QObject::tr("确定"));
    }
}

bool MainWindow::checkInputContent(){
    QString account = ui->accountEdit->text();
    QString password = ui->pwdEdit->text();
    if(account.length() < 10 || password.length() < 10){
        qDebug() << "账号或者密码长度不够";
        return false;
    }
    return true;
}

void MainWindow::quitClick(){
    std::cout << "点击了退出" << std::endl;
}

MainWindow::~MainWindow()
{
    delete ui;
}

