#ifndef MYTIMER_H
#define MYTIMER_H
#include <QTimer>

class MyTimer : public QObject
{
    Q_OBJECT
public:
    MyTimer();
    MyTimer(QObject* parent);
public slots:
    void TimerHandlerFunction();
    void TimerDelay(const float);
private:
    float Fr;
    int m_a;
};

#endif // MYTIMER_H
