#include "vip_settings.h"
#include "ui_vip_settings.h"

vip_settings::vip_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::vip_settings)
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

    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right: 0;}"
                                "QPushButton#pushButton:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 0;}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(255,255,255,0%);padding-right: 0;}"
                                "QPushButton#pushButton_2:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 0;}");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right: 0;}"
                                "QPushButton#pushButton_3:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 0;}");
    ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{border:0px;background-color:rgb(255,255,255,0%);padding-right: 10;}"
                                "QPushButton#pushButton_4:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 10;}");

    this->installEventFilter(this);
    ui->label->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);

    QIcon button_ico1(":/new/prefix1/source/qq_vip.png");
    ui->pushButton_4->setIcon(button_ico1);
    ui->pushButton_4->setIconSize(QSize(18,18));

    ui->label->setStyleSheet("QLabel#label{border-image:url(:/new/prefix1/source/to_right.png);}");

    hot_uses1 = new hot_uses;
    hot_uses1->installEventFilter(this);
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);
    timer1->setSingleShot(true);
    timer2->setSingleShot(true);
    connect(timer1,SIGNAL(timeout()),hot_uses1,SLOT(show()));
    connect(timer2,SIGNAL(timeout()),hot_uses1,SLOT(hide()));

    connect(hot_uses1,SIGNAL(button_reset_signal()),this,SLOT(send_to_menu()));

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(hide()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(hide()));

}

void vip_settings::send_to_menu()
{
    emit send_2_menu();
}

//事件过滤器
bool vip_settings::eventFilter(QObject *target, QEvent *e)
{
    if(QEvent::WindowDeactivate == e->type())//窗口停用
           {
                this->hide();
              }
    if(target==ui->label||target==ui->pushButton_3)
    {
        if(e->type()==QEvent::Enter)
        {
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(235,235,235,90%);padding-right: 0;}");
            time1_btn = ui->pushButton_3->mapToGlobal(ui->pushButton_3->pos());
            hot_uses1->move(time1_btn.x()+156,time1_btn.y()-465);
            timer1->start(400);
        }
        else if(e->type()==QEvent::Leave)
        {
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right: 0;}");
            timer2->start(400);
        }
    }

    if(target==hot_uses1)
    {
        if(e->type()==QEvent::Enter)
        {
           timer2->stop();
           hot_uses1->show();
           emit vip_setting_show();
           ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(235,235,235,90%);padding-right: 0;}");
        }
        else if(e->type()==QEvent::Leave)
        {
            timer2->start(400);
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right: 0;}");
            emit vip_setting_hide();
        }
    }

    return QDialog::eventFilter(target, e);
    }

vip_settings::~vip_settings()
{
    delete ui;
}
