#ifndef HOT_USES_H
#define HOT_USES_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class hot_uses;
}

class hot_uses : public QDialog
{
    Q_OBJECT

public:
    explicit hot_uses(QWidget *parent = nullptr);
    ~hot_uses();

private:
    Ui::hot_uses *ui;

public slots:
    void btn1_sig();
    void btn2_sig();
    void btn3_sig();
    void btn4_sig();
    void btn5_sig();
    void btn6_sig();
    void btn7_sig();
    void btn8_sig();
    void btn9_sig();
    void btn10_sig();
    void btn11_sig();
    void btn12_sig();
    void btn13_sig();

signals:
    void button_reset_signal();
};

#endif // HOT_USES_H
