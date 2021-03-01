#ifndef HELP_GUIDE_H
#define HELP_GUIDE_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class help_guide;
}

class help_guide : public QDialog
{
    Q_OBJECT

public:
    explicit help_guide(QWidget *parent = nullptr);
    ~help_guide();

private:
    Ui::help_guide *ui;
};

#endif // HELP_GUIDE_H
