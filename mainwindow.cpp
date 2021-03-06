#include "mainwindow.h"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    this->setWindowTitle("千秋戏");
    this->setFixedSize(1500,900);
    QTextEdit *edit=new QTextEdit(this);
    informationshow(edit);
    scoredit->setParent(this);
    scoredit2->setParent(this);
    mycombine=new combine();
    mycombine->score=0;
    aicombine=new azcombine();
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


    QString str=":/image1/00";
    for(int i=0;i<43;i++)
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
    for(int i=0;i<=43;i++){snum[i]=1;}
    for(int i=0;i<17;i++){num[i]=0;};
    label_0->setParent(this);
    labelk->setParent(this);
    labelc->setParent(this);
    random();
    allphoto();
    photo();
    midphoto();
    labelk->setVisible(false);
    for(int i=0;i<50;i++){
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
            if((num[i]==3)||(num[i]==11)||(num[i]==12)||(num[i]==15)||(num[i]==26)||(num[i]==28)||(num[i]==30)||(num[i]==31)||(num[i]==36)||(num[i]==39)||(num[i]==41))
            {
                for(int k=1;k<8;k++)
                {
                    if((num[k+16]==3)||(num[k+16]==11)||(num[k+16]==12)||(num[k+16]==15)||(num[k+16]==26)||(num[k+16]==28)||(num[k+16]==30)||(num[k+16]==31)||(num[k+16]==36)||(num[k+16]==39)||(num[k+16]==41))
                        label2[k].move(label2[k].x(),label2[k].y()-30);
                }
            }
            if((num[i]==9)||(num[i]==14)||(num[i]==17)||(num[i]==18)||(num[i]==19)||(num[i]==25)||(num[i]==32)||(num[i]==33)||(num[i]==40)||(num[i]==42))
            {
                for(int k=1;k<8;k++)
                {
                    if((num[k+16]==9)||(num[k+16]==14)||(num[k+16]==17)||(num[k+16]==18)||(num[k+16]==19)||(num[k+16]==25)||(num[k+16]==32)||(num[k+16]==33)||(num[k+16]==40)||(num[k+16]==42))
                        label2[k].move(label2[k].x(),label2[k].y()-30);
                }
            }
            if((num[i]==1)||(num[i]==2)||(num[i]==4)||(num[i]==5)||(num[i]==8)||(num[i]==16)||(num[i]==27)||(num[i]==35)||(num[i]==37)||(num[i]==38))
            {
                for(int k=1;k<8;k++)
                {
                    if((num[k+16]==1)||(num[k+16]==2)||(num[k+16]==4)||(num[k+16]==5)||(num[k+16]==8)||(num[k+16]==16)||(num[k+16]==27)||(num[k+16]==35)||(num[k+16]==37)||(num[k+16]==38))
                        label2[k].move(label2[k].x(),label2[k].y()-30);
                }
            }
            if((num[i]==6)||(num[i]==7)||(num[i]==10)||(num[i]==13)||(num[i]==20)||(num[i]==21)||(num[i]==22)||(num[i]==23)||(num[i]==24)||(num[i]==29)||(num[i]==34))
            {
                for(int k=1;k<8;k++)
                {
                    if((num[k+16]==6)||(num[k+16]==7)||(num[k+16]==10)||(num[k+16]==13)||(num[k+16]==20)||(num[k+16]==21)||(num[k+16]==22)||(num[k+16]==23)||(num[k+16]==24)||(num[k+16]==29)||(num[k+16]==34))
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
            if(!flag&&((num[i+16]==3)||(num[i+16]==11)||(num[i+16]==12)||(num[i+16]==15)||(num[i+16]==26)||(num[i+16]==28)||(num[i+16]==30)||(num[i+16]==31)||(num[i+16]==36)||(num[i+16]==39)||(num[i+16]==41)))
            {
                for(int j=1;j<=8;j++){
                    if(label[j].y()==620){
                        if((num[j]==3)||(num[j]==11)||(num[j]==12)||(num[j]==15)||(num[j]==26)||(num[j]==28)||(num[j]==30)||(num[j]==31)||(num[j]==36)||(num[j]==39)||(num[j]==41)){
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
            if(!flag&&((num[i+16]==9)||(num[i+16]==14)||(num[i+16]==17)||(num[i+16]==18)||(num[i+16]==19)||(num[i+16]==25)||(num[i+16]==32)||(num[i+16]==33)||(num[i+16]==40)||(num[i+16]==42))){

                for(int j=1;j<=8;j++){
                    if(label[j].y()==620){
                        if((num[j]==9)||(num[j]==14)||(num[j]==17)||(num[j]==18)||(num[j]==19)||(num[j]==25)||(num[j]==32)||(num[j]==33)||(num[j]==40)||(num[j]==42)){
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
            if(!flag&&((num[i+16]==1)||(num[i+16]==2)||(num[i+16]==4)||(num[i+16]==5)||(num[i+16]==8)||(num[i+16]==16)||(num[i+16]==27)||(num[i+16]==35)||(num[i+16]==37)||(num[i+16]==38))){

                for(int j=1;j<=8;j++){
                    if(label[j].y()==620){
                        if((num[j]==1)||(num[j]==2)||(num[j]==4)||(num[j]==5)||(num[j]==8)||(num[j]==16)||(num[j]==27)||(num[j]==35)||(num[j]==37)||(num[j]==38)){
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
            if(!flag&&((num[i+16]==6)||(num[i+16]==7)||(num[i+16]==10)||(num[i+16]==13)||(num[i+16]==20)||(num[i+16]==21)||(num[i+16]==22)||(num[i+16]==23)||(num[i+16]==24)||(num[i+16]==29)||(num[i+16]==34)))
            {

                for(int j=1;j<=8;j++){
                    if(label[j].y()==620){
                        if((num[j]==6)||(num[j]==7)||(num[j]==10)||(num[j]==13)||(num[j]==20)||(num[j]==21)||(num[j]==22)||(num[j]==23)||(num[j]==24)||(num[j]==29)||(num[j]==34)){
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
                if(whichone==1)
                {
                    player1=new QMediaPlayer();
                    player1->setMedia(QUrl("qrc:/yin/combo.mp3"));
               l1:  bool have=0;
                    int k=7,j=8;
                    for(;k>0;--k)
                    {
                        if((num[k+16]==3)||(num[k+16]==11)||(num[k+16]==12)||(num[k+16]==15)||(num[k+16]==26)||(num[k+16]==28)||(num[k+16]==30)||(num[k+16]==31)||(num[k+16]==36)||(num[k+16]==39)||(num[k+16]==41))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==3)||(num[j+8]==11)||(num[j+8]==12)||(num[j+8]==15)||(num[j+8]==26)||(num[j+8]==28)||(num[j+8]==30)||(num[j+8]==31)||(num[j+8]==36)||(num[j+8]==39)||(num[j+8]==41)))
                                {
                                    have=1;
                                    break;
                                }
                        if((num[k+16]==9)||(num[k+16]==14)||(num[k+16]==17)||(num[k+16]==18)||(num[k+16]==19)||(num[k+16]==25)||(num[k+16]==32)||(num[k+16]==33)||(num[k+16]==40)||(num[k+16]==42))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==9)||(num[j+8]==14)||(num[j+8]==17)||(num[j+8]==18)||(num[j+8]==19)||(num[j+8]==25)||(num[j+8]==32)||(num[j+8]==33)||(num[j+8]==40)||(num[j+8]==42)))
                                {
                                    have=1;
                                    break;
                                }
                        if((num[k+16]==1)||(num[k+16]==2)||(num[k+16]==4)||(num[k+16]==5)||(num[k+16]==8)||(num[k+16]==16)||(num[k+16]==27)||(num[k+16]==35)||(num[k+16]==37)||(num[k+16]==38))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==1)||(num[j+8]==2)||(num[j+8]==4)||(num[j+8]==5)||(num[j+8]==8)||(num[j+8]==16)||(num[j+8]==27)||(num[j+8]==35)||(num[j+8]==37)||(num[j+8]==38)))
                                {
                                    have=1;
                                    break;
                                }
                        if((num[k+16]==6)||(num[k+16]==7)||(num[k+16]==10)||(num[k+16]==13)||(num[k+16]==20)||(num[k+16]==21)||(num[k+16]==22)||(num[k+16]==23)||(num[k+16]==24)||(num[k+16]==29)||(num[k+16]==34))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==6)||(num[j+8]==7)||(num[j+8]==10)||(num[j+8]==13)||(num[j+8]==20)||(num[j+8]==21)||(num[j+8]==22)||(num[j+8]==23)||(num[j+8]==24)||(num[j+8]==29)||(num[j+8]==34)))
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
                    if(whichone==2)
                {
                    player1=new QMediaPlayer();
                    player1->setMedia(QUrl("qrc:/yin/combo.mp3"));
                 l2:
                    bool have=0;
                    int k=7,j=8,a=0,b=0,max=0,temp=0;
                    for(;k>0;--k)
                    {
                        if((num[k+16]==3)||(num[k+16]==11)||(num[k+16]==12)||(num[k+16]==15)||(num[k+16]==26)||(num[k+16]==28)||(num[k+16]==30)||(num[k+16]==31)||(num[k+16]==36)||(num[k+16]==39)||(num[k+16]==41))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==3)||(num[j+8]==11)||(num[j+8]==12)||(num[j+8]==15)||(num[j+8]==26)||(num[j+8]==28)||(num[j+8]==30)||(num[j+8]==31)||(num[j+8]==36)||(num[j+8]==39)||(num[j+8]==41)))
                                {
                                    aicombine->cards[num[k+16]]->isai=1;
                                    temp=aicombine->judgescore();


                                    if(temp>=max)
                                    {
                                        a=k;
                                        b=j;
                                        max=temp;
                                    }
                                    //qDebug()<<max<<temp;

                                    aicombine->cards[num[k+16]]->isai=0;
                                    have=1;
                                }
                        if((num[k+16]==9)||(num[k+16]==14)||(num[k+16]==17)||(num[k+16]==18)||(num[k+16]==19)||(num[k+16]==25)||(num[k+16]==32)||(num[k+16]==33)||(num[k+16]==40)||(num[k+16]==42))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==9)||(num[j+8]==14)||(num[j+8]==17)||(num[j+8]==18)||(num[j+8]==19)||(num[j+8]==25)||(num[j+8]==32)||(num[j+8]==33)||(num[j+8]==40)||(num[j+8]==42)))
                                {
                                    aicombine->cards[num[k+16]]->isai=1;
                                    temp=aicombine->judgescore();

                                    if(temp>=max)
                                    {
                                        a=k;
                                        b=j;
                                        max=temp;
                                    }

                                    //qDebug()<<max<<temp;

                                    aicombine->cards[num[k+16]]->isai=0;
                                    have=1;
                                }
                        if((num[k+16]==1)||(num[k+16]==2)||(num[k+16]==4)||(num[k+16]==5)||(num[k+16]==8)||(num[k+16]==16)||(num[k+16]==27)||(num[k+16]==35)||(num[k+16]==37)||(num[k+16]==38))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==1)||(num[j+8]==2)||(num[j+8]==4)||(num[j+8]==5)||(num[j+8]==8)||(num[j+8]==16)||(num[j+8]==27)||(num[j+8]==35)||(num[j+8]==37)||(num[j+8]==38)))
                                {
                                    aicombine->cards[num[k+16]]->isai=1;
                                    temp=aicombine->judgescore();


                                    if(temp>=max)
                                    {
                                        a=k;
                                        b=j;
                                        max=temp;
                                    }
                                    //qDebug()<<max<<temp;
                                    aicombine->cards[num[k+16]]->isai=0;
                                    have=1;
                                }
                        if((num[k+16]==6)||(num[k+16]==7)||(num[k+16]==10)||(num[k+16]==13)||(num[k+16]==20)||(num[k+16]==21)||(num[k+16]==22)||(num[k+16]==23)||(num[k+16]==24)||(num[k+16]==29)||(num[k+16]==34))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==6)||(num[j+8]==7)||(num[j+8]==10)||(num[j+8]==13)||(num[j+8]==20)||(num[j+8]==21)||(num[j+8]==22)||(num[j+8]==23)||(num[j+8]==24)||(num[j+8]==29)||(num[j+8]==34)))
                                {
                                    aicombine->cards[num[k+16]]->isai=1;
                                    temp=aicombine->judgescore();


                                    if(temp>=max)
                                    {
                                        a=k;
                                        b=j;
                                        max=temp;
                                    }
                                     //qDebug()<<max<<temp;
                                    aicombine->cards[num[k+16]]->isai=0;
                                    have=1;
                                }
                    }
                    if(have)
                    {
                        aicombine->count[b]=0;
                        //qDebug()<<b<<aicombine->count[b];
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
                        //qDebug()<<isend(aicombine);
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
                if(whichone==3)
                {
                    player1=new QMediaPlayer();
                    player1->setMedia(QUrl("qrc:/yin/combo.mp3"));
              l3:   bool have=0;
                    int k=7,j=8,a=0,b=0,max=0,temp1=0,temp2=0;
                    for(;k>0;--k)
                    {
                        if((num[k+16]==3)||(num[k+16]==11)||(num[k+16]==12)||(num[k+16]==15)||(num[k+16]==26)||(num[k+16]==28)||(num[k+16]==30)||(num[k+16]==31)||(num[k+16]==36)||(num[k+16]==39)||(num[k+16]==41))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==3)||(num[j+8]==11)||(num[j+8]==12)||(num[j+8]==15)||(num[j+8]==26)||(num[j+8]==28)||(num[j+8]==30)||(num[j+8]==31)||(num[j+8]==36)||(num[j+8]==39)||(num[j+8]==41)))
                                {
                                    aicombine->cards[num[k+16]]->isai=1;
                                    temp1=aicombine->judgescore();
                                    aicombine->cards[num[k+16]]->isai=0;
                                    mycombine->cards[num[k+16]]->ismine=1;
                                    temp2=mycombine->judgescore2();
                                    mycombine->cards[num[k+16]]->ismine=0;
                                    if(temp1+temp2>=max)
                                    {
                                       a=k;
                                       b=j;
                                       max=temp1+temp2;
                                    }
                                    have=1;
                                }
                        if((num[k+16]==9)||(num[k+16]==14)||(num[k+16]==17)||(num[k+16]==18)||(num[k+16]==19)||(num[k+16]==25)||(num[k+16]==32)||(num[k+16]==33)||(num[k+16]==40)||(num[k+16]==42))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==9)||(num[j+8]==14)||(num[j+8]==17)||(num[j+8]==18)||(num[j+8]==19)||(num[j+8]==25)||(num[j+8]==32)||(num[j+8]==33)||(num[j+8]==40)||(num[j+8]==42)))
                                {
                                    aicombine->cards[num[k+16]]->isai=1;
                                    temp1=aicombine->judgescore();
                                    aicombine->cards[num[k+16]]->isai=0;
                                    mycombine->cards[num[k+16]]->ismine=1;
                                    temp2=mycombine->judgescore2();
                                    mycombine->cards[num[k+16]]->ismine=0;
                                    if(temp1+temp2>=max)
                                    {
                                       a=k;
                                       b=j;
                                       max=temp1+temp2;
                                    }
                                    have=1;
                                }
                        if((num[k+16]==1)||(num[k+16]==2)||(num[k+16]==4)||(num[k+16]==5)||(num[k+16]==8)||(num[k+16]==16)||(num[k+16]==27)||(num[k+16]==35)||(num[k+16]==37)||(num[k+16]==38))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==1)||(num[j+8]==2)||(num[j+8]==4)||(num[j+8]==5)||(num[j+8]==8)||(num[j+8]==16)||(num[j+8]==27)||(num[j+8]==35)||(num[j+8]==37)||(num[j+8]==38)))
                                {
                                    aicombine->cards[num[k+16]]->isai=1;
                                    temp1=aicombine->judgescore();
                                    aicombine->cards[num[k+16]]->isai=0;
                                    mycombine->cards[num[k+16]]->ismine=1;
                                    temp2=mycombine->judgescore2();
                                    mycombine->cards[num[k+16]]->ismine=0;
                                    if(temp1+temp2>=max)
                                    {
                                       a=k;
                                       b=j;
                                       max=temp1+temp2;
                                    }
                                    have=1;
                                }
                        if((num[k+16]==6)||(num[k+16]==7)||(num[k+16]==10)||(num[k+16]==13)||(num[k+16]==20)||(num[k+16]==21)||(num[k+16]==22)||(num[k+16]==23)||(num[k+16]==24)||(num[k+16]==29)||(num[k+16]==34))
                            for(j=8;j>0;--j)
                                if((aicombine->count[j])&&((num[j+8]==6)||(num[j+8]==7)||(num[j+8]==10)||(num[j+8]==13)||(num[j+8]==20)||(num[j+8]==21)||(num[j+8]==22)||(num[j+8]==23)||(num[j+8]==24)||(num[j+8]==29)||(num[j+8]==34)))
                                {
                                    aicombine->cards[num[k+16]]->isai=1;
                                    temp1=aicombine->judgescore();
                                    aicombine->cards[num[k+16]]->isai=0;
                                    mycombine->cards[num[k+16]]->ismine=1;
                                    temp2=mycombine->judgescore2();
                                    mycombine->cards[num[k+16]]->ismine=0;
                                    if(temp1+temp2>=max)
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

void MainWindow::showcard()
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
    for (int ii=1;ii<=42;ii++) {
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

void MainWindow::allphoto()
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
    pixmap_0.load(":/image1/43");
    pixmap_0.scaled(label_0->size(),Qt::KeepAspectRatio);
    label_0->setScaledContents(true);
    label_0->setPixmap(pixmap_0);
    labelc->setGeometry(40,650,150,200);
    labelc->setAttribute(Qt::WA_TranslucentBackground,true);
}

void MainWindow::random()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    for(int i=1;i<24; )
    {
        int n=qrand()%42+1;
        if(snum[n]!=0)
        {
            snum[n]=0;
            num[i]=n;
            if(i>=9&&i<=23)
            {
                aicombine->cards[num[i]]->isai=1;
            }
            i++;
        }
    }

}

