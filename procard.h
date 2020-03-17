#ifndef PROCARD_H
#define PROCARD_H
#include<QString>
#include<QLabel>

class procard
{
    int num;
    QLabel pic;
public:
    QString name;
    procard(int n,QString str);
    int ismine;
    void changebool();
    int isai;
};

#endif // PROCARD_H
