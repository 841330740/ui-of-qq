#include "login_condition.h"
#include "ui_login_condition.h"

login_condition::login_condition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login_condition)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground); //窗口透明
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint|Qt::WindowStaysOnTopHint);
    ui->frame->setStyleSheet("QFrame#frame{background-color:rgb(255,255,255,90%);border-radius:5px;}");

    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;padding-right: 100;}QPushButton#pushButton:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 100;}");
    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;padding-right: 115;}QPushButton#pushButton_2:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 115;}");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;padding-right: 119;}QPushButton#pushButton_3:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 119;}");
    ui->pushButton_4->setStyleSheet("QPushButton#pushButton_4{border:0px;padding-right: 119;}QPushButton#pushButton_4:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 119;}");
    ui->pushButton_5->setStyleSheet("QPushButton#pushButton_5{border:0px;padding-right: 95;}QPushButton#pushButton_5:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 95;}");
    ui->pushButton_6->setStyleSheet("QPushButton#pushButton_6{border:0px;padding-right: 119;}QPushButton#pushButton_6:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 119;}");
    ui->pushButton_7->setStyleSheet("QPushButton#pushButton_7{border:0px;padding-right: 119;}QPushButton#pushButton_7:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 119;}");
    ui->pushButton_8->setStyleSheet("QPushButton#pushButton_8{border:0px;padding-right: 53;}QPushButton#pushButton_8:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 53;}");
    ui->pushButton_9->setStyleSheet("QPushButton#pushButton_9{border:0px;padding-right: 53;}QPushButton#pushButton_9:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 53;}");
    ui->pushButton_10->setStyleSheet("QPushButton#pushButton_10{border:0px;padding-right: 53;}QPushButton#pushButton_10:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 53;}");
    ui->pushButton_11->setStyleSheet("QPushButton#pushButton_11{border:0px;padding-right: 30;}QPushButton#pushButton_11:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 30;}");
    ui->pushButton_12->setStyleSheet("QPushButton#pushButton_12{border:0px;padding-right: 70;}QPushButton#pushButton_12:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 70;}");
    ui->pushButton_13->setStyleSheet("QPushButton#pushButton_13{border:0px;padding-right: 70;}QPushButton#pushButton_13:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 70;}");
    ui->pushButton_14->setStyleSheet("QPushButton#pushButton_14{border:0px;padding-right: 60;}QPushButton#pushButton_14:hover{background-color:rgb(220,220,220,75%);border:0px;padding-right: 60;}");

    QIcon button_ico1(":/new/prefix1/source/login_now.png");
    ui->pushButton->setIconSize(QSize(15,15));
    ui->pushButton->setIcon(button_ico1);

    QIcon button_ico2(":/new/prefix1/source/smile_face.png");
    ui->pushButton_2->setIconSize(QSize(12,12));
    ui->pushButton_2->setIcon(button_ico2);

    QIcon button_ico3(":/new/prefix1/source/leave.png");
    ui->pushButton_3->setIconSize(QSize(12,12));
    ui->pushButton_3->setIcon(button_ico3);

    QIcon button_ico4(":/new/prefix1/source/busy.png");
    ui->pushButton_4->setIconSize(QSize(12,12));
    ui->pushButton_4->setIcon(button_ico4);

    QIcon button_ico5(":/new/prefix1/source/avoid.png");
    ui->pushButton_5->setIconSize(QSize(12,12));
    ui->pushButton_5->setIcon(button_ico5);

    QIcon button_ico6(":/new/prefix1/source/hide.png");
    ui->pushButton_6->setIconSize(QSize(12,12));
    ui->pushButton_6->setIcon(button_ico6);

    QIcon button_ico7(":/new/prefix1/source/logout.png");
    ui->pushButton_7->setIconSize(QSize(12,12));
    ui->pushButton_7->setIcon(button_ico7);

    QIcon button_ico8(":/new/prefix1/source/locked.png");
    ui->pushButton_11->setIconSize(QSize(16,16));
    ui->pushButton_11->setIcon(button_ico8);

    ui->frame_2->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(227,226,224);border-left:0px solid;border-right: 0px solid;");
    ui->frame_3->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(227,226,224);border-left:0px solid;border-right: 0px solid;");
    ui->frame_4->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(227,226,224);border-left:0px solid;border-right: 0px solid;");
    ui->frame_5->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(227,226,224);border-left:0px solid;border-right: 0px solid;");
    ui->frame_6->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(227,226,224);border-left:0px solid;border-right: 0px solid;");
    ui->frame_7->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(227,226,224);border-left:0px solid;border-right: 0px solid;");

    installEventFilter(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(login_em_fnc()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(chat_with_em_fnc()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(leave_em_fnc()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(busy_em_fnc()));
    connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(avoid_em_fnc()));
    connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(hide_em_fnc()));
    connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(logout_fnc()));
}

//按钮功能，发送信号
void login_condition::login_em_fnc()
{
    this->hide();
    emit login_em();
}
void login_condition::chat_with_em_fnc()
{
    this->hide();
    emit chat_with_em();
}
void login_condition::leave_em_fnc()
{
    this->hide();
    emit leave_em();
}
void login_condition::busy_em_fnc()
{
    this->hide();
    emit busy_em();
}
void login_condition::avoid_em_fnc()
{
    this->hide();
    emit avoid_em();
}
void login_condition::hide_em_fnc()
{
    this->hide();
    emit hide_em();
}
void login_condition::logout_fnc()
{
    this->hide();
    emit logout();
}


//事件过滤器
bool login_condition::eventFilter(QObject *target, QEvent *e)
{
    if(QEvent::WindowDeactivate == e->type())//窗口停用
       {
            this->hide();//或者关闭窗口
          }
    return QDialog::eventFilter(target, e);
}

//析构
login_condition::~login_condition()
{
    delete ui;
}
