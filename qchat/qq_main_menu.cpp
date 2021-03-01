#include "qq_main_menu.h"
#include "ui_qq_main_menu.h"

qq_main_menu::qq_main_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qq_main_menu)
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

    this->installEventFilter(this);

    ui->files_helper->setStyleSheet("QToolButton#files_helper{border:0px;background-color:rgb(255,255,255,0%);}"
                                    "QToolButton#files_helper:hover{border:0px;background-color:rgb(235,235,235,90%);}");
    ui->files_helper->setToolTip(u8"文件助手");
    ui->manage_com->setStyleSheet("QToolButton#manage_com{border:0px;background-color:rgb(255,255,255,0%);}"
                                  "QToolButton#manage_com:hover{border:0px;background-color:rgb(235,235,235,90%);}");
    ui->manage_com->setToolTip(u8"消息管理");
    ui->my_collect->setStyleSheet("QToolButton#my_collect{border:0px;background-color:rgb(255,255,255,0%);}"
                                  "QToolButton#my_collect:hover{border:0px;background-color:rgb(235,235,235,90%);}");
    ui->my_collect->setToolTip(u8"我的收藏");
    ui->groupBox->setStyleSheet("QGroupBox#groupBox{border:0px;background-color:rgb(255,255,255,0%);}");
    ui->groupBox_3->setStyleSheet("QGroupBox#groupBox_3{border:0px;background-color:rgb(255,255,255,0%);}");

    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right: 100;}"
                                "QPushButton#pushButton:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 100;}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(255,255,255,0%);padding-right: 110;}"
                                "QPushButton#pushButton_2:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 110;}");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right: 110;}"
                                "QPushButton#pushButton_3:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 110;}");
    ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{border:0px;background-color:rgb(255,255,255,0%);padding-right: 110;}"
                                "QPushButton#pushButton_4:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 110;}");
    ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5{border:0px;background-color:rgb(255,255,255,0%);padding-right: 27;}"
                                "QPushButton#pushButton_5:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 27;}");
    ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6{border:0px;background-color:rgb(255,255,255,0%);padding-right: 110;}"
                                "QPushButton#pushButton_6:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 110;}");
    ui->pushButton_7->setStyleSheet("QPushButton#pushButton_7{border:0px;background-color:rgb(255,255,255,0%);padding-right: 95;}"
                                "QPushButton#pushButton_7:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 95;}");
    ui->pushButton_8->setStyleSheet("QPushButton#pushButton_8{border:0px;background-color:rgb(255,255,255,0%);padding-right: 85;}"
                                "QPushButton#pushButton_8:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 85;}");
    ui->pushButton_9->setStyleSheet("QPushButton#pushButton_9{border:0px;background-color:rgb(255,255,255,0%);padding-right: 130;}"
                                "QPushButton#pushButton_9:hover{border:0px;background-color:rgb(235,235,235,90%);padding-right: 130;}");


    QIcon button_ico1(":/new/prefix1/source/files_helper.png");
    ui->files_helper->setIcon(button_ico1);
    ui->files_helper->setIconSize(QSize(28,28));
    ui->files_helper->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QIcon button_ico2(":/new/prefix1/source/manage_com.png");
    ui->manage_com->setIcon(button_ico2);
    ui->manage_com->setIconSize(QSize(28,28));
    ui->manage_com->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QIcon button_ico3(":/new/prefix1/source/my_collect.png");
    ui->my_collect->setIcon(button_ico3);
    ui->my_collect->setIconSize(QSize(28,28));
    ui->my_collect->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QIcon button_ico4(":/new/prefix1/source/exit_log.png");
    ui->pushButton_9->setIcon(button_ico4);

    ui->label->setStyleSheet("QLabel#label{border-image:url(:/new/prefix1/source/to_right.png);}");
    ui->label_2->setStyleSheet("QLabel#label_2{border-image:url(:/new/prefix1/source/to_right.png);}");
    ui->label_3->setStyleSheet("QLabel#label_3{border-image:url(:/new/prefix1/source/to_right.png);}");

    ui->label->installEventFilter(this);
    ui->label_2->installEventFilter(this);
    ui->label_3->installEventFilter(this);
    ui->pushButton->installEventFilter(this);
    ui->pushButton_2->installEventFilter(this);
    ui->pushButton_3->installEventFilter(this);

    //定时器
    vip_settings1=new vip_settings;
    timer1=new QTimer(this);
    timer2=new QTimer(this);
    timer1->setSingleShot(true);
    timer2->setSingleShot(true);
    connect(timer1, SIGNAL(timeout()), vip_settings1, SLOT(show()));
    connect(timer2, SIGNAL(timeout()), vip_settings1, SLOT(hide()));

    //信号传递显示和隐藏窗口
    vip_settings1->installEventFilter(this);
    connect(vip_settings1,SIGNAL(vip_setting_show()),this,SLOT(vip_setting_show()));
    connect(vip_settings1,SIGNAL(vip_setting_hide()),this,SLOT(vip_setting_hide()));

    security1 = new Security;
    timer3=new QTimer(this);
    timer4=new QTimer(this);
    timer3->setSingleShot(true);
    timer4->setSingleShot(true);
    connect(timer3, SIGNAL(timeout()), security1, SLOT(show()));
    connect(timer4, SIGNAL(timeout()), security1, SLOT(hide()));

    timer_hide_this = new QTimer(this);
    timer_hide_this->setSingleShot(true);
    connect(timer_hide_this, SIGNAL(timeout()), this, SLOT(hide()));

    connect(vip_settings1,SIGNAL(send_2_menu()),this,SLOT(reset_btn_color()));

    security1->installEventFilter(this);


    help_guide1 = new help_guide;
    timer5 = new QTimer(this);
    timer6 = new QTimer(this);
    timer5->setSingleShot(true);
    timer6->setSingleShot(true);
    connect(timer5, SIGNAL(timeout()), help_guide1, SLOT(show()));
    connect(timer6, SIGNAL(timeout()), help_guide1, SLOT(hide()));

    help_guide1->installEventFilter(this);

}

