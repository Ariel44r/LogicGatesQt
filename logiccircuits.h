#ifndef LOGICCIRCUITS_H
#define LOGICCIRCUITS_H

#include <threeinputgates.h>
#include <QDebug>


class SemiSum{
    public:
        bool output, carry;
        SemiSum(){
            output = false;
            carry = false;
        }
        SemiSum(const bool A, const bool B){
            XOr xorOut(A, B);
            And andOut(A, B);
            output = xorOut.output;
            carry = andOut.output;
        }

        void printOutputs(){
            qDebug() << "\n output = " << output << "\n carry = " << carry << "\n";
        }
        ~SemiSum(){
            qDebug() << "deleted Object";
        }
};

class CompSum{
    public:
        bool output, carry;
        CompSum(){
            output = false;
            carry = false;
        }
        CompSum(const bool A, const bool B, const bool Ci){
            output = this->getSum(A,B,Ci);
            carry = this->getCarry(A,B,Ci);
        }
        bool getSum(const bool A, const bool B, const bool Ci){
            XOr xor1(A, B);
            XOr xor2(Ci, xor1.output);
            return xor2.output;
        }
        bool getCarry(const bool A, const bool B, const bool Ci){
            And and1(A,B);
            And and2(A,Ci);
            And and3(B,Ci);
            Or3 or3in(and1.output, and2.output, and3.output);
            return or3in.output;
        }
        void printOutputs(){
            qDebug() << "\n output = " << output << "\n carry = " << carry << "\n";
        }
        ~CompSum(){
            qDebug() << "Deleted Object";
        }
};
#endif // LOGICCIRCUITS_H
