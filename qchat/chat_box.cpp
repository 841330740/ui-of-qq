#include "chat_box.h"
#include "ui_chat_box.h"

chat_box::chat_box(QWidget *parent,QString a,QString b,QString c) :          //名字，图片名，消息
    QDialog(parent),
    ui(new Ui::chat_box)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint);
    ui->frame->setStyleSheet("QFrame#frame{background-color:rgb(255,255,255,80%);border-radius:2px;border-image:url(:/new/prefix1/source/2.png);}");
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(6);
    ui->frame->setGraphicsEffect(shadow_effect);  //应用于login按钮

    ui->btn_1_1->setStyleSheet("QPushButton#btn_1_1{border:0px;background-color:rgb(255,255,255,0%);color:rgb(255,255,255);text-align:center;font-size:14px}" "QPushButton#btn_1_1::hover{text-decoration: underline;}");
    ui->btn_1_1->setText(a);
    ui->btn_1_2->setStyleSheet("QPushButton#btn_1_2{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/qqzone.png);}");
    ui->btn_1_2->setToolTip(u8"进入QQ空间");

    ui->btn_1_3->setStyleSheet("QPushButton#btn_1_3{border:0px;background-color:rgb(255,255,255,0%);}" "QPushButton#btn_1_3::hover{background-color:rgb(255,255,255,50%);}");
    ui->btn_1_3->setToolTip(u8"窗口设置");
    ui->btn_1_4->setStyleSheet("QPushButton#btn_1_4{border:0px;background-color:rgb(255,255,255,0%);}" "QPushButton#btn_1_4::hover{background-color:rgb(255,255,255,50%);}");
    ui->btn_1_4->setToolTip(u8"最小化");
    ui->btn_1_5->setStyleSheet("QPushButton#btn_1_5{border:0px;background-color:rgb(255,255,255,0%);}" "QPushButton#btn_1_5::hover{background-color:rgb(255,255,255,50%);}");
    ui->btn_1_5->setToolTip(u8"最大化");
    ui->btn_1_6->setStyleSheet("QPushButton#btn_1_6{border:0px;background-color:rgb(255,255,255,0%);}" "QPushButton#btn_1_6::hover{background-color:rgb(255,0,0,90%);}");
    ui->btn_1_6->setToolTip(u8"关闭");

    ui->btn_2_1->setStyleSheet("QPushButton#btn_2_1{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/telephone.png);}");
    ui->btn_2_1->setToolTip(u8"发起语音通话");
    ui->btn_2_2->setStyleSheet("QPushButton#btn_2_2{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/camera_1.png);}");
    ui->btn_2_2->setToolTip(u8"发起视频通话");
    ui->btn_2_3->setStyleSheet("QPushButton#btn_2_3{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/three_points1.png);}");
    ui->btn_2_3->setToolTip(u8"更多");
    ui->btn_2_4->setStyleSheet("QPushButton#btn_2_4{border-top:1px solid rgb(204,200,193);border-bottom:0px solid;border-left:1px solid rgb(204,200,193);border-right: 0px solid;background-color:rgb(255,255,255,0%);}");

    ui->btn_3_1->setStyleSheet("QPushButton#btn_3_1{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/chat_btn1.png);}" "QPushButton#btn_3_1::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_1->setToolTip(u8"选择表情");
    ui->btn_3_2->setStyleSheet("QPushButton#btn_3_2{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/gif.png);}" "QPushButton#btn_3_2::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_2->setToolTip(u8"选择热图");
    ui->btn_3_3->setStyleSheet("QPushButton#btn_3_3{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/shears.png);}" "QPushButton#btn_3_3::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_4->setStyleSheet("QPushButton#btn_3_4{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/send_files.png);}" "QPushButton#btn_3_4::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_5->setStyleSheet("QPushButton#btn_3_5{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/tenc_word_2.png);}" "QPushButton#btn_3_5::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_5->setToolTip(u8"发送腾讯文档");
    ui->btn_3_6->setStyleSheet("QPushButton#btn_3_6{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/send_picture.png);}" "QPushButton#btn_3_6::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_7->setStyleSheet("QPushButton#btn_3_7{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/shake.png);}" "QPushButton#btn_3_7::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_7->setToolTip(u8"向好友发送窗口抖动");
    ui->btn_3_8->setStyleSheet("QPushButton#btn_3_8{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/three_points1.png);}" "QPushButton#btn_3_8::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_9->setStyleSheet("QPushButton#btn_3_9{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/largest.png);}" "QPushButton#btn_3_9::hover{background-color:rgb(200,200,200);}");
    ui->btn_3_9->setToolTip(u8"开启全屏输入");
    ui->btn_3_10->setStyleSheet("QPushButton#btn_3_10{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/clock.png);}" "QPushButton#btn_3_10::hover{background-color:rgb(200,200,200);}");

    ui->textEdit->setStyleSheet("QTextEdit#textEdit{border:0px;background-color:rgb(255,255,255,0%);}");
    ui->groupBox->setStyleSheet("QGroupBox#groupBox{background-color:rgb(255,255,255,80%);}");
    ui->groupBox_2->setStyleSheet("QGroupBox#groupBox_2{border-top:0px solid;border-bottom:1px solid rgb(204,200,193);}");

    ui->close->setStyleSheet("QPushButton#close{border-radius:2px;background-color:rgb(232,228,223);border:1px solid rgb(217,217,217);}" "QPushButton#close::hover{background-color:rgb(255,255,255);}");
    ui->send->setStyleSheet("QPushButton#send{border-top-left-radius:2px;border-bottom-left-radius:2px;background-color:rgb(132,113,85);color:white;border:1px solid rgb(217,217,217);}" "QPushButton#send::hover{background-color:rgb(174,160,139);}");
    ui->send_selections->setStyleSheet("QPushButton#send_selections{border-top-right-radius:1px;border-bottom-right-radius:2px;background-color:rgb(132,113,85);border:1px solid rgb(217,217,217);}" "QPushButton#send_selections::hover{background-color:rgb(174,160,139);}");

    QIcon button_ico1(":/new/prefix1/source/down_white.png");
    ui->btn_1_3->setIcon(button_ico1);
    ui->btn_1_3->setIconSize(QSize(14,14));
    ui->send_selections->setIcon(button_ico1);
    ui->send_selections->setIconSize(QSize(11,11));

    QIcon button_ico2(":/new/prefix1/source/get_min.png");
    ui->btn_1_4->setIcon(button_ico2);
    ui->btn_1_4->setIconSize(QSize(12,12));

    QIcon button_ico3(":/new/prefix1/source/set_max.png");
    ui->btn_1_5->setIcon(button_ico3);
    ui->btn_1_5->setIconSize(QSize(18,18));

    QIcon button_ico4(":/new/prefix1/source/man.png");
    ui->btn_2_4->setIcon(button_ico4);
    ui->btn_2_4->setIconSize(QSize(238,300));

    QIcon button_ico5(":/new/prefix1/source/qq_close.png");
    ui->btn_1_6->setIcon(button_ico5);
    ui->btn_1_6->setIconSize(QSize(12,12));

    ui->label->setStyleSheet("QLabel#label{background-color:rgb(255,255,255,0%);color:rgb(108,104,102);}");

    QWidget  *message1 = message(a,b,c);
    message1->setParent(ui->groupBox_2);
    message1->move(10,8);

}

void chat_box::on_close_clicked()
{
    this->close();
}

void chat_box::on_btn_1_6_clicked()
{
    this->close();
}

//拖动窗体
void chat_box::mousePressEvent(QMouseEvent *e)
{
    bPressFlag = true;
    beginDrag = e->pos();
    QWidget::mousePressEvent(e);
}

void chat_box::mouseReleaseEvent(QMouseEvent *e)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(e);
}

void chat_box::mouseMoveEvent(QMouseEvent *e)
{
    if(bPressFlag)
    {
        QPoint relaPos(QCursor::pos() - beginDrag);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(e);
}



chat_box::~chat_box()
{
    delete ui;
}
