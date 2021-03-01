#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //主界面布局
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground); //窗口透明
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint);
    ui->login->setStyleSheet("background-color:rgb(85,170,255);border:1px solid #3C80B1;border-radius:5px;color:white;");
    //控件布局
    ui->backlabel->setStyleSheet("border-radius:5px;border-image:url(:/new/prefix1/source/4.PNG);");
    ui->toolButton_8->setStyleSheet("border-image:url(:/new/prefix1/source/51.png);");
    //ui->sculpture_label->setStyleSheet("min-width:62px;min-height:62px;max-width:62px;max-height:62px;border-radius:35px;");

    ui->login_condition->setStyleSheet("QToolButton{min-width:14px;min-height:14px;max-width:14px;max-height:14px;border-radius:7px;border:1px solid white;background-color:rgb(9,241,117);}");
    ui->login_condition->setToolTip(u8"在线状态：我在线上");
    ui->close_btn->setStyleSheet("background:transparent;");
    ui->close_btn->setToolTip(u8"关闭");

    //密码输入框
    ui->lineEdit->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(229,229,229);border-left:0px solid;border-right: 0px solid;");
    ui->lineEdit->setTextMargins(16,10,0,0);
    ui->lineEdit->setEchoMode(QLineEdit::Password);
    ui->lineEdit_2->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(229,229,229);border-left:0px solid;border-right: 0px solid;");
    ui->lineEdit_2->setTextMargins(16,10,0,0);

    ui->checkBox->setStyleSheet("QCheckBox#checkBox{color:rgb(166,166,166);}"
                                "QCheckBox#checkBox::indicator:checked{image: url(:/new/prefix1/source/checkbox_checked.png)}"
                                "QCheckBox#checkBox::indicator:unchecked{image: url(:/new/prefix1/source/checkbox_unchecked.png)}");
    ui->checkBox_2->setStyleSheet("QCheckBox#checkBox_2{color:rgb(166,166,166);}"
                                  "QCheckBox#checkBox_2::indicator:checked{image: url(:/new/prefix1/source/checkbox_checked.png)}"
                                  "QCheckBox#checkBox_2::indicator:unchecked{image: url(:/new/prefix1/source/checkbox_unchecked.png)}");

    ui->username->setStyleSheet("background:transparent;");
    ui->username->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/pointdown.png);");
    ui->password->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/keyboardgrey.png);");

    ui->label->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/QQgrey.png);");
    ui->label_2->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/suo1.png);");

    //向右移动的背景的气泡球-------------------------------------------------------------------------------------------------------------------------------
    ui->toolButton_8->setVisible(false);
    ui->register_2->setStyleSheet("background:transparent;color:rgb(166,166,166);");

    ui->pushButton->setStyleSheet("background:transparent;color:rgb(166,166,166);");
    ui->QRcode->setStyleSheet("QToolButton{background:transparent;}");

    ui->setMin->setStyleSheet("QToolButton{background:transparent;}");
    ui->setMin->setToolTip(u8"最小化");
    ui->settings->setStyleSheet("background:transparent;");
    ui->settings->setToolTip(u8"设置");

    //装载事件过滤器
    ui->close_btn->installEventFilter(this);
    ui->setMin->installEventFilter(this);
    ui->settings->installEventFilter(this);
    //ui->sculpture_label->installEventFilter(this);
    ui->toolButton_8->installEventFilter(this);
    ui->pushButton->installEventFilter(this);
    ui->password->installEventFilter(this);
    ui->register_2->installEventFilter(this);
    ui->lineEdit->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);

    //阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(12);
    ui->frame->setGraphicsEffect(shadow_effect);


    //实例化线程对象
    thread1 = new Thread1;
    connect(thread1,SIGNAL(finished()),this,SLOT(finishedThreadBtnSlot()));
    connect(thread1,SIGNAL(Signal1()),this,SLOT(post_mes()));
    //线程部分

    //传给子线程的参数信号槽
    connect(this,SIGNAL(emit2thread(QString)),thread1,SLOT(slotFunc(QString)));

    //信号槽
    connect(ui->close_btn, SIGNAL(clicked()), this, SLOT(close_win()));
    connect(ui->setMin, SIGNAL(clicked()), this, SLOT(setMin()));
    connect(ui->password,SIGNAL(clicked()),this,SLOT(set_keyboard()));
    connect(ui->login,SIGNAL(clicked()),this,SLOT(login()));

}

