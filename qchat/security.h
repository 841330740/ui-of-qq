#ifndef SECURITY_H
#define SECURITY_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class Security;
}

class Security : public QDialog
{
    Q_OBJECT

public:
    explicit Security(QWidget *parent = nullptr);
    ~Security();

private:
    Ui::Security *ui;
};

#endif // SECURITY_H
