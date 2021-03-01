#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QAction>
#include <QMenu>
#include <QMouseEvent>
#include <QDebug>
#include <QThread>
#include <QtCore/QString>
#include <QGraphicsDropShadowEffect>
#include <keyboard.h>
#include <register_database.h>
#include <Thread1.h>
#include <qqchat_main_window.h>
#include <QNetworkInterface>
#include <QTcpServer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSystemTrayIcon *mSysTrayIcon;
    QMenu *mMenu;
    QAction *mShowMainAction;
    QAction *mExitAppAction;
    bool isDrag;
    QPoint m_position;
    QPoint pwd_position;
    QString test_ele="test_ele";
    keyboard *keyboard1;
    qqchat_main_window *chat_window;

private:
    Ui::MainWindow *ui;
    Thread1 *thread1;

public slots:
    void close_win();     //关闭按钮
    void setMin();     //最小化按钮
    void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void createActions();
    void createMenu();
    void on_showMainAction();
    void on_exitAppAction();
    void set_keyboard();
    void finishedThreadBtnSlot();
    void post_mes();

    void mousePressEvent(QMouseEvent *e);//鼠标点击事件
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放事件

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void send_messs();
    void login();

    //事件过滤器
    bool eventFilter(QObject *target, QEvent *event);
    void onNewConnection();


signals:
    void emit2thread(QString);


};
#endif // MAINWINDOW_H
