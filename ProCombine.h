#ifndef PROCOMBINE_H
#define PROCOMBINE_H
#include<QString>
#include"procard.h"
#include<QDebug>
#include<QMovie>

class proCombine
{
public:
    proCombine();
    procard *cards[38];
    bool com[39];
    QPixmap list[39];
    void  judge();
    int judgescore2();
    QLabel pic[39];
    int score=0;
    int count[9];
};

#endif // PROCOMBINE_H
