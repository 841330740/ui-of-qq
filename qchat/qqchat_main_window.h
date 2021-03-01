#ifndef QQCHAT_MAIN_WINDOW_H
#define QQCHAT_MAIN_WINDOW_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QDebug>
#include <setting1.h>
#include <QTimer>
#include <QPushButton>
#include <login_condition.h>
#include <weather.h>
#include <personal_document.h>
#include <qq_main_menu.h>
#include <QLabel>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QTreeWidgetItem>
#include <QHostInfo>
#include <QNetworkInterface>
#include <chat_box.h>
#include <QPainter>

namespace Ui {
class qqchat_main_window;
}

class qqchat_main_window : public QDialog
{
    Q_OBJECT

public:
    explicit qqchat_main_window(QWidget *parent = nullptr);
    ~qqchat_main_window();
    bool bPressFlag;
    QPoint beginDrag;

    QSystemTrayIcon *mSysTrayIcon1;
    QMenu *mMenu;
    QAction *mShowMainAction;
    QAction *mExitAppAction;
    setting1 *setting1_1;
    login_condition *log_condition;
    weather *qqweather;

    QPoint t_points_position;
    QPoint log_condition_btn;
    QPoint cloud_move;
    QPoint personal_move;
    QPoint qq_main_menu_btn;

    QTimer *pTimer;
    personal_document *personal_document1;
    QTimer *timer_1;
    qq_main_menu *qq_main_menu1;

private:
    Ui::qqchat_main_window *ui;

public slots:
    void close_chat(); //关闭窗口
    void set_message_index();
    void set_link_peo_index();
    void set_qzone_index();
    void mousePressEvent(QMouseEvent *e);//鼠标点击事件
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放事件
    void test();
    void log_condition_func();
    void min_qqchat();
    void show_main_menu();

    //事件过滤器
    bool eventFilter(QObject *target, QEvent *event);

    void login_change();
    void chat_me_change();
    void leave_change();
    void busy_change();
    void avoid_change();
    void hide_change();
    void logout_change();

    void index_changed(int);
    void turn_group_chat();
    void turn_friends();

    //测试
    void open_chat_window(int i,QString a,QString b,QString c,QString d);


public:
    struct User {
        bool bVIP;  // 会员
        QString strName;  // 名字
        QString strIcon;  // 图像
        QString strDesc;  // 个人说明
    }

    //列表内容
    user[3][5] =
    {
        {
            {true, u8"喜羊羊", ":/new/prefix1/source/1.jpg", u8"我是喜羊羊"},
            {true, u8"美羊羊", ":/new/prefix1/source/2.jpg", u8"我是美羊羊"},
            {true, u8"沸羊羊", ":/new/prefix1/source/3.jpg", u8"我是沸羊羊"},
            {false, u8"懒羊羊", ":/new/prefix1/source/4.jpg", u8"我是懒羊羊"},
            {false, u8"慢羊羊", ":/new/prefix1/source/5.jpg", u8"我是慢羊羊"}
        },
        {
            {true,u8"灰太狼", ":/new/prefix1/source/6.jpg", u8"我是灰太狼"},
            {true,u8"红太狼", ":/new/prefix1/source/16.jpg", u8"我是红太狼"},
            {true,u8"夜太狼", ":/new/prefix1/source/8.jpg", u8"我是夜太狼"},
            {false,u8"蕉太狼", ":/new/prefix1/source/9.jpg", u8"我是蕉太狼"},
            {false,u8"小灰灰", ":/new/prefix1/source/10.jpg", u8"我是小灰灰"}
        },
        {
            {true, u8"潇洒哥", ":/new/prefix1/source/11.jpg", u8"我是潇洒哥"},
            {true, u8"黑大帅", ":/new/prefix1/source/12.jpg", u8"我是黑大帅"},
            {false,u8"包包大人", ":/new/prefix1/source/13.jpg", u8"我是包包大人"},
            {false,u8"蛋蛋", ":/new/prefix1/source/14.jpg", u8"我是蛋蛋"},
            {false,u8"泰哥", ":/new/prefix1/source/15.jpg", u8"我是泰哥"}
        }
    };

    //QToolBox单元控件
    //水平布局【头像+竖直布局（qq昵称+个性签名）】
    QWidget* initWidget(bool bVIP, const QString &name,
                        const QString &icon, const QString &desc = "") {
        QWidget *pWidget = new QWidget(this);
        QLabel *pPixmapLabel = new QLabel(this);    //头像
        QLabel *pNameLabel = new QLabel(this);     //名字
        QLabel *pDescLabel = new QLabel(this);    //个性签名

        //pPixmapLabel->setStyleSheet("min-width:40px;min-height:40px;max-width:40px;max-height:40px;border-radius:20px;");
        // 图像 名称 描述
        pPixmapLabel->setPixmap(QPixmap(icon));
        pNameLabel->setText(name);
        pDescLabel->setText(desc);

        //vip颜色
        pNameLabel->setStyleSheet(QString("color: %1;").arg(bVIP ? "rgb(240, 30, 40)" : "black"));
        pDescLabel->setStyleSheet("color: gray;");

        //水平布局
        QHBoxLayout *HBoxLayout1 = new QHBoxLayout();
        HBoxLayout1->addWidget(pPixmapLabel);
        HBoxLayout1->addWidget(pNameLabel);
        HBoxLayout1->addWidget(pDescLabel);
        HBoxLayout1->addStretch();
        HBoxLayout1->setContentsMargins(0, 0, 0, 0);

        pWidget->setLayout(HBoxLayout1);
        return pWidget;
    }



    QPushButton* message_boxs(const QString &name,const QString &icon, const QString &message, const QString &msg_date) {
        QPushButton *qwidget = new QPushButton(this);

        QPushButton *qqicon = new QPushButton(qwidget);    //头像
        QLabel *qqname = new QLabel(qwidget);     //名字
        QLabel *qqmessage = new QLabel(qwidget);
        QLabel *msg_date_label = new QLabel(qwidget);

        //头像，qq名，qq信息，最后信息时间
        qqicon->setStyleSheet(QString("width:40px;height:40px;border:0px;border-radius:20px;border-image:url(:/new/prefix1/source/%1);").arg(icon));
        qqname->setStyleSheet("background-color:rgb(255,255,255,0%);");
        qqname->setText(name);

        qqmessage->setText(message);
        qqmessage->setStyleSheet("background-color:rgb(255,255,255,0%);color:rgb(173,173,173)");
        msg_date_label->setText(msg_date);
        msg_date_label->setStyleSheet("background-color:rgb(255,255,255,0%);");

        qqicon->move(15,10);
        qqname->move(65,15);
        qqmessage->move(65,35);
        msg_date_label->move(240,15);

        qwidget->resize(290,60);
        return qwidget;
    }

    QList<QPushButton *> qWidget_group;
};

#endif // QQCHAT_MAIN_WINDOW_H