void MainWindow::photo()
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

void MainWindow::midphoto()
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

void MainWindow::stringg()
{
    string[0]="牌背面";
    string[1]="【八国联军侵华】                     可组合的卡牌：鸦片战争、第二次鸦片战争、甲午战争、抗日战争、义和团";
    string[2]="【北伐战争】                        可组合的卡牌：北洋政府、国共联军";
    string[3]="【北京大学】                        可组合的卡牌：五四运动、南开大学、清华大学、戊戌变法";
    string[4]="【北洋政府】                        可组合的卡牌：袁世凯、北伐战争、国共联军";
    string[5]="【邓世昌&致远舰】                    可组合的卡牌：甲午战争、林则徐、太平天国、义和团、戊戌六君子、孙中山、毛泽东";
    string[6]="【邓小平】                          可组合的卡牌：抗日战争、香港&澳门、经济特区、航天";
    string[7]="【邓颖超】                          可组合的卡牌：周恩来、西花厅";
    string[8]="【第二次鸦片战争】                    可组合的卡牌：鸦片战争、甲午战争、八国联军侵华、抗日战争、圆明园、太平天国";
    string[9]="【工人&学生】                        可组合的卡牌：五四运动、共产党、马克思主义";
    string[10]="【共产党】                          可组合的卡牌：嘉兴南湖、红军、毛泽东、井冈山";
    string[11]="【国共联军】                        可组合的卡牌：北伐战争、北洋政府、抗日战争";
    string[12]="【航天】                           可组合的卡牌：毛泽东、邓小平";
    string[13]="【红军】                           可组合的卡牌：毛泽东、井冈山、长征、共产党";
    string[14]="【嘉兴南湖】                        可组合的卡牌：共产党";
    string[15]="【甲午战争】                        可组合的卡牌：鸦片战争、第二次鸦片战争、八国联军侵华、抗日战争、邓世昌&致远舰";
    string[16]="【蒋介石】                          可组合的卡牌：毛泽东、重庆和谈、长征";
    string[17]="【经济特区】                        可组合的卡牌：邓小平";
    string[18]="【井冈山】                          可组合的卡牌：毛泽东、红军、共产党";
    string[19]="【开国大典】                        可组合的卡牌：毛泽东、周恩来";
    string[20]="【抗日战争】                        可组合的卡牌：鸦片战争、第二次鸦片战争、八国联军侵华、甲午战争、国共联军、邓小平";
    string[21]="【林则徐】                          可组合的卡牌：太平天国、邓世昌&致远舰、义和团、戊戌六君子、孙中山、毛泽东、鸦片战争";
    string[22]="【马克思主义】                       可组合的卡牌：毛泽东、周恩来、共产党、工人&学生";
    string[23]="【毛泽东】                          可组合的卡牌：井冈山、红军、蒋介石、周恩来、马克思主义、南开大学、开国大典、航天、共产党、重庆和谈、蒋介石、周恩来、林则徐、太平天国、邓世昌&致远舰、义和团、戊戌六君子、孙中山";
    string[24]="【南开大学】                        可组合的卡牌：毛泽东、周恩来、清华大学、北京大学";
    string[25]="【清华大学】                        可组合的卡牌：南开大学、北京大学";
    string[26]="【孙中山】                          可组合的卡牌：林则徐、太平天国、邓世昌&致远舰、义和团、戊戌六君子、毛泽东、辛亥革命";
    string[27]="【太平天国】                        可组合的卡牌：林则徐、邓世昌&致远舰、义和团、戊戌六君子、孙中山、毛泽东、第二次鸦片战争";
    string[28]="【万隆会议】                        可组合的卡牌：周恩来";
    string[29]="【五四运动】                        可组合的卡牌：南开大学、工人&学生";
    string[30]="【戊戌变法】                        可组合的卡牌：洋务运动、辛亥革命、北京大学、戊戌六君子";
    string[31]="【戊戌六君子】                      可组合的卡牌：林则徐、太平天国、邓世昌&致远舰、义和团、孙中山、毛泽东、戊戌变法";
    string[32]="【西花厅】                          可组合的卡牌：周恩来、邓颖超";
    string[33]="【香港&澳门】                       可组合的卡牌：邓小平";
    string[34]="【辛亥革命】                        可组合的卡牌：戊戌变法、洋务运动、孙中山、袁世凯";
    string[35]="【鸦片战争】                        可组合的卡牌：第二次鸦片战争、甲午战争、八国联军侵华、抗日战争、林则徐";
    string[36]="【洋务运动】                        可组合的卡牌：戊戌变法、辛亥革命、邓世昌&致远舰";
    string[37]="【义和团】                          可组合的卡牌：林则徐、太平天国、邓世昌&致远舰、戊戌六君子、孙中山、毛泽东、八国联军侵华";
    string[38]="【袁世凯】                          可组合的卡牌：辛亥革命、北洋政府";
    string[39]="【圆明园】                          可组合的卡牌：第二次鸦片战争";
    string[40]="【长征】                           可组合的卡牌：红军、蒋介石";
    string[41]="【重庆和谈】                        可组合的卡牌：毛泽东、蒋介石";
    string[42]="【周恩来】                          可组合的卡牌：毛泽东、马克思主义、西花厅、邓颖超、南开大学、开国大典、万隆会议";
}