void qq_main_menu::vip_setting_hide()
{
    timer2->start(400);
    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right: 100;}");
}
void qq_main_menu::vip_setting_show()
{
    timer2->stop();
    vip_settings1->show();
    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(235,235,235,90%);padding-right: 100;}");
}


void qq_main_menu::reset_btn_color()
{
    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right: 100;}");
}


//事件过滤器
bool qq_main_menu::eventFilter(QObject *target, QEvent *e)
{
    if(QEvent::WindowDeactivate == e->type())//窗口停用
       {
            timer_hide_this->start(100);
          }
    if(target == ui->label||target == ui->pushButton)
    {
        if (e->type() == QEvent::Enter){
            ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(235,235,235,90%);padding-right: 100;}");
            time1_btn = ui->pushButton->mapToGlobal(ui->pushButton->pos());
            vip_settings1->move(time1_btn.x()+220,time1_btn.y()-20);
            timer1->start(400);
        }
        else if(e->type()==QEvent::Leave){
            ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right: 100;}");
            timer2->start(400);
        }
    }

    //安全
    if(target == ui->label_2||target == ui->pushButton_2)
    {
        if (e->type() == QEvent::Enter){
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(235,235,235,90%);padding-right: 110;}");
            time3_btn = ui->pushButton_2->mapToGlobal(ui->pushButton_2->pos());
            security1->move(time3_btn.x()+220,time3_btn.y()-50);
            timer3->start(400);
        }
        else if(e->type()==QEvent::Leave){
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(255,255,255,0%);padding-right: 110;}");
            timer4->start(400);
        }
    }
    if(target == security1)
    {
        if (e->type() == QEvent::Enter){
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(235,235,235,90%);padding-right: 110;}");
            time3_btn = ui->pushButton_2->mapToGlobal(ui->pushButton_2->pos());
            security1->move(time3_btn.x()+220,time3_btn.y()-50);
            timer4->stop();
            security1->show();
            //timer3->start(400);
        }
        else if(e->type()==QEvent::Leave){
            ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(255,255,255,0%);padding-right: 110;}");
            timer4->start(400);
        }
    }


   //帮助
    if(target == ui->label_3||target == ui->pushButton_3)
    {
        if (e->type() == QEvent::Enter){
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(235,235,235,90%);padding-right: 110;}");
            time5_btn = ui->pushButton_3->mapToGlobal(ui->pushButton_3->pos());
            help_guide1->move(time5_btn.x()+220,time5_btn.y()-80);
            timer5->start(400);
        }
        else if(e->type()==QEvent::Leave){
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right: 110;}");
            timer6->start(400);
        }
    }

    if (target==help_guide1)
    {
        if(e->type() == QEvent::Enter)
        {
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(235,235,235,90%);padding-right: 110;}");
            time5_btn = ui->pushButton_3->mapToGlobal(ui->pushButton_3->pos());
            help_guide1->move(time5_btn.x()+220,time5_btn.y()-80);
            timer6->stop();
            help_guide1->show();
        }
        else if (e->type() == QEvent::Leave)
        {
            ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;background-color:rgb(255,255,255,0%);padding-right: 110;}");
            timer6->start(400);
        }
        else{return QDialog::eventFilter(target, e);}
    }



    if (target==vip_settings1)
    {
        if(e->type() == QEvent::Enter)
        {
            timer2->stop();
            ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(235,235,235,90%);padding-right: 100;}");
            vip_settings1->show();
        }
        else if (e->type() == QEvent::Leave)
        {
            ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;background-color:rgb(255,255,255,0%);padding-right: 100;}");
            timer2->start(400);
        }
        else{return QDialog::eventFilter(target, e);}
    }



    return QDialog::eventFilter(target, e);
}

qq_main_menu::~qq_main_menu()
{
    delete ui;
}
