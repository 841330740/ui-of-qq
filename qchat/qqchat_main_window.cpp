#include "qqchat_main_window.h"
#include "ui_qqchat_main_window.h"

qqchat_main_window::qqchat_main_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qqchat_main_window)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_TranslucentBackground); //窗口透明
    this->setWindowFlags (Qt::FramelessWindowHint|Qt::Tool| Qt::X11BypassWindowManagerHint|Qt::WindowStaysOnTopHint);
    ui->frame->setStyleSheet("QFrame#frame{border-image:url(:/new/prefix1/source/2.png);border-radius:2px;}");

    QIcon button_ico_qq_close(":/new/prefix1/source/qq_close.png");
    ui->close_qqchat->setIcon(button_ico_qq_close);
    ui->close_qqchat->setStyleSheet("QPushButton#close_qqchat{background:transparent;}QPushButton#close_qqchat:hover{background-color:rgb(255,0,0,50%);border:0px;}");

    QIcon button_ico_min_qqchat(":/new/prefix1/source/get_min.png");
    ui->min_qqchat->setIcon(button_ico_min_qqchat);
    ui->min_qqchat->setStyleSheet("QPushButton#min_qqchat{background:transparent;}QPushButton#min_qqchat:hover{background-color:rgb(255,255,255,50%);border:0px;}");
    ui->head_label->setStyleSheet("border-image:url(:/new/prefix1/source/qqth.png);background:transparent;");

    QIcon button_ico_q_zone(":/new/prefix1/source/qzone.png");
    ui->q_zone->setIcon(button_ico_q_zone);
    ui->q_zone->setIconSize(QSize(17,17));
    ui->q_zone->setStyleSheet("QPushButton#q_zone{background:transparent;}QPushButton#q_zone:hover{background-color:rgb(255,255,255,50%);border:0px;}");
    ui->q_zone->setToolTip(u8"QQ空间");

    QIcon button_ico_tribe(":/new/prefix1/source/tribe.png");
    ui->tribe->setIcon(button_ico_tribe);
    ui->tribe->setIconSize(QSize(20,20));
    ui->tribe->setStyleSheet("QPushButton#tribe{background:transparent;}QPushButton#tribe:hover{background-color:rgb(255,255,255,50%);border:0px;}");
    ui->tribe->setToolTip(u8"兴趣部落");

    QIcon button_ico_medal(":/new/prefix1/source/medal.png");
    ui->medal->setIcon(button_ico_medal);
    ui->medal->setIconSize(QSize(17,17));
    ui->medal->setStyleSheet("QPushButton#medal{background:transparent;}QPushButton#medal:hover{background-color:rgb(255,255,255,50%);border:0px;}");
    ui->medal->setToolTip(u8"有未领取的勋章，领取后QQ聊天更安全快捷");

    QIcon button_ico_attire(":/new/prefix1/source/attire.png");
    ui->attire->setIcon(button_ico_attire);
    ui->attire->setIconSize(QSize(17,17));
    ui->attire->setStyleSheet("QPushButton#attire{background:transparent;}QPushButton#attire:hover{background-color:rgb(255,255,255,50%);border:0px;}");
    ui->attire->setToolTip(u8"个性装扮");

    QIcon button_ico_vip(":/new/prefix1/source/VIP.png");
    ui->vip->setIcon(button_ico_vip);
    ui->vip->setStyleSheet("QPushButton#vip{background:transparent;}QPushButton#vip:hover{background-color:rgb(255,255,255,30%);border:0px;}");

    ui->cloud->setStyleSheet("QLabel#cloud{border-image:url(:/new/prefix1/source/cloud.png);background:transparent;}");
    ui->vip->setToolTip(u8"开通QQ会员尊享QQ等级最高2.0倍加速");

    ui->message_btn_down->setToolTip(u8"消息");

    ui->message_btn->setStyleSheet("QPushButton#message_btn{background-color:rgb(255,255,255);border:0px;color:rgb(139,123,106);}");
    ui->link_peo_btn->setStyleSheet("QPushButton#link_peo_btn{background-color:rgb(255,255,255);border:0px;color:rgb(169,165,162);}QPushButton#link_peo_btn:hover{background-color:rgb(255,255,255);border:0px;color:rgb(0,0,0)}");
    ui->qzone_btn->setStyleSheet("QPushButton#qzone_btn{background-color:rgb(255,255,255);border:0px;color:rgb(169,165,162);}QPushButton#qzone_btn:hover{background-color:rgb(255,255,255);border:0px;color:rgb(0,0,0)}");

    ui->qzone_btn_down->setStyleSheet("border:1px solid;border-image:url(:/new/prefix1/source/pointdown.png)");

    QIcon button_ico_t_points(":/new/prefix1/source/t_points.png");
    ui->t_points->setIcon(button_ico_t_points);
    ui->t_points->setStyleSheet("QPushButton#t_points{background:transparent;}QPushButton#t_points:hover{background-color:rgb(255,255,255,50%);border:0px;}");
    ui->close_qqchat->setToolTip(u8"关闭");
    ui->min_qqchat->setToolTip(u8"最小化");
    ui->message_box->setStyleSheet("QWidget{background-color:rgb(255,255,255)}");
    ui->link_persons->setStyleSheet("QWidget{background-color:rgb(255,255,255)}");
    ui->qzone->setStyleSheet("QWidget{background-color:rgb(255,255,255)}");
    ui->search_line->setPlaceholderText(u8"搜索");

    ui->signature->setPlaceholderText(u8"编辑个性签名");
    ui->signature->setStyleSheet("QLineEdit#signature{color:white;background:transparent;border:1px solid rgb(0,0,0,0%);}QLineEdit#signature:hover{color:white;background:transparent;border:1px solid grey;border-radius:2px;}");

    ui->search_label->setStyleSheet("QLabel{border-image:url(:/new/prefix1/source/search.png);background:transparent;}");
    ui->search->setStyleSheet("background-color:rgb(255,255,255,60%)");
    QGraphicsOpacityEffect* opacityEffect_search = new QGraphicsOpacityEffect;
    opacityEffect_search->setOpacity(0.5);
    ui->search->setGraphicsEffect(opacityEffect_search);
    ui->profile->setStyleSheet("QPushButton#profile{border-radius:25px;border-image:url(:/new/prefix1/source/profile.png);}");

    ui->log_condition->setStyleSheet("QPushButton#log_condition{border-radius:7px;background-color:rgb(0,255,0);}QPushButton#log_condition:pressed{border-radius:7px;background-color:rgb(9,241,117);}");
    ui->log_condition->setToolTip(u8"在线状态菜单\n 当前状态：我在线上\n 声音：开启\n 消息提醒框：关闭\n 会话消息：任务栏头像闪动");

    ui->search_line->setStyleSheet("background-color:rgb(255,255,255);border-top:0px solid;border-bottom:0px solid;border-left:0px solid;border-right: 0px solid;");
    QGraphicsOpacityEffect* opacityEffect_search_line = new QGraphicsOpacityEffect;
    opacityEffect_search_line->setOpacity(0.3);
    ui->search_line->setGraphicsEffect(opacityEffect_search_line);

    QIcon button_ico_main_menu(":/new/prefix1/source/main_menu.png");
    ui->main_menu->setIcon(button_ico_main_menu);
    ui->main_menu->setIconSize(QSize(20,20));
    ui->main_menu->setStyleSheet("QPushButton#main_menu{background:transparent;}QPushButton#main_menu:hover{background-color:rgb(212,207,200,50%);border:0px;}");
    ui->main_menu->setToolTip(u8"主菜单");

    QIcon button_ico_add_friends(":/new/prefix1/source/add_friends.png");
    ui->add_friends->setIcon(button_ico_add_friends);
    ui->add_friends->setIconSize(QSize(30,30));
    ui->add_friends->setStyleSheet("QPushButton#add_friends{background:transparent;}QPushButton#add_friends:hover{background-color:rgb(212,207,200,50%);border:0px;}");
    ui->add_friends->setToolTip(u8"加好友/群");

    QIcon button_ico_tenc_word(":/new/prefix1/source/tenc_word.png");
    ui->tenc_word->setIcon(button_ico_tenc_word);
    ui->tenc_word->setIconSize(QSize(20,20));
    ui->tenc_word->setStyleSheet("QPushButton#tenc_word{background:transparent;}QPushButton#tenc_word:hover{background-color:rgb(212,207,200,50%);border:0px;}");
    ui->tenc_word->setToolTip(u8"腾讯文档");

    QIcon button_ico_tenc_video(":/new/prefix1/source/tenc_video.png");
    ui->tenc_video->setIcon(button_ico_tenc_video);
    ui->tenc_video->setIconSize(QSize(20,20));
    ui->tenc_video->setStyleSheet("QPushButton#tenc_video{background:transparent;}QPushButton#tenc_video:hover{background-color:rgb(212,207,200,50%);border:0px;}");
    ui->tenc_video->setToolTip(u8"腾讯视频");

    QIcon button_ico_tenc_music(":/new/prefix1/source/tenc_music.png");
    ui->tenc_music->setIcon(button_ico_tenc_music);
    ui->tenc_music->setIconSize(QSize(20,20));
    ui->tenc_music->setStyleSheet("QPushButton#tenc_music{background:transparent;}QPushButton#tenc_music:hover{background-color:rgb(212,207,200,50%);border:0px;}");
    ui->tenc_music->setToolTip(u8"QQ音乐");

    QIcon button_ico_application(":/new/prefix1/source/application.png");
    ui->application->setIcon(button_ico_application);
    ui->application->setIconSize(QSize(20,20));
    ui->application->setStyleSheet("QPushButton#application{background:transparent;}QPushButton#application:hover{background-color:rgb(212,207,200,50%);border:0px;}");
    ui->application->setToolTip(u8"应用管理器");

    ui->frame_2->setStyleSheet("QFrame#frame_2{background-color:rgb(255,255,255)}");

    ui->label->setStyleSheet("background-color:rgb(141,125,106,80%)");
    ui->label_3->setStyleSheet("background-color:rgb(141,125,106,0%)");
    ui->label_4->setStyleSheet("background-color:rgb(141,125,106,0%)");

    QFont font1 ( "Microsoft YaHei", 12);   //字体，大小
    font1.setFamily("Microsoft YaHei"); //设置字体
    font1.setUnderline(false);   //下划线
    font1.setOverline(false);  //上划线
    font1.setPixelSize(15);   //设置字体像素大小
    font1.setBold(false);  //加粗
    font1.setItalic(false);  //斜体
    font1.setPointSize(12); //字体大小
    font1.setStrikeOut(false); //删除线
    ui->label_2->setFont(font1); //应用于label
    ui->label_2->setStyleSheet("color:white");//文本颜色

    ui->qqlevel->setStyleSheet("QPushButton#qqlevel{color:rgb(235,240,49);background:transparent;}QPushButton#qqlevel:hover{background-color:rgb(255,255,255,30%);border:0px;color:rgb(235,240,49);}");
    ui->qqlevel->setFixedSize(25,10);
    ui->qqlevel->setToolTip(u8"我的Q等级\n 等级：59级\n 剩余升级天数：8天");

    ui->message_btn_down->setStyleSheet("QPushButton#message_btn_down{border:0px;}");

    connect(ui->close_qqchat,SIGNAL(clicked()),this,SLOT(close_chat()));
    connect(ui->message_btn,SIGNAL(clicked()),this,SLOT(set_message_index()));
    connect(ui->link_peo_btn,SIGNAL(clicked()),this,SLOT(set_link_peo_index()));
    connect(ui->qzone_btn,SIGNAL(clicked()),this,SLOT(set_qzone_index()));
    connect(ui->log_condition,SIGNAL(clicked()),this,SLOT(log_condition_func()));
    connect(ui->min_qqchat,SIGNAL(clicked()),this,SLOT(min_qqchat()));

    //阴影
    QGraphicsDropShadowEffect *shadow_effect = new QGraphicsDropShadowEffect(this);
    shadow_effect->setOffset(0, 0);
    //阴影颜色
    shadow_effect->setColor(QColor(38, 78, 119, 127));
    //阴影半径
    shadow_effect->setBlurRadius(10);
    ui->frame->setGraphicsEffect(shadow_effect);

    //半透明
    QGraphicsOpacityEffect* opacityEffect1 = new QGraphicsOpacityEffect;
    opacityEffect1->setOpacity(0.8);
    ui->qzone->setGraphicsEffect(opacityEffect1);

    QGraphicsOpacityEffect* opacityEffect2 = new QGraphicsOpacityEffect;
    opacityEffect2->setOpacity(0.8);
    ui->link_persons->setGraphicsEffect(opacityEffect2);

    QGraphicsOpacityEffect* opacityEffect3 = new QGraphicsOpacityEffect;
    opacityEffect3->setOpacity(0.8);
    ui->message_box->setGraphicsEffect(opacityEffect3);

    QGraphicsOpacityEffect* opacityEffect4 = new QGraphicsOpacityEffect;
    opacityEffect4->setOpacity(0.8);
    ui->message_btn->setGraphicsEffect(opacityEffect4);
    QGraphicsOpacityEffect* opacityEffect5 = new QGraphicsOpacityEffect;
    opacityEffect5->setOpacity(0.8);
    ui->link_peo_btn->setGraphicsEffect(opacityEffect5);
    QGraphicsOpacityEffect* opacityEffect6 = new QGraphicsOpacityEffect;
    opacityEffect6->setOpacity(0.8);
    ui->qzone_btn->setGraphicsEffect(opacityEffect6);
    QGraphicsOpacityEffect* opacityEffect7 = new QGraphicsOpacityEffect;
    opacityEffect7->setOpacity(0.9);
    ui->frame_2->setGraphicsEffect(opacityEffect7);

    setting1_1 = new setting1(this);
    log_condition = new login_condition(this);
    ui->t_points->installEventFilter(this);
    ui->message_btn->installEventFilter(this);
    ui->stack_qqchat->setCurrentIndex(0);

    ui->message_btn_down->installEventFilter(this);
    ui->qzone_btn_down->installEventFilter(this);

    ui->profile->setToolTip(QStringLiteral("个人资料完整度79%，完善个人资料"));

    connect(log_condition,SIGNAL(login_em()),this,SLOT(login_change()));
    connect(log_condition,SIGNAL(chat_with_em()),this,SLOT(chat_me_change()));
    connect(log_condition,SIGNAL(leave_em()),this,SLOT(leave_change()));
    connect(log_condition,SIGNAL(busy_em()),this,SLOT(busy_change()));
    connect(log_condition,SIGNAL(avoid_em()),this,SLOT(avoid_change()));
    connect(log_condition,SIGNAL(hide_em()),this,SLOT(hide_change()));
    connect(log_condition,SIGNAL(logout()),this,SLOT(logout_change()));

    //列表结构

    //ui->listWidget->setStyleSheet("QListWidget#listWidget{border:0px;}");
    ui->cloud->installEventFilter(this);
    qqweather = new weather(this);
    qqweather->installEventFilter(this);

    pTimer = new QTimer(this);
    pTimer->setSingleShot(true);
    connect(pTimer, SIGNAL(timeout()), qqweather, SLOT(hide()));
    ui->profile->installEventFilter(this);

    timer_1=new QTimer(this);
    timer_1->setSingleShot(true);
    personal_document1 = new personal_document;
    connect(timer_1, SIGNAL(timeout()), personal_document1, SLOT(hide()));
    personal_document1->installEventFilter(this);

    qq_main_menu1 = new qq_main_menu(this);
    connect(ui->main_menu,SIGNAL(clicked()),this,SLOT(show_main_menu()));

    ui->add_friends_2->setStyleSheet("QPushButton#add_friends_2{border:0px;border-image:url(:/new/prefix1/source/plus.png);}"
                                     "QPushButton#add_friends_2:hover{border:0px;background-color:rgb(225,225,225,80%);border-radius:2px;border-image:url(:/new/prefix1/source/plus.png);}");
    ui->add_friends_2->setToolTip(u8"加好友/群");

    ui->friends_btn->setStyleSheet("QPushButton#friends_btn{border:0px;color:rgb(142,120,95);background-color:rgb(225,225,225,80%);}");
    ui->group_chat_btn->setStyleSheet("QPushButton#group_chat_btn{border:0px;color:grey;}");

    QScrollArea *m_ScrollArea = new QScrollArea(ui->friends);
    m_ScrollArea->setWidget(ui->link_people);
    m_ScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_ScrollArea->resize(290,315);
    m_ScrollArea->setStyleSheet("border:0px;");

    ui->link_people->setStyleSheet("QToolBox#link_people{background-color:rgb(255,255,255,80%);}"
                                   "QToolBox#link_people::tab{border:0px;}"
                                   );
    //设置下拉选项卡菜单
    ui->link_people->setItemText(0,u8"🐏  羊村 5/5");
    ui->link_people->setItemText(1,u8"🐺  狼堡 5/5");
    ui->link_people->setItemText(2,u8"🐘  森林 5/5");

    ui->link_people->setCurrentIndex(0);
    QIcon ico_link_people(":/new/prefix1/source/to_right.png");
    QIcon ico_link_people2(":/new/prefix1/source/to_down.png");
    ui->link_people->setItemIcon(0,ico_link_people2);
    ui->link_people->setItemIcon(1,ico_link_people);
    ui->link_people->setItemIcon(2,ico_link_people);


    QVBoxLayout *pLayout = new QVBoxLayout(ui->tool_page_1);     //垂直布局
    QVBoxLayout *pLayout2 = new QVBoxLayout(ui->tool_page_2);
    QVBoxLayout *pLayout3 = new QVBoxLayout(ui->tool_page_3);

    // 添加好友
    for (int j = 0; j < sizeof(user[0])/sizeof(user[0][0]); ++j)    //分组下朋友个数
    {
        QWidget *pWidget = initWidget(user[0][j].bVIP, user[0][j].strName,
                                      user[0][j].strIcon, user[0][j].strDesc);

        QWidget *pWidget2 = initWidget(user[1][j].bVIP, user[1][j].strName,
                                      user[1][j].strIcon, user[1][j].strDesc);

        QWidget *pWidget3 = initWidget(user[2][j].bVIP, user[2][j].strName,
                                      user[2][j].strIcon, user[2][j].strDesc);
        pLayout->addWidget(pWidget);
        pLayout2->addWidget(pWidget2);
        pLayout3->addWidget(pWidget3);
        }

    pLayout->addStretch();        //在button按钮间增加伸缩量
    pLayout2->addStretch();
    pLayout3->addStretch();
    pLayout->setSpacing(10);      //插入间距10
    pLayout2->setSpacing(10);
    pLayout3->setSpacing(10);
    pLayout->setContentsMargins(10, 10, 10, 10);    //左、上、右、下边距
    pLayout2->setContentsMargins(10, 10, 10, 10);
    pLayout3->setContentsMargins(10, 10, 10, 10);

    ui->stackedWidget->setCurrentIndex(0);

    connect(ui->link_people,SIGNAL(currentChanged(int)),this,SLOT(index_changed(int)));

    connect(ui->group_chat_btn,SIGNAL(clicked()),this,SLOT(turn_group_chat()));
    connect(ui->friends_btn,SIGNAL(clicked()),this,SLOT(turn_friends()));

    ui->group_tree->setStyleSheet("QTreeWidget#group_tree{border:0px;}QTreeWidget#group_tree::item{height:40px;}");
    QTreeWidgetItem *item1=new QTreeWidgetItem(ui->group_tree);
    QTreeWidgetItem *item2=new QTreeWidgetItem(item1);
    QTreeWidgetItem *item3=new QTreeWidgetItem(item1);
    QTreeWidgetItem *item4=new QTreeWidgetItem(item1);
    QTreeWidgetItem *item5=new QTreeWidgetItem(item1);
    QTreeWidgetItem *item6=new QTreeWidgetItem(item1);

    QIcon group_ico1(":/new/prefix1/source/19.jpg");
    QIcon group_ico2(":/new/prefix1/source/18.jpg");
    QIcon group_ico3(":/new/prefix1/source/17.jpg");
    QIcon group_ico4(":/new/prefix1/source/20.jpg");
    QIcon group_ico5(":/new/prefix1/source/21.jpg");

    ui->group_tree->setRootIsDecorated(true);
    ui->group_tree->setIconSize(QSize(50,50));
    ui->group_tree->setColumnCount(2);
    ui->group_tree->setHeaderHidden(true);
    ui->group_tree->setColumnWidth(0, 235);
    ui->group_tree->setColumnWidth(1, 30);

    item1->setText(0,u8"我的群聊 3/3");

    item2->setIcon(0,group_ico3);
    item2->setText(0,u8"羊村大队");
    item2->setTextColor(0,QColor(255,0,0));
    item2->setText(1,u8"10-29");
    item2->setTextColor(1,QColor(180,180,180));

    item3->setIcon(0,group_ico2);
    item3->setText(0,u8"狼堡敢死队");
    item3->setTextColor(0,QColor(255,0,0));
    item3->setText(1,u8"10-29");
    item3->setTextColor(1,QColor(180,180,180));

    item4->setIcon(0,group_ico1);
    item4->setText(0,u8"泰哥健美队");
    item4->setTextColor(0,QColor(255,0,0));
    item4->setText(1,u8"10-29");
    item4->setTextColor(1,QColor(180,180,180));

    item5->setIcon(0,group_ico4);
    item5->setText(0,u8"青青草原交友");
    item5->setTextColor(0,QColor(0,0,0));
    item5->setText(1,u8"10-29");
    item5->setTextColor(1,QColor(180,180,180));

    item6->setIcon(0,group_ico5);
    item6->setText(0,u8"拼多多拼单群");
    item6->setTextColor(0,QColor(0,0,0));
    item6->setText(1,u8"10-29");
    item6->setTextColor(1,QColor(180,180,180));

    ui->group_tree->addTopLevelItem(item1);

    item1->addChild(item2);
    item1->addChild(item3);
    item1->addChild(item4);
    item1->addChild(item5);
    item1->addChild(item6);
    ui->group_tree->expandAll();

    //消息列表----------------------------------------------------------------
    QStringList namelist,iconlist,meslist,timelist;
    //使用时，以下内容就可以替换为数据库中的信息。像QQ中那样则应该还需要把信息传递给服务器，信息等存储在本地，朋友的头像和其他信息等需要在服务器下载
    namelist.append(u8"喜羊羊");
    namelist.append(u8"懒羊羊");
    namelist.append(u8"慢羊羊");
    namelist.append(u8"泰哥");
    iconlist.append("1.jpg");
    iconlist.append("4.jpg");
    iconlist.append("5.jpg");
    iconlist.append("15.jpg");
    meslist.append(u8"哈哈哈哈");
    meslist.append(u8"我肚子好饿");
    meslist.append(u8"发生肾莫事了");
    meslist.append(u8"我一拳头下去就把他鼻子打骨折了");
    timelist.append("20:21");
    timelist.append("20:21");
    timelist.append("20:21");
    timelist.append("20:21");

    for (int i=0;i<4;i++)
        qWidget_group.push_back(message_boxs(namelist.at(i),iconlist.at(i),meslist.at(i),timelist.at(i))),
        qWidget_group[i]->setParent(ui->message_box),
        qWidget_group[i]->setStyleSheet("QPushButton{border:0px;}" "QPushButton::hover{background-color:rgb(235,235,235)}"),
        qWidget_group[i]->move(0,60*i),
        connect(qWidget_group[i],&QPushButton::clicked, this, [=](){open_chat_window(i,namelist.at(i),iconlist.at(i),meslist.at(i),timelist.at(i));});

    QIcon btn_ico1(":/new/prefix1/source/to_down.png");
    ui->pushButton->setIcon(btn_ico1);
    ui->pushButton->setIconSize(QSize(12,12));
    ui->pushButton->setStyleSheet("QPushButton#pushButton{border:0px;text-align:left;}" "QPushButton#pushButton::hover{text-decoration:underline;}");
    ui->pushButton->setText(u8"好友动态");

    ui->pushButton_2->setStyleSheet("QPushButton#pushButton_2{border:0px;background-color:rgb(255,255,255,0%);border-image:url(:/new/prefix1/source/fresh_2.png);}" "QPushButton#pushButton_2::hover{border-image:url(:/new/prefix1/source/fresh.png);}");

    ui->textEdit->setStyleSheet("QTextEdit#textEdit{border:1px solid rgb(222,217,210);}");
    ui->textEdit->setPlaceholderText(u8"说点什么吧...");

    ui->label_5->setStyleSheet("QLabel#label_5{border-radius:20px;border-image:url(:/new/prefix1/source/3.jpg);}");
    ui->label_5->setText("");
    ui->pushButton_3->setStyleSheet("QPushButton#pushButton_3{border:0px;text-align:left;}" "QPushButton#pushButton_3::hover{text-decoration:underline}");  //"QLabel#label_6{border:0px;text-align:left;}"
    ui->label_7->setStyleSheet("QLabel#label_7{color:rgb(128,128,128);}");
    ui->label_13->setStyleSheet("QLabel#label_13{color:rgb(44,88,131);}");
    ui->label_9->setStyleSheet("QLabel#label_9{color:rgb(128,128,128);}");

    ui->label_10->setStyleSheet("QLabel#label_10{border:0px;border-image:url(:/new/prefix1/source/up2.png);}" "QLabel#label_10::hover{border-image:url(:/new/prefix1/source/up1.png);}");
    ui->label_10->setText("");
    ui->label_11->setStyleSheet("QLabel#label_11{border:0px;border-image:url(:/new/prefix1/source/comment2.png);}" "QLabel#label_11::hover{border-image:url(:/new/prefix1/source/comment1.png);}");
    ui->label_11->setText("");
    ui->label_12->setStyleSheet("QLabel#label_12{border:0px;border-image:url(:/new/prefix1/source/share2.png);}" "QLabel#label_12::hover{border-image:url(:/new/prefix1/source/share1.png);} ");
    ui->label_12->setText("");

    ui->label_6->setStyleSheet("background-color:rgb(221,216,210);");
    ui->label_6->setText("");

    ui->label_14->setStyleSheet("QLabel#label_14{border:0px;border-image:url(:/new/prefix1/source/up3.png);}");
    ui->label_14->setText("");

    ui->label_15->setStyleSheet("QLabel#label_15{color:rgb(44,88,131);}");
    ui->label_15->setText(u8"喜羊羊、灰太狼");

    ui->label_17->setStyleSheet("QLabel#label_17{color:rgb(44,88,131);}");

    ui->label_16->setText(u8"觉得很赞");
    ui->label_18->setText(u8"怕了。");

    ui->textEdit_2->setStyleSheet("QTextEdit#textEdit_2{border:1px solid rgb(222,217,210);}");
    ui->textEdit_2->setPlaceholderText(u8"我也说一句");
}

