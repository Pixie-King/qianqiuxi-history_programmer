#include "azcombine.h"
#include"mycard.h"
#include<QDebug>
#include<QTimer>
#include<QSound>
#include<QApplication>
#include<QTime>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

void aimysleep(int msec)
{
    QTime reachtime = QTime::currentTime().addMSecs(msec);
    while(QTime::currentTime()<reachtime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100);
    }
}

azcombine::azcombine()
{
    sentence.setAttribute(Qt::WA_TranslucentBackground,true);
    sentence.setGeometry(40,50,150,200);
    sentence.setFontFamily("楷体");
    sentence.setFontPointSize(14);
    sentence.setFontWeight(63);
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
    {
        com[i]=1;
    }

    for(int i=0;i<9;++i)
    {
        this->count[i]=1;
    }

    combineNum = 0;
    for(int i=0;i<50;i++)
    {
        CombineName[i]="null";
    }
}


void azcombine::aijudge(){
    combineNum = 0;
    if(cards[1]->ismine==1)
    {
        if(cards[35]->ismine==1&&cards[8]->ismine==1 &&cards[15]->ismine==1 &&com[1])
        {
            score+=20;
            CombineName[combineNum] ="天朝梦碎";
            com[1]=0;
            combineNum+=1;
        }
        if(cards[35]->ismine==1 && cards[8]->ismine == 1 && cards[15]->ismine == 1 && cards[20]->ismine == 1 && com[2])
        {
            score+=40;
            CombineName[combineNum] ="山河之殇";
            com[2]=0;
            combineNum+=1;
        }
        if(cards[37]->ismine==1&&com[3])
        {
            score+=4;
            CombineName[combineNum] ="唇亡齿寒";
            com[3]=0;
            combineNum+=1;
        }
    }
    if(cards[2]->ismine==1)
    {
        if(cards[4]->ismine == 1 && cards[11]->ismine == 1 && com[4])
        {
            score+=10;
            CombineName[combineNum] ="伐无道";
            com[4]=0;
            combineNum+=1;
        }
    }
    if(cards[3]->ismine==1)
    {
        if(cards[29]->ismine == 1 && com[5])
        {
            score+=4;
            CombineName[combineNum] ="自由先导";
            com[5]=0;
            combineNum+=1;
        }
        if(cards[24]->ismine == 1 && cards[25]->ismine == 1 && com[6])
        {
            score+=10;
            CombineName[combineNum] ="北府南行";
            com[6]=0;
            combineNum+=1;
        }
        if(cards[30]->ismine == 1 && com[7])
        {
            score+=4;
            CombineName[combineNum] ="京师大学堂";
            com[7]=0;
            combineNum+=1;
        }
    }
    if(cards[4]->ismine==1)
    {
        if(cards[38]->ismine==1 && com[8])
        {
            score+=4;
            CombineName[combineNum] ="浮云蔽日";
            com[8]=0;
            combineNum+=1;
        }
    }
    if(cards[5]->ismine==1)
    {
        if(cards[15]->ismine==1 && com[9])
        {
            score+=4;
            CombineName[combineNum] ="青史留名";
            com[9]=0;
            combineNum+=1;

        }
        if(cards[21]->ismine==1 && cards[27]->ismine == 1 && cards[37]->ismine == 1 && cards[31]->ismine == 1 && cards[26]->ismine==1 && cards[23]->ismine==1 && com[10])
        {
            score+=80;
            CombineName[combineNum] ="烽火英雄";
            com[10]=0;
            combineNum+=1;

        }
        if(cards[36]->ismine==1 && com[48])
        {

            score+=4;
            CombineName[combineNum] ="北洋水师";
            com[48]=0;
            combineNum+=1;

        }
    }
    if(cards[6]->ismine==1)
    {
        if(cards[20]->ismine==1 &&com[11])
        {
            score+=4;
            CombineName[combineNum] ="烽火半生";
            com[11]=0;
            combineNum+=1;

        }


        if(cards[33]->ismine==1 && com[12])
        {
            score+=4;
            CombineName[combineNum] ="回归";
            com[12]=0;
            combineNum+=1;

        }
        if(cards[17]->ismine==1 && com[13])
        {
            score+=4;
            CombineName[combineNum] ="时代之风";
            com[13]=0;
            combineNum+=1;

        }
        if(cards[12]->ismine==1 && com[14])
        {
            score+=4;
            CombineName[combineNum] ="总设计师之梦";
            com[14]=0;
            combineNum+=1;

        }
    }
    if(cards[7]->ismine==1)
    {
        if(cards[42]->ismine==1 && com[15])
        {
            score+=4;
            CombineName[combineNum] ="伉俪情深";
            com[15]=0;
            combineNum+=1;
        }
        if(cards[42]->ismine==1 && cards[32]->ismine == 1 && com[16])
        {
            score+=10;
            CombineName[combineNum] ="别鹤孤鸾";
            com[16]=0;
            combineNum+=1;

        }
    }
    if(cards[8]->ismine==1)
    {
        if(cards[39]->ismine==1 && com[17])
        {
            score+=4;
            CombineName[combineNum] ="瑰宝之殇";
            com[17]=0;
            combineNum+=1;
        }
        if(cards[27]->ismine==1 && com[41])
        {
            score+=4;
            CombineName[combineNum] ="挽歌";
            com[41]=0;
        }
    }
    if(cards[9]->ismine==1)
    {
        if(cards[29]->ismine==1 && com[18])
        {
            score+=4;
            CombineName[combineNum] ="觉醒";
            com[18]=0;
            combineNum+=1;
        }
        if(cards[10]->ismine==1 && cards[22]->ismine == 1 && com[19])
        {
            score+=10;
            CombineName[combineNum] ="信仰之歌";
            com[19]=0;
            combineNum+=1;

        }
    }
    if(cards[10]->ismine==1)
    {
        if(cards[14]->ismine==1 && com[20])
        {
            score+=4;
           CombineName[combineNum] ="开天辟地";
            com[20]=0;
            combineNum+=1;


        }
        if(cards[18]->ismine==1 && com[21])
        {

            score+=4;
            CombineName[combineNum] ="红色遗韵";
            com[21]=0;
            combineNum+=1;


        }
        if(cards[13]->ismine==1 && com[22])
        {

            score+=4;
            CombineName[combineNum] ="以卫以征";
            com[22]=0;
            combineNum+=1;

        }
        if(cards[23]->ismine==1 && com[23])
        {

            score+=5;
            CombineName[combineNum] ="领袖";
            com[23]=0;
            combineNum+=1;

        }
    }
    if(cards[11]->ismine==1)
    {
        if(cards[20]->ismine==1 && com[24])
        {

            score+=4;
            CombineName[combineNum] ="同仇敌忾";
            com[24]=0;
            combineNum+=1;

        }
    }
    if(cards[12]->ismine==1)
    {
        if(cards[23]->ismine==1 && com[25])
        {

            score+=4;
           CombineName[combineNum] = "东方红";
            com[25]=0;
            combineNum+=1;

        }
    }
    if(cards[13]->ismine==1)
    {
        if(cards[23]->ismine==1 && cards[18]->ismine==1 &&com[26])
        {

            score+=10;
            CombineName[combineNum] ="星火燎原";
            com[26]=0;
            combineNum+=1;


        }
        if(cards[40]->ismine==1 && com[27])
        {

            score+=4;
            CombineName[combineNum] ="万里咫尺";
            com[27]=0;
            combineNum+=1;


        }
    }
    if(cards[14]->ismine==1)
    {
        ;
    }
    if(cards[15]->ismine){
        if(cards[20]->ismine&&com[28]){

            score+=4;
            CombineName[combineNum] ="扶桑祸";
            com[28]=0;
            combineNum+=1;

        }
    }
    if(cards[16]->ismine){
        if(cards[23]->ismine&&com[29]){

            score+=4;
            CombineName[combineNum] ="亦敌亦友";
            com[29]=0;
            combineNum+=1;


        }
        if(cards[23]->ismine&&cards[41]->ismine&&com[30]){

            score+=10;
            CombineName[combineNum] ="沧海横流";
            com[30]=0;
            combineNum+=1;

        }
        if(cards[40]->ismine&&com[31]){

            score+=4;
            CombineName[combineNum] ="围剿";
            com[31]=0;
            combineNum+=1;

        }
    }
    if(cards[19]->ismine){
        if(cards[23]->ismine&&com[32]){

            score+=4;
            CombineName[combineNum] ="世纪风采";
            com[32]=0;
            combineNum+=1;


        }
        if(cards[42]->ismine&&com[33]){

            score+=4;
            CombineName[combineNum] ="心潮澎湃";
            com[33]=0;
            combineNum+=1;

        }
        if(cards[42]->ismine&&cards[23]->ismine&&com[34]){

            score+=10;
            CombineName[combineNum] ="夙愿";
            com[34]=0;
            combineNum+=1;

        }
    }
    if(cards[21]->ismine){
        if(cards[35]->ismine&&com[35]){
            score+=4;
            CombineName[combineNum] ="孤掌难鸣";
            com[35]=0;
            combineNum+=1;
        }
    }
    if(cards[22]->ismine){

        if(cards[23]->ismine&&com[49]){

            score+=4;
            CombineName[combineNum] ="曙光";
            com[49]=0;
            combineNum+=1;


        }
        if(cards[42]->ismine&&com[36]){

            score+=4;
            CombineName[combineNum] ="发声者";
            com[36]=0;
            combineNum+=1;


        }
    }
    if(cards[23]->ismine){
        if(cards[42]->ismine&&com[37]){

            score+=5;
            CombineName[combineNum] ="相得益彰";
            com[37]=0;
            combineNum+=1;

        }
        if(cards[24]->ismine&&com[38]){

            score+=4;
            CombineName[combineNum] ="题字之谊";
            com[38]=0;
            combineNum+=1;


        }
    }
    if(cards[24]->ismine){
        if(cards[42]->ismine&&com[39]){

            score+=4;
            CombineName[combineNum] ="我是爱南开的";
            com[39]=0;
            combineNum+=1;


        }
    }
    if(cards[26]->ismine){
        if(cards[34]->ismine&&com[40]){

            score+=4;
            CombineName[combineNum] ="民国伊始";
            com[40]=0;
            combineNum+=1;


        }

    }
    if(cards[28]->ismine){
        if(cards[42]->ismine&&com[42]){

            score+=4;
            CombineName[combineNum] ="求同存异";
            com[42]=0;
            combineNum+=1;


        }
    }
    if(cards[29]->ismine){
        if(cards[24]->ismine&&com[43]){

            score+=4;
            CombineName[combineNum] ="共百年";
            com[43]=0;
            combineNum+=1;


        }
    }
    if(cards[30]->ismine){
        if(cards[34]->ismine&&cards[36]->ismine&&com[44]){

            score+=10;
            CombineName[combineNum] ="救国初探";
            com[44]=0;
            combineNum+=1;


        }
        if(cards[31]->ismine&&com[45]){

            score+=4;
            CombineName[combineNum] ="肝胆昆仑";
            com[45]=0;
            combineNum+=1;



        }

    }
    if(cards[32]->ismine){
        if(cards[42]->ismine&&com[46]){

            score+=4;
            CombineName[combineNum] ="海棠花开";
            com[46]=0;
            combineNum+=1;


        }
    }
    if(cards[34]->ismine){
        if(cards[38]->ismine&&com[47]){

            score+=4;
            CombineName[combineNum] ="别有用心";
            com[47]=0;
            combineNum+=1;
        }
    }

    for(int uto=0;uto<combineNum;uto++)
    {
        //qDebug()<<uto<<CombineName[uto];
        sentence.setText(QString("对方完成组合:" + CombineName[uto]));
        aimysleep(500);
    }
}

