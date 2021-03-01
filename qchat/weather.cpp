#include "weather.h"
#include "ui_weather.h"

weather::weather(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::weather)
{
    ui->setupUi(this);
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint);
    this->setAttribute(Qt::WA_TranslucentBackground); //窗口透明
    ui->frame->setStyleSheet("QFrame#frame{border-image:url(:/new/prefix1/source/weather.png);background-color:rgb(255,255,255,95%);border-radius:3px;}");

    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(10);
    ui->frame->setGraphicsEffect(shadow_effect);

    ui->setting_11->setStyleSheet("QPushButton#setting_11{background:transparent;border:1px solid rgb(1,0,0,0%);border-radius:2px;}QPushButton#setting_11:hover{background:transparent;background-color:rgb(255,255,255,20%);border:1px solid grey;border-radius:2px;}");

    ui->yestoday->setStyleSheet("QPushButton#yestoday{background:transparent;border:1px solid rgb(1,0,0,0%);}QPushButton#yestoday:hover{background:transparent;background-color:rgb(255,255,255,5%);border:1px solid grey;}");
    ui->today->setStyleSheet("QPushButton#today{background:transparent;border:1px solid rgb(1,0,0,0%);}QPushButton#today:hover{background:transparent;background-color:rgb(255,255,255,5%);border:1px solid grey;}");
    ui->tomorrow->setStyleSheet("QPushButton#tomorrow{background:transparent;border:1px solid rgb(1,0,0,0%);}QPushButton#tomorrow:hover{background:transparent;background-color:rgb(255,255,255,5%);border:1px solid grey;}");


}

weather::~weather()
{
    delete ui;
}
