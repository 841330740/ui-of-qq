#include "help_guide.h"
#include "ui_help_guide.h"

help_guide::help_guide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::help_guide)
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


    ui->groupBox->setStyleSheet("QGroupBox#groupBox{border:0px;}");
    ui->groupBox_3->setStyleSheet("QGroupBox#groupBox_3{border:0px;}");

    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right: 20;}"
                                  "QPushButton#pushButton:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right: 20;}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(255,255,255,0%);padding-right: 30;}"
                                    "QPushButton#pushButton_2:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right: 30;}");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right: 30;}"
                                    "QPushButton#pushButton_3:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right: 30;}");
    ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{border:0px;background-color:rgb(255,255,255,0%);padding-right: 30;}"
                                    "QPushButton#pushButton_4:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right: 30;}");
    ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5{border:0px;background-color:rgb(255,255,255,0%);padding-right: 27;}"
                                    "QPushButton#pushButton_5:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right: 27;}");
    ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6{border:0px;background-color:rgb(255,255,255,0%);padding-right: 37;}"
                                    "QPushButton#pushButton_6:hover{border:0px;background-color:rgb(225,225,225,80%);padding-right: 37;}");

    QIcon button_ico1(":/new/prefix1/source/qq_center.png");
    ui->pushButton->setIcon(button_ico1);
    ui->pushButton->setIconSize(QSize(18,18));

    QIcon button_ico2(":/new/prefix1/source/why.png");
    ui->pushButton_2->setIcon(button_ico2);
    ui->pushButton_2->setIconSize(QSize(18,18));

    QIcon button_ico3(":/new/prefix1/source/text_line.png");
    ui->pushButton_3->setIcon(button_ico3);
    ui->pushButton_3->setIconSize(QSize(18,18));

    QIcon button_ico4(":/new/prefix1/source/send_emails.png");
    ui->pushButton_4->setIcon(button_ico4);
    ui->pushButton_4->setIconSize(QSize(18,18));

    QIcon button_ico5(":/new/prefix1/source/message_text.png");
    ui->pushButton_5->setIcon(button_ico5);
    ui->pushButton_5->setIconSize(QSize(18,18));

    QIcon button_ico6(":/new/prefix1/source/qq_index.png");
    ui->pushButton_6->setIcon(button_ico6);
    ui->pushButton_6->setIconSize(QSize(18,18));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(hide()));
}

help_guide::~help_guide()
{
    delete ui;
}
