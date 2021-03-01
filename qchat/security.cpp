#include "security.h"
#include "ui_security.h"

Security::Security(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Security)
{
    ui->setupUi(this);
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint|Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground); //窗口透明
    ui->frame->setStyleSheet("QFrame#frame{background-color:rgb(255,255,255,95%);border-radius:3px;}");

    //阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(10);
    ui->frame->setGraphicsEffect(shadow_effect);

    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right:40px;}"
                                  "QPushButton#pushButton:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right:40px;}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(255,255,255,0%);padding-right:20px;}"
                                    "QPushButton#pushButton_2:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right:20px;}");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right:-5px;}"
                                    "QPushButton#pushButton_3:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right:-5px;}");
    ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{border:0px;background-color:rgb(255,255,255,0%);padding-right:5px;}"
                                    "QPushButton#pushButton_4:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right:5px;}");
    ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5{border:0px;background-color:rgb(255,255,255,0%);padding-right:47px;}"
                                    "QPushButton#pushButton_5:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right:47px;}");

    QIcon button_ico1(":/new/prefix1/source/security_1.png");
    ui->pushButton->setIcon(button_ico1);
    ui->pushButton->setIconSize(QSize(18,18));

    QIcon button_ico2(":/new/prefix1/source/locked.png");
    ui->pushButton_5->setIcon(button_ico2);
    ui->pushButton_5->setIconSize(QSize(18,18));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(hide()));
}

Security::~Security()
{
    delete ui;
}
