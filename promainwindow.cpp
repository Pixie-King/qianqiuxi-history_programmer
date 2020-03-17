#include "promainwindow.h"
#include "ui_promainwindow.h"
#include "QScrollArea"
#include "qdebug.h"
#include "qrandom.h"
#include "qlabel.h"
#include "QTime"
#include "mylabel.h"
#include<QTime>
#include"QTextEdit"
#include"combine.h"
#include"azcombine.h"
#include<QTimer>
#include<QSound>
#include<mypushbutton1.h>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif


promainwindow::promainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::promainwindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    this->setWindowTitle("千秋戏");
    this->setFixedSize(1500,900);
    QTextEdit *edit=new QTextEdit(this);
    informationshow(edit);
    scoredit->setParent(this);
    scoredit2->setParent(this);
    mycombine=new proCombine();
    mycombine->score=0;
    aicombine=new proai();
    aicombine->score=0;
    scoreshow();

    QPixmap retrnnn(":/image/Image/back.png");
    mylabel *ptn0=new mylabel;
    ptn0->setParent(this);
    ptn0->setAttribute(Qt::WA_TranslucentBackground,true);
    ptn0->setPixmap(retrnnn);
    ptn0->setGeometry(1250,750,150,150);


    labelfan1->setParent(ui->page2);
    labeltui1->setParent(ui->page2);
    labelfan1->setGeometry(100,570,220,70);
    labeltui1->setGeometry(100,720,220,70);
    labelfan1->setAttribute(Qt::WA_TranslucentBackground,true);
    labeltui1->setAttribute(Qt::WA_TranslucentBackground,true);

    labelfan2->setParent(ui->page3);
    labeltui2->setParent(ui->page3);
    labelfan2->setGeometry(330,610,220,70);
    labeltui2->setGeometry(330,760,220,70);
    labelfan2->setAttribute(Qt::WA_TranslucentBackground,true);
    labeltui2->setAttribute(Qt::WA_TranslucentBackground,true);

    connect(labelfan1,&mylabel::clicked,[=](){
        QSound *son = new QSound(":/sound/Sound/beginclick.wav");
        son->play();
        emit fan();
        this->close();
    });

    connect(labelfan2,&mylabel::clicked,[=](){
        QSound *son = new QSound(":/sound/Sound/beginclick.wav");
        son->play();
        emit fan();
        this->close();

    });

    connect(labeltui1,&mylabel::clicked,[=](){
        QSound *son = new QSound(":/sound/Sound/beginclick.wav");
        son->play();
        emit tui();
        this->close();


    });

    connect(labeltui2,&mylabel::clicked,[=](){
        QSound *son = new QSound(":/sound/Sound/beginclick.wav");
        son->play();
        emit tui();
        this->close();

    });
    connect(ptn0,&mylabel::clicked,[=](){
        QSound son (":/sound/Sound/beginclick.wav");
        son.play();
        this->close();
        emit fan();

    });


    QString str=":/image2/00";
    for(int i=0;i<38;i++)
    {
        if(i<10)
        {
            str[10]=i+'0';
        }
        else {
            str[9]=i/10+'0';
            str[10]=i%10+'0';
        }
        pixmap[i].load(str);
    }
    for(int i=0;i<=38;i++){snum[i]=1;}
    for(int i=0;i<17;i++){num[i]=0;};
    label_0->setParent(this);
    labelk->setParent(this);
    labelc->setParent(this);
    random();
    allphoto();
    photo();
    midphoto();
    labelk->setVisible(false);
    for(int i=0;i<39;i++){
        mycombine->pic[i].setParent(this);
        mycombine->pic[i].setVisible(false);
        mycombine->pic[i].move(130,250);
        mycombine->pic[i].resize(1200,400);
    }
    aicombine->sentence.setParent(this);
    stringg();
    for(int i=1;i<9;i++)
    {
        connect(label+i,&mylabel::enter,[=]()
        {
            edit->setText(string[num[i]]);
        });
    }
    for(int i=1;i<8;i++)
    {
        connect(label2+i,&mylabel::enter,[=]()
        {
            edit->setText(string[num[i+16]]);
        });
    }
    for(int i=1;i<9;i++)
    {
        connect(label+i,&mylabel::clicked,[=]()
        {
            player=new QMediaPlayer();
            player->setMedia(QUrl("qrc:/yin/activate.mp3"));
            player->play();

            for(int j=1;j<9;j++)
            {
                label[j].move(label[j].x(),650);
            }
            for(int k=1;k<8;k++)
            {
                label2[k].move(label2[k].x(),350);
            }
            label[i].move(label[i].x(),label[i].y()-30);
            if(num[i]<=10&&num[i]>=1)
            {
                for(int k=1;k<8;k++)
                {
                    if(num[k+16]<=10&&num[k+16]>=1)
                        label2[k].move(label2[k].x(),label2[k].y()-30);
                }
            }
            if(num[i]<=19&&num[i]>=11)
            {
                for(int k=1;k<8;k++)
                {
                    if(num[k+16]<=19&&num[k+16]>=11)
                        label2[k].move(label2[k].x(),label2[k].y()-30);
                }
            }
            if(num[i]<=28&&num[i]>=20)
            {
                for(int k=1;k<8;k++)
                {
                    if(num[k+16]<=28&&num[k+16]>=20)
                        label2[k].move(label2[k].x(),label2[k].y()-30);
                }
            }
            if(num[i]<=37&&num[i]>=29)
            {
                for(int k=1;k<8;k++)
                {
                    if(num[k+16]<=37&&num[k+16]>=29)
                        label2[k].move(label2[k].x(),label2[k].y()-30);
                }
            }
        });
    }
    for(int i=1;i<=7;i++){
        connect(label2+i,&mylabel::clicked2,[=]()
        {
            player1=new QMediaPlayer();
            player1->setMedia(QUrl("qrc:/yin/combo.mp3"));
            player1->play();
            bool flag=0;
            if(!flag&&(num[i+16]<=10&&num[i+16]>=1))
            {
                for(int j=1;j<=8;j++){
                    if(label[j].y()==620){
                        if((num[j]<=10&&num[j]>=1)){
                            mycombine->cards[num[i+16]]->ismine=1;                    //让牌池的牌进入mine；
                            mycombine->cards[num[j]]->ismine=1;
                            ptn0->setVisible(false);
                            mycombine->judge();
                            ptn0->setVisible(true);
                            scoreshow();
                            label[j].setVisible(false);
                            label[j].move(label[j].x(),label[j].y()+30);
                            labelk->setVisible(true);
                            labelc->setPixmap(pixmap[num[j]]);
                            labelc->setScaledContents(true);
                            mycombine->count[j]=0;
                            mycombine->score+=4;
                            scoreshow();
                            replace(label2,i);
                            for(int m=j+1;m<=8;m++){
                                label[m].setGeometry(label[m].x()-100,label[m].y(),150,200);
                            }

                            for(int k=1;k<8;k++)
                            {
                                label2[k].move(label2[k].x(),350);
                            }
                            flag=1;
                            break;
                        }
                    }
                    else
                        continue;
                }
            }
            if(!flag&&(num[i+16]<=19&&num[i+16]>=11)){

                for(int j=1;j<=8;j++){
                    if(label[j].y()==620){
                        if((num[j]<=19&&num[j]>=11)){
                            mycombine->cards[num[i+16]]->ismine=1;
                            mycombine->cards[num[j]]->ismine=1;     //让自己的手牌进入mine;
                            ptn0->setVisible(false);
                            mycombine->judge();
                            ptn0->setVisible(true);
                            scoreshow();
                            label[j].setVisible(false);
                            label[j].move(label[j].x(),label[j].y()+30);
                            labelk->setVisible(true);
                            labelc->setPixmap(pixmap[num[j]]);
                            labelc->setScaledContents(true);
                            mycombine->count[j]=0;
                            mycombine->score+=4;
                            scoreshow();
                            replace(label2,i);
                            for(int m=j+1;m<=8;m++){
                                label[m].setGeometry(label[m].x()-100,label[m].y(),150,200);
                            }

                            for(int k=1;k<8;k++)
                            {
                                label2[k].move(label2[k].x(),350);
                            }
                            flag=1;
                            break;


                        }
                    }
                    else continue;
                }
            }
            if(!flag&&(num[i+16]<=28&&num[i+16]>=20)){

                for(int j=1;j<=8;j++){
                    if(label[j].y()==620){
                        if((num[j]<=28&&num[j]>=20)){
                            mycombine->cards[num[i+16]]->ismine=1;
                            mycombine->cards[num[j]]->ismine=1;     //让自己的手牌进入mine;
                            ptn0->setVisible(false);
                            mycombine->judge();
                            ptn0->setVisible(true);
                            scoreshow();
                            label[j].setVisible(false);
                            label[j].move(label[j].x(),label[j].y()+30);
                            labelk->setVisible(true);
                            labelc->setPixmap(pixmap[num[j]]);
                            labelc->setScaledContents(true);
                            mycombine->count[j]=0;
                            mycombine->score+=4;
                            scoreshow();
                            replace(label2,i);
                            for(int m=j+1;m<=8;m++){
                                label[m].setGeometry(label[m].x()-100,label[m].y(),150,200);
                            }
                            for(int k=1;k<8;k++)
                            {
                                label2[k].move(label2[k].x(),350);
                            }
                            flag=1;
                            break;
                        }
                    }
                    else continue;
                }
            }
            if(!flag&&(num[i+16]<=37&&num[i+16]>=29))
            {

                for(int j=1;j<=8;j++){
                    if(label[j].y()==620){
                        if((num[j]<=37&&num[j]>=29)){
                            mycombine->cards[num[i+16]]->ismine=1;
                            mycombine->cards[num[j]]->ismine=1;     //让自己的手牌进入mine;

                            ptn0->setVisible(false);
                            mycombine->judge();
                            ptn0->setVisible(true);
                            scoreshow();
                            label[j].setVisible(false);
                            label[j].move(label[j].x(),label[j].y()+30);
                            labelk->setVisible(true);
                            labelc->setPixmap(pixmap[num[j]]);
                            labelc->setScaledContents(true);
                            mycombine->count[j]=0;
                            mycombine->score+=4;
                            scoreshow();
                            replace(label2,i);
                            for(int m=j+1;m<=8;m++){
                                label[m].setGeometry(label[m].x()-100,label[m].y(),150,200);
                            }
                            for(int k=1;k<8;k++)
                            {
                                label2[k].move(label2[k].x(),350);
                            }
                            flag=1;
                            break;
                        }
                    }
                    else continue;
                }
            }
                        if(flag)
                            //第一个ai
                            if(prowhichone==1)
                            {
                                player1=new QMediaPlayer();
                                player1->setMedia(QUrl("qrc:/yin/combo.mp3"));
                           l1:  bool have=0;
                                int k=7,j=8;
                                for(;k>0;--k)
                                {
                                    if(num[k+16]<=10&&num[k+16]>=1)
                                        for(j=8;j>0;--j)
                                            if((aicombine->count[j])&&(num[j+8]<=10&&num[j+8]>=1))
                                            {
                                                have=1;
                                                break;
                                            }
                                    if(num[k+16]<=19&&num[k+16]>=11)
                                        for(j=8;j>0;--j)
                                            if((aicombine->count[j])&&(num[j+8]<=19&&num[j+8]>=11))
                                            {
                                                have=1;
                                                break;
                                            }
                                    if(num[k+16]<=28&&num[k+16]>=20)
                                        for(j=8;j>0;--j)
                                            if((aicombine->count[j])&&(num[j+8]<=28&&num[j+8]>=20))
                                            {
                                                have=1;
                                                break;
                                            }
                                    if(num[k+16]<=37&&num[k+16]>=29)
                                        for(j=8;j>0;--j)
                                            if((aicombine->count[j])&&(num[j+8]<=37&&num[j+8]>=29))
                                            {
                                                have=1;
                                                break;
                                            }
                                    if(have)
                                        break;

                                }
                                if(k>0&&j>0)
                                {
                                    aicombine->count[j]=0;
                                    aicombine->cards[num[k+16]]->ismine=1; //让牌池的牌进入mine；
                                    aicombine->cards[num[k+16]]->isai=1;
                                    aicombine->cards[num[j+8]]->ismine=1;
                                    aicombine->aijudge();
                                    scoreshow();
                                    aicombine->score+=4;
                                    scoreshow();
                                    label[j+8].setVisible(false);
                                    for(int m1=j+9;m1<=16;m1++){
                                        label[m1].setGeometry(label[m1].x()-100,label[m1].y(),150,200);
                                    }
                                    replace(label2,k);
                                    if(isend(aicombine)){
                                        if(aicombine->score>mycombine->score){
                                            playerend=new QMediaPlayer();
                                            playerend->setMedia(QUrl("qrc:/yin/lose.mp3"));
                                            playerend->play();
                                            ui->page3->setParent(this);
                                            ui->page3->show();
                                            connect(labelc,&mylabel::clicked,[=](){
                                                QSound *son1 =new QSound("qrc:/sound/Sound/beginclick.wav");
                                                son1->play();
                                                showcard();
                                                ui->page3->hide();
                                            });
                                            connect(labelr,&mylabel::clicked,[=]()
                                            {
                                                QSound *son =new QSound("qrc:/sound/Sound/beginclick.wav");
                                                son->play();
                                                ui->page1->hide();
                                                ui->page3->setParent(this);
                                                ui->page3->show();
                                            });
                                        }
                                        else if (aicombine->score<=mycombine->score) {
                                            playerend=new QMediaPlayer();
                                            playerend->setMedia(QUrl("qrc:/yin/win.mp3"));
                                            playerend->play();
                                            ui->page2->setParent(this);
                                            ui->page2->show();
                                            connect(labelc,&mylabel::clicked,[=](){
                                                QSound *son1 =new QSound("qrc:/sound/Sound/beginclick.wav");
                                                son1->play();
                                                showcard();
                                                ui->page2->hide();
                                            });
                                            connect(labelr,&mylabel::clicked,[=]()
                                            {
                                                QSound *son =new QSound("qrc:/sound/Sound/beginclick.wav");
                                                son->play();
                                                ui->page1->hide();
                                                ui->page2->setParent(this);
                                                ui->page2->show();
                                            });
                                        }

                                    }
                                }
                                else
                                {
                                    exchange(aicombine,0);
                                    goto l1;
                                }
                            }
                            //第二个ai
                            else
                                {
                                if(prowhichone==2)
                            {
                                player1=new QMediaPlayer();
                                player1->setMedia(QUrl("qrc:/yin/combo.mp3"));
                             l2:
                                bool have=0;
                                int k=7,j=8,a=0,b=0,max=0,temp=0;
                                for(;k>0;--k)
                                {
                                    if(num[k+16]<=10&&num[k+16]>=1)
                                        for(j=8;j>0;--j)
                                            if((aicombine->count[j])&&(num[j+8]<=10&&num[j+8]>=1))
                                            {
                                                aicombine->cards[num[k+16]]->isai=1;
                                                temp=aicombine->judgescore();


                                                if(temp>=max)
                                                {
                                                    a=k;
                                                    b=j;
                                                    max=temp;
                                                }
                                                qDebug()<<max<<temp;

                                                aicombine->cards[num[k+16]]->isai=0;
                                                have=1;
                                            }
                                    if(num[k+16]<=19&&num[k+16]>=11)
                                        for(j=8;j>0;--j)
                                            if((aicombine->count[j])&&(num[j+8]<=19&&num[j+8]>=11))
                                            {
                                                aicombine->cards[num[k+16]]->isai=1;
                                                temp=aicombine->judgescore();

                                                if(temp>=max)
                                                {
                                                    a=k;
                                                    b=j;
                                                    max=temp;
                                                }

                                                qDebug()<<max<<temp;

                                                aicombine->cards[num[k+16]]->isai=0;
                                                have=1;
                                            }
                                    if(num[k+16]<=28&&num[k+16]>=20)
                                        for(j=8;j>0;--j)
                                            if((aicombine->count[j])&&(num[j+8]<=28&&num[j+8]>=20))
                                            {
                                                aicombine->cards[num[k+16]]->isai=1;
                                                temp=aicombine->judgescore();
                                                if(temp>=max)
                                                {
                                                    a=k;
                                                    b=j;
                                                    max=temp;
                                                }
                                                qDebug()<<max<<temp;
                                                aicombine->cards[num[k+16]]->isai=0;
                                                have=1;
                                            }
                                    if(num[k+16]<=37&&num[k+16]>=29)
                                        for(j=8;j>0;--j)
                                            if((aicombine->count[j])&&(num[j+8]<=37&&num[j+8]>=29))
                                            {
                                                aicombine->cards[num[k+16]]->isai=1;
                                                temp=aicombine->judgescore();


                                                if(temp>=max)
                                                {
                                                    a=k;
                                                    b=j;
                                                    max=temp;
                                                }
                                                 qDebug()<<max<<temp;
                                                aicombine->cards[num[k+16]]->isai=0;
                                                have=1;
                                            }
                                }
                                if(have)
                                {
                                    aicombine->count[b]=0;
                                    qDebug()<<b<<aicombine->count[b];
                                    aicombine->cards[num[a+16]]->ismine=1; //让牌池的牌进入mine；
                                    aicombine->cards[num[a+16]]->isai=1;
                                    aicombine->cards[num[b+8]]->ismine=1;

                                    aicombine->aijudge();

                                    scoreshow();
                                    aicombine->score+=4;
                                    scoreshow();
                                    label[b+8].setVisible(false);
                                    for(int m1=b+9;m1<=16;m1++){
                                        label[m1].setGeometry(label[m1].x()-100,label[m1].y(),150,200);
                                    }
                                    replace(label2,a);
                                    qDebug()<<isend(aicombine);
                                    if(isend(aicombine)){
                                        if(aicombine->score>mycombine->score){
                                            playerend=new QMediaPlayer();
                                            playerend->setMedia(QUrl("qrc:/yin/lose.mp3"));
                                            playerend->play();
                                            ui->page3->setParent(this);
                                            ui->page3->show();
                                            connect(labelc,&mylabel::clicked,[=](){
                                                QSound *son1 =new QSound("qrc:/sound/Sound/beginclick.wav");
                                                son1->play();
                                                showcard();
                                                ui->page3->hide();
                                            });
                                            connect(labelr,&mylabel::clicked,[=]()
                                            {
                                                QSound *son =new QSound("qrc:/sound/Sound/beginclick.wav");
                                                son->play();
                                                ui->page1->hide();
                                                ui->page3->setParent(this);
                                                ui->page3->show();
                                            });
                                        }
                                        else if (aicombine->score<=mycombine->score) {
                                            playerend=new QMediaPlayer();
                                            playerend->setMedia(QUrl("qrc:/yin/win.mp3"));
                                            playerend->play();
                                            ui->page2->setParent(this);
                                            ui->page2->show();
                                            connect(labelc,&mylabel::clicked,[=](){
                                                QSound *son1 =new QSound("qrc:/sound/Sound/beginclick.wav");
                                                son1->play();
                                                showcard();
                                                ui->page2->hide();
                                            });
                                            connect(labelr,&mylabel::clicked,[=]()
                                            {
                                                QSound *son =new QSound("qrc:/sound/Sound/beginclick.wav");
                                                son->play();
                                                ui->page1->hide();
                                                ui->page2->setParent(this);
                                                ui->page2->show();
                                            });
                                        }

                                    }
                                }
                                else
                                {
                                    exchange(aicombine,0);
                                    goto l2;
                                }

                            }
                            }
                        //第三个ai
                        if(prowhichone==3)
                        {
                            player1=new QMediaPlayer();
                            player1->setMedia(QUrl("qrc:/yin/combo.mp3"));
                      l3:   bool have=0;
                            int k=7,j=8,a=0,b=0,max=0,temp1=0,temp2=0;
                            for(;k>0;--k)
                            {
                                if(num[k+16]<=10&&num[k+16]>=1)
                                    for(j=8;j>0;--j)
                                        if((aicombine->count[j])&&(num[j+8]<=10&&num[j+8]>=1))
                                        {
                                            aicombine->cards[num[k+16]]->isai=1;
                                            temp1=aicombine->judgescore();
                                            aicombine->cards[num[k+16]]->isai=0;
                                            mycombine->cards[num[k+16]]->ismine=1;
                                            temp2=mycombine->judgescore2();
                                            mycombine->cards[num[k+16]]->ismine=0;
                                            if(temp1+temp2>max)
                                            {
                                               a=k;
                                               b=j;
                                               max=temp1+temp2;
                                            }
                                            have=1;
                                        }
                                if(num[k+16]<=19&&num[k+16]>=11)
                                    for(j=8;j>0;--j)
                                        if((aicombine->count[j])&&(num[j+8]<=19&&num[j+8]>=11))
                                        {
                                            aicombine->cards[num[k+16]]->isai=1;
                                            temp1=aicombine->judgescore();
                                            aicombine->cards[num[k+16]]->isai=0;
                                            mycombine->cards[num[k+16]]->ismine=1;
                                            temp2=mycombine->judgescore2();
                                            mycombine->cards[num[k+16]]->ismine=0;
                                            if(temp1+temp2>max)
                                            {
                                               a=k;
                                               b=j;
                                               max=temp1+temp2;
                                            }
                                            have=1;
                                        }
                                if(num[k+16]<=28&&num[k+16]>=20)
                                    for(j=8;j>0;--j)
                                        if((aicombine->count[j])&&(num[j+8]<=28&&num[j+8]>=20))
                                        {
                                            aicombine->cards[num[k+16]]->isai=1;
                                            temp1=aicombine->judgescore();
                                            aicombine->cards[num[k+16]]->isai=0;
                                            mycombine->cards[num[k+16]]->ismine=1;
                                            temp2=mycombine->judgescore2();
                                            mycombine->cards[num[k+16]]->ismine=0;
                                            if(temp1+temp2>max)
                                            {
                                               a=k;
                                               b=j;
                                               max=temp1+temp2;
                                            }
                                            have=1;
                                        }
                                if(num[k+16]<=37&&num[k+16]>=29)
                                    for(j=8;j>0;--j)
                                        if((aicombine->count[j])&&(num[j+8]<=37&&num[j+8]>=29))
                                        {
                                            aicombine->cards[num[k+16]]->isai=1;
                                            temp1=aicombine->judgescore();
                                            aicombine->cards[num[k+16]]->isai=0;
                                            mycombine->cards[num[k+16]]->ismine=1;
                                            temp2=mycombine->judgescore2();
                                            mycombine->cards[num[k+16]]->ismine=0;
                                            if(temp1+temp2>max)
                                            {
                                               a=k;
                                               b=j;
                                               max=temp1+temp2;
                                            }
                                            have=1;
                                        }
                            }
                            if(have)
                            {
                                aicombine->count[b]=0;
                                aicombine->cards[num[a+16]]->ismine=1; //让牌池的牌进入mine；
                                aicombine->cards[num[a+16]]->isai=1;
                                aicombine->cards[num[b+8]]->ismine=1;

                                aicombine->aijudge();

                                scoreshow();
                                aicombine->score+=4;
                                scoreshow();
                                label[b+8].setVisible(false);
                                for(int m1=b+9;m1<=16;m1++){
                                    label[m1].setGeometry(label[m1].x()-100,label[m1].y(),150,200);
                                }
                                replace(label2,a);
                                if(isend(aicombine)){
                                    if(aicombine->score>mycombine->score){
                                        playerend=new QMediaPlayer();
                                        playerend->setMedia(QUrl("qrc:/yin/lose.mp3"));
                                        playerend->play();
                                        ui->page3->setParent(this);
                                        ui->page3->show();
                                        connect(labelc,&mylabel::clicked,[=](){
                                            QSound *son1 =new QSound("qrc:/sound/Sound/beginclick.wav");
                                            son1->play();
                                            showcard();
                                            ui->page3->hide();
                                        });
                                        connect(labelr,&mylabel::clicked,[=]()
                                        {
                                            QSound *son =new QSound("qrc:/sound/Sound/beginclick.wav");
                                            son->play();
                                            ui->page1->hide();
                                            ui->page3->setParent(this);
                                            ui->page3->show();
                                        });
                                    }
                                    else if (aicombine->score<=mycombine->score) {
                                        playerend=new QMediaPlayer();
                                        playerend->setMedia(QUrl("qrc:/yin/win.mp3"));
                                        playerend->play();
                                        ui->page2->setParent(this);
                                        ui->page2->show();
                                        connect(labelc,&mylabel::clicked,[=](){
                                            QSound *son1 =new QSound("qrc:/sound/Sound/beginclick.wav");
                                            son1->play();
                                            showcard();
                                            ui->page2->hide();
                                        });
                                        connect(labelr,&mylabel::clicked,[=]()
                                        {
                                            QSound *son =new QSound("qrc:/sound/Sound/beginclick.wav");
                                            son->play();
                                            ui->page1->hide();
                                            ui->page2->setParent(this);
                                            ui->page2->show();
                                        });
                                    }

                                }
                            }
                            else
                            {
                                exchange(aicombine,0);
                                goto l3;
                            }
                        }
        });
    }
    connect(label_0,&mylabel::clicked,[=]()
    {

        while(!ischose(mycombine))
        {
            exchange(mycombine,1);
            player2=new QMediaPlayer();
            player2->setMedia(QUrl("qrc:/yin/discard.mp3"));
            player2->play();
        }
    });
    ui->page1->hide();
    ui->page2->hide();
    ui->page3->hide();
    connect(labelc,&mylabel::clicked,[=](){
        QSound *son1 =new QSound("qrc:/sound/Sound/beginclick.wav");
        son1->play();
        showcard();
    });
    connect(labelr,&mylabel::clicked,[=]()
    {
        QSound *son =new QSound("qrc:/sound/Sound/beginclick.wav");
        son->play();
        ui->page1->hide();
    });
}

