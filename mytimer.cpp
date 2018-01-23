#include "mytimer.h"
#include <QTimer>
#include <QDebug>
#include <math.h>

MyTimer::MyTimer(){
    qDebug() << "MyTimer Staring";
}

void MyTimer::TimerDelay(const float ms){
    m_a = ms;
    Fr = pow(10,3)*1/ms;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerHandlerFunction()));
    timer->start(ms);
}

void MyTimer::TimerHandlerFunction(){
    qDebug() << "HelLoMaX! " << Fr << "[Hz]";
}
