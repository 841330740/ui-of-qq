#ifndef LOGIN_CONDITION_H
#define LOGIN_CONDITION_H

#include <QDialog>

namespace Ui {
class login_condition;
}

class login_condition : public QDialog
{
    Q_OBJECT

public:
    explicit login_condition(QWidget *parent = nullptr);
    ~login_condition();

public slots:
    bool eventFilter(QObject *target, QEvent *event);

    void login_em_fnc();
    void chat_with_em_fnc();
    void leave_em_fnc();
    void busy_em_fnc();
    void avoid_em_fnc();
    void hide_em_fnc();
    void logout_fnc();

private:
    Ui::login_condition *ui;

signals:
    void login_em();
    void chat_with_em();
    void leave_em();
    void busy_em();
    void avoid_em();
    void hide_em();
    void logout();
};

#endif // LOGIN_CONDITION_H