void promainwindow::showcard()
{
    ui->page1->setParent(this);
    editt->setParent(ui->page1);
    editt->setGeometry(560,0,380,90);
    editt->setFontFamily("华文行楷");
    editt->setFontPointSize(40);
    editt->setText("我  方  卡  牌");
    editt->setReadOnly(true);
    editt->setAttribute(Qt::WA_TranslucentBackground,true);
    labelr->setParent(ui->page1);
    labelr->setGeometry(1020,650,380,200);
    labelr->setAttribute(Qt::WA_TranslucentBackground,true);
    QPixmap pp1;
    pp1.load(":/image1/re");
    pp1.scaled(labelr->size(),Qt::KeepAspectRatio);
    labelr->setScaledContents(true);
    labelr->setPixmap(pp1);
    const int w=230;
    const int h=280;
    int jj=0;
    for (int ii=1;ii<=37;ii++) {
        if(mycombine->cards[ii]->ismine)
        {
            labelch[ii-1].setParent(ui->page1);
            labelch[ii-1].setGeometry((jj%6)*w+100,(jj/6)*h+90,150,200);
            labelch[ii-1].setScaledContents(true);
            labelch[ii-1].setPixmap(pixmap[ii]);
            jj++;
        }
    }
    ui->page1->show();

}

