#include "combine.h"
#include"mycard.h"
#include<QDebug>
#include<QTimer>
#include<QSound>
#include<QApplication>

#include<QTime>
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
void mysleep(int msec)
{
    QTime reachtime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachtime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

combine::combine()
{
    cards[0]=new mycard(0,"牌背面");
    cards[1]=new mycard(1,"八国联军侵华");
    cards[2]=new mycard(2,"北伐战争");
    cards[3]=new mycard(3,"北京大学");
    cards[4]=new mycard(4,"北洋政府");
    cards[5]=new mycard(5,"邓世昌&致远舰");
    cards[6]=new mycard(6,"邓小平");
    cards[7]=new mycard(7,"邓颖超");
    cards[8]=new mycard(8,"第二次鸦片战争");
    cards[9]=new mycard(9,"工人&学生");
    cards[10]=new mycard(10,"共产党");
    cards[11]=new mycard(11,"国共联军");
    cards[12]=new mycard(12,"航天");
    cards[13]=new mycard(13,"红军");
    cards[14]=new mycard(14,"嘉兴南湖");
    cards[15]=new mycard(15,"甲午战争");
    cards[16]=new mycard(16,"蒋介石");
    cards[17]=new mycard(17,"经济特区");
    cards[18]=new mycard(18,"井冈山");
    cards[19]=new mycard(19,"开国大典");
    cards[20]=new mycard(20,"抗日战争");
    cards[21]=new mycard(21,"林则徐");
    cards[22]=new mycard(22,"马克思主义");
    cards[23]=new mycard(23,"毛泽东");
    cards[24]=new mycard(24,"南开大学");
    cards[25]=new mycard(25,"清华大学");
    cards[26]=new mycard(26,"孙中山");
    cards[27]=new mycard(27,"太平天国");
    cards[28]=new mycard(28,"万隆会议");
    cards[29]=new mycard(29,"五四运动");
    cards[30]=new mycard(30,"戊戌变法");
    cards[31]=new mycard(31,"戊戌六君子");
    cards[32]=new mycard(32,"西花厅");
    cards[33]=new mycard(33,"香港&澳门");
    cards[34]=new mycard(34,"辛亥革命");
    cards[35]=new mycard(35,"鸦片战争");
    cards[36]=new mycard(36,"洋务运动");
    cards[37]=new mycard(37,"义和团");
    cards[38]=new mycard(38,"袁世凯");
    cards[39]=new mycard(39,"圆明园");
    cards[40]=new mycard(40,"长征");
    cards[41]=new mycard(41,"重庆和谈");
    cards[42]=new mycard(42,"周恩来");

    for (int i=0;i<50;i++)
        com[i]=1;

    list[0].load(":/CI/ComBineImage/comb01.png");

    for(int i=1;i<10;i++)
    {
        QString str = QString(":/CI/ComBineImage/comb0%1.png").arg(QString::number(i));

        list[i].load(str);

    }
    for(int i=10;i<50;i++)
    {
        QString str = QString(":/CI/ComBineImage/comb%1.png").arg(QString::number(i));
        list[i].load(str);

    }

    for(int i=0;i<9;++i)
    {
        count[i]=1;
    }

}


void combine::judge(){
    if(cards[1]->ismine==1)
    {
        if(cards[35]->ismine==1&&cards[8]->ismine==1 &&cards[15]->ismine==1 &&com[1])
        {
            pic[1].setVisible(true);
            score+=20;
            qDebug()<<"天朝梦碎";
            com[1]=0;
            QSound son(":/comyin/comsound1.wav");
            son.play();
            list[1].scaled(pic[1].size(),Qt::KeepAspectRatio);
            pic[1].setScaledContents(true);
            pic[1].setPixmap(list[1]);
            mysleep(6000);
            pic[1].setVisible(false);


        }
        if(cards[35]->ismine==1 && cards[8]->ismine == 1 && cards[15]->ismine == 1 && cards[20]->ismine == 1 && com[2])
        {
            pic[2].setVisible(true);
            score+=40;
            qDebug()<<"山河之殇";
            com[2]=0;
            list[2].scaled(pic[2].size(),Qt::KeepAspectRatio);
            pic[2].setScaledContents(true);
            pic[2].setPixmap(list[2]);
            mysleep(2000);
            pic[2].setVisible(false);

        }
        if(cards[37]->ismine==1&&com[3])
        {
            pic[3].setVisible(true);
            score+=4;
            qDebug()<<"唇亡齿寒";
            com[3]=0;
            list[3].scaled(pic[3].size(),Qt::KeepAspectRatio);
            pic[3].setScaledContents(true);
            pic[3].setPixmap(list[3]);
            mysleep(2000);
            pic[3].setVisible(false);

        }
    }
    if(cards[2]->ismine==1)
    {
        if(cards[4]->ismine == 1 && cards[11]->ismine == 1 && com[4])
        {
            pic[4].setVisible(true);
            score+=10;
            qDebug()<<"伐无道";
            com[4]=0;
            QSound son(":/image/comyin/comsound4.wav");
            son.play();
            list[4].scaled(pic[4].size(),Qt::KeepAspectRatio);
            pic[4].setScaledContents(true);
            pic[4].setPixmap(list[4]);
            mysleep(3500);
            pic[4].setVisible(false);

        }
    }
    if(cards[3]->ismine==1)
    {
        if(cards[29]->ismine == 1 && com[5])
        {
            pic[5].setVisible(true);
            score+=4;
            qDebug()<<"自由先导";
            com[5]=0;
            QSound son(":/image/comyin/comsound5.wav");
            son.play();
            list[5].scaled(pic[5].size(),Qt::KeepAspectRatio);
            pic[5].setScaledContents(true);
            pic[5].setPixmap(list[5]);
            mysleep(5300);
            pic[5].setVisible(false);

        }
        if(cards[24]->ismine == 1 && cards[25]->ismine == 1 && com[6])
        {
            pic[6].setVisible(true);
            score+=10;
            qDebug()<<"北府南行";
            com[6]=0;
            QSound son(":/image/comyin/comsound6.wav");
            son.play();
            list[6].scaled(pic[6].size(),Qt::KeepAspectRatio);
            pic[6].setScaledContents(true);
            pic[6].setPixmap(list[6]);
            mysleep(4000);
            pic[6].setVisible(false);

        }
        if(cards[30]->ismine == 1 && com[7])
        {
            pic[7].setVisible(true);
            score+=4;
            qDebug()<<"京师大学堂";
            com[7]=0;
            list[7].scaled(pic[7].size(),Qt::KeepAspectRatio);
            pic[7].setScaledContents(true);
            pic[7].setPixmap(list[7]);
            mysleep(2000);
            pic[7].setVisible(false);

        }
    }
    if(cards[4]->ismine==1)
    {
        if(cards[38]->ismine==1 && com[8])
        {
            pic[8].setVisible(true);
            score+=4;
            qDebug()<<"浮云蔽日";
            com[8]=0;
            list[8].scaled(pic[8].size(),Qt::KeepAspectRatio);
            pic[8].setScaledContents(true);
            pic[8].setPixmap(list[8]);
            mysleep(2000);
            pic[8].setVisible(false);

        }
    }
    if(cards[5]->ismine==1)
    {
        if(cards[15]->ismine==1 && com[9])
        {
            pic[9].setVisible(true);
            score+=4;
            qDebug()<<"青史留名";
            com[9]=0;
            QSound son(":/comyin/comsound9.wav");
            son.play();
            list[9].scaled(pic[9].size(),Qt::KeepAspectRatio);
            pic[9].setScaledContents(true);
            pic[9].setPixmap(list[9]);
            mysleep(4900);
            pic[9].setVisible(false);

        }
        if(cards[21]->ismine==1 && cards[27]->ismine == 1 && cards[37]->ismine == 1 && cards[31]->ismine == 1 && cards[26]->ismine==1 && cards[23]->ismine==1 && com[10])
        {
            pic[10].setVisible(true);
            score+=80;
            qDebug()<<"烽火英雄";
            com[10]=0;
            list[10].scaled(pic[10].size(),Qt::KeepAspectRatio);
            pic[10].setScaledContents(true);
            pic[10].setPixmap(list[10]);
            mysleep(2000);
            pic[10].setVisible(false);

        }
        if(cards[36]->ismine==1 && com[48])
        {
            pic[48].setVisible(true);
            score+=4;
            qDebug()<<"北洋水师";
            com[48]=0;
            QSound son(":/comyin/comsound48.wav");
            son.play();
            list[48].scaled(pic[48].size(),Qt::KeepAspectRatio);
            pic[48].setScaledContents(true);
            pic[48].setPixmap(list[48]);
            mysleep(11000);
            pic[48].setVisible(false);

        }
    }
    if(cards[6]->ismine==1)
    {
        if(cards[20]->ismine==1 &&com[11])
        {
            pic[11].setVisible(true);
            score+=4;
            qDebug()<<"烽火半生";
            com[11]=0;
            list[11].scaled(pic[11].size(),Qt::KeepAspectRatio);
            pic[11].setScaledContents(true);
            pic[11].setPixmap(list[11]);
            mysleep(2000);
            pic[11].setVisible(false);

        }


        if(cards[33]->ismine==1 && com[12])
        {
            pic[12].setVisible(true);
            score+=4;
            qDebug()<<"回归";
            com[12]=0;
            list[12].scaled(pic[12].size(),Qt::KeepAspectRatio);
            pic[12].setScaledContents(true);
            pic[12].setPixmap(list[12]);
            mysleep(2000);
            pic[12].setVisible(false);


        }
        if(cards[17]->ismine==1 && com[13])
        {
            pic[13].setVisible(true);
            score+=4;
            qDebug()<<"时代之风";
            com[13]=0;
            list[13].scaled(pic[13].size(),Qt::KeepAspectRatio);
            pic[13].setScaledContents(true);
            pic[13].setPixmap(list[13]);
            mysleep(2000);
            pic[13].setVisible(false);


        }
        if(cards[12]->ismine==1 && com[14])
        {
            pic[14].setVisible(true);
            score+=4;
            qDebug()<<"总设计师之梦";
            com[14]=0;
            list[14].scaled(pic[14].size(),Qt::KeepAspectRatio);
            pic[14].setScaledContents(true);
            pic[14].setPixmap(list[14]);
            mysleep(2000);
            pic[14].setVisible(false);

        }
    }
    if(cards[7]->ismine==1)
    {
        if(cards[42]->ismine==1 && com[15])
        {
            pic[15].setVisible(true);
            score+=4;
            qDebug()<<"伉俪情深";
            com[15]=0;
            QSound son(":/image/comyin/comsound15.wav");
            son.play();
            list[15].scaled(pic[15].size(),Qt::KeepAspectRatio);
            pic[15].setScaledContents(true);
            pic[15].setPixmap(list[15]);
            mysleep(5000);
            pic[15].setVisible(false);

        }
        if(cards[42]->ismine==1 && cards[32]->ismine == 1 && com[16])
        {
            pic[16].setVisible(true);
            score+=10;
            qDebug()<<"别鹤孤鸾";
            com[16]=0;
            QSound son(":/comyin/comsound16.wav");
            son.play();
            list[16].scaled(pic[16].size(),Qt::KeepAspectRatio);
            pic[16].setScaledContents(true);
            pic[16].setPixmap(list[16]);
            mysleep(7000);
            pic[16].setVisible(false);

        }
    }
    if(cards[8]->ismine==1)
    {
        if(cards[39]->ismine==1 && com[17])
        {
            pic[17].setVisible(true);
            score+=4;
            qDebug()<<"瑰宝之殇";
            com[17]=0;
            list[17].scaled(pic[17].size(),Qt::KeepAspectRatio);
            pic[17].setScaledContents(true);
            pic[17].setPixmap(list[17]);
            mysleep(2000);
            pic[17].setVisible(false);

        }
        if(cards[27]->ismine==1 && com[41])
        {
            pic[41].setVisible(true);
            score+=4;
            qDebug()<<"挽歌";
            com[41]=0;
            QSound son(":/image/comyin/comsound41.wav");
            son.play();
            list[41].scaled(pic[41].size(),Qt::KeepAspectRatio);
            pic[41].setScaledContents(true);
            pic[41].setPixmap(list[41]);
            mysleep(4000);
            pic[41].setVisible(false);

        }
    }
    if(cards[9]->ismine==1)
    {
        if(cards[29]->ismine==1 && com[18])
        {
            pic[18].setVisible(true);
            score+=4;
            qDebug()<<"觉醒";
            com[18]=0;
            QSound son(":/image/comyin/comsound18.wav");
            son.play();
            list[18].scaled(pic[18].size(),Qt::KeepAspectRatio);
            pic[18].setScaledContents(true);
            pic[18].setPixmap(list[18]);
            mysleep(3500);
            pic[18].setVisible(false);

        }
        if(cards[10]->ismine==1 && cards[22]->ismine == 1 && com[19])
        {
            pic[19].setVisible(true);
            score+=10;
            qDebug()<<"信仰之歌";
            com[19]=0;
            QSound son(":/image/comyin/comsound19.wav");
            son.play();
            list[19].scaled(pic[19].size(),Qt::KeepAspectRatio);
            pic[19].setScaledContents(true);
            pic[19].setPixmap(list[19]);
            mysleep(2000);
            pic[19].setVisible(false);

        }
    }
    if(cards[10]->ismine==1)
    {
        if(cards[14]->ismine==1 && com[20])
        {
            pic[20].setVisible(true);
            score+=4;
            qDebug() << "开天辟地";
            com[20]=0;
            list[20].scaled(pic[20].size(),Qt::KeepAspectRatio);
            pic[20].setScaledContents(true);
            pic[20].setPixmap(list[20]);
            mysleep(2000);
            pic[20].setVisible(false);

        }
        if(cards[18]->ismine==1 && com[21])
        {
            pic[21].setVisible(true);
            score+=4;
            qDebug()<<"红色遗韵";
            com[21]=0;
            QSound son(":/image/comyin/comsound21.wav");
            son.play();
            list[21].scaled(pic[21].size(),Qt::KeepAspectRatio);
            pic[21].setScaledContents(true);
            pic[21].setPixmap(list[21]);
            mysleep(4200);
            pic[21].setVisible(false);

        }
        if(cards[13]->ismine==1 && com[22])
        {
            pic[22].setVisible(true);
            score+=4;
            qDebug()<<"以卫以征";
            com[22]=0;
            QSound son(":/image/comyin/comsound22.wav");
            son.play();
            list[22].scaled(pic[22].size(),Qt::KeepAspectRatio);
            pic[22].setScaledContents(true);
            pic[22].setPixmap(list[22]);
            mysleep(4000);
            pic[22].setVisible(false);

        }
        if(cards[23]->ismine==1 && com[23])
        {
            pic[23].setVisible(true);
            score+=5;
            qDebug()<<"领袖";
            com[23]=0;
            list[23].scaled(pic[23].size(),Qt::KeepAspectRatio);
            pic[23].setScaledContents(true);
            pic[23].setPixmap(list[23]);
            mysleep(2000);
            pic[23].setVisible(false);

        }
    }
    if(cards[11]->ismine==1)
    {
        if(cards[20]->ismine==1 && com[24])
        {
            pic[24].setVisible(true);
            score+=4;
            qDebug()<<"同仇敌忾";
            com[24]=0;
            QSound son(":/image/comyin/comsound24.wav");
            son.play();
            list[24].scaled(pic[24].size(),Qt::KeepAspectRatio);
            pic[24].setScaledContents(true);
            pic[24].setPixmap(list[24]);
            mysleep(6900);
            pic[24].setVisible(false);

        }
    }
    if(cards[12]->ismine==1)
    {
        if(cards[23]->ismine==1 && com[25])
        {
            pic[25].setVisible(true);
            score+=4;
            qDebug() << "东方红";
            com[25]=0;
            list[25].scaled(pic[25].size(),Qt::KeepAspectRatio);
            pic[25].setScaledContents(true);
            pic[25].setPixmap(list[25]);
            mysleep(2000);
            pic[25].setVisible(false);

        }
    }
    if(cards[13]->ismine==1)
    {
        if(cards[23]->ismine==1 && cards[18]->ismine==1 &&com[26])
        {
            pic[26].setVisible(true);
            score+=10;
            qDebug() << "星火燎原";
            com[26]=0;
            QSound son(":/comyin/comsound26.wav");
            son.play();
            list[26].scaled(pic[26].size(),Qt::KeepAspectRatio);
            pic[26].setScaledContents(true);
            pic[26].setPixmap(list[26]);
            mysleep(3500);
            pic[26].setVisible(false);

        }
        if(cards[40]->ismine==1 && com[27])
        {
            pic[27].setVisible(true);
            score+=4;
            qDebug()<<"万里咫尺";
            com[27]=0;
            list[27].scaled(pic[27].size(),Qt::KeepAspectRatio);
            pic[27].setScaledContents(true);
            pic[27].setPixmap(list[27]);
            mysleep(2000);
            pic[27].setVisible(false);

        }
    }
    if(cards[14]->ismine==1)
    {
        ;
    }
    if(cards[15]->ismine){
        if(cards[20]->ismine&&com[28]){
            pic[28].setVisible(true);
            score+=4;
            qDebug()<<"扶桑祸";
            com[28]=0;
            list[28].scaled(pic[28].size(),Qt::KeepAspectRatio);
            pic[28].setScaledContents(true);
            pic[28].setPixmap(list[28]);
            mysleep(2000);
            pic[28].setVisible(false);

        }
    }
    if(cards[16]->ismine){
        if(cards[23]->ismine&&com[29]){
            pic[29].setVisible(true);
            score+=4;
            qDebug()<<"亦敌亦友";
            com[29]=0;
            list[29].scaled(pic[29].size(),Qt::KeepAspectRatio);
            pic[29].setScaledContents(true);
            pic[29].setPixmap(list[29]);
            mysleep(2000);
            pic[29].setVisible(false);

        }
        if(cards[23]->ismine&&cards[41]->ismine&&com[30]){
            pic[30].setVisible(true);
            score+=10;
            qDebug()<<"沧海横流";
            com[30]=0;
            list[30].scaled(pic[30].size(),Qt::KeepAspectRatio);
            pic[30].setScaledContents(true);
            pic[30].setPixmap(list[30]);
            mysleep(2000);
            pic[30].setVisible(false);

        }
        if(cards[40]->ismine&&com[31]){
            pic[31].setVisible(true);
            score+=4;
            qDebug()<<"围剿";
            com[31]=0;
            list[31].scaled(pic[31].size(),Qt::KeepAspectRatio);
            pic[31].setScaledContents(true);
            pic[31].setPixmap(list[31]);
            mysleep(2000);
            pic[31].setVisible(false);

        }
    }
    if(cards[19]->ismine){
        if(cards[23]->ismine&&com[32]){
            pic[32].setVisible(true);
            score+=4;
            qDebug()<<"世纪风采";
            com[32]=0;
            list[32].scaled(pic[32].size(),Qt::KeepAspectRatio);
            pic[32].setScaledContents(true);
            pic[32].setPixmap(list[32]);
            mysleep(2000);
            pic[32].setVisible(false);

        }
        if(cards[42]->ismine&&com[33]){
            pic[33].setVisible(true);
            score+=4;
            qDebug()<<"心潮澎湃";
            com[33]=0;
            list[33].scaled(pic[33].size(),Qt::KeepAspectRatio);
            pic[33].setScaledContents(true);
            pic[33].setPixmap(list[33]);
            mysleep(2000);
            pic[33].setVisible(false);

        }
        if(cards[42]->ismine&&cards[23]->ismine&&com[34]){
            pic[34].setVisible(true);
            score+=10;
            qDebug()<<"夙愿";
            com[34]=0;
            list[34].scaled(pic[34].size(),Qt::KeepAspectRatio);
            pic[34].setScaledContents(true);
            pic[34].setPixmap(list[34]);
            mysleep(2000);
            pic[34].setVisible(false);

        }
    }
    if(cards[21]->ismine){
        if(cards[35]->ismine&&com[35]){
            pic[35].setVisible(true);
            score+=4;
            qDebug()<<"孤掌难鸣";
            com[35]=0;
            QSound son(":/comyin/comsound35.wav");
            son.play();
            list[35].scaled(pic[35].size(),Qt::KeepAspectRatio);
            pic[35].setScaledContents(true);
            pic[35].setPixmap(list[35]);
            mysleep(7000);
            pic[35].setVisible(false);

        }
    }
    if(cards[22]->ismine){

        if(cards[23]->ismine&&com[49]){
            pic[49].setVisible(true);
            score+=4;
            qDebug()<<"曙光";
            com[49]=0;
            list[49].scaled(pic[49].size(),Qt::KeepAspectRatio);
            pic[49].setScaledContents(true);
            pic[49].setPixmap(list[49]);
            mysleep(2000);
            pic[49].setVisible(false);

        }
        if(cards[42]->ismine&&com[36]){
            pic[36].setVisible(true);
            score+=4;
            qDebug()<<"发声者";
            com[36]=0;
            list[36].scaled(pic[36].size(),Qt::KeepAspectRatio);
            pic[36].setScaledContents(true);
            pic[36].setPixmap(list[36]);
            mysleep(2000);
            pic[36].setVisible(false);

        }
    }
    if(cards[23]->ismine){
        if(cards[42]->ismine&&com[37]){
            pic[37].setVisible(true);
            score+=5;
            qDebug()<<"携手同行";
            com[37]=0;
            QSound son(":/image/comyin/comsound37.wav");
            son.play();
            list[37].scaled(pic[37].size(),Qt::KeepAspectRatio);
            pic[37].setScaledContents(true);
            pic[37].setPixmap(list[37]);
            mysleep(6000);
            pic[37].setVisible(false);

        }
        if(cards[24]->ismine&&com[38]){
            pic[38].setVisible(true);
            score+=4;
            qDebug()<<"题字之谊";
            com[38]=0;
            list[38].scaled(pic[38].size(),Qt::KeepAspectRatio);
            pic[38].setScaledContents(true);
            pic[38].setPixmap(list[38]);
            mysleep(2000);
            pic[38].setVisible(false);

        }
    }
    if(cards[24]->ismine){
        if(cards[42]->ismine&&com[39]){
            pic[39].setVisible(true);
            score+=4;
            qDebug()<<"我是爱南开的";
            com[39]=0;
            QSound son(":/comyin/comsound39.wav");
            son.play();
            list[39].scaled(pic[39].size(),Qt::KeepAspectRatio);
            pic[39].setScaledContents(true);
            pic[39].setPixmap(list[39]);
            mysleep(4000);
            pic[39].setVisible(false);

        }
    }
    if(cards[26]->ismine){
        if(cards[34]->ismine&&com[40]){
            pic[40].setVisible(true);
            score+=4;
            qDebug()<<"民国伊始";
            com[40]=0;
            list[40].scaled(pic[40].size(),Qt::KeepAspectRatio);
            pic[40].setScaledContents(true);
            pic[40].setPixmap(list[40]);
            mysleep(2000);
            pic[40].setVisible(false);

        }

    }
    if(cards[28]->ismine){
        if(cards[42]->ismine&&com[42]){
            pic[42].setVisible(true);
            score+=4;
            qDebug()<<"求同存异";
            com[42]=0;
            list[42].scaled(pic[42].size(),Qt::KeepAspectRatio);
            pic[42].setScaledContents(true);
            pic[42].setPixmap(list[42]);
            mysleep(2000);
            pic[42].setVisible(false);

        }
    }
    if(cards[29]->ismine){
        if(cards[24]->ismine&&com[43]){
            pic[43].setVisible(true);
            score+=4;
            qDebug()<<"共百年";
            QSound son(":/comyin/comsound43.wav");
            son.play();
            com[43]=0;
            list[43].scaled(pic[43].size(),Qt::KeepAspectRatio);
            pic[43].setScaledContents(true);
            pic[43].setPixmap(list[43]);
            mysleep(7000);
            pic[43].setVisible(false);

        }
    }
    if(cards[30]->ismine){
        if(cards[34]->ismine&&cards[36]->ismine&&com[44]){
            pic[44].setVisible(true);
            score+=10;
            qDebug()<<"救国初探";
            com[44]=0;
            list[44].scaled(pic[44].size(),Qt::KeepAspectRatio);
            pic[44].setScaledContents(true);
            pic[44].setPixmap(list[44]);
            mysleep(2000);
            pic[44].setVisible(false);

        }
        if(cards[31]->ismine&&com[45]){
            pic[45].setVisible(true);
            score+=4;
            qDebug()<<"肝胆昆仑";
            com[45]=0;
            list[45].scaled(pic[45].size(),Qt::KeepAspectRatio);
            pic[45].setScaledContents(true);
            pic[45].setPixmap(list[45]);
            mysleep(2000);
            pic[45].setVisible(false);


        }

    }
    if(cards[32]->ismine){
        if(cards[42]->ismine&&com[46]){
            pic[46].setVisible(true);
            score+=4;
            qDebug()<<"海棠花开";
            com[46]=0;
            QSound son(":/image/comyin/comsound46.wav");
            son.play();
            list[46].scaled(pic[46].size(),Qt::KeepAspectRatio);
            pic[46].setScaledContents(true);
            pic[46].setPixmap(list[46]);
            mysleep(10000);
            pic[46].setVisible(false);

        }
    }
    if(cards[34]->ismine){
        if(cards[38]->ismine&&com[47]){
            pic[47].setVisible(true);
            score+=4;
            qDebug()<<"别有用心";
            com[47]=0;
            QSound son(":/comyin/comsound47.wav");
            son.play();
            list[47].scaled(pic[47].size(),Qt::KeepAspectRatio);
            pic[47].setScaledContents(true);
            pic[47].setPixmap(list[47]);
            mysleep(4000);
            pic[47].setVisible(false);

        }
    }
}

int combine::judgescore()
{
    int tot=0;
        if(cards[1]->isai==1)
        {
            if(cards[35]->isai==1&&cards[8]->isai==1 &&cards[15]->isai==1 &&com[1])
            {
                tot+=20;
                qDebug()<<"天朝梦碎";
                //com[1]=0;
            }
            if(cards[35]->isai==1 && cards[8]->isai == 1 && cards[15]->isai == 1 && cards[20]->isai == 1 && com[2])
            {
                tot+=40;
                qDebug()<<"山河之殇";
                //com[2]=0;
            }
            if(cards[37]->isai==1&&com[3])
            {

                tot+=4;
                qDebug()<<"唇亡齿寒";
                //com[3]=0;

            }
        }
        if(cards[2]->isai==1)
        {
            if(cards[4]->isai == 1 && cards[11]->isai == 1 && com[4])
            {

                tot+=10;
                qDebug()<<"伐无道";
                //com[4]=0;

            }
        }
        if(cards[3]->isai==1)
        {
            if(cards[29]->isai == 1 && com[5])
            {

                tot+=4;
                qDebug()<<"自由先导";
                //com[5]=0;

            }
            if(cards[24]->isai == 1 && cards[25]->isai == 1 && com[6])
            {

                tot+=10;
                qDebug()<<"北府南行";
                //com[6]=0;

            }
            if(cards[30]->isai == 1 && com[7])
            {

                tot+=4;
                qDebug()<<"京师大学堂";
                //com[7]=0;

            }
        }
        if(cards[4]->isai==1)
        {
            if(cards[38]->isai==1 && com[8])
            {

                tot+=4;
                qDebug()<<"浮云蔽日";
                //com[8]=0;

            }
        }
        if(cards[5]->isai==1)
        {
            if(cards[15]->isai==1 && com[9])
            {

                tot+=4;
                qDebug()<<"青史留名";
                //com[9]=0;

            }
            if(cards[21]->isai==1 && cards[27]->isai == 1 && cards[37]->isai == 1 && cards[31]->isai == 1 && cards[26]->isai==1 && cards[23]->isai==1 && com[10])
            {

                tot+=80;
                qDebug()<<"烽火英雄";
                //com[10]=0;

            }
            if(cards[36]->isai==1 && com[48])
            {

                tot+=4;
                qDebug()<<"北洋水师";
                //com[48]=0;

            }
        }
        if(cards[6]->isai==1)
        {
            if(cards[20]->isai==1 &&com[11])
            {

                tot+=4;
                qDebug()<<"烽火半生";
                //com[11]=0;

            }


            if(cards[33]->isai==1 && com[12])
            {

                tot+=4;
                qDebug()<<"回归";
                //com[12]=0;

            }
            if(cards[17]->isai==1 && com[13])
            {

                tot+=4;
                qDebug()<<"时代之风";
                //com[13]=0;

            }
            if(cards[12]->isai==1 && com[14])
            {

                tot+=4;
                qDebug()<<"总设计师之梦";
                //com[14]=0;

            }
        }
        if(cards[7]->isai==1)
        {
            if(cards[42]->isai==1 && com[15])
            {

                tot+=4;
                qDebug()<<"伉俪情深";
                //com[15]=0;

            }
            if(cards[42]->isai==1 && cards[32]->isai == 1 && com[16])
            {

                tot+=10;
                qDebug()<<"别鹤孤鸾";
                //com[16]=0;

            }
        }
        if(cards[8]->isai==1)
        {
            if(cards[39]->isai==1 && com[17])
            {

                tot+=4;
                qDebug()<<"瑰宝之殇";
                //com[17]=0;

            }
            if(cards[27]->isai==1 && com[41])
            {

                tot+=4;
                qDebug()<<"挽歌";
                //com[41]=0;

            }
        }
        if(cards[9]->isai==1)
        {
            if(cards[29]->isai==1 && com[18])
            {

                tot+=4;
                qDebug()<<"觉醒";
                //com[18]=0;

            }
            if(cards[10]->isai==1 && cards[22]->isai == 1 && com[19])
            {

                tot+=10;
                qDebug()<<"信仰之歌";
                //com[19]=0;

            }
        }
        if(cards[10]->isai==1)
        {
            if(cards[14]->isai==1 && com[20])
            {

                tot+=4;
                qDebug() << "开天辟地";
                //com[20]=0;

            }
            if(cards[18]->isai==1 && com[21])
            {

                tot+=4;
                qDebug()<<"红色遗韵";
                //com[21]=0;

            }
            if(cards[13]->isai==1 && com[22])
            {

                tot+=4;
                qDebug()<<"以卫以征";
                //com[22]=0;

            }
            if(cards[23]->isai==1 && com[23])
            {

                tot+=5;
                qDebug()<<"领袖";
                //com[23]=0;

            }
        }
        if(cards[11]->isai==1)
        {
            if(cards[20]->isai==1 && com[24])
            {

                tot+=4;
                qDebug()<<"同仇敌忾";
                //com[24]=0;

            }
        }
        if(cards[12]->isai==1)
        {
            if(cards[23]->isai==1 && com[25])
            {

                tot+=4;
                qDebug() << "东方红";
                //com[25]=0;

            }
        }
        if(cards[13]->isai==1)
        {
            if(cards[23]->isai==1 && cards[18]->isai==1 &&com[26])
            {

                tot+=10;
                qDebug() << "星火燎原";
                //com[26]=0;

            }
            if(cards[40]->isai==1 && com[27])
            {

                tot+=4;
                qDebug()<<"万里咫尺";
                //com[27]=0;

            }
        }
        if(cards[14]->isai==1)
        {
            ;
        }
        if(cards[15]->isai){
            if(cards[20]->isai&&com[28]){

                tot+=4;
                qDebug()<<"扶桑祸";
                //com[28]=0;

            }
        }
        if(cards[16]->isai){
            if(cards[23]->isai&&com[29]){

                tot+=4;
                qDebug()<<"亦敌亦友";
                //com[29]=0;

            }
            if(cards[23]->isai&&cards[41]->isai&&com[30]){

                tot+=10;
                qDebug()<<"沧海横流";
                //com[30]=0;

            }
            if(cards[40]->isai&&com[31]){

                tot+=4;
                qDebug()<<"围剿";
                //com[31]=0;

            }
        }
        if(cards[19]->isai){
            if(cards[23]->isai&&com[32]){

                tot+=4;
                qDebug()<<"世纪风采";
                //com[32]=0;

            }
            if(cards[42]->isai&&com[33]){

                tot+=4;
                qDebug()<<"心潮澎湃";
                //com[33]=0;

            }
            if(cards[42]->isai&&cards[23]->isai&&com[34]){

                tot+=10;
                qDebug()<<"夙愿";
                //com[34]=0;

            }
        }
        if(cards[21]->isai){
            if(cards[35]->isai&&com[35]){

                tot+=4;
                qDebug()<<"孤掌难鸣";
                //com[35]=0;

            }
        }
        if(cards[22]->isai){

            if(cards[23]->isai&&com[49]){

                tot+=4;
                qDebug()<<"曙光";
                //com[49]=0;

            }
            if(cards[42]->isai&&com[36]){

                tot+=4;
                qDebug()<<"发声者";
                //com[36]=0;

            }
        }
        if(cards[23]->isai){
            if(cards[42]->isai&&com[37]){

                tot+=5;
                qDebug()<<"携手同行";
                //com[37]=0;

            }
            if(cards[24]->isai&&com[38]){

                tot+=4;
                qDebug()<<"题字之谊";
                //com[38]=0;

            }
        }
        if(cards[24]->isai){
            if(cards[42]->isai&&com[39]){

                tot+=4;
                qDebug()<<"我是爱南开的";
                //com[39]=0;

            }
        }
        if(cards[26]->isai){
            if(cards[34]->isai&&com[40]){

                tot+=4;
                qDebug()<<"民国伊始";
                //com[40]=0;

            }

        }
        if(cards[28]->isai){
            if(cards[42]->isai&&com[42]){

                tot+=4;
                qDebug()<<"求同存异";
                //com[42]=0;

            }
        }
        if(cards[29]->isai){
            if(cards[24]->isai&&com[43]){

                tot+=4;
                qDebug()<<"共百年";
                //com[43]=0;

            }
        }
        if(cards[30]->isai){
            if(cards[34]->isai&&cards[36]->isai&&com[44]){

                tot+=10;
                qDebug()<<"救国初探";
                //com[44]=0;

            }
            if(cards[31]->isai&&com[45]){

                tot+=4;
                qDebug()<<"肝胆昆仑";
                //com[45]=0;

            }

        }
        if(cards[32]->isai){
            if(cards[42]->isai&&com[46]){

                tot+=4;
                qDebug()<<"海棠花开";
                //com[46]=0;

            }
        }
        if(cards[34]->isai){
            if(cards[38]->isai&&com[47]){

                tot+=4;
                qDebug()<<"别有用心";
                //com[47]=0;

            }
        }
        return tot;
}

int combine::judgescore2()
{
    int tot=0;
        if(cards[1]->ismine==1)
        {
            if(cards[35]->ismine==1&&cards[8]->ismine==1 &&cards[15]->ismine==1 &&com[1])
            {
                tot+=20;
                qDebug()<<"天朝梦碎";
                //com[1]=0;
            }
            if(cards[35]->ismine==1 && cards[8]->ismine == 1 && cards[15]->ismine == 1 && cards[20]->ismine == 1 && com[2])
            {
                tot+=40;
                qDebug()<<"山河之殇";
                //com[2]=0;
            }
            if(cards[37]->ismine==1&&com[3])
            {

                tot+=4;
                qDebug()<<"唇亡齿寒";
                //com[3]=0;

            }
        }
        if(cards[2]->ismine==1)
        {
            if(cards[4]->ismine == 1 && cards[11]->ismine == 1 && com[4])
            {

                tot+=10;
                qDebug()<<"伐无道";
                //com[4]=0;

            }
        }
        if(cards[3]->ismine==1)
        {
            if(cards[29]->ismine == 1 && com[5])
            {

                tot+=4;
                qDebug()<<"自由先导";
                //com[5]=0;

            }
            if(cards[24]->ismine == 1 && cards[25]->ismine == 1 && com[6])
            {

                tot+=10;
                qDebug()<<"北府南行";
                //com[6]=0;

            }
            if(cards[30]->ismine == 1 && com[7])
            {

                tot+=4;
                qDebug()<<"京师大学堂";
                //com[7]=0;

            }
        }
        if(cards[4]->ismine==1)
        {
            if(cards[38]->ismine==1 && com[8])
            {

                tot+=4;
                qDebug()<<"浮云蔽日";
                //com[8]=0;

            }
        }
        if(cards[5]->ismine==1)
        {
            if(cards[15]->ismine==1 && com[9])
            {

                tot+=4;
                qDebug()<<"青史留名";
                //com[9]=0;

            }
            if(cards[21]->ismine==1 && cards[27]->ismine == 1 && cards[37]->ismine == 1 && cards[31]->ismine == 1 && cards[26]->ismine==1 && cards[23]->ismine==1 && com[10])
            {

                tot+=80;
                qDebug()<<"烽火英雄";
                //com[10]=0;

            }
            if(cards[36]->ismine==1 && com[48])
            {

                tot+=4;
                qDebug()<<"北洋水师";
                //com[48]=0;

            }
        }
        if(cards[6]->ismine==1)
        {
            if(cards[20]->ismine==1 &&com[11])
            {

                tot+=4;
                qDebug()<<"烽火半生";
                //com[11]=0;

            }


            if(cards[33]->ismine==1 && com[12])
            {

                tot+=4;
                qDebug()<<"回归";
                //com[12]=0;

            }
            if(cards[17]->ismine==1 && com[13])
            {

                tot+=4;
                qDebug()<<"时代之风";
                //com[13]=0;

            }
            if(cards[12]->ismine==1 && com[14])
            {

                tot+=4;
                qDebug()<<"总设计师之梦";
                //com[14]=0;

            }
        }
        if(cards[7]->ismine==1)
        {
            if(cards[42]->ismine==1 && com[15])
            {

                tot+=4;
                qDebug()<<"伉俪情深";
                //com[15]=0;

            }
            if(cards[42]->ismine==1 && cards[32]->ismine == 1 && com[16])
            {

                tot+=10;
                qDebug()<<"别鹤孤鸾";
                //com[16]=0;

            }
        }
        if(cards[8]->ismine==1)
        {
            if(cards[39]->ismine==1 && com[17])
            {

                tot+=4;
                qDebug()<<"瑰宝之殇";
                //com[17]=0;

            }
            if(cards[27]->ismine==1 && com[41])
            {

                tot+=4;
                qDebug()<<"挽歌";
                //com[41]=0;

            }
        }
        if(cards[9]->ismine==1)
        {
            if(cards[29]->ismine==1 && com[18])
            {

                tot+=4;
                qDebug()<<"觉醒";
                //com[18]=0;

            }
            if(cards[10]->ismine==1 && cards[22]->ismine == 1 && com[19])
            {

                tot+=10;
                qDebug()<<"信仰之歌";
                //com[19]=0;

            }
        }
        if(cards[10]->ismine==1)
        {
            if(cards[14]->ismine==1 && com[20])
            {

                tot+=4;
                qDebug() << "开天辟地";
                //com[20]=0;

            }
            if(cards[18]->ismine==1 && com[21])
            {

                tot+=4;
                qDebug()<<"红色遗韵";
                //com[21]=0;

            }
            if(cards[13]->ismine==1 && com[22])
            {

                tot+=4;
                qDebug()<<"以卫以征";
                //com[22]=0;

            }
            if(cards[23]->ismine==1 && com[23])
            {

                tot+=5;
                qDebug()<<"领袖";
                //com[23]=0;

            }
        }
        if(cards[11]->ismine==1)
        {
            if(cards[20]->ismine==1 && com[24])
            {

                tot+=4;
                qDebug()<<"同仇敌忾";
                //com[24]=0;

            }
        }
        if(cards[12]->ismine==1)
        {
            if(cards[23]->ismine==1 && com[25])
            {

                tot+=4;
                qDebug() << "东方红";
                //com[25]=0;

            }
        }
        if(cards[13]->ismine==1)
        {
            if(cards[23]->ismine==1 && cards[18]->ismine==1 &&com[26])
            {

                tot+=10;
                qDebug() << "星火燎原";
                //com[26]=0;

            }
            if(cards[40]->ismine==1 && com[27])
            {

                tot+=4;
                qDebug()<<"万里咫尺";
                //com[27]=0;

            }
        }
        if(cards[14]->ismine==1)
        {
            ;
        }
        if(cards[15]->ismine){
            if(cards[20]->ismine&&com[28]){

                tot+=4;
                qDebug()<<"扶桑祸";
                //com[28]=0;

            }
        }
        if(cards[16]->ismine){
            if(cards[23]->ismine&&com[29]){

                tot+=4;
                qDebug()<<"亦敌亦友";
                //com[29]=0;

            }
            if(cards[23]->ismine&&cards[41]->ismine&&com[30]){

                tot+=10;
                qDebug()<<"沧海横流";
                //com[30]=0;

            }
            if(cards[40]->ismine&&com[31]){

                tot+=4;
                qDebug()<<"围剿";
                //com[31]=0;

            }
        }
        if(cards[19]->ismine){
            if(cards[23]->ismine&&com[32]){

                tot+=4;
                qDebug()<<"世纪风采";
                //com[32]=0;

            }
            if(cards[42]->ismine&&com[33]){

                tot+=4;
                qDebug()<<"心潮澎湃";
                //com[33]=0;

            }
            if(cards[42]->ismine&&cards[23]->ismine&&com[34]){

                tot+=10;
                qDebug()<<"夙愿";
                //com[34]=0;

            }
        }
        if(cards[21]->ismine){
            if(cards[35]->ismine&&com[35]){

                tot+=4;
                qDebug()<<"孤掌难鸣";
                //com[35]=0;

            }
        }
        if(cards[22]->ismine){

            if(cards[23]->ismine&&com[49]){

                tot+=4;
                qDebug()<<"曙光";
                //com[49]=0;

            }
            if(cards[42]->ismine&&com[36]){

                tot+=4;
                qDebug()<<"发声者";
                //com[36]=0;

            }
        }
        if(cards[23]->ismine){
            if(cards[42]->ismine&&com[37]){

                tot+=5;
                qDebug()<<"携手同行";
                //com[37]=0;

            }
            if(cards[24]->ismine&&com[38]){

                tot+=4;
                qDebug()<<"题字之谊";
                //com[38]=0;

            }
        }
        if(cards[24]->ismine){
            if(cards[42]->ismine&&com[39]){

                tot+=4;
                qDebug()<<"我是爱南开的";
                //com[39]=0;

            }
        }
        if(cards[26]->ismine){
            if(cards[34]->ismine&&com[40]){

                tot+=4;
                qDebug()<<"民国伊始";
                //com[40]=0;

            }

        }
        if(cards[28]->ismine){
            if(cards[42]->ismine&&com[42]){

                tot+=4;
                qDebug()<<"求同存异";
                //com[42]=0;

            }
        }
        if(cards[29]->ismine){
            if(cards[24]->ismine&&com[43]){

                tot+=4;
                qDebug()<<"共百年";
                //com[43]=0;

            }
        }
        if(cards[30]->ismine){
            if(cards[34]->ismine&&cards[36]->ismine&&com[44]){

                tot+=10;
                qDebug()<<"救国初探";
                //com[44]=0;

            }
            if(cards[31]->ismine&&com[45]){

                tot+=4;
                qDebug()<<"肝胆昆仑";
                //com[45]=0;

            }

        }
        if(cards[32]->ismine){
            if(cards[42]->ismine&&com[46]){

                tot+=4;
                qDebug()<<"海棠花开";
                //com[46]=0;

            }
        }
        if(cards[34]->ismine){
            if(cards[38]->ismine&&com[47]){

                tot+=4;
                qDebug()<<"别有用心";
                //com[47]=0;

            }
        }
        return tot;
}
