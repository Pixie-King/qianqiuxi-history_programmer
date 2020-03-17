#ifndef AZCOMBINE_H
#define AZCOMBINE_H
#include<QString>
#include"mycard.h"
#include<QDebug>
#include<QMovie>
#include<QTextEdit>
class azcombine
{
public:
    azcombine();
    mycard *cards[44];
    bool com[52];
    void aijudge();
    int score=0;
    int count[9];
    int combineNum;
    int judgescore();
    int judgescore2();
    QTextEdit sentence;
    QString CombineName[50];

};

#endif // AZCOMBINE_H
