#include "mymainscene.h"
#include "ui_mymainscene.h"
#include <QMessageBox>
#include <QPainter>
#include <QTimer>
#include <QSound>
#include "combine.h"
#include "mainwindow.h"
#include "promainwindow.h"

MyMainScene::MyMainScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyMainScene)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("Ç§ÇïÏ·"));
    this->setFixedSize(1500,900);

    QSound *sounds = new QSound(":/sound/Sound/begin.wav",this);
    sounds->setLoops(100);
    sounds->play();

    QSound *hap= new QSound(":/sound/Sound/happy1.wav");
    hap->setLoops(1000);

    QSound *hap2= new QSound(":/sound/Sound/happy2.wav");
    hap2->setLoops(1000);


    ui->stackedWidget->setStyleSheet(tr("border:0xp"));


    QLabel *gifcloud1 = new QLabel;
    gifcloud1->setParent(ui->page1);
    gifcloud1->move(this->pos().rx(),0);
    gifcloud1->resize(1500,900);


    QLabel *gifcloud2 = new QLabel;
    gifcloud2->setParent(ui->page2);
    gifcloud2->move(0,0);
    gifcloud2->resize(1500,900);

    QLabel *gifcloud3 = new QLabel;
    gifcloud3->setParent(ui->page3);
    gifcloud3->move(0,0);
    gifcloud3->resize(1500,900);

    QLabel *gifcloud4 = new QLabel;
    gifcloud4->setParent(ui->page4);
    gifcloud4->move(0,0);
    gifcloud4->resize(1500,900);

    QLabel *gifcloud5 = new QLabel;
    gifcloud5->setParent(ui->page5);
    gifcloud5->move(0,0);
    gifcloud5->resize(1500,900);
    QLabel *gifcloud6 = new QLabel;
    gifcloud6->setParent(ui->page6);
    gifcloud6->move(0,0);
    gifcloud6->resize(1500,900);

    QPixmap bg2(":/image/Image/probg.png");
    QLabel *bg = new QLabel;
    bg->setParent(ui->page7);
    bg->setGeometry(0,0,1500,900);
    bg->setPixmap(bg2);

    movie = new QMovie(":/image/Image/cloud.gif");
    gifcloud1->setMovie(movie);
    gifcloud2->setMovie(movie);
    gifcloud3->setMovie(movie);
    gifcloud4->setMovie(movie);
    gifcloud5->setMovie(movie);
    gifcloud6->setMovie(movie);
    movie->start();

    QSound *sounds1 = new QSound(":/sound/Sound/mouseon.wav",this);
    QSound *begcli = new QSound(":/sound/Sound/beginclick.wav",this);
    QSound *inscli = new QSound(":/sound/Sound/insideclick.wav",this);
    QSound *backing = new QSound(":/sound/Sound/back.wav",this);
    ptn1= new Mypushbutton1(":/image/Image/history1.png");
    ptn2= new Mypushbutton1(":/image/Image/program1.png");
    ptn3= new Mypushbutton1(":/image/Image/people1.png");
    ptn4= new Mypushbutton1(":/image/Image/rule1.png");

    connect(ptn1,&QPushButton::clicked,[=](){
        begcli->play();
        ui->stackedWidget->setCurrentIndex(5);
    });
    connect(ptn2,&QPushButton::clicked,[=](){
        begcli->play();
        ui->stackedWidget->setCurrentIndex(6);
        sounds->stop();

        hap->play();
    });
    connect(ptn3,&QPushButton::clicked,[=](){
        begcli->play();
        ui->stackedWidget->setCurrentIndex(4);
    });
    connect(ptn4,&QPushButton::clicked,[=](){
        begcli->play();
        ui->stackedWidget->setCurrentIndex(2);
    });
    ptn5= new Mypushbutton1(":/image/Image/quit1.png");
    connect(ptn5,&QPushButton::clicked,[=](){
        begcli->play();

        this->close();

    });


    ptn1->setParent(ui->page1);
    ptn1->move(550,this->height()*0.2);

    connect(ptn1,&Mypushbutton1::mousein,[=](){
        sounds1->play();
        QPixmap pix;
        QString str=QString(":/image/Image/history2.png");
        pix.load(str);
        ptn1->setFixedSize(pix.width(),pix.height());
        ptn1->setStyleSheet("QPushButton{border:0px;}");
        ptn1->setIcon(pix);
        ptn1->setIconSize(QSize(pix.width(),pix.height()));
    });
    connect(ptn1,&Mypushbutton1::mouseout,[=](){
        QPixmap pix;
        QString str=QString(":/image/Image/history1.png");
        pix.load(str);
        ptn1->setFixedSize(pix.width(),pix.height());

        ptn1->setStyleSheet("QPushButton{border:0px;}");

        ptn1->setIcon(pix);

        ptn1->setIconSize(QSize(pix.width(),pix.height()));
    });
    ptn2->setParent(ui->page1);
    ptn2->move(550,this->height()*0.35);
    connect(ptn2,&Mypushbutton1::mousein,[=](){
        sounds1->play();
        QPixmap pix;
        QString str=QString(":/image/Image/program2.png");
        pix.load(str);
        ptn2->setFixedSize(pix.width(),pix.height());
        ptn2->setStyleSheet("QPushButton{border:0px;}");
        ptn2->setIcon(pix);
        ptn2->setIconSize(QSize(pix.width(),pix.height()));
    });
    connect(ptn2,&Mypushbutton1::mouseout,[=](){
        QPixmap pix;
        QString str=QString(":/image/Image/program1.png");
        pix.load(str);
        ptn2->setFixedSize(pix.width(),pix.height());

        ptn2->setStyleSheet("QPushButton{border:0px;}");

        ptn2->setIcon(pix);

        ptn2->setIconSize(QSize(pix.width(),pix.height()));
    });
    ptn3->setParent(ui->page1);
    ptn3->move(550,this->height()*0.5);
    connect(ptn3,&Mypushbutton1::mousein,[=](){
        sounds1->play();
        QPixmap pix;
        QString str=QString(":/image/Image/people2.png");
        pix.load(str);
        ptn3->setFixedSize(pix.width(),pix.height());
        ptn3->setStyleSheet("QPushButton{border:0px;}");
        ptn3->setIcon(pix);
        ptn3->setIconSize(QSize(pix.width(),pix.height()));
    });
    connect(ptn3,&Mypushbutton1::mouseout,[=](){
        QPixmap pix;
        QString str=QString(":/image/Image/people1.png");
        pix.load(str);
        ptn3->setFixedSize(pix.width(),pix.height());

        ptn3->setStyleSheet("QPushButton{border:0px;}");

        ptn3->setIcon(pix);

        ptn3->setIconSize(QSize(pix.width(),pix.height()));
    });
    ptn4->setParent(ui->page1);
    ptn4->move(550,this->height()*0.65);
    connect(ptn4,&Mypushbutton1::mousein,[=](){
        sounds1->play();
        QPixmap pix;
        QString str=QString(":/image/Image/rule2.png");
        pix.load(str);
        ptn4->setFixedSize(pix.width(),pix.height());
        ptn4->setStyleSheet("QPushButton{border:0px;}");
        ptn4->setIcon(pix);
        ptn4->setIconSize(QSize(pix.width(),pix.height()));
    });
    connect(ptn4,&Mypushbutton1::mouseout,[=](){
        QPixmap pix;
        QString str=QString(":/image/Image/rule1.png");
        pix.load(str);
        ptn4->setFixedSize(pix.width(),pix.height());

        ptn4->setStyleSheet("QPushButton{border:0px;}");

        ptn4->setIcon(pix);

        ptn4->setIconSize(QSize(pix.width(),pix.height()));
    });
    ptn5->setParent(ui->page1);
    ptn5->move(550,this->height()*0.8);
    connect(ptn5,&Mypushbutton1::mousein,[=](){
        sounds1->play();
        QPixmap pix;
        QString str=QString(":/image/Image/quit2.png");
        pix.load(str);
        ptn5->setFixedSize(pix.width(),pix.height());
        ptn5->setStyleSheet("QPushButton{border:0px;}");
        ptn5->setIcon(pix);
        ptn5->setIconSize(QSize(pix.width(),pix.height()));
    });
    connect(ptn5,&Mypushbutton1::mouseout,[=](){
        QPixmap pix;
        QString str=QString(":/image/Image/quit1.png");
        pix.load(str);
        ptn5->setFixedSize(pix.width(),pix.height());

        ptn5->setStyleSheet("QPushButton{border:0px;}");

        ptn5->setIcon(pix);

        ptn5->setIconSize(QSize(pix.width(),pix.height()));
    });



    ui->stackedWidget->setCurrentIndex(0);
    Mypushbutton1 *ptn01=new Mypushbutton1(":/image/Image/next.png");
    ptn01->setParent(ui->page3);
    ptn01->move(1200,0);
    connect(ptn01,&QPushButton::clicked,[=](){
        inscli->play();
        ui->stackedWidget->setCurrentIndex(3);
    });
    Mypushbutton1 *ptn02=new Mypushbutton1(":/image/Image/last.png");
    ptn02->setParent(ui->page4);
    ptn02->move(100,0);
    connect(ptn02,&QPushButton::clicked,[=](){
        inscli->play();
        ui->stackedWidget->setCurrentIndex(2);
    });
    Mypushbutton1 *ptn03=new Mypushbutton1(":/image/Image/back.png");
    ptn03->setParent(ui->page3);
    ptn03->move(1250,750);
    connect(ptn03,&QPushButton::clicked,[=](){
        backing->play();
        ui->stackedWidget->setCurrentIndex(0);
    });
    Mypushbutton1 *ptn04=new Mypushbutton1(":/image/Image/back.png");
    ptn04->setParent(ui->page4);
    ptn04->move(1250,750);
    connect(ptn04,&QPushButton::clicked,[=](){
        backing->play();
        ui->stackedWidget->setCurrentIndex(0);
    });

    Mypushbutton1 *ptn05=new Mypushbutton1(":/image/Image/back.png");
    ptn05->setParent(ui->page5);
    ptn05->move(1250,750);
    connect(ptn05,&QPushButton::clicked,[=](){
        backing->play();
        ui->stackedWidget->setCurrentIndex(0);
    });

    Mypushbutton1 *ptn06=new Mypushbutton1(":/image/Image/back.png");
    ptn06->setParent(ui->page6);
    ptn06->move(1250,750);
    connect(ptn06,&QPushButton::clicked,[=](){
        backing->play();
        ui->stackedWidget->setCurrentIndex(0);
    });

    Mypushbutton1 *ptn07=new Mypushbutton1(":/image/Image/back2.png");
    ptn07->setParent(ui->page7);
    ptn07->move(1250,750);
    connect(ptn07,&QPushButton::clicked,[=](){
        backing->play();
        ui->stackedWidget->setCurrentIndex(0);
        hap->stop();
        sounds->play();
    });





    Mypushbutton1 *AI1 = new Mypushbutton1(":/image/Image/easy.png");
    AI1->setParent(ui->page6);
    AI1->move(100,100);

    connect(AI1,&Mypushbutton1::clicked,[=](){

        inscli->play();
        MainWindow *gameui = new MainWindow;
        this->hide();
        sounds->stop();
        gameui->show();
        whichone=1;
        connect(gameui,&MainWindow::fan,[=]()
        {
            sounds->play();
            this->show();
        });

        connect(gameui,&MainWindow::tui,[=]()
        {
            sounds->play();
            this->close();
        });
    });

    Mypushbutton1 *AI2 = new Mypushbutton1(":/image/Image/middle.png");
    AI2->setParent(ui->page6);
    AI2->move(600,100);
    connect(AI2,&Mypushbutton1::clicked,[=](){
        inscli->play();

        MainWindow *gameui = new MainWindow;

        this->hide();
        sounds->stop();
        gameui->show();
        whichone=2;
        connect(gameui,&MainWindow::fan,[=]()
        {

            sounds->play();
            this->show();
        });

        connect(gameui,&MainWindow::tui,[=]()
        {
            sounds->play();
            this->close();
        });
    });

    Mypushbutton1 *AI3 = new Mypushbutton1(":/image/Image/hard.png");
    AI3->setParent(ui->page6);
    AI3->move(1050,100);
    connect(AI3,&Mypushbutton1::clicked,[=](){
        MainWindow *gameui = new MainWindow;
        inscli->play();
        this->hide();
        sounds->stop();
        gameui->show();
        whichone=3;
        connect(gameui,&MainWindow::fan,[=]()
        {
            sounds->play();
            this->show();
        });

        connect(gameui,&MainWindow::tui,[=]()
        {
            sounds->play();
            this->close();
        });
    });

    Mypushbutton1 *AI4 = new Mypushbutton1(":/image/Image/proeasy.png");
    AI4->setParent(ui->page7);
    AI4->move(100,100);

    connect(AI4,&Mypushbutton1::clicked,[=](){
        promainwindow *game2ui = new promainwindow;
        inscli->play();
        this->hide();
        hap->stop();
        hap2->play();
        game2ui->prowhichone=1;
        game2ui->show();
        connect(game2ui,&promainwindow::fan,[=]()
        {
            hap2->stop();
            hap->play();
            this->show();
        });

        connect(game2ui,&promainwindow::tui,[=]()
        {
            hap2->stop();
            hap->play();
            this->close();
        });
    });

    Mypushbutton1 *AI5 = new Mypushbutton1(":/image/Image/promid.png");
    AI5->setParent(ui->page7);
    AI5->move(600,100);
    connect(AI5,&Mypushbutton1::clicked,[=](){
        inscli->play();

        promainwindow *game2ui = new promainwindow;

        this->hide();
        hap->stop();
        hap2->play();
        game2ui->show();
        game2ui->prowhichone=2;
        connect(game2ui,&promainwindow::fan,[=]()
        {
            hap2->stop();
            hap->play();
            this->show();
        });

        connect(game2ui,&promainwindow::tui,[=]()
        {
            hap2->stop();
            hap->play();
            this->close();
        });
    });

    Mypushbutton1 *AI6 = new Mypushbutton1(":/image/Image/prohard.png");
    AI6->setParent(ui->page7);
    AI6->move(1050,100);
    connect(AI6,&Mypushbutton1::clicked,[=](){
        promainwindow *game2ui = new promainwindow;
        inscli->play();
        this->hide();
        hap->stop();
        hap2->play();
        game2ui->show();
        game2ui->prowhichone=3;
        connect(game2ui,&promainwindow::fan,[=]()
        {
            hap2->stop();
            hap->play();
            this->show();
        });

        connect(game2ui,&promainwindow::tui,[=]()
        {
            hap2->stop();
            hap->play();
            this->close();
        });
    });


    QLabel *label_5 = new QLabel;
    label_5->setGeometry(320,10,781,151);
    label_5->setParent(ui->page1);
    QPixmap pixx1;
    pixx1.load(":/image/Image/title.png");
    label_5->setPixmap(pixx1);

    QLabel *label = new QLabel;
    label->setGeometry(290,160,1071,661);
    label->setParent(ui->page3);
    QPixmap pixx2;
    pixx2.load(":/image/Image/ruleshow.png");
    label->setPixmap(pixx2);

    QLabel *label_2 = new QLabel;
    label_2->setGeometry(340,110,1011,631);
    label_2->setParent(ui->page4);
    QPixmap pixx3;
    pixx3.load(":/image/Image/rulecontinue.png");
    label_2->setPixmap(pixx3);

    QLabel *label_3 = new QLabel;
    label_3->setGeometry(310,100,1011,681);
    label_3->setParent(ui->page5);
    QPixmap pixx4;
    pixx4.load(":/image/Image/git.png");
    label_3->setPixmap(pixx4);

    QLabel *label_6 = new QLabel;
    label_6->setGeometry(280,380,991,101);
    label_6->setParent(ui->page5);
    QPixmap pixx6;
    pixx6.load(":/image/Image/CV.png");
    label_6->setPixmap(pixx6);


    QLabel *label_4 = new QLabel;
    label_4->setGeometry(270,520,1031,191);
    label_4->setParent(ui->page6);
    QPixmap pixx5;
    pixx5.load(":/image/Image/geyan.png");
    label_4->setPixmap(pixx5);


}

void MyMainScene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/bg.png");
    painter.drawPixmap(0,0,pix);
}

MyMainScene::~MyMainScene()
{
    delete movie;
    delete ui;

}
