#include "mytimer.h"
#include <QTimer>
#include <QDebug>
#include <math.h>

MyTimer::MyTimer(){
    qDebug() << "MyTimer Staring";
}

void MyTimer::SetTimer(const float ms){
    Fr = pow(10,3)*1/ms;
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerHandlerFunction()));
    timer->start(ms);
}

void MyTimer::SetClock(const float hz){
    Fr = hz;
    float ms = 1000/hz;
    connect(timer, SIGNAL(timeout()), this, SLOT(ToggleLogicLevel()));
    timer->start(ms/2);
}

void MyTimer::ToggleLogicLevel(){
    if(this->output == 0){
        this->output = 1;
    } else {
        this->output = 0;
    }
    qDebug() << "HelLoMaX! " << Fr << "[Hz] " << this->output;
}

void MyTimer::TimerDelay(const float ms){
    connect(timer, SIGNAL(timeout()), this, SLOT(ToggleOff()));
    timer->start(ms);
    this->output = true;
    qDebug() << StatusLogic();
}

void MyTimer::ToggleOff(){
    timer->stop();
    this->output = false;
    qDebug() << StatusLogic();
}

bool MyTimer::StatusLogic(){
    if(timer->isActive()){
        return true;
    } else{
        return false;
    }
}
