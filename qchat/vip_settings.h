#ifndef VIP_SETTINGS_H
#define VIP_SETTINGS_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>
#include <hot_uses.h>
#include <QTimer>

namespace Ui {
class vip_settings;
}

class vip_settings : public QDialog
{
    Q_OBJECT

public:
    explicit vip_settings(QWidget *parent = nullptr);
    ~vip_settings();
    hot_uses *hot_uses1;
    QTimer *timer1;
    QTimer *timer2;
    QPoint time1_btn;

private:
    Ui::vip_settings *ui;

public slots:
    bool eventFilter(QObject *target, QEvent *e);
    void send_to_menu();

signals:
    void vip_setting_show();
    void vip_setting_hide();

    void send_2_menu();
};

#endif // VIP_SETTINGS_H
