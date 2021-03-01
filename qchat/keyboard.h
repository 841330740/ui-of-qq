#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QDialog>
#include <QMouseEvent>
namespace Ui {
class keyboard;
}

class keyboard : public QDialog
{
    Q_OBJECT

public:
    explicit keyboard(QWidget *parent = nullptr);
    ~keyboard();
    bool isDrag;
    QPoint m_position;

private:
    Ui::keyboard *ui;

public slots:
    void close_key();
    void mousePressEvent(QMouseEvent *e);//鼠标点击事件
    void mouseMoveEvent(QMouseEvent *e);//鼠标移动事件
    void mouseReleaseEvent(QMouseEvent *e);//鼠标释放事件

};

#endif // KEYBOARD_H
