#ifndef PERSONAL_DOCUMENT_H
#define PERSONAL_DOCUMENT_H

#include <QDialog>
#include <QGraphicsDropShadowEffect>

namespace Ui {
class personal_document;
}

class personal_document : public QDialog
{
    Q_OBJECT

public:
    explicit personal_document(QWidget *parent = nullptr);
    ~personal_document();

private:
    Ui::personal_document *ui;

public slots:
    bool eventFilter(QObject *target, QEvent *event);
};

#endif // PERSONAL_DOCUMENT_H
