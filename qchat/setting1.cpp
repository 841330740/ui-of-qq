#include "setting1.h"
#include "ui_setting1.h"

setting1::setting1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting1)
{
    ui->setupUi(this);
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint|Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground); //窗口透明
    ui->frame->setStyleSheet("QFrame#frame{background-color:rgb(255,255,255,95%);border-radius:3px;}");

    ui->my_email->setStyleSheet("QPushButton#my_email{background:transparent;padding-right: 50;}QPushButton#my_email:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 50;}");
    ui->my_shopping->setStyleSheet("QPushButton#my_shopping{background:transparent;padding-right: 50;}QPushButton#my_shopping:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 50;}");
    ui->my_purse->setStyleSheet("QPushButton#my_purse{background:transparent;padding-right: 50;}QPushButton#my_purse:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 50;}");
    ui->vip_center->setStyleSheet("QPushButton#vip_center{background:transparent;padding-right: 38;}QPushButton#vip_center:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 38;}");
    ui->dianping->setStyleSheet("QPushButton#dianping{background:transparent;padding-right: 50;}QPushButton#dianping:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 50;}");
    ui->app_center->setStyleSheet("QPushButton#app_center{background:transparent;padding-right: 50;}QPushButton#app_center:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 50;}");
    ui->layout_control->setStyleSheet("QPushButton#layout_control{background:transparent;padding-right: 38;}QPushButton#layout_control:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 38;}");


    QIcon button_ico1(":/new/prefix1/source/my_email.png");
    ui->my_email->setIcon(button_ico1);

    QIcon button_ico2(":/new/prefix1/source/myshopping.png");
    ui->my_shopping->setIcon(button_ico2);

    QIcon button_ico3(":/new/prefix1/source/my_purse.png");
    ui->my_purse->setIcon(button_ico3);

    QIcon button_ico4(":/new/prefix1/source/vip_center.png");
    ui->vip_center->setIcon(button_ico4);

    QIcon button_ico5(":/new/prefix1/source/dianping.png");
    ui->dianping->setIcon(button_ico5);

    QIcon button_ico6(":/new/prefix1/source/app_center.png");
    ui->app_center->setIcon(button_ico6);

    QIcon button_ico7(":/new/prefix1/source/layout_control.png");
    ui->layout_control->setIcon(button_ico7);
    installEventFilter(this);

    connect(ui->my_email,SIGNAL(clicked()),this,SLOT(set_email()));
    connect(ui->my_shopping,SIGNAL(clicked()),this,SLOT(set_shopping()));
    pTimer = new QTimer(this);
    connect(pTimer,SIGNAL(timeout()),this,SLOT(timer_nu()));
}

setting1::~setting1()
{
    delete ui;
}

void setting1::set_email()
{
     pTimer->start(100);
}

void setting1::set_shopping()
{
    pTimer->stop();
}

void setting1::timer_nu()
{
    qDebug()<<u8"进入";
}

//事件过滤器
bool setting1::eventFilter(QObject *target, QEvent *e)
{
    if (target==this )
    {
        if(e->type() == QEvent::Enter)
        {
               this->show();
        }
        else if (e->type() == QEvent::Leave)
        {
            this->hide();
        }
        else{return QDialog::eventFilter(target, e);}
        }

    return QDialog::eventFilter(target, e);
}
