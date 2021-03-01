#ifndef SETTING1_H
#define SETTING1_H

#include <QDialog>
#include <QDebug>
#include <QTimer>
namespace Ui {
class setting1;
}

class setting1 : public QDialog
{
    Q_OBJECT

public:
    explicit setting1(QWidget *parent = nullptr);
    ~setting1();
    QTimer *pTimer;

private:
    Ui::setting1 *ui;

public slots:
    bool eventFilter(QObject *target, QEvent *event);
    void set_email();
    void timer_nu();
    void set_shopping();

};

#endif // SETTING1_H