void MainWindow::replace(mylabel *lab,int i)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int n=qrand()%42+1;
    while(snum[n]==0){
        n=(qrand()%42)+1;
    }
    snum[n]=0;
    num[i+16]=n;
    //    lab[i].setParent(this);
    //    lab[i].setGeometry(80+110*i,350,150,200);
    pixmap[num[i+16]].scaled(lab[i].size(),Qt::KeepAspectRatio);
    lab[i].setScaledContents(true);
    lab[i].setPixmap(pixmap[num[i+16]]);
}

void MainWindow::informationshow(QTextEdit *edit)
{
    edit->setFontFamily("楷体");
    edit->setFontWeight(63);
    edit->setFontPointSize(14);
    edit->setGeometry(1210,300,280,280);
    edit->setReadOnly(true);
    edit->setAttribute(Qt::WA_TranslucentBackground,true);
}

void MainWindow::scoreshow()
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

int MainWindow::ischose(combine*com){
    int pd=0;
    if(isend(com))
        return 1;
    for(int i=1;i<=8;i++)
    {
        if(com->count[i]==1)
        {
            if((num[i]==3)||(num[i]==11)||(num[i]==12)||(num[i]==15)||(num[i]==26)||(num[i]==28)||(num[i]==30)||(num[i]==31)||(num[i]==36)||(num[i]==39)||(num[i]==41))
            {
                for(int k=1;k<8;k++)
                {
                    if((num[k+16]==3)||(num[k+16]==11)||(num[k+16]==12)||(num[k+16]==15)||(num[k+16]==26)||(num[k+16]==28)||(num[k+16]==30)||(num[k+16]==31)||(num[k+16]==36)||(num[k+16]==39)||(num[k+16]==41))
                        pd++;
                }
            }
            if((num[i]==9)||(num[i]==14)||(num[i]==17)||(num[i]==18)||(num[i]==19)||(num[i]==25)||(num[i]==32)||(num[i]==33)||(num[i]==40)||(num[i]==42))
            {
                for(int k=1;k<8;k++)
                {
                    if((num[k+16]==9)||(num[k+16]==14)||(num[k+16]==17)||(num[k+16]==18)||(num[k+16]==19)||(num[k+16]==25)||(num[k+16]==32)||(num[k+16]==33)||(num[k+16]==40)||(num[k+16]==42))
                        pd++;
                }
            }
            if((num[i]==1)||(num[i]==2)||(num[i]==4)||(num[i]==5)||(num[i]==8)||(num[i]==16)||(num[i]==27)||(num[i]==35)||(num[i]==37)||(num[i]==38))
            {
                for(int k=1;k<8;k++)
                {
                    if((num[k+16]==1)||(num[k+16]==2)||(num[k+16]==4)||(num[k+16]==5)||(num[k+16]==8)||(num[k+16]==16)||(num[k+16]==27)||(num[k+16]==35)||(num[k+16]==37)||(num[k+16]==38))
                        pd++;
                }
            }
            if((num[i]==6)||(num[i]==7)||(num[i]==10)||(num[i]==13)||(num[i]==20)||(num[i]==21)||(num[i]==22)||(num[i]==23)||(num[i]==24)||(num[i]==29)||(num[i]==34))
            {
                for(int k=1;k<8;k++)
                {
                    if((num[k+16]==6)||(num[k+16]==7)||(num[k+16]==10)||(num[k+16]==13)||(num[k+16]==20)||(num[k+16]==21)||(num[k+16]==22)||(num[k+16]==23)||(num[k+16]==24)||(num[k+16]==29)||(num[k+16]==34))
                        pd++;
                }
            }
        }
    }
    if(pd==0)
        return 0;
    return 1;
}

void MainWindow::exchange(combine*com,bool personorai)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int n2;
    while(1)
    {
        n2=qrand()%42+1;
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
void MainWindow::exchange(azcombine*com,bool personorai)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int n2;
    while(1)
    {
        n2=qrand()%42+1;
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

bool MainWindow::isend(combine*com){
    bool flag=1;
    for(int i=1;i<=8;i++){
        if(com->count[i]==1){
            flag=0;
            continue;
        }
    }
    return flag;           //如果结束返回1，没有结束返回0
}
bool MainWindow::isend(azcombine*com){
    bool flag=1;
    for(int i=1;i<=8;i++){
        if(com->count[i]==1){
            flag=0;
            continue;
        }
    }
    return flag;           //如果结束返回1，没有结束返回0
}


MainWindow::~MainWindow()
{
    delete [] labelch;
    delete [] label;
    delete [] label2;
    delete [] string;
    delete mycombine;
    delete aicombine;
    delete ui;

}

