#ifndef PROAI_H
#define PROAI_H
#include "procard.h"
#include<QDebug>
#include<QMovie>
#include<QTextEdit>
#include<QString>
class proai
{
public:
    proai();
    procard *cards[38];
    bool com[40];
    void aijudge();
    int score=0;
    int count[9];
    int combineNum;
    int judgescore();
    int judgescore2();
    QTextEdit sentence;
    QString CombineName[40];
};

#endif // PROAI_H