void promainwindow::allphoto()
{
    labelk->setGeometry(32,642,166,216);
    labelk->setAttribute(Qt::WA_TranslucentBackground,true);
    QPixmap pp;
    pp.load(":/image/image1/kk");
    pp.scaled(labelk->size(),Qt::KeepAspectRatio);
    labelk->setScaledContents(true);
    labelk->setPixmap(pp);
    label_0->setGeometry(1040,340,150,200);
    QPixmap pixmap_0;
    pixmap_0.load(":/image2/38.png");
    pixmap_0.scaled(label_0->size(),Qt::KeepAspectRatio);
    label_0->setScaledContents(true);
    label_0->setPixmap(pixmap_0);
    labelc->setGeometry(40,650,150,200);
    labelc->setAttribute(Qt::WA_TranslucentBackground,true);
}

void promainwindow::random()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i=1;i<24; )
    {
        int n=qrand()%37+1;
        if(snum[n]!=0)
        {
            snum[n]=0;
            num[i]=n;
            if(i>=9&&i<=23)
            {
                //                aicombine->cards[num[i]]->isai=1;
            }
            i++;
        }
    }

}

void promainwindow::photo()
{
    for(int i=1;i<9;i++)
    {
        label[i].setParent(this);
        label[i].setGeometry(140+100*i,650,150,200);
        pixmap[num[i]].scaled(label[i].size(),Qt::KeepAspectRatio);
        label[i].setScaledContents(true);
        label[i].setPixmap(pixmap[num[i]]);
    }
    for(int i=9;i<17;i++)
    {
        label[i].setParent(this);
        label[i].setGeometry(140+100*(i-8),50,150,200);
        pixmap[0].scaled(label[i].size(),Qt::KeepAspectRatio);
        label[i].setScaledContents(true);
        label[i].setPixmap(pixmap[0]);
    }
}

