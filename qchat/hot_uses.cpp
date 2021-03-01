#include "hot_uses.h"
#include "ui_hot_uses.h"

hot_uses::hot_uses(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hot_uses)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground); //窗口透明
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint|Qt::WindowStaysOnTopHint);
    ui->frame->setStyleSheet("QFrame#frame{background-color:rgb(255,255,255,90%);border-radius:5px;}");

    //阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(10);
    ui->frame->setGraphicsEffect(shadow_effect);

    ui->groupBox->setStyleSheet("QGroupBox#groupBox{border:0px;}");
    ui->groupBox_2->setStyleSheet("QGroupBox#groupBox_2{}");
    ui->groupBox_3->setStyleSheet("QGroupBox#groupBox_3{border-top:0px solid;border-bottom:1px solid rgb(220,220,220);}");
    ui->groupBox_4->setStyleSheet("QGroupBox#groupBox_4{border:0px;}");

    QIcon button_ico1(":/new/prefix1/source/red_name.png");
    ui->pushButton->setIcon(button_ico1);
    ui->pushButton->setIconSize(QSize(18,18));
    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right: 42;}"
                                  "QPushButton#pushButton:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 42;}");

    QIcon button_ico2(":/new/prefix1/source/acc_level.png");
    ui->pushButton_2->setIcon(button_ico2);
    ui->pushButton_2->setIconSize(QSize(18,18));
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(255,255,255,0%);padding-right: 28;}"
                                    "QPushButton#pushButton_2:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 28;}");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right: 20;}"
                                    "QPushButton#pushButton_3:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 20;}");

    QIcon button_ico3(":/new/prefix1/source/face_f.png");
    ui->pushButton_4->setIcon(button_ico3);
    ui->pushButton_4->setIconSize(QSize(18,18));
    ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{border:0px;background-color:rgb(255,255,255,0%);padding-right: 15;}"
                                    "QPushButton#pushButton_4:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 15;}");
    ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5{border:0px;background-color:rgb(255,255,255,0%);padding-right: 15;}"
                                    "QPushButton#pushButton_5:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 15;}");
    ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6{border:0px;background-color:rgb(255,255,255,0%);padding-right: 15;}"
                                    "QPushButton#pushButton_6:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 15;}");

    QIcon button_ico4(":/new/prefix1/source/tequan.png");
    ui->pushButton_7->setIcon(button_ico4);
    ui->pushButton_7->setIconSize(QSize(18,18));
    ui->pushButton_7->setStyleSheet("QPushButton#pushButton_7{border:0px;background-color:rgb(255,255,255,0%);padding-right: 22;}"
                                    "QPushButton#pushButton_7:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 22;}");
    ui->pushButton_8->setStyleSheet("QPushButton#pushButton_8{border:0px;background-color:rgb(255,255,255,0%);padding-right: -10;}"
                                    "QPushButton#pushButton_8:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: -10;}");
    ui->pushButton_9->setStyleSheet("QPushButton#pushButton_9{border:0px;background-color:rgb(255,255,255,0%);padding-right: 12;}"
                                    "QPushButton#pushButton_9:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 12;}");
    ui->pushButton_10->setStyleSheet("QPushButton#pushButton_10{border:0px;background-color:rgb(255,255,255,0%);padding-right: -2;}"
                                     "QPushButton#pushButton_10:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: -2;}");
    ui->pushButton_11->setStyleSheet("QPushButton#pushButton_11{border:0px;background-color:rgb(255,255,255,0%);padding-right: 10;}"
                                     "QPushButton#pushButton_11:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 10;}");
    ui->pushButton_12->setStyleSheet("QPushButton#pushButton_12{border:0px;background-color:rgb(255,255,255,0%);padding-right: 20;}"
                                     "QPushButton#pushButton_12:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 20;}");
    ui->pushButton_13->setStyleSheet("QPushButton#pushButton_13{border:0px;background-color:rgb(255,255,255,0%);padding-right: 8;}"
                                     "QPushButton#pushButton_13:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 8;}");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(btn1_sig()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(btn2_sig()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(btn3_sig()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(btn4_sig()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(btn5_sig()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(btn6_sig()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(btn7_sig()));
    connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(btn8_sig()));
    connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(btn9_sig()));
    connect(ui->pushButton_10,SIGNAL(clicked()),this,SLOT(btn10_sig()));
    connect(ui->pushButton_11,SIGNAL(clicked()),this,SLOT(btn11_sig()));
    connect(ui->pushButton_12,SIGNAL(clicked()),this,SLOT(btn12_sig()));
    connect(ui->pushButton_13,SIGNAL(clicked()),this,SLOT(btn13_sig()));
}

void hot_uses::btn1_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn2_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn3_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn4_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn5_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn6_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn7_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn8_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn9_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn10_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn11_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn12_sig()
{    this->hide();
     emit button_reset_signal();
}
void hot_uses::btn13_sig()
{    this->hide();
     emit button_reset_signal();
}

hot_uses::~hot_uses()
{
    delete ui;
}
