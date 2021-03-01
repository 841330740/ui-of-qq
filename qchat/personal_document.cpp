#include "personal_document.h"
#include "ui_personal_document.h"

personal_document::personal_document(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::personal_document)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_TranslucentBackground); //窗口透明
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint);
    ui->frame->setStyleSheet("QFrame#frame{background-color:rgb(255,255,255,100%);border-radius:2px;}");

    ui->groupBox->setStyleSheet("QGroupBox#groupBox{border:0px;border-top-left-radius:2px;border-top-right-radius:2px;border-image:url(:/new/prefix1/source/3.png);}");
    ui->level_1->setStyleSheet("QPushButton#level_1{background:transparent;}");
    ui->level_2->setStyleSheet("QPushButton#level_2{background:transparent;}");
    ui->level_3->setStyleSheet("QPushButton#level_3{background:transparent;}");
    ui->level_4->setStyleSheet("QPushButton#level_4{background:transparent;}");
    ui->level_5->setStyleSheet("QPushButton#level_5{background:transparent;}");
    ui->level_6->setStyleSheet("QPushButton#level_6{background:transparent;}");
    ui->level_7->setStyleSheet("QPushButton#level_7{background:transparent;}");
    ui->level_8->setStyleSheet("QPushButton#level_8{background:transparent;}");
    ui->level_9->setStyleSheet("QPushButton#level_9{background:transparent;}");
    ui->level_10->setStyleSheet("QPushButton#level_10{background:transparent;}");
    ui->level_11->setStyleSheet("QPushButton#level_11{background:transparent;}");
    ui->level_12->setStyleSheet("QPushButton#level_12{background:transparent;}");
    ui->level_13->setStyleSheet("QPushButton#level_13{background:transparent;}");
    ui->level_14->setStyleSheet("QPushButton#level_14{background:transparent;}");

    QFont font1 ( "Microsoft YaHei", 12);
    font1.setPointSize(12); //字体大小
    ui->qq_name->setStyleSheet("QPushButton#qq_name{background:transparent;color:white;}QPushButton#qq_name:hover{background:transparent;color:white;text-decoration:underline;}");
    ui->qq_name->setFont(font1);


    QIcon button_ico_left(":/new/prefix1/source/to_left.png");
    QIcon button_ico_right(":/new/prefix1/source/to_right.png");
    ui->turn_2_left->setStyleSheet("QPushButton#turn_2_left{background:transparent;}QPushButton#turn_2_left:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->turn_2_left->setIcon(button_ico_left);
    ui->turn_2_left->setIconSize(QSize(25,25));
    ui->turn_2_right->setStyleSheet("QPushButton#turn_2_right{background:transparent;}QPushButton#turn_2_right:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->turn_2_right->setIcon(button_ico_right);
    ui->turn_2_right->setIconSize(QSize(25,25));


    QIcon button_ico_level_sun(":/new/prefix1/source/sun.png");
    QIcon button_ico_level_moon(":/new/prefix1/source/moon.png");
    QIcon button_ico_level_star(":/new/prefix1/source/star.png");
    ui->level_1->setIcon(button_ico_level_sun);
    ui->level_1->setIconSize(QSize(25,25));
    ui->level_1->setToolTip(u8"等级：59");
    ui->level_2->setIcon(button_ico_level_sun);
    ui->level_2->setIconSize(QSize(25,25));
    ui->level_2->setToolTip(u8"等级：59");
    ui->level_3->setIcon(button_ico_level_sun);
    ui->level_3->setIconSize(QSize(25,25));
    ui->level_3->setToolTip(u8"等级：59");
    ui->level_4->setIcon(button_ico_level_moon);
    ui->level_4->setIconSize(QSize(18,18));
    ui->level_4->setToolTip(u8"等级：59");
    ui->level_5->setIcon(button_ico_level_moon);
    ui->level_5->setIconSize(QSize(18,18));
    ui->level_5->setToolTip(u8"等级：59");
    ui->level_6->setIcon(button_ico_level_star);
    ui->level_6->setIconSize(QSize(16,16));
    ui->level_6->setToolTip(u8"等级：59");
    ui->level_7->setIcon(button_ico_level_star);
    ui->level_7->setIconSize(QSize(16,16));
    ui->level_7->setToolTip(u8"等级：59");
    ui->level_8->setIcon(button_ico_level_star);
    ui->level_8->setIconSize(QSize(16,16));
    ui->level_8->setToolTip(u8"等级：59");
    ui->level_9->setToolTip(u8"等级：59");
    ui->level_10->setToolTip(u8"等级：59");
    ui->level_11->setToolTip(u8"等级：59");
    ui->level_12->setToolTip(u8"等级：59");
    ui->level_13->setToolTip(u8"等级：59");
    ui->level_14->setToolTip(u8"等级：59");

    //阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(10);
    ui->frame->setGraphicsEffect(shadow_effect);

    ui->qq_name->installEventFilter(this);
    ui->level_1->installEventFilter(this);
    ui->level_2->installEventFilter(this);
    ui->level_3->installEventFilter(this);
    ui->level_4->installEventFilter(this);
    ui->level_5->installEventFilter(this);
    ui->level_6->installEventFilter(this);
    ui->level_7->installEventFilter(this);
    ui->level_8->installEventFilter(this);
    ui->level_9->installEventFilter(this);
    ui->level_10->installEventFilter(this);
    ui->level_11->installEventFilter(this);
    ui->level_12->installEventFilter(this);
    ui->level_13->installEventFilter(this);
    ui->level_14->installEventFilter(this);

    QIcon button_ico_aixin(":/new/prefix1/source/qqaixin.png");
    ui->qqaixin->setIcon(button_ico_aixin);
    ui->qqaixin->setStyleSheet("QPushButton#qqaixin{background:transparent;}QPushButton#qqaixin:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->qqaixin->setIconSize(QSize(22,22));
    ui->qqaixin->setToolTip(u8"爱心企鹅1级（行动中）");

    QIcon button_ico_ledoudaren(":/new/prefix1/source/ledoudaren.png");
    ui->ledoudaren->setIcon(button_ico_ledoudaren);
    ui->ledoudaren->setStyleSheet("QPushButton#ledoudaren{background:transparent;}QPushButton#ledoudaren:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->ledoudaren->setIconSize(QSize(15,15));
    ui->ledoudaren->setToolTip(u8"乐斗达人1级");

    QIcon button_ico_qqzone(":/new/prefix1/source/qqzone.png");
    ui->qqzone->setIcon(button_ico_qqzone);
    ui->qqzone->setStyleSheet("QPushButton#qqzone{background:transparent;}QPushButton#qqzone:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->qqzone->setIconSize(QSize(17,17));
    ui->qqzone->setToolTip(u8"QQ空间");

    QIcon button_ico_app(":/new/prefix1/source/app.png");
    ui->app_daren->setIcon(button_ico_app);
    ui->app_daren->setStyleSheet("QPushButton#app_daren{background:transparent;}QPushButton#app_daren:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->app_daren->setIconSize(QSize(17,17));
    ui->app_daren->setToolTip(u8"应用达人");

    QIcon button_ico_photos(":/new/prefix1/source/photos.png");
    ui->photos->setIcon(button_ico_photos);
    ui->photos->setStyleSheet("QPushButton#photos{background:transparent;}QPushButton#photos:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->photos->setIconSize(QSize(17,17));
    ui->photos->setToolTip(u8"QQ相册");

    QIcon button_ico_lessons(":/new/prefix1/source/lessons.png");
    ui->lessons->setIcon(button_ico_lessons);
    ui->lessons->setStyleSheet("QPushButton#lessons{background:transparent;}QPushButton#lessons:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->lessons->setIconSize(QSize(17,17));
    ui->lessons->setToolTip(u8"腾讯课堂");

    QIcon button_ico_farm(":/new/prefix1/source/farm.png");
    ui->farm->setIcon(button_ico_farm);
    ui->farm->setStyleSheet("QPushButton#farm{background:transparent;}QPushButton#farm:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->farm->setIconSize(QSize(17,17));
    ui->farm->setToolTip(u8"QQ农场");

    QIcon button_ico_camera(":/new/prefix1/source/camera.png");
    ui->camera->setIcon(button_ico_camera);
    ui->camera->setStyleSheet("QPushButton#camera{background:transparent;}QPushButton#camera:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->camera->setIconSize(QSize(17,17));
    ui->camera->setToolTip(u8"视频用户");

    QIcon button_ico_yedianzhiwang(":/new/prefix1/source/yedianzhiwang.png");
    ui->yedianzhiwang->setIcon(button_ico_yedianzhiwang);
    ui->yedianzhiwang->setStyleSheet("QPushButton#yedianzhiwang{background:transparent;}QPushButton#yedianzhiwang:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->yedianzhiwang->setIconSize(QSize(17,17));
    ui->yedianzhiwang->setToolTip(u8"新新人类");

    QIcon button_ico_lol(":/new/prefix1/source/lol.png");
    ui->lol->setIcon(button_ico_lol);
    ui->lol->setStyleSheet("QPushButton#lol{background:transparent;}QPushButton#lol:hover{background-color:rgb(225,225,225,70%);border:0px;}");
    ui->lol->setIconSize(QSize(17,17));
    ui->lol->setToolTip(u8"英雄联盟");
}

//事件过滤器
bool personal_document::eventFilter(QObject *target, QEvent *e)
{
    //鼠标样式
    if (target==ui->qq_name||target==ui->level_1||target==ui->level_2||target==ui->level_3||target==ui->level_4||target==ui->level_5||
            target==ui->level_6||target==ui->level_7||target==ui->level_8||target==ui->level_9||target==ui->level_10||target==ui->level_11
            ||target==ui->level_12||target==ui->level_12||target==ui->level_13||target==ui->level_14)
    {
        if(e->type() == QEvent::Enter)
        {
            this->setCursor(Qt::PointingHandCursor);
        }
        else if (e->type() == QEvent::Leave)
        {
            this->setCursor(Qt::ArrowCursor);
        }
        else{return QDialog::eventFilter(target, e);}
        }
    return QDialog::eventFilter(target, e);
}

personal_document::~personal_document()
{
    delete ui;
}