void promainwindow::midphoto()
{
    for(int i=1;i<=7;i++)
    {
        label2[i].setParent(this);
        label2[i].setGeometry(80+110*i,350,150,200);
        pixmap[num[i+16]].scaled(label2[i].size(),Qt::KeepAspectRatio);
        label2[i].setScaledContents(true);
        label2[i].setPixmap(pixmap[num[i+16]]);
    }
}

void promainwindow::stringg()
{
    string[0]="牌背面";
    string[1]="【C】                             可组合的卡牌： C++、汇编语言、Java、Python、JavaScript";
    string[2]="【Python】                        可组合的卡牌：C、汇编语言、Java、C++、JavaScript";
    string[3]="【=】                             可组合的卡牌：==";
    string[4]="【double】                        可组合的卡牌：int、char、float、enum、bool";
    string[5]="【*】                             可组合的卡牌：new、&、->、链表";
    string[6]="【virtual】                       可组合的卡牌：class、函数、抽象类、虚基类";
    string[7]="【private】                       可组合的卡牌：public、protected、class";
    string[8]="【->】                            可组合的卡牌：*、this、class";
    string[9]="【队列】                           可组合的卡牌：链表、栈";
    string[10]="【tail】                         可组合的卡牌：head、链表";
    string[11]="【C++】                          可组合的卡牌：C、汇编语言、Java、Python、JavaScript、class";
    string[12]="【JavaScript】                   可组合的卡牌：C、C++、汇编语言、Java、Python";
    string[13]="【==】                           可组合的卡牌：=";
    string[14]="【float】                        可组合的卡牌：int、char、double、enum、bool";
    string[15]="【&】                            可组合的卡牌：*、抽象类";
    string[16]="【虚基类】                        可组合的卡牌：virtual、抽象类";
    string[17]="【protected】                    可组合的卡牌：public、protected、class";
    string[18]="【this】                         可组合的卡牌：class、->";
    string[19]="【函数】                          可组合的卡牌：栈、class、virtual、抽象类";
    string[20]="【汇编语言】                      可组合的卡牌：C、C++、Java、Python、JavaScript";
    string[21]="【new】                          可组合的卡牌：delete、*";
    string[22]="【int】                          可组合的卡牌：char、double、float、enum、bool";
    string[23]="【enum】                         可组合的卡牌：int、char、double、float、bool";
    string[24]="【struct】                       可组合的卡牌：class、public";
    string[25]="【抽象类】                        可组合的卡牌：virtual、虚基类、函数";
    string[26]="【true】                         可组合的卡牌：bool、false";
    string[27]="【链表】                          可组合的卡牌：*、栈、队列、head、tail";
    string[28]="【~】                            可组合的卡牌：delete";
    string[29]="【Java】                         可组合的卡牌：C、C++、汇编语言、Python、JavaScript、class";
    string[30]="【delete】                        可组合的卡牌：new、~";
    string[31]="【char】                         可组合的卡牌：int、double、float、enum、bool";
    string[32]="【bool】                          可组合的卡牌：int、char、double、float、enum、true、false";
    string[33]="【class】                        可组合的卡牌：struct、virtual、public、private、protected、this、->、函数、C++、Java";
    string[34]="【public】                        可组合的卡牌：private、protected、class、struct";
    string[35]="【false】                        可组合的卡牌：bool、true";
    string[36]="【栈】                            可组合的卡牌：链表、队列、函数";
    string[37]="【head】                          可组合的卡牌：tail、链表";
}