//调起消息列表----------------------------------------
void qqchat_main_window::open_chat_window(int i,QString a,QString b,QString c,QString d)
//位置  喜羊羊  图片名  最后消息   最后时间
{
    chat_box *chat_box1 = new chat_box(this,a,b,c);
    chat_box1->move(300,300);
    chat_box1->show();
}
//--------------------------------------------------
void qqchat_main_window::turn_friends()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->friends_btn->setStyleSheet("QPushButton#friends_btn{border:0px;color:rgb(142,120,95);background-color:rgb(225,225,225,80%);}");
    ui->group_chat_btn->setStyleSheet("QPushButton#group_chat_btn{border:0px;color:grey;}");
}

void qqchat_main_window:: turn_group_chat()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->group_chat_btn->setStyleSheet("QPushButton#group_chat_btn{border:0px;color:rgb(142,120,95);background-color:rgb(225,225,225,80%);}");
    ui-> friends_btn->setStyleSheet("QPushButton#friends_btn{border:0px;color:grey;}");
}

//QToolBox切页
void qqchat_main_window::index_changed(int index)
{
    QIcon ico_link_people(":/new/prefix1/source/to_right.png");
    QIcon ico_link_people2(":/new/prefix1/source/to_down.png");
    ui->link_people->setItemIcon(0,ico_link_people);
    ui->link_people->setItemIcon(1,ico_link_people);
    ui->link_people->setItemIcon(2,ico_link_people);
    ui->link_people->setItemIcon(index,ico_link_people2);
}

