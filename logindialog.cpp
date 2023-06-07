#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDebug>
#include <QButtonGroup>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    QButtonGroup *group = new QButtonGroup(this);
    group->addButton(ui->yuwen,1000);
    group->addButton(ui->shuxue,1001);
    group->addButton(ui->lishi,1002);
    group->addButton(ui->dili,1003);
    connect(group,SIGNAL(buttonClicked(int)),this,SLOT(recvButtonId(int)));
}

void LoginDialog::quitClick(){
    this->hide();
    qDebug() << "退出点击" ;
}

void LoginDialog::recvButtonId(int id){
    qDebug() << id;
}

LoginDialog::~LoginDialog()
{
    delete ui;
}