void promainwindow::replace(mylabel *lab,int i)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int n=qrand()%37+1;
    while(snum[n]==0){
        n=(qrand()%37)+1;
    }
    snum[n]=0;
    num[i+16]=n;
    //    lab[i].setParent(this);
    //    lab[i].setGeometry(80+110*i,350,150,200);
    pixmap[num[i+16]].scaled(lab[i].size(),Qt::KeepAspectRatio);
    lab[i].setScaledContents(true);
    lab[i].setPixmap(pixmap[num[i+16]]);
}

void promainwindow::informationshow(QTextEdit *edit)
{
    edit->setFontFamily("楷体");
    edit->setFontWeight(63);
    edit->setFontPointSize(14);
    edit->setGeometry(1210,300,280,280);
    edit->setReadOnly(true);
    edit->setAttribute(Qt::WA_TranslucentBackground,true);
}

void promainwindow::scoreshow()
{
    scoredit->setGeometry(30,340,120,100);
    scoredit->setFontFamily("华文行楷");
    scoredit->setFontPointSize(50);
    QString strnum = QString::number(aicombine->score);
    scoredit->setText(strnum);
    scoredit->setReadOnly(true);
    scoredit->setAttribute(Qt::WA_TranslucentBackground,true);
    scoredit2->setGeometry(30,460,120,100);
    scoredit2->setFontFamily("华文行楷");
    scoredit2->setFontPointSize(50);
    strnum = QString::number(mycombine->score);
    scoredit2->setText(strnum);
    scoredit2->setReadOnly(true);
    scoredit2->setAttribute(Qt::WA_TranslucentBackground,true);
}