//显示主菜单按钮
void qqchat_main_window::show_main_menu()
{
    qq_main_menu_btn = ui->main_menu->mapToGlobal(ui->main_menu->pos());
    qq_main_menu1->move(qq_main_menu_btn.x()-27,qq_main_menu_btn.y()-392);
    qq_main_menu1->show();
    qq_main_menu1->activateWindow();
}

//最小化按钮
void qqchat_main_window::min_qqchat()
{
    qDebug()<<u8"最小化";
}

void qqchat_main_window::login_change()  //我在线上
{
    QIcon button_ico_log_condition("");
    ui->log_condition->setIcon(button_ico_log_condition);
    ui->log_condition->setStyleSheet("QPushButton#log_condition{border-radius:7px;background-color:rgb(0,255,0);}QPushButton#log_condition:pressed{border-radius:7px;background-color:rgb(9,241,117);}");
    ui->log_condition->setToolTip(u8"在线状态菜单\n 当前状态：我在线上\n 声音：开启\n 消息提醒框：关闭\n 会话消息：任务栏头像闪动");
}
void qqchat_main_window::chat_me_change()   //Q我吧
{
    QIcon button_ico_log_condition(":/new/prefix1/source/smile_face.png");
    ui->log_condition->setIcon(button_ico_log_condition);
    ui->log_condition->setIconSize(QSize(14,14));
    ui->log_condition->setStyleSheet("QPushButton#log_condition{border-radius:7px;}");
    ui->log_condition->setToolTip(u8"在线状态菜单\n 当前状态：Q我吧\n 声音：开启\n 消息提醒框：关闭\n 会话消息：自动弹出会话窗口");
}
void qqchat_main_window::leave_change()   //离开
{
    QIcon button_ico_log_condition(":/new/prefix1/source/leave.png");
    ui->log_condition->setIcon(button_ico_log_condition);
    ui->log_condition->setIconSize(QSize(14,14));
    ui->log_condition->setStyleSheet("QPushButton#log_condition{border-radius:7px;}");
    ui->log_condition->setToolTip(u8"在线状态菜单\n 当前状态：离开\n 声音：开启\n 消息提醒框：关闭\n 会话消息：任务栏头像闪动");
}
void qqchat_main_window::busy_change()     //忙碌
{
    QIcon button_ico_log_condition(":/new/prefix1/source/busy.png");
    ui->log_condition->setIcon(button_ico_log_condition);
    ui->log_condition->setIconSize(QSize(14,14));
    ui->log_condition->setStyleSheet("QPushButton#log_condition{border-radius:7px;}");
    ui->log_condition->setToolTip(u8"在线状态菜单\n 当前状态：忙碌\n 声音：开启\n 消息提醒框：关闭\n 会话消息：任务栏显示气泡");
}
void qqchat_main_window::avoid_change()     //请勿打扰
{
    QIcon button_ico_log_condition(":/new/prefix1/source/avoid.png");
    ui->log_condition->setIcon(button_ico_log_condition);
    ui->log_condition->setIconSize(QSize(14,14));
    ui->log_condition->setStyleSheet("QPushButton#log_condition{border-radius:7px;}");
    ui->log_condition->setToolTip(u8"在线状态菜单\n 当前状态：请勿打扰\n 声音：开启\n 消息提醒框：关闭\n 会话消息：任务栏显示气泡");
}
void qqchat_main_window::hide_change()     //隐身
{
    QIcon button_ico_log_condition(":/new/prefix1/source/hide.png");
    ui->log_condition->setIcon(button_ico_log_condition);
    ui->log_condition->setIconSize(QSize(14,14));
    ui->log_condition->setStyleSheet("QPushButton#log_condition{border-radius:7px;}QPushButton#log_condition:pressed{border-radius:7px;background-color:rgb(9,241,117);}");
    ui->log_condition->setToolTip(u8"在线状态菜单\n 当前状态：隐身\n 声音：开启\n 消息提醒框：关闭\n 会话消息：任务栏头像闪动");
}
void qqchat_main_window::logout_change()     //离线
{
    QIcon button_ico_log_condition(":/new/prefix1/source/logout.png");
    ui->log_condition->setIcon(button_ico_log_condition);
    ui->log_condition->setIconSize(QSize(14,14));
    ui->log_condition->setStyleSheet("QPushButton#log_condition{border-radius:7px;}QPushButton#log_condition:pressed{border-radius:7px;background-color:rgb(9,241,117);}");
    ui->log_condition->setToolTip("");
}

