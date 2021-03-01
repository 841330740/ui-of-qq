#include "Thread1.h"
#include <QDebug>
#include <QMutex>


Thread1::Thread1()
{
    isStop = false;
}

void Thread1::closeThread()
{
    isStop = true;
}

void Thread1::run()
{
    emit Signal1();

}

void Thread1::slotFunc(QString to_thrd)
{
    string2=to_thrd;
    qDebug()<<string2;
}