int azcombine::judgescore()
{
    int tot=0;
    if(cards[1]->isai==1)
    {
        if(cards[35]->isai==1&&cards[8]->isai==1 &&cards[15]->isai==1 &&com[1])
        {
            tot+=20;
        }
        if(cards[35]->isai==1 && cards[8]->isai == 1 && cards[15]->isai == 1 && cards[20]->isai == 1 && com[2])
        {
            tot+=40;
        }
        if(cards[37]->isai==1&&com[3])
        {

            tot+=4;
        }
    }
    if(cards[2]->isai==1)
    {
        if(cards[4]->isai == 1 && cards[11]->isai == 1 && com[4])
        {

            tot+=10;

        }
    }
    if(cards[3]->isai==1)
    {
        if(cards[29]->isai == 1 && com[5])
        {

            tot+=4;

        }
        if(cards[24]->isai == 1 && cards[25]->isai == 1 && com[6])
        {

            tot+=10;


        }
        if(cards[30]->isai == 1 && com[7])
        {

            tot+=4;


        }
    }
    if(cards[4]->isai==1)
    {
        if(cards[38]->isai==1 && com[8])
        {

            tot+=4;


        }
    }
    if(cards[5]->isai==1)
    {
        if(cards[15]->isai==1 && com[9])
        {

            tot+=4;


        }
        if(cards[21]->isai==1 && cards[27]->isai == 1 && cards[37]->isai == 1 && cards[31]->isai == 1 && cards[26]->isai==1 && cards[23]->isai==1 && com[10])
        {

            tot+=80;


        }
        if(cards[36]->isai==1 && com[48])
        {

            tot+=4;


        }
    }
    if(cards[6]->isai==1)
    {
        if(cards[20]->isai==1 &&com[11])
        {

            tot+=4;


        }


        if(cards[33]->isai==1 && com[12])
        {

            tot+=4;


        }
        if(cards[17]->isai==1 && com[13])
        {

            tot+=4;


        }
        if(cards[12]->isai==1 && com[14])
        {

            tot+=4;


        }
    }
    if(cards[7]->isai==1)
    {
        if(cards[42]->isai==1 && com[15])
        {

            tot+=4;

        }
        if(cards[42]->isai==1 && cards[32]->isai == 1 && com[16])
        {

            tot+=10;

        }
    }
    if(cards[8]->isai==1)
    {
        if(cards[39]->isai==1 && com[17])
        {

            tot+=4;


        }
        if(cards[27]->isai==1 && com[41])
        {

            tot+=4;


        }
    }
    if(cards[9]->isai==1)
    {
        if(cards[29]->isai==1 && com[18])
        {

            tot+=4;

        }
        if(cards[10]->isai==1 && cards[22]->isai == 1 && com[19])
        {

            tot+=10;

        }
    }
    if(cards[10]->isai==1)
    {
        if(cards[14]->isai==1 && com[20])
        {

            tot+=4;


        }
        if(cards[18]->isai==1 && com[21])
        {

            tot+=4;

        }
        if(cards[13]->isai==1 && com[22])
        {

            tot+=4;


        }
        if(cards[23]->isai==1 && com[23])
        {

            tot+=5;


        }
    }
    if(cards[11]->isai==1)
    {
        if(cards[20]->isai==1 && com[24])
        {

            tot+=4;


        }
    }
    if(cards[12]->isai==1)
    {
        if(cards[23]->isai==1 && com[25])
        {

            tot+=4;


        }
    }
    if(cards[13]->isai==1)
    {
        if(cards[23]->isai==1 && cards[18]->isai==1 &&com[26])
        {

            tot+=10;


        }
        if(cards[40]->isai==1 && com[27])
        {

            tot+=4;


        }
    }
    if(cards[14]->isai==1)
    {
        ;
    }
    if(cards[15]->isai){
        if(cards[20]->isai&&com[28]){

            tot+=4;

        }
    }
    if(cards[16]->isai){
        if(cards[23]->isai&&com[29]){

            tot+=4;


        }
        if(cards[23]->isai&&cards[41]->isai&&com[30]){

            tot+=10;


        }
        if(cards[40]->isai&&com[31]){

            tot+=4;

        }
    }
    if(cards[19]->isai){
        if(cards[23]->isai&&com[32]){

            tot+=4;

        }
        if(cards[42]->isai&&com[33]){

            tot+=4;

        }
        if(cards[42]->isai&&cards[23]->isai&&com[34]){

            tot+=10;

        }
    }
    if(cards[21]->isai){
        if(cards[35]->isai&&com[35]){

            tot+=4;

        }
    }
    if(cards[22]->isai){

        if(cards[23]->isai&&com[49]){

            tot+=4;


        }
        if(cards[42]->isai&&com[36]){

            tot+=4;


        }
    }
    if(cards[23]->isai){
        if(cards[42]->isai&&com[37]){

            tot+=5;


        }
        if(cards[24]->isai&&com[38]){

            tot+=4;


        }
    }
    if(cards[24]->isai){
        if(cards[42]->isai&&com[39]){

            tot+=4;


        }
    }
    if(cards[26]->isai){
        if(cards[34]->isai&&com[40]){

            tot+=4;


        }

    }
    if(cards[28]->isai){
        if(cards[42]->isai&&com[42]){

            tot+=4;


        }
    }
    if(cards[29]->isai){
        if(cards[24]->isai&&com[43]){

            tot+=4;


        }
    }
    if(cards[30]->isai){
        if(cards[34]->isai&&cards[36]->isai&&com[44]){

            tot+=10;


        }
        if(cards[31]->isai&&com[45]){

            tot+=4;


        }

    }
    if(cards[32]->isai){
        if(cards[42]->isai&&com[46]){

            tot+=4;

        }
    }
    if(cards[34]->isai){
        if(cards[38]->isai&&com[47]){

            tot+=4;


        }
    } for(int ip=0;ip<42;ip++)
        qDebug()<<ip<<cards[ip]->isai;
    qDebug()<<"tot = "<<tot;
    return tot;
}