//StackWidget切页按钮
void qqchat_main_window:: set_message_index()
{
    ui->stack_qqchat->setCurrentIndex(0);
    ui->message_btn_down->show();
    ui->label->setStyleSheet("background-color:rgb(141,125,106,80%)");
    ui->label_3->setStyleSheet("background-color:rgb(141,125,106,0%)");
    ui->label_4->setStyleSheet("background-color:rgb(141,125,106,0%)");
    ui->message_btn->setStyleSheet("QPushButton#message_btn{background-color:rgb(255,255,255);border:0px;color:rgb(139,123,106);}");
    ui->link_peo_btn->setStyleSheet("QPushButton#link_peo_btn{background-color:rgb(255,255,255);border:0px;color:rgb(169,165,162);}QPushButton#link_peo_btn:hover{background-color:rgb(255,255,255);border:0px;color:rgb(0,0,0)}");
    ui->qzone_btn->setStyleSheet("QPushButton#qzone_btn{background-color:rgb(255,255,255);border:0px;color:rgb(169,165,162);}QPushButton#qzone_btn:hover{background-color:rgb(255,255,255);border:0px;color:rgb(0,0,0)}");
}
void qqchat_main_window::set_link_peo_index()
{
    ui->stack_qqchat->setCurrentIndex(1);
    ui->message_btn_down->hide();
    ui->label->setStyleSheet("background-color:rgb(141,125,106,0%)");
    ui->label_3->setStyleSheet("background-color:rgb(141,125,106,80%)");
    ui->label_4->setStyleSheet("background-color:rgb(141,125,106,0%)");
    ui->message_btn->setStyleSheet("QPushButton#message_btn{background-color:rgb(255,255,255);border:0px;color:rgb(169,165,162);}QPushButton#message_btn:hover{background-color:rgb(255,255,255);border:0px;color:rgb(0,0,0)}");
    ui->link_peo_btn->setStyleSheet("QPushButton#link_peo_btn{background-color:rgb(255,255,255);border:0px;color:rgb(139,123,106);}");
    ui->qzone_btn->setStyleSheet("QPushButton#qzone_btn{background-color:rgb(255,255,255);border:0px;color:rgb(169,165,162);}QPushButton#qzone_btn:hover{background-color:rgb(255,255,255);border:0px;color:rgb(0,0,0)}");
}
void qqchat_main_window::set_qzone_index()
{
    ui->stack_qqchat->setCurrentIndex(2);
    ui->message_btn_down->hide();
    ui->label->setStyleSheet("background-color:rgb(141,125,106,0%)");
    ui->label_3->setStyleSheet("background-color:rgb(141,125,106,0%)");
    ui->label_4->setStyleSheet("background-color:rgb(141,125,106,80%)");
    ui->message_btn->setStyleSheet("QPushButton#message_btn{background-color:rgb(255,255,255);border:0px;color:rgb(169,165,162);}QPushButton#message_btn:hover{background-color:rgb(255,255,255);border:0px;color:rgb(0,0,0)}");
    ui->link_peo_btn->setStyleSheet("QPushButton#link_peo_btn{background-color:rgb(255,255,255);border:0px;color:rgb(169,165,162);}QPushButton#link_peo_btn:hover{background-color:rgb(255,255,255);border:0px;color:rgb(0,0,0)}");
    ui->qzone_btn->setStyleSheet("QPushButton#qzone_btn{background-color:rgb(255,255,255);border:0px;color:rgb(139,123,106);}");
}

