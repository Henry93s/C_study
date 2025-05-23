#include "thread.h"
#include <QLabel>

Thread::Thread(QObject *obj)
    : m_stopFlag(play)
{
    m_label = (QLabel*)obj;
}

void Thread::run(){
    int count =0 ;
    Q_FOREVER{
        m_mutex.lock();
        if(m_stopFlag == stop){
            m_waitCondition.wait(&m_mutex);
        }
        m_mutex.unlock();

        emit setLabeled(QString("run %1").arg(count++));
        sleep(1);
    }
}

void Thread::stopThread(){
    m_stopFlag = stop;
}

void Thread::resumeThread(){
    m_mutex.lock();
    m_stopFlag = play;
    m_waitCondition.wakeAll();
    m_mutex.unlock();
}