int promainwindow::ischose(proCombine*com){
    int pd=0;
    if(isend(com))
        return 1;
    for(int i=1;i<=8;i++)
    {
        if(com->count[i]==1)
        {
            if(num[i]>=1&&num[i]<=10)
            {
                for(int k=1;k<8;k++)
                {
                    if(num[k+16]>=1&&num[k+16]<=10)
                        pd++;
                }
            }
            if(num[i]>=11&&num[i]<=19)
            {
                for(int k=1;k<8;k++)
                {
                    if(num[k+16]>=11&&num[k+16]<=19)
                        pd++;
                }
            }
            if(num[i]>=20&&num[i]<=28)
            {
                for(int k=1;k<8;k++)
                {
                    if(num[k+16]>=20&&num[k+16]<=28)
                        pd++;
                }
            }
            if(num[i]>=29&&num[i]<=37)
            {
                for(int k=1;k<8;k++)
                {
                    if(num[k+16]>=29&&num[k+16]<=37)
                        pd++;
                }
            }
        }
    }
    if(pd==0)
        return 0;
    return 1;
}

void promainwindow::exchange(proCombine*com,bool personorai)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int n2;
    while(1)
    {
        n2=qrand()%37+1;
        if(snum[n2]==1)
        {
            break;
        }
    }
    int mm=8;
    while((!com->count[mm])&&mm>0)
    {
        mm--;
    }
    if(mm>0&&personorai)
    {
        snum[num[mm]]=1;
        num[mm]=n2;
        label[mm].setPixmap(pixmap[num[mm]]);
        snum[num[mm]]=0;
    }
    if(mm>0&&(!personorai))
    {
        snum[num[mm+8]]=1;
        com->cards[num[mm+8]]->isai=0;
        num[mm+8]=n2;
        com->cards[num[mm+8]]->isai=1;
        snum[num[mm+8]]=0;
    }
}
void promainwindow::exchange(proai*com,bool personorai)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int n2;
    while(1)
    {
        n2=qrand()%37+1;
        if(snum[n2]==1)
        {
            break;
        }
    }
    int mm=8;
    while((!com->count[mm])&&mm>0)
    {
        mm--;
    }
    if(mm>0&&personorai)
    {
        snum[num[mm]]=1;
        num[mm]=n2;
        label[mm].setPixmap(pixmap[num[mm]]);
        snum[num[mm]]=0;
    }
    if(mm>0&&(!personorai))
    {
        snum[num[mm+8]]=1;
        com->cards[num[mm+8]]->isai=0;
        num[mm+8]=n2;
        com->cards[num[mm+8]]->isai=1;
        snum[num[mm+8]]=0;
    }
}

bool promainwindow::isend(proCombine*com){
    bool flag=1;
    for(int i=1;i<=8;i++){
        if(com->count[i]==1){
            flag=0;
            continue;
        }
    }
    return flag;           //如果结束返回1，没有结束返回0
}
bool promainwindow::isend(proai*com){
    bool flag=1;
    for(int i=1;i<=8;i++){
        if(com->count[i]==1){
            flag=0;
            continue;
        }
    }
    return flag;           //如果结束返回1，没有结束返回0
}





promainwindow::~promainwindow()
{
    delete [] labelch;
    delete [] label;
    delete [] label2;
    delete [] string;
    delete mycombine;
    delete aicombine;
    delete ui;
}
