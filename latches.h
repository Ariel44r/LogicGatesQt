#ifndef LATCHES_H
#define LATCHES_H

#include <string>
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
            qDebug() << name.c_str();
            qDebug() << "Q = " << Q;
            qDebug() << "Qn = " << Qn;
            qDebug() << "Status = " << status.c_str();
        }
        void resetParameters(const bool S, const bool R){
            this->setParameters(S,R);
        }
        void setParameters(const bool S, const bool R){
            if(S && !R){
                Q = true;
                Qn = false;
                status = "al";
            }
            if((!S && !R) && count00 == 0){
                count00 = 1;
                Q = true;
                Qn = false;
                status = "all";
            } else if ((!S && !R) && count00 == 1){
                Q = false;
                Qn = true;
                count00 = 0;
                status = "allow";
            }
            if(!S && R){
                Q = false;
                Qn = true;
                status = "allo";
            }
            if(S && R){
                Q = false;
                Qn = false;
                status = "prohibited";
            }
        }
};

#endif // LATCHES_H
