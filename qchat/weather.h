#ifndef WEATHER_H
#define WEATHER_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class weather;
}

class weather : public QDialog
{
    Q_OBJECT

public:
    explicit weather(QWidget *parent = nullptr);
    ~weather();

private:
    Ui::weather *ui;

};

#endif // WEATHER_H
