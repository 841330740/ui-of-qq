#ifndef THREAD1_H
#define THREAD1_H

#include <QThread>

class Thread1 : public QThread
{
    Q_OBJECT

private:
        volatile bool isStop;

protected:
    void run() Q_DECL_OVERRIDE;

public:
    Thread1();
    void closeThread();
    QString string1=u8"线，这是程";
    QString string2=u8"年轻人";

public slots:
    void slotFunc(QString to_thrd);

signals:
    void Signal1();

};

#endif // THREAD1_H
