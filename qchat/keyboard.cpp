#include "keyboard.h"
#include "ui_keyboard.h"

keyboard::keyboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::keyboard)
{
    ui->setupUi(this);
    setWindowFlags( Qt::Dialog|Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint|Qt::Tool);
    //this->setStyleSheet("border:3px;");
    ui->pushButton_16->setToolTip(u8"关闭");
    ui->pushButton_16->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/source/close.png);}");

    connect(ui->pushButton_16,SIGNAL(clicked()),SLOT(close_key()));
}

//拖动窗体
//鼠标点击事件
void keyboard::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        isDrag = true;
        m_position = e->globalPos() - this->pos();
        e->accept();
        //ui->frame->setVisible(false);
    }
}

//鼠标移动事件
void keyboard::mouseMoveEvent(QMouseEvent *e)
{
    if(isDrag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - m_position);
        e->accept();
    }
}

//鼠标释放事件
void keyboard::mouseReleaseEvent(QMouseEvent *)
{
    isDrag = false;
}


void keyboard::close_key()
{
    this->close();
}


keyboard::~keyboard()
{
    delete ui;
}
