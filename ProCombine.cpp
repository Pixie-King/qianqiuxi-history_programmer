#include "ProCombine.h"
#include "combine.h"
#include"procard.h"
#include<QDebug>
#include<QTimer>
#include<QSound>
#include<QApplication>
#include<QTime>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


void prosleep(int msec)
{
    QTime reachtime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachtime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

proCombine::proCombine()
{
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

    for (int i=0;i<39;i++)
    {
        com[i]=1;
    }

    list[0].load(":/CI/ComBineImage/comb01.png");

    for(int i=1;i<10;i++)
    {
        QString str = QString(":/CI/ComBineImage/comb0%1.png").arg(QString::number(i));

        list[i].load(str);

    }
    for(int i=10;i<39;i++)
    {
        QString str = QString(":/CI/ComBineImage/comb%1.png").arg(QString::number(i));
        list[i].load(str);

    }

    for(int i=0;i<9;++i)
    {
        count[i]=1;
    }

}

void proCombine::judge()
{
    if(cards[1]->ismine==1)
    {
        if(cards[11]->ismine==1&&com[1])
        {
            pic[1].setVisible(true);
            score+=5;
            qDebug()<<"日新月异";
            com[1]=0;
            list[1].scaled(pic[1].size(),Qt::KeepAspectRatio);
            pic[1].setScaledContents(true);
            pic[1].setPixmap(list[1]);
            prosleep(2000);
            pic[1].setVisible(false);
        }
        if(cards[11]->ismine==1&&cards[20]->ismine&&cards[29]->ismine&&cards[12]->ismine&&cards[2]->ismine&&com[2])
        {
            pic[2].setVisible(true);
            score+=70;
            qDebug()<<"岁月集影";
            com[2]=0;
            list[2].scaled(pic[1].size(),Qt::KeepAspectRatio);
            pic[2].setScaledContents(true);
            pic[2].setPixmap(list[2]);
            prosleep(2000);
            pic[2].setVisible(false);
        }
    }
    if(cards[11]->ismine)
    {
        if(cards[2]->ismine&&cards[29]->ismine&&com[3])
        {
            pic[3].setVisible(true);
            score+=10;
            qDebug()<<"争冠";
            com[3]=0;
            list[3].scaled(pic[3].size(),Qt::KeepAspectRatio);
            pic[3].setScaledContents(true);
            pic[3].setPixmap(list[3]);
            prosleep(2000);
            pic[3].setVisible(false);
        }
        if(cards[29]->ismine&&cards[33]->ismine&&com[4])
        {
            pic[4].setVisible(true);
            score+=10;
            qDebug()<<"面向对象编程";
            com[4]=0;
            list[4].scaled(pic[4].size(),Qt::KeepAspectRatio);
            pic[4].setScaledContents(true);
            pic[4].setPixmap(list[4]);
            prosleep(2000);
            pic[4].setVisible(false);
        }
    }
    if(cards[29]->ismine)
    {
        if(cards[12]->ismine&&com[5])
        {
            pic[5].setVisible(true);
            score+=5;
            qDebug()<<"陌路";
            com[5]=0;
            list[5].scaled(pic[5].size(),Qt::KeepAspectRatio);
            pic[5].setScaledContents(true);
            pic[5].setPixmap(list[5]);
            prosleep(2000);
            pic[5].setVisible(false);
        }
    }
    if(cards[21]->ismine)
    {
        if(cards[30]->ismine&&com[6])
        {
            pic[6].setVisible(true);
            score+=5;
            qDebug()<<"永相随";
            com[6]=0;
            list[6].scaled(pic[6].size(),Qt::KeepAspectRatio);
            pic[6].setScaledContents(true);
            pic[6].setPixmap(list[6]);
            prosleep(2000);
            pic[6].setVisible(false);
        }
        if(cards[5]->ismine && com[7])
        {
            pic[7].setVisible(true);
            score+=5;
            qDebug()<<"动态规划";
            com[7]=0;
            list[7].scaled(pic[7].size(),Qt::KeepAspectRatio);
            pic[7].setScaledContents(true);
            pic[7].setPixmap(list[7]);
            prosleep(2000);
            pic[7].setVisible(false);
        }
    }
    if(cards[30]->ismine)
    {
        if(cards[28]->ismine && com[8])
        {
            pic[8].setVisible(true);
            score+=5;
            qDebug()<<"时有始终";
            com[8]=0;
            list[8].scaled(pic[8].size(),Qt::KeepAspectRatio);
            pic[8].setScaledContents(true);
            pic[8].setPixmap(list[8]);
            prosleep(2000);
            pic[8].setVisible(false);
        }
    }

    if(cards[3]->ismine&&cards[13]->ismine&&com[9])
    {
        pic[9].setVisible(true);
        score+=5;
        qDebug()<<"扑朔迷离";
        com[9]=0;
        list[9].scaled(pic[9].size(),Qt::KeepAspectRatio);
        pic[9].setScaledContents(true);
        pic[9].setPixmap(list[9]);
        prosleep(2000);
        pic[9].setVisible(false);
    }

    if(cards[22]->ismine)
    {
        if(cards[4]->ismine && cards[14]->ismine &&cards[23]->ismine &&cards[31]->ismine &&cards[32]->ismine &&com[10])
        {
            pic[10].setVisible(true);
            score+=70;
            qDebug()<<"基本数据";
            com[10]=0;
            list[10].scaled(pic[10].size(),Qt::KeepAspectRatio);
            pic[10].setScaledContents(true);
            pic[10].setPixmap(list[10]);
            prosleep(2000);
            pic[10].setVisible(false);
        }
        if(cards[31]->ismine && com[11])
        {
            pic[11].setVisible(true);
            score+=5;
            qDebug()<<"ASCLL";
            com[11]=0;
            list[11].scaled(pic[11].size(),Qt::KeepAspectRatio);
            pic[11].setScaledContents(true);
            pic[11].setPixmap(list[11]);
            prosleep(2000);
            pic[11].setVisible(false);
        }
        if(cards[4]->ismine && cards[14]->ismine && com[12])
        {
            pic[12].setVisible(true);
            score+=5;
            qDebug()<<"有理数";
            com[12]=0;
            list[12].scaled(pic[12].size(),Qt::KeepAspectRatio);
            pic[12].setScaledContents(true);
            pic[12].setPixmap(list[12]);
            prosleep(2000);
            pic[12].setVisible(false);
        }
    }

    if(cards[32]->ismine)
    {
        if(cards[26]->ismine && com[13])
        {
            pic[13].setVisible(true);
            score+=5;
            qDebug()<<"真真切切";
            com[13]=0;
            list[13].scaled(pic[13].size(),Qt::KeepAspectRatio);
            pic[13].setScaledContents(true);
            pic[13].setPixmap(list[13]);
            prosleep(2000);
            pic[13].setVisible(false);
        }

        if(cards[35]->ismine && com[14])
        {
            pic[14].setVisible(true);
            score+=5;
            qDebug()<<"假模假样";
            com[14]=0;
            list[14].scaled(pic[14].size(),Qt::KeepAspectRatio);
            pic[14].setScaledContents(true);
            pic[14].setPixmap(list[14]);
            prosleep(2000);
            pic[14].setVisible(false);
        }
        if(cards[26]->ismine && cards[35]->ismine && com[15])
        {
            pic[15].setVisible(true);
            score+=10;
            qDebug()<<"非黑即白";
            com[15]=0;
            list[15].scaled(pic[15].size(),Qt::KeepAspectRatio);
            pic[15].setScaledContents(true);
            pic[15].setPixmap(list[15]);
            prosleep(2000);
            pic[15].setVisible(false);
        }
    }
    if(cards[5]->ismine)
    {
        if(cards[27]->ismine && com[16])
        {
            pic[16].setVisible(true);
            score+=5;
            qDebug()<<"链条";
            com[16]=0;
            list[16].scaled(pic[16].size(),Qt::KeepAspectRatio);
            pic[16].setScaledContents(true);
            pic[16].setPixmap(list[16]);
            prosleep(2000);
            pic[16].setVisible(false);
        }
        if(cards[15]->ismine && com[17])
        {
            pic[17].setVisible(true);
            score+=5;
            qDebug()<<"寻址";
            com[17]=0;
            list[17].scaled(pic[17].size(),Qt::KeepAspectRatio);
            pic[17].setScaledContents(true);
            pic[17].setPixmap(list[17]);
            prosleep(2000);
            pic[17].setVisible(false);
        }
        if(cards[8]->ismine && com[18])
        {
            pic[18].setVisible(true);
            score+=5;
            qDebug()<<"成员调用";
            com[18]=0;
            list[18].scaled(pic[18].size(),Qt::KeepAspectRatio);
            pic[18].setScaledContents(true);
            pic[18].setPixmap(list[18]);
            prosleep(2000);
            pic[18].setVisible(false);
        }

    }
    if(cards[24]->ismine)
    {
        if(cards[33]->ismine && com[19])
        {
            pic[19].setVisible(true);
            score+=5;
            qDebug()<<"DIY";
            com[19]=0;
            list[19].scaled(pic[19].size(),Qt::KeepAspectRatio);
            pic[19].setScaledContents(true);
            pic[19].setPixmap(list[19]);
            prosleep(2000);
            pic[19].setVisible(false);
        }
        if(cards[34]->ismine &&com[20])
        {
            pic[20].setVisible(true);
            score+=5;
            qDebug() << "卿本自来";
            com[20]=0;
            list[20].scaled(pic[20].size(),Qt::KeepAspectRatio);
            pic[20].setScaledContents(true);
            pic[20].setPixmap(list[20]);
            prosleep(2000);
            pic[20].setVisible(false);
        }
    }
    if(cards[33]->ismine)
    {
        if(cards[6]->ismine &&com[21])
        {
            pic[21].setVisible(true);
            score+=5;
            qDebug()<<"另类传承";
            com[21]=0;
            list[21].scaled(pic[21].size(),Qt::KeepAspectRatio);
            pic[21].setScaledContents(true);
            pic[21].setPixmap(list[21]);
            prosleep(2000);
            pic[21].setVisible(false);
        }
        if(cards[8]->ismine &&cards[18]->ismine && com[22])
        {
            pic[22].setVisible(true);
            score+=10;
            qDebug()<<"自寻";
            com[22]=0;
            list[22].scaled(pic[22].size(),Qt::KeepAspectRatio);
            pic[22].setScaledContents(true);
            pic[22].setPixmap(list[22]);
            prosleep(2000);
            pic[22].setVisible(false);
        }
        if(cards[18]->ismine && com[23])
        {
            pic[23].setVisible(true);
            score+=5;
            qDebug()<<"同根生";
            com[23]=0;
            list[23].scaled(pic[23].size(),Qt::KeepAspectRatio);
            pic[23].setScaledContents(true);
            pic[23].setPixmap(list[23]);
            prosleep(2000);
            pic[23].setVisible(false);
        }
        if(cards[19]->ismine && com[24])
        {
            pic[24].setVisible(true);
            score+=5;
            qDebug()<<"方法论";
            com[24]=0;
            list[24].scaled(pic[24].size(),Qt::KeepAspectRatio);
            pic[24].setScaledContents(true);
            pic[24].setPixmap(list[24]);
            prosleep(2000);
            pic[24].setVisible(false);
        }
        if(cards[7]->ismine && com[25])
        {
            pic[25].setVisible(true);
            score+=5;
            qDebug() << "私有财产神圣不可侵犯";
            com[25]=0;
            list[25].scaled(pic[25].size(),Qt::KeepAspectRatio);
            pic[25].setScaledContents(true);
            pic[25].setPixmap(list[25]);
            prosleep(2000);
            pic[25].setVisible(false);
        }
        if(cards[34]->ismine && com[26])
        {
            pic[26].setVisible(true);
            score+=5;
            qDebug() << "开诚布公";
            com[26]=0;
            list[26].scaled(pic[26].size(),Qt::KeepAspectRatio);
            pic[26].setScaledContents(true);
            pic[26].setPixmap(list[26]);
            prosleep(2000);
            pic[26].setVisible(false);
        }
        if(cards[17]->ismine && com[27])
        {
            pic[27].setVisible(true);
            score+=5;
            qDebug()<<"坐不垂堂";
            com[27]=0;
            list[27].scaled(pic[27].size(),Qt::KeepAspectRatio);
            pic[27].setScaledContents(true);
            pic[27].setPixmap(list[27]);
            prosleep(2000);
            pic[27].setVisible(false);
        }
    }
    if(cards[6]->ismine)
    {
        if(cards[19]->ismine && cards[25]->ismine && com[28])
        {
            pic[28].setVisible(true);
            score+=10;
            qDebug()<<"纯虚";
            com[28]=0;
            list[28].scaled(pic[28].size(),Qt::KeepAspectRatio);
            pic[28].setScaledContents(true);
            pic[28].setPixmap(list[28]);
            prosleep(2000);
            pic[28].setVisible(false);
        }
        if(cards[16]->ismine && cards[25]->ismine && com[29])
        {
            pic[29].setVisible(true);
            score+=10;
            qDebug()<<"一义";
            com[29]=0;
            list[29].scaled(pic[29].size(),Qt::KeepAspectRatio);
            pic[29].setScaledContents(true);
            pic[29].setPixmap(list[29]);
            prosleep(2000);
            pic[29].setVisible(false);
        }
    }
    if(cards[34]->ismine)
    {
        if(cards[7]->ismine && cards[17]->ismine && com[30])
        {
            pic[30].setVisible(true);
            score+=10;
            qDebug()<<"权限之证";
            com[30]=0;
            list[30].scaled(pic[30].size(),Qt::KeepAspectRatio);
            pic[30].setScaledContents(true);
            pic[30].setPixmap(list[30]);
            prosleep(2000);
            pic[30].setVisible(false);
        }
    }
    if(cards[26]->ismine)
    {
        if(cards[35]->ismine && com[31])
        {
            pic[31].setVisible(true);
            score+=5;
            qDebug()<<"真与假";
            com[31]=0;
            list[31].scaled(pic[31].size(),Qt::KeepAspectRatio);
            pic[31].setScaledContents(true);
            pic[31].setPixmap(list[31]);
            prosleep(2000);
            pic[31].setVisible(false);

        }
    }
    if(cards[27]->ismine)
    {
        if(cards[9]->ismine && cards[36]->ismine && com[32])
        {
            pic[32].setVisible(true);
            score+=5;
            qDebug()<<"数据结构";
            com[32]=0;
            list[32].scaled(pic[32].size(),Qt::KeepAspectRatio);
            pic[32].setScaledContents(true);
            pic[32].setPixmap(list[32]);
            prosleep(2000);
            pic[32].setVisible(false);

        }
        if(cards[37]->ismine && com[33])
        {
            pic[33].setVisible(true);
            score+=5;
            qDebug()<<"如日方升";
            com[33]=0;
            list[33].scaled(pic[33].size(),Qt::KeepAspectRatio);
            pic[33].setScaledContents(true);
            pic[33].setPixmap(list[33]);
            prosleep(2000);
            pic[33].setVisible(false);
        }
        if(cards[10]->ismine && com[34])
        {
            pic[34].setVisible(true);
            score+=5;
            qDebug()<<"收锣罢鼓";
            com[34]=0;
            list[34].scaled(pic[34].size(),Qt::KeepAspectRatio);
            pic[34].setScaledContents(true);
            pic[34].setPixmap(list[34]);
            prosleep(2000);
            pic[34].setVisible(false);
        }
        if(cards[37]->ismine && cards[10]->ismine && com[35])
        {
            pic[35].setVisible(true);
            score+=10;
            qDebug()<<"有头有尾";
            com[35]=0;
            list[35].scaled(pic[35].size(),Qt::KeepAspectRatio);
            pic[35].setScaledContents(true);
            pic[35].setPixmap(list[35]);
            prosleep(2000);
            pic[35].setVisible(false);
        }
    }
    if(cards[36]->ismine)
    {
        if(cards[19]->ismine && com[36])
        {
            pic[36].setVisible(true);
            score+=5;
            qDebug()<<"方寸之地";
            com[36]=0;
            list[36].scaled(pic[36].size(),Qt::KeepAspectRatio);
            pic[36].setScaledContents(true);
            pic[36].setPixmap(list[36]);
            prosleep(2000);
            pic[36].setVisible(false);

        }
    }
    if(cards[4]->ismine)
    {
        if(cards[14]->ismine && com[37])
        {
            pic[37].setVisible(true);
            score+=5;
            qDebug()<<"精益求精";
            com[37]=0;
            list[37].scaled(pic[37].size(),Qt::KeepAspectRatio);
            pic[37].setScaledContents(true);
            pic[37].setPixmap(list[37]);
            prosleep(2000);
            pic[37].setVisible(false);
        }
    }
    if(cards[15]->ismine)
    {
        if(cards[25]->ismine && com[38])
        {
            pic[38].setVisible(true);
            score+=5;
            qDebug()<<"多态超载";
            com[38]=0;
            list[38].scaled(pic[38].size(),Qt::KeepAspectRatio);
            pic[38].setScaledContents(true);
            pic[38].setPixmap(list[38]);
            prosleep(2000);
            pic[38].setVisible(false);
        }
    }
}
int proCombine::judgescore2()
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
    for(int io=0;io<38;io++)
        qDebug()<<cards[io]->ismine;
    qDebug()<<"total2 = "<<total;
    return total;
}
