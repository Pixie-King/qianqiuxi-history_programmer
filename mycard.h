#ifndef MYCARD_H
#define MYCARD_H
#include<QString>
#include<QLabel>
class mycard
{
    int num;
    QLabel pic;

public:
    QString name;
    mycard(int n,QString str);
    int ismine;
    void changebool();
    int isai;
};

#endif // MYCARD_H