void qqchat_main_window:: test()
{
    this->hide();
}

//登录状态下拉框
void qqchat_main_window::log_condition_func()
{
    log_condition_btn = ui->log_condition->mapToGlobal(ui->log_condition->pos());
    log_condition->move(log_condition_btn.x()-70,log_condition_btn.y()-70);
    log_condition->show();
    log_condition->activateWindow();
}

//事件过滤器
bool qqchat_main_window::eventFilter(QObject *target, QEvent *e)
{

    if (target==ui->t_points )
    {
        if(e->type() == QEvent::Enter)
        {
               t_points_position = ui->t_points->mapToGlobal(ui->t_points->pos());
               setting1_1->move(t_points_position.x()-320,t_points_position.y()+15);
               setting1_1->show();
        }
        else if (e->type() == QEvent::Leave)
        {
            setting1_1->hide();
        }
        else{return QDialog::eventFilter(target, e);}
        }


    if (target==ui->message_btn )
    {
        if(e->type() == QEvent::Enter)
        {
            ui->message_btn_down->setStyleSheet("QPushButton#message_btn_down{border:1px;border-image:url(:/new/prefix1/source/pointdown.png);}");
        }
        else if (e->type() == QEvent::Leave)
        {
            ui->message_btn_down->setStyleSheet("QPushButton#message_btn_down{border:0px;}");
        }
        else{return QDialog::eventFilter(target, e);}
        }

     if (target==ui->message_btn_down )
     {
        if(e->type() == QEvent::Enter)
        {
            ui->message_btn_down->setStyleSheet("QPushButton#message_btn_down{border:1px solid black;border-image:url(:/new/prefix1/source/pointdown.png);background-color:rgb(220,220,220);}");
        }
        else if (e->type() == QEvent::Leave)
        {
            ui->message_btn_down->setStyleSheet("QPushButton#message_btn_down{border:1px;border-image:url(:/new/prefix1/source/pointdown.png);}");
        }
        else{return QDialog::eventFilter(target, e);}
        }


     if (target==ui->qzone_btn_down )
     {
        if(e->type() == QEvent::Enter)
        {
            ui->qzone_btn_down->setStyleSheet("QPushButton#qzone_btn_down{border:1px solid black;border-image:url(:/new/prefix1/source/pointdown.png);background-color:rgb(220,220,220);}");
        }
        else if (e->type() == QEvent::Leave)
        {
            ui->qzone_btn_down->setStyleSheet("QPushButton#qzone_btn_down{border:1px;border-image:url(:/new/prefix1/source/pointdown.png);}");
        }
        else{return QDialog::eventFilter(target, e);}
        }

     if (target==ui->cloud )
     {
         if(e->type() == QEvent::Enter)
         {
                this->setCursor(Qt::PointingHandCursor);
                cloud_move = ui->cloud->mapToGlobal(ui->cloud->pos());
                qqweather->move(cloud_move.x()-160,cloud_move.y()-110);
                qqweather->show();
         }
         else if (e->type() == QEvent::Leave)
         {
             this->setCursor(Qt::ArrowCursor);
             pTimer->start(400);
         }
         else{return QDialog::eventFilter(target, e);}
         }
     if (target==qqweather)
     {
         if(e->type() == QEvent::Enter)
         {
                cloud_move = ui->cloud->mapToGlobal(ui->cloud->pos());
                qqweather->move(cloud_move.x()-160,cloud_move.y()-110);
                qqweather->show();
                pTimer->stop();
         }
         else if (e->type() == QEvent::Leave)
         {
             pTimer->start(400);
         }
         else{return QDialog::eventFilter(target, e);}

     }
     if (target==ui->profile)
     {
         if(e->type() == QEvent::Enter)
         {
             this->setCursor(Qt::PointingHandCursor);

             personal_move = ui->cloud->mapToGlobal(ui->profile->pos());
             personal_document1->move(personal_move.x()-552,personal_move.y()-65);
             personal_document1->show();
         }
         else if (e->type() == QEvent::Leave)
         {
             this->setCursor(Qt::ArrowCursor);
             timer_1->start(400);
         }
         else{return QDialog::eventFilter(target, e);}
     }

     if (target==personal_document1)
     {
         if(e->type() == QEvent::Enter)
         {
                personal_document1->show();
                timer_1->stop();
         }
         else if (e->type() == QEvent::Leave)
         {
             timer_1->start(400);
         }
         else{return QDialog::eventFilter(target, e);}
     }
    return QDialog::eventFilter(target, e);
}

//拖动窗体
void qqchat_main_window::mousePressEvent(QMouseEvent *e)
{
    bPressFlag = true;
    beginDrag = e->pos();
    QWidget::mousePressEvent(e);
}


void qqchat_main_window::mouseReleaseEvent(QMouseEvent *e)
{
    bPressFlag = false;
    QWidget::mouseReleaseEvent(e);
}

void qqchat_main_window::mouseMoveEvent(QMouseEvent *e)
{
    if(bPressFlag)
    {
        QPoint relaPos(QCursor::pos() - beginDrag);
        move(relaPos);
    }
    QWidget::mouseMoveEvent(e);
}

//关闭qq界面
void qqchat_main_window::close_chat()
{
    QApplication* app2;
    app2->quit();
}

//析构
qqchat_main_window::~qqchat_main_window()
{
    delete ui;
}
