#include "worker.h"


Worker::Worker(QObject *parent) : QObject(parent)
{
    QThread* thread = new QThread(this);
    thread->start();
    this->moveToThread(thread);
    connect(this,&Worker::sigStartWork,this,&Worker::work);
}

void Worker::work()
{
    qInfo()<<"start work in thread "<<QThread::currentThreadId();
}
