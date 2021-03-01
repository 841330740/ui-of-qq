#ifndef CHAT_BOX_H
#define CHAT_BOX_H

#include <QDialog>
#include <qDebug>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QPushButton>
#include <QLabel>
#include <QWidget>

namespace Ui {
class chat_box;
}

class chat_box : public QDialog
{
    Q_OBJECT

public:
    explicit chat_box(QWidget *parent = nullptr,QString a = "",QString b = "",QString c = "");
    ~chat_box();

    bool bPressFlag;
    QPoint beginDrag;


    QWidget* message(const QString &name,const QString &icon, const QString &message) {
        QWidget *qwidget = new QWidget(this);

        QPushButton *qqicon = new QPushButton(qwidget);    //头像
        QLabel *h1 = new QLabel(qwidget);     //名字
        QLabel *qqmessage = new QLabel(qwidget);

        //头像，qq名，qq信息，最后信息时间
        qqicon->setStyleSheet(QString("width:34px;height:34px;border:0px;border-radius:17px;border-image:url(:/new/prefix1/source/%1);").arg(icon));
        h1->setStyleSheet("background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/h1.png);");
        h1->resize(8,10);

        qqmessage->setText(message);
        qqmessage->adjustSize();
        qqmessage->resize(qqmessage->width()+30,qqmessage->height()+20);
        qqmessage->setAlignment(Qt::AlignCenter);
        qqmessage->setStyleSheet("background-color:rgb(191,191,191);border-radius:5px;");
        qqicon->move(15,10);
        h1->move(55,22);
        qqmessage->move(63,15);

        qwidget->resize(290,80);
        return qwidget;
    }

private:
    Ui::chat_box *ui;

public slots:
    void on_close_clicked();
    void on_btn_1_6_clicked();
    void mousePressEvent(QMouseEvent *e);//鼠标点击事件
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放事件
};

#endif // CHAT_BOX_H