void MainWindow::onNewConnection()
{
    qDebug()<<u8"已建立新连接";
}


//测试函数
void MainWindow::send_messs()
{
    qDebug()<<u8"信号提交了！";
}

void MainWindow::login()
{
    this->close();
    chat_window=new qqchat_main_window();
    chat_window->show();
    chat_window->activateWindow();
}


//显示小键盘按钮
void MainWindow::set_keyboard()
{
   QString to_thrd = u8"年轻人，不讲武德。";
   emit emit2thread(to_thrd);
   thread1->start();
   qDebug()<<thread1->string1;

   keyboard1 = new keyboard() ;//将类指针实例化

   pwd_position = ui->password->mapToGlobal(ui->password->pos());
   keyboard1->move(pwd_position.x()-450,pwd_position.y()-180);
   keyboard1->show();
}

//线程结束信号槽函数
void MainWindow::finishedThreadBtnSlot()
{
    qDebug()<<u8"线程结束";
}

//线程emit信号signal1触发函数
void MainWindow::post_mes()
{
    qDebug()<<u8"线程执行中";
}

//鼠标移入
void MainWindow::enterEvent(QEvent *)
{
    //对应事件
    qDebug()<<u8"鼠标移入";
}

//鼠标移出
void MainWindow::leaveEvent(QEvent *)
{
    //对应事件
    qDebug()<<u8"鼠标移出";
}

//事件过滤器
bool MainWindow::eventFilter(QObject *target, QEvent *e)
{
    if (target==ui->close_btn)  //关闭按钮
    {if(e->type() == QEvent::Enter)
        {
            ui->close_btn->setStyleSheet("QToolButton#close_btn{background-color:rgb(255,84,57,60%);border:0px;}");
        }
        else if (e->type() == QEvent::Leave)
        {
            ui->close_btn->setStyleSheet("QToolButton#close_btn{background:transparent;}");
        }
        else if (e->type() == QEvent::MouseButtonPress)
        {
            ui->close_btn->setStyleSheet("QToolButton#close_btn{background-color:rgb(255,0,0,60%);border:0px;}");
        }
        }
    if (target==ui->setMin)   //托盘球最小化按钮
    {
        if(e->type() == QEvent::Enter)
        {
            ui->setMin->setStyleSheet("QToolButton#setMin{background-color:rgb(255,255,255,40%);border:0px;}");
        }
        else if (e->type() == QEvent::Leave)
        {
            ui->setMin->setStyleSheet("QToolButton#setMin{background:transparent;}");
        }
    }
    if (target==ui->settings)   //设置按钮
    {
        if(e->type() == QEvent::Enter)
        {
            ui->settings->setStyleSheet("QToolButton#settings{background-color:rgb(255,255,255,40%);border:0px;}");
        }
        else if (e->type() == QEvent::Leave)
        {
            ui->settings->setStyleSheet("QToolButton#settings{background:transparent;}");
        }
     }
//    if (target==ui->sculpture_label)
//    {
//        if(e->type() == QEvent::Enter)
//        {
//                ui->toolButton_8->setGeometry(280, 100, 45, 45);
//                ui->toolButton_8->setVisible(true);
//        }
//        else if (e->type() == QEvent::Leave)
//        {
//                //QThread::msleep(500);//阻塞延时50ms
//                ui->toolButton_8->setGeometry(190, 100, 45, 45);
//                ui->toolButton_8->setVisible(false);
//        }
//    }

    //鼠标在按钮的区域中时改变为手
    if(target==ui->register_2||target==ui->pushButton)
    {
        if(e->type() == QEvent::Enter)
        {
            this->setCursor(Qt::PointingHandCursor);
        }
        else if (e->type() == QEvent::Leave)
        {
            this->setCursor(Qt::ArrowCursor);
        }
    }
    //指向密码的时候变成键盘
    if(target==ui->password)
    {
        if(e->type() == QEvent::Enter)
        {
            this->setCursor(Qt::PointingHandCursor);
            ui->password->setStyleSheet("background:transparent;image: url(:/new/prefix1/source/keyboardblue.png);");
        }
        else if (e->type() == QEvent::Leave)
        {
            this->setCursor(Qt::ArrowCursor);
            ui->password->setStyleSheet("background:transparent;image: url(:/new/prefix1/source/keyboardgrey.png);");
        }
    }
    if(target==ui->lineEdit)
    {
        if(e->type()==QEvent::FocusIn)
        {
            ui->lineEdit->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(18,183,245);border-left:0px solid;border-right: 0px solid;");
            //ui->label->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/QQblue.png);");
            ui->label_2->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/suo2.png);");
        }
        else if (e->type()==QEvent::FocusOut)
                {
                    ui->lineEdit->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(229,229,229);border-left:0px solid;border-right: 0px solid;");
                    ui->label_2->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/suo1.png);");
                }
    }
    if(target==ui->lineEdit_2)
    {
        if(e->type()==QEvent::FocusIn)
        {
            ui->lineEdit_2->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(18,183,245);border-left:0px solid;border-right: 0px solid;");
            ui->label->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/QQblue.png);");
        }
        else if (e->type()==QEvent::FocusOut)
                {
                    ui->lineEdit_2->setStyleSheet("border-top:0px solid;border-bottom:1px solid rgb(229,229,229);border-left:0px solid;border-right: 0px solid;");
                    ui->label->setStyleSheet("background:transparent;image:url(:/new/prefix1/source/QQgrey.png);");
                }
    }

         else{return QMainWindow::eventFilter(target, e);}
    return QMainWindow::eventFilter(target, e);
}

