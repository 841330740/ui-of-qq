#ifndef QQ_MAIN_MENU_H
#define QQ_MAIN_MENU_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <vip_settings.h>
#include <QTimer>
#include <hot_uses.h>
#include <QDebug>
#include <security.h>
#include <help_guide.h>

namespace Ui {
class qq_main_menu;
}

class qq_main_menu : public QDialog
{
    Q_OBJECT

public:
    explicit qq_main_menu(QWidget *parent = nullptr);
    ~qq_main_menu();

private:
    Ui::qq_main_menu *ui;

public:
    vip_settings *vip_settings1;
    QTimer *timer1;
    QTimer *timer2;
    QPoint time1_btn;
    QPoint time3_btn;
    QPoint time5_btn;
    QTimer *timer3;
    QTimer *timer4;

    QTimer *timer5;
    QTimer *timer6;

    QTimer *timer_hide_this;

    Security *security1;
    help_guide *help_guide1;



public slots:
    bool eventFilter(QObject *target, QEvent *e);
    void vip_setting_show();
    void vip_setting_hide();
    void reset_btn_color();

signals:
    void reset_color();
};

#endif // QQ_MAIN_MENU_H
