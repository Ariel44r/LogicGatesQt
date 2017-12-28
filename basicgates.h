#ifndef BASICGATES_H
#define BASICGATES_H
#include <QDebug>

using namespace std;

class Gate{
    public:
        string name;
        bool output;
};

class Or : public Gate{
    public:
        Or(const bool A, const bool B){
            output = (A || B);
            name = "Or";
        }
        ~Or(){
            qDebug() << "Deleted Object";
        }
};

class And : public Gate{
    public:
        And(const bool A, const bool B){
            output = (A && B);
            name = "And";
        }
        ~And(){
            qDebug() << "Deleted Object";
        }
};

class Not : public Gate{
    public:
        Not(const bool A){
            output = !A;
            name = "Not";
        }
        ~Not(){
            qDebug() << "Deleted Object";
        }
};

class NOr : public Gate{
    public:
        NOr(const bool A, const bool B){
            Or or1(A, B);
            Not not1(or1.output);
            output = not1.output;
            name = "NOr";
        }
        ~NOr(){
            qDebug() << "Deleted Object";
        }
};

class NAnd : public Gate{
    public:
        NAnd(const bool A, const bool B){
            And and1(A, B);
            Not not1(and1.output);
            output = not1.output;
            name = "NAnd";
        }
        ~NAnd(){
            qDebug() << "Deleted Object";
        }
};

class XOr : public Gate{
    public:
        XOr(){
            name = "XOr";
            output = false;
        }
        XOr(const bool A, const bool B){
            Not notA(A);
            Not notB(B);
            And andA(A,notB.output);
            And andB(notA.output,B);
            Or orOut(andA.output, andB.output);
            output = orOut.output;
            name = "XOr";
        }
        ~XOr(){
            qDebug() << "Deleted Object";
        }
};

class XNor : public Gate{
    public:
        XNor(const bool A, const bool B){
            XOr xor1(A,B);
            Not notOut(xor1.output);
            output = notOut.output;
            name = "XNor";
        }
        ~XNor(){
            qDebug() << "Deleted Object";
        }
};
#endif // BASICGATES_H
