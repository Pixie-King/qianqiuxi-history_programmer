#ifndef COMBINE_H
#define COMBINE_H
#include<QString>
#include"mycard.h"
#include<QDebug>
#include<QMovie>
class combine
{
public:
    combine();
    mycard *cards[44];
    bool com[52];
    QPixmap list[50];
    void  judge();
    QLabel pic[50];
    int score=0;
    int count[9];
    int judgescore();
    int judgescore2();


};

#endif // COMBINE_H