//拖动窗体
//鼠标点击事件
void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        isDrag = true;
        m_position = e->globalPos() - this->pos();
        e->accept();

    }
}

//鼠标移动事件
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    if(isDrag && (e->buttons() && Qt::LeftButton))
    {
        move(e->globalPos() - m_position);
        e->accept();
    }
}

//鼠标释放事件
void MainWindow::mouseReleaseEvent(QMouseEvent *)
{
    isDrag = false;
}

//关闭按钮
void MainWindow::close_win()
{
    QApplication* app;
    app->quit();
}

//托盘球最小化
void MainWindow::setMin()
{
    //this->setWindowState(Qt::WindowMinimized);
    //隐藏程序主窗口
    this->hide();

    //新建QSystemTrayIcon对象
    mSysTrayIcon = new QSystemTrayIcon(this);
    //托盘球背景
    QIcon icon = QIcon(":/new/prefix1/source/QQblack.png");
    mSysTrayIcon->setIcon(icon);
    //当鼠标移动到托盘上的图标时，会显示此处设置的内容
    mSysTrayIcon->setToolTip(QObject::trUtf8(u8"QQ"));
    //添加槽函数连接
    connect(mSysTrayIcon,SIGNAL(activated(QSystemTrayIcon::ActivationReason)),this,SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
    //建立托盘操作的菜单
    createActions();
    createMenu();
    //在系统托盘显示此对象
    mSysTrayIcon->show();
}

//托盘菜单
void MainWindow::createActions()
{
    mShowMainAction = new QAction(QObject::trUtf8(u8"打开主面板"),this);  //不加u8乱码
    connect(mShowMainAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));

    mExitAppAction = new QAction(QObject::trUtf8(u8"退出"),this);
    connect(mExitAppAction,SIGNAL(triggered()),this,SLOT(on_exitAppAction()));

}

//菜单栏
void MainWindow::createMenu()
{
    mMenu = new QMenu(this);
    mMenu->addAction(mShowMainAction);

    mMenu->addSeparator();

    mMenu->addAction(mExitAppAction);

    mSysTrayIcon->setContextMenu(mMenu);
}

//显示主界面
void MainWindow::on_showMainAction()
{
    this->show();
    mSysTrayIcon->deleteLater();
}

//退出
void MainWindow::on_exitAppAction()
{
    exit(0);
}

//双击显示窗口
void MainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch(reason){
    case QSystemTrayIcon::Trigger:
        //单击托盘图标
        break;
    case QSystemTrayIcon::DoubleClick:
        //双击托盘图标
        //双击后显示主程序窗口
        this->show();
        mSysTrayIcon->deleteLater();    //删除图标
        break;
    default:
        break;
    }
}

//析构函数
MainWindow::~MainWindow()
{
    delete ui;
}