int azcombine::judgescore2()
{
    int tot=0;
    if(cards[1]->ismine==1)
    {
        if(cards[35]->ismine==1&&cards[8]->ismine==1 &&cards[15]->ismine==1 &&com[1])
        {
            tot+=20;

        }
        if(cards[35]->ismine==1 && cards[8]->ismine == 1 && cards[15]->ismine == 1 && cards[20]->ismine == 1 && com[2])
        {
            tot+=40;

        }
        if(cards[37]->ismine==1&&com[3])
        {

            tot+=4;


        }
    }
    if(cards[2]->ismine==1)
    {
        if(cards[4]->ismine == 1 && cards[11]->ismine == 1 && com[4])
        {

            tot+=10;


        }
    }
    if(cards[3]->ismine==1)
    {
        if(cards[29]->ismine == 1 && com[5])
        {

            tot+=4;


        }
        if(cards[24]->ismine == 1 && cards[25]->ismine == 1 && com[6])
        {

            tot+=10;

        }
        if(cards[30]->ismine == 1 && com[7])
        {

            tot+=4;


        }
    }
    if(cards[4]->ismine==1)
    {
        if(cards[38]->ismine==1 && com[8])
        {

            tot+=4;


        }
    }
    if(cards[5]->ismine==1)
    {
        if(cards[15]->ismine==1 && com[9])
        {

            tot+=4;


        }
        if(cards[21]->ismine==1 && cards[27]->ismine == 1 && cards[37]->ismine == 1 && cards[31]->ismine == 1 && cards[26]->ismine==1 && cards[23]->ismine==1 && com[10])
        {

            tot+=80;


        }
        if(cards[36]->ismine==1 && com[48])
        {

            tot+=4;


        }
    }
    if(cards[6]->ismine==1)
    {
        if(cards[20]->ismine==1 &&com[11])
        {

            tot+=4;


        }


        if(cards[33]->ismine==1 && com[12])
        {

            tot+=4;


        }
        if(cards[17]->ismine==1 && com[13])
        {

            tot+=4;


        }
        if(cards[12]->ismine==1 && com[14])
        {

            tot+=4;


        }
    }
    if(cards[7]->ismine==1)
    {
        if(cards[42]->ismine==1 && com[15])
        {

            tot+=4;


        }
        if(cards[42]->ismine==1 && cards[32]->ismine == 1 && com[16])
        {

            tot+=10;

        }
    }
    if(cards[8]->ismine==1)
    {
        if(cards[39]->ismine==1 && com[17])
        {

            tot+=4;

        }
        if(cards[27]->ismine==1 && com[41])
        {

            tot+=4;


        }
    }
    if(cards[9]->ismine==1)
    {
        if(cards[29]->ismine==1 && com[18])
        {

            tot+=4;

        }
        if(cards[10]->ismine==1 && cards[22]->ismine == 1 && com[19])
        {

            tot+=10;


        }
    }
    if(cards[10]->ismine==1)
    {
        if(cards[14]->ismine==1 && com[20])
        {

            tot+=4;


        }
        if(cards[18]->ismine==1 && com[21])
        {

            tot+=4;


        }
        if(cards[13]->ismine==1 && com[22])
        {

            tot+=4;


        }
        if(cards[23]->ismine==1 && com[23])
        {

            tot+=5;

        }
    }
    if(cards[11]->ismine==1)
    {
        if(cards[20]->ismine==1 && com[24])
        {

            tot+=4;


        }
    }
    if(cards[12]->ismine==1)
    {
        if(cards[23]->ismine==1 && com[25])
        {

            tot+=4;


        }
    }
    if(cards[13]->ismine==1)
    {
        if(cards[23]->ismine==1 && cards[18]->ismine==1 &&com[26])
        {

            tot+=10;


        }
        if(cards[40]->ismine==1 && com[27])
        {

            tot+=4;


        }
    }
    if(cards[14]->ismine==1)
    {
        ;
    }
    if(cards[15]->ismine){
        if(cards[20]->ismine&&com[28]){

            tot+=4;


        }
    }
    if(cards[16]->ismine){
        if(cards[23]->ismine&&com[29]){

            tot+=4;


        }
        if(cards[23]->ismine&&cards[41]->ismine&&com[30]){

            tot+=10;


        }
        if(cards[40]->ismine&&com[31]){

            tot+=4;

        }
    }
    if(cards[19]->ismine){
        if(cards[23]->ismine&&com[32]){

            tot+=4;

        }
        if(cards[42]->ismine&&com[33]){

            tot+=4;


        }
        if(cards[42]->ismine&&cards[23]->ismine&&com[34]){

            tot+=10;

        }
    }
    if(cards[21]->ismine){
        if(cards[35]->ismine&&com[35]){

            tot+=4;


        }
    }
    if(cards[22]->ismine){

        if(cards[23]->ismine&&com[49]){

            tot+=4;


        }
        if(cards[42]->ismine&&com[36]){

            tot+=4;


        }
    }
    if(cards[23]->ismine){
        if(cards[42]->ismine&&com[37]){

            tot+=5;


        }
        if(cards[24]->ismine&&com[38]){

            tot+=4;


        }
    }
    if(cards[24]->ismine){
        if(cards[42]->ismine&&com[39]){

            tot+=4;


        }
    }
    if(cards[26]->ismine){
        if(cards[34]->ismine&&com[40]){

            tot+=4;


        }

    }
    if(cards[28]->ismine){
        if(cards[42]->ismine&&com[42]){

            tot+=4;


        }
    }
    if(cards[29]->ismine){
        if(cards[24]->ismine&&com[43]){

            tot+=4;


        }
    }
    if(cards[30]->ismine){
        if(cards[34]->ismine&&cards[36]->ismine&&com[44]){

            tot+=10;


        }
        if(cards[31]->ismine&&com[45]){

            tot+=4;


        }

    }
    if(cards[32]->ismine){
        if(cards[42]->ismine&&com[46]){

            tot+=4;


        }
    }
    if(cards[34]->ismine){
        if(cards[38]->ismine&&com[47]){

            tot+=4;


        }
    }

    return tot;
}
