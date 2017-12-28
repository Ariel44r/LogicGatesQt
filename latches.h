#ifndef LATCHES_H
#define LATCHES_H

#include <iostream>
#include <basicgates.h>
#include <QDebug>

using namespace std;

class SRLatch{
    public:
        string name;
        string status;
        bool Q;
        bool Qn;
        int count00;

        SRLatch(){
            name = "SRLatch";
            count00 = 0;
        }
        SRLatch(const bool S, const bool R){
            name = "SRLatch";
            count00 = 0;
            this->setParameters(S,R);
        }
        void printParameters(){
            qDebug() << status.c_str();
            qDebug() << name.c_str();
            qDebug() << "Q = " << Q;
            qDebug() << "Qn = " << Qn;
        }
        void resetParameters(const bool S, const bool R){
            this->setParameters(S,R);
        }
        void setParameters(const bool S, const bool R){
            if(S && !R){
                Q = true;
                Qn = false;
                status = "allow0";
            }
            if((!S && !R) && count00 == 0){
                count00 = 1;
                Q = true;
                Qn = false;
                status = "allow1";
            } else if ((!S && !R) && count00 == 1){
                Q = false;
                Qn = true;
                count00 = 0;
                status = "allow3";
            }
            if(!S && R){
                Q = false;
                Qn = true;
                status = "allow2";
            }
            if(S && R){
                Q = false;
                Qn = false;
                status = "prohibited4";
            }
        }
};

#endif // LATCHES_H
