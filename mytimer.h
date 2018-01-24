#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    MyTimer(QObject* parent);
    QTimer *timer = new QTimer(this);

public slots:
    void ToggleLogicLevel();
    void SetTimer(const float);
    void SetClock(const float);
    void TimerDelay(const float);
    void ToggleOff();
    bool StatusLogic();

private:
    float Fr;
    bool output;
};

#endif // MYTIMER_H
