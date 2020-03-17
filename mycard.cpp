#include "mycard.h"

mycard::mycard(int n,QString str)
{
    num=n;
    name=str;
    ismine=0;
    isai=0;

}
void mycard::changebool()
{
    if(ismine==0)
        ismine=1;
}
