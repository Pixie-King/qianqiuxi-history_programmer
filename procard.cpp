#include "procard.h"

procard::procard(int n,QString str)
{
    num=n;
    name=str;
    ismine=0;
    isai=0;

}
void procard::changebool()
{
    if(ismine==0)
        ismine=1;
}
