#include "proai.h"
#include"procard.h"
#include<QDebug>
#include<QTimer>
#include<QSound>
#include<QApplication>
#include<QTime>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

void proaimysleep(int msec)
{
    QTime reachtime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachtime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

proai::proai()
{
    sentence.setAttribute(Qt::WA_TranslucentBackground,true);
    sentence.setGeometry(40,50,150,200);
    sentence.setFontFamily("楷体");
    sentence.setFontPointSize(14);
    sentence.setFontWeight(63);
    cards[0]=new procard(0,"牌背面");
    cards[1]=new procard(1,"C");
    cards[2]=new procard(2,"Python");
    cards[3]=new procard(3,"=");
    cards[4]=new procard(4,"double");
    cards[5]=new procard(5,"*");
    cards[6]=new procard(6,"virtual");
    cards[7]=new procard(7,"private");
    cards[8]=new procard(8,"->");
    cards[9]=new procard(9,"队列");
    cards[10]=new procard(10,"tail");
    cards[11]=new procard(11,"C++");
    cards[12]=new procard(12,"JavaScript");
    cards[13]=new procard(13,"==");
    cards[14]=new procard(14,"float");
    cards[15]=new procard(15,"&");
    cards[16]=new procard(16,"虚基类");
    cards[17]=new procard(17,"protected");
    cards[18]=new procard(18,"this");
    cards[19]=new procard(19,"函数");
    cards[20]=new procard(20,"汇编语言");
    cards[21]=new procard(21,"new");
    cards[22]=new procard(22,"int");
    cards[23]=new procard(23,"enum");
    cards[24]=new procard(24,"struct");
    cards[25]=new procard(25,"抽象类");
    cards[26]=new procard(26,"true");
    cards[27]=new procard(27,"链表");
    cards[28]=new procard(28,"~");
    cards[29]=new procard(29,"Java");
    cards[30]=new procard(30,"delete");
    cards[31]=new procard(31,"char");
    cards[32]=new procard(32,"bool");
    cards[33]=new procard(33,"class");
    cards[34]=new procard(34,"public");
    cards[35]=new procard(35,"false");
    cards[36]=new procard(36,"栈");
    cards[37]=new procard(37,"head");

    for (int i=0;i<38;i++)
    {
        com[i]=1;
    }

    for(int i=0;i<9;++i)
    {
        this->count[i]=1;
    }

    combineNum = 0;
    for(int i=0;i<40;i++)
    {
        CombineName[i]="null";
    }
}
void proai::aijudge()
{
    combineNum = 0;
    if(cards[1]->ismine==1)
    {
        if(cards[11]->ismine==1&&com[1])
        {
            score+=5;
            CombineName[combineNum] ="日新月异";
            com[1]=0;
            combineNum++;
        }
        if(cards[11]->ismine==1&&cards[20]->ismine&&cards[29]->ismine&&cards[12]->ismine&&cards[2]->ismine&&com[2])
        {
            score+=70;
            CombineName[combineNum] ="岁月集影";
            com[2]=0;
            combineNum++;
        }
    }
    if(cards[11]->ismine)
    {
        if(cards[2]->ismine&&cards[29]->ismine&&com[3])
        {
            score+=10;
            CombineName[combineNum] ="争冠";
            com[3]=0;
            combineNum++;
        }
        if(cards[29]->ismine&&cards[33]->ismine&&com[4])
        {

            score+=10;
            CombineName[combineNum] ="面向对象编程";
            com[4]=0;
            combineNum++;
        }
    }
    if(cards[29]->ismine)
    {
        if(cards[12]->ismine&&com[5])
        {

            score+=5;
            CombineName[combineNum] ="陌路";
            com[5]=0;
            combineNum++;
        }
    }
    if(cards[21]->ismine)
    {
        if(cards[30]->ismine&&com[6])
        {

            score+=5;
            CombineName[combineNum] ="永相随";
            com[6]=0;
            combineNum++;
        }
        if(cards[5]->ismine && com[7])
        {

            score+=5;
            CombineName[combineNum] ="动态规划";
            com[7]=0;
            combineNum++;
        }
    }
    if(cards[30]->ismine)
    {
        if(cards[28]->ismine && com[8])
        {

            score+=5;
            CombineName[combineNum] ="时有始终";
            com[8]=0;
            combineNum++;
        }
    }

    if(cards[3]->ismine&&cards[13]->ismine&&com[9])
    {

        score+=5;
        CombineName[combineNum] ="扑朔迷离";
        com[9]=0;
        combineNum++;
    }

    if(cards[22]->ismine)
    {
        if(cards[4]->ismine && cards[14]->ismine &&cards[23]->ismine &&cards[31]->ismine &&cards[32]->ismine &&com[10])
        {

            score+=70;
            CombineName[combineNum] ="基本数据";
            com[10]=0;
            combineNum++;
        }
        if(cards[31]->ismine && com[11])
        {
            score+=5;
            CombineName[combineNum] ="ASCLL";
            com[11]=0;
            combineNum++;
        }
        if(cards[4]->ismine && cards[14]->ismine && com[12])
        {

            score+=5;
            CombineName[combineNum] ="有理数";
            com[12]=0;
            combineNum++;
        }
    }

    if(cards[32]->ismine)
    {
        if(cards[26]->ismine && com[13])
        {

            score+=5;
            CombineName[combineNum] ="真真切切";
            com[13]=0;
            combineNum++;
        }

        if(cards[35]->ismine && com[14])
        {

            score+=5;
            CombineName[combineNum] ="假模假样";
            com[14]=0;
            combineNum++;
        }
        if(cards[26]->ismine && cards[35]->ismine && com[15])
        {

            score+=10;
            CombineName[combineNum] ="非黑即白";
            com[15]=0;
            combineNum++;
        }
    }
    if(cards[5]->ismine)
    {
        if(cards[27]->ismine && com[16])
        {

            score+=5;
            CombineName[combineNum] ="链条";
            com[16]=0;
            combineNum++;
        }
        if(cards[15]->ismine && com[17])
        {

            score+=5;
            CombineName[combineNum] ="寻址";
            com[17]=0;
            combineNum++;
        }
        if(cards[8]->ismine && com[18])
        {

            score+=5;
            CombineName[combineNum] ="成员调用";
            com[18]=0;
            combineNum++;
        }

    }
    if(cards[24]->ismine)
    {
        if(cards[33]->ismine && com[19])
        {

            score+=5;
            CombineName[combineNum] ="DIY";
            com[19]=0;
            combineNum++;
        }
        if(cards[34]->ismine &&com[20])
        {

            score+=5;
            CombineName[combineNum] ="卿本自来";
            com[20]=0;
            combineNum++;
        }
    }
    if(cards[33]->ismine)
    {
        if(cards[6]->ismine &&com[21])
        {

            score+=5;
            CombineName[combineNum] ="另类传承";
            com[21]=0;
            combineNum++;
        }
        if(cards[8]->ismine &&cards[18]->ismine && com[22])
        {

            score+=10;
            CombineName[combineNum] ="自寻";
            com[22]=0;
            combineNum++;
        }
        if(cards[18]->ismine && com[23])
        {

            score+=5;
            CombineName[combineNum] ="同根生";
            com[23]=0;
            combineNum++;
        }
        if(cards[19]->ismine && com[24])
        {

            score+=5;
            CombineName[combineNum] ="方法论";
            com[24]=0;
            combineNum++;
        }
        if(cards[7]->ismine && com[25])
        {

            score+=5;
            CombineName[combineNum] = "私有财产神圣不可侵犯";
            com[25]=0;
            combineNum++;
        }
        if(cards[34]->ismine && com[26])
        {

            score+=5;
           CombineName[combineNum] = "开诚布公";
            com[26]=0;
            combineNum++;
        }
        if(cards[17]->ismine && com[27])
        {

            score+=5;
            CombineName[combineNum] ="坐不垂堂";
            com[27]=0;
            combineNum++;
        }
    }
    if(cards[6]->ismine)
    {
        if(cards[19]->ismine && cards[25]->ismine && com[28])
        {

            score+=10;
            CombineName[combineNum] ="纯虚";
            com[28]=0;
            combineNum++;
        }
        if(cards[16]->ismine && cards[25]->ismine && com[29])
        {

            score+=10;
            CombineName[combineNum] ="一义";
            com[29]=0;
            combineNum++;
        }
    }
    if(cards[34]->ismine)
    {
        if(cards[7]->ismine && cards[17]->ismine && com[30])
        {

            score+=10;
            CombineName[combineNum] ="权限之证";
            com[30]=0;
            combineNum++;
        }
    }
    if(cards[26]->ismine)
    {
        if(cards[35]->ismine && com[31])
        {

            score+=5;
            CombineName[combineNum] ="真与假";
            com[31]=0;
            combineNum++;

        }
    }
    if(cards[27]->ismine)
    {
        if(cards[9]->ismine && cards[36]->ismine && com[32])
        {

            score+=5;
            CombineName[combineNum] ="数据结构";
            com[32]=0;
            combineNum++;

        }
        if(cards[37]->ismine && com[33])
        {

            score+=5;
            CombineName[combineNum] ="如日方升";
            com[33]=0;
            combineNum++;
        }
        if(cards[10]->ismine && com[34])
        {

            score+=5;
            CombineName[combineNum] ="收锣罢鼓";
            com[34]=0;
            combineNum++;
        }
        if(cards[37]->ismine && cards[10]->ismine && com[35])
        {

            score+=10;
            CombineName[combineNum] ="有头有尾";
            com[35]=0;
            combineNum++;
        }
    }
    if(cards[36]->ismine)
    {
        if(cards[19]->ismine && com[36])
        {

            score+=5;
            CombineName[combineNum] ="方寸之地";
            com[36]=0;
            combineNum++;
        }
    }
    if(cards[4]->ismine)
    {
        if(cards[14]->ismine && com[37])
        {

            score+=5;
            CombineName[combineNum] ="精益求精";
            com[37]=0;
            combineNum++;
        }
    }
    if(cards[15]->ismine)
    {
        if(cards[25]->ismine && com[38])
        {

            score+=5;
            CombineName[combineNum] ="多态超载";
            com[38]=0;
            combineNum++;
        }
    }

    for(int uto=0;uto<combineNum;uto++)
    {
        //qDebug()<<uto<<CombineName[uto];
        sentence.setText(QString("对方完成组合:" + CombineName[uto]));
        proaimysleep(500);
    }
}
int proai::judgescore()
{
        int total = 0;
        if(cards[1]->isai==1)
        {
            if(cards[11]->isai==1&&com[1])
            {
                total+=5;
            }
            if(cards[11]->isai==1&&cards[20]->isai&&cards[29]->isai&&cards[12]->isai&&cards[2]->isai&&com[2])
            {
                total+=70;
            }
        }
        if(cards[11]->isai)
        {
            if(cards[2]->isai&&cards[29]->isai&&com[3])
            {
                total+=10;
            }
            if(cards[29]->isai&&cards[33]->isai&&com[4])
            {

                total+=10;
            }
        }
        if(cards[29]->isai)
        {
            if(cards[12]->isai&&com[5])
            {

                total+=5;

            }
        }
        if(cards[21]->isai)
        {
            if(cards[30]->isai&&com[6])
            {

                total+=5;

            }
            if(cards[5]->isai && com[7])
            {

                total+=5;

            }
        }
        if(cards[30]->isai)
        {
            if(cards[28]->isai && com[8])
            {

                total+=5;

            }
        }

        if(cards[3]->isai&&cards[13]->isai&&com[9])
        {

            total+=5;

        }

        if(cards[22]->isai)
        {
            if(cards[4]->isai && cards[14]->isai &&cards[23]->isai &&cards[31]->isai &&cards[32]->isai &&com[10])
            {

                total+=70;

            }
            if(cards[31]->isai && com[11])
            {
                total+=5;

            }
            if(cards[4]->isai && cards[14]->isai && com[12])
            {

                total+=5;

            }
        }

        if(cards[32]->isai)
        {
            if(cards[26]->isai && com[13])
            {

                total+=5;

            }

            if(cards[35]->isai && com[14])
            {

                total+=5;

            }
            if(cards[26]->isai && cards[35]->isai && com[15])
            {

                total+=10;

            }
        }
        if(cards[5]->isai)
        {
            if(cards[27]->isai && com[16])
            {

                total+=5;

            }
            if(cards[15]->isai && com[17])
            {

                total+=5;

            }
            if(cards[8]->isai && com[18])
            {

                total+=5;

            }

        }
        if(cards[24]->isai)
        {
            if(cards[33]->isai && com[19])
            {

                total+=5;

            }
            if(cards[34]->isai &&com[20])
            {

                total+=5;
            }
        }
        if(cards[33]->isai)
        {
            if(cards[6]->isai &&com[21])
            {

                total+=5;

            }
            if(cards[8]->isai &&cards[18]->isai && com[22])
            {

                total+=10;

            }
            if(cards[18]->isai && com[23])
            {

                total+=5;

            }
            if(cards[19]->isai && com[24])
            {

                total+=5;

            }
            if(cards[7]->isai && com[25])
            {

                total+=5;

            }
            if(cards[34]->isai && com[26])
            {


            }
            if(cards[17]->isai && com[27])
            {

                total+=5;

            }
        }
        if(cards[6]->isai)
        {
            if(cards[19]->isai && cards[25]->isai && com[28])
            {

                total+=10;

            }
            if(cards[16]->isai && cards[25]->isai && com[29])
            {

                total+=10;

            }
        }
        if(cards[34]->isai)
        {
            if(cards[7]->isai && cards[17]->isai && com[30])
            {

                total+=10;

            }
        }
        if(cards[26]->isai)
        {
            if(cards[35]->isai && com[31])
            {

                total+=5;


            }
        }
        if(cards[27]->isai)
        {
            if(cards[9]->isai && cards[36]->isai && com[32])
            {

                total+=5;


            }
            if(cards[37]->isai && com[33])
            {

                total+=5;

            }
            if(cards[10]->isai && com[34])
            {

                total+=5;

            }
            if(cards[37]->isai && cards[10]->isai && com[35])
            {

                total+=10;

            }
        }
        if(cards[36]->isai)
        {
            if(cards[19]->isai && com[36])
            {

                total+=5;

            }
        }
        if(cards[4]->isai)
        {
            if(cards[14]->isai && com[37])
            {

                total+=5;

            }
        }
        if(cards[15]->isai)
        {
            if(cards[25]->isai && com[38])
            {

                total+=5;

            }
        }
        for(int io=0;io<38;io++)
            qDebug()<<io<<cards[io]->isai;

        qDebug()<<"total = "<<total;
        return total;
}
int proai::judgescore2()
{
    int total = 0;
    if(cards[1]->ismine==1)
    {
        if(cards[11]->ismine==1&&com[1])
        {
            total+=5;
        }
        if(cards[11]->ismine==1&&cards[20]->ismine&&cards[29]->ismine&&cards[12]->ismine&&cards[2]->ismine&&com[2])
        {
            total+=70;
        }
    }
    if(cards[11]->ismine)
    {
        if(cards[2]->ismine&&cards[29]->ismine&&com[3])
        {
            total+=10;
        }
        if(cards[29]->ismine&&cards[33]->ismine&&com[4])
        {

            total+=10;
        }
    }
    if(cards[29]->ismine)
    {
        if(cards[12]->ismine&&com[5])
        {

            total+=5;

        }
    }
    if(cards[21]->ismine)
    {
        if(cards[30]->ismine&&com[6])
        {

            total+=5;

        }
        if(cards[5]->ismine && com[7])
        {

            total+=5;

        }
    }
    if(cards[30]->ismine)
    {
        if(cards[28]->ismine && com[8])
        {

            total+=5;

        }
    }

    if(cards[3]->ismine&&cards[13]->ismine&&com[9])
    {

        total+=5;

    }

    if(cards[22]->ismine)
    {
        if(cards[4]->ismine && cards[14]->ismine &&cards[23]->ismine &&cards[31]->ismine &&cards[32]->ismine &&com[10])
        {

            total+=70;

        }
        if(cards[31]->ismine && com[11])
        {
            total+=5;

        }
        if(cards[4]->ismine && cards[14]->ismine && com[12])
        {

            total+=5;

        }
    }

    if(cards[32]->ismine)
    {
        if(cards[26]->ismine && com[13])
        {

            total+=5;

        }

        if(cards[35]->ismine && com[14])
        {

            total+=5;

        }
        if(cards[26]->ismine && cards[35]->ismine && com[15])
        {

            total+=10;

        }
    }
    if(cards[5]->ismine)
    {
        if(cards[27]->ismine && com[16])
        {

            total+=5;

        }
        if(cards[15]->ismine && com[17])
        {

            total+=5;

        }
        if(cards[8]->ismine && com[18])
        {

            total+=5;

        }

    }
    if(cards[24]->ismine)
    {
        if(cards[33]->ismine && com[19])
        {

            total+=5;

        }
        if(cards[34]->ismine &&com[20])
        {

            total+=5;
        }
    }
    if(cards[33]->ismine)
    {
        if(cards[6]->ismine &&com[21])
        {

            total+=5;

        }
        if(cards[8]->ismine &&cards[18]->ismine && com[22])
        {

            total+=10;

        }
        if(cards[18]->ismine && com[23])
        {

            total+=5;

        }
        if(cards[19]->ismine && com[24])
        {

            total+=5;

        }
        if(cards[7]->ismine && com[25])
        {

            total+=5;

        }
        if(cards[34]->ismine && com[26])
        {


        }
        if(cards[17]->ismine && com[27])
        {

            total+=5;

        }
    }
    if(cards[6]->ismine)
    {
        if(cards[19]->ismine && cards[25]->ismine && com[28])
        {

            total+=10;

        }
        if(cards[16]->ismine && cards[25]->ismine && com[29])
        {

            total+=10;

        }
    }
    if(cards[34]->ismine)
    {
        if(cards[7]->ismine && cards[17]->ismine && com[30])
        {

            total+=10;

        }
    }
    if(cards[26]->ismine)
    {
        if(cards[35]->ismine && com[31])
        {

            total+=5;


        }
    }
    if(cards[27]->ismine)
    {
        if(cards[9]->ismine && cards[36]->ismine && com[32])
        {

            total+=5;


        }
        if(cards[37]->ismine && com[33])
        {

            total+=5;

        }
        if(cards[10]->ismine && com[34])
        {

            total+=5;

        }
        if(cards[37]->ismine && cards[10]->ismine && com[35])
        {

            total+=10;

        }
    }
    if(cards[36]->ismine)
    {
        if(cards[19]->ismine && com[36])
        {

            total+=5;

        }
    }
    if(cards[4]->ismine)
    {
        if(cards[14]->ismine && com[37])
        {

            total+=5;

        }
    }
    if(cards[15]->ismine)
    {
        if(cards[25]->ismine && com[38])
        {

            total+=5;

        }
    }

    return total;
}
