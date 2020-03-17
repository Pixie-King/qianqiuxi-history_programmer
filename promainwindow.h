#ifndef PROMAINWINDOW_H
#define PROMAINWINDOW_H

#include <QWidget>
#include "QLabel"
#include "mylabel.h"
#include<QSoundEffect>
#include<QMediaPlayer>
#include"ProCombine.h"
#include<azcombine.h>
#include"QTextEdit"
#include "proai.h"

namespace Ui {
class promainwindow;
}

class promainwindow : public QWidget
{
    Q_OBJECT

public:
    explicit promainwindow(QWidget *parent = nullptr);
    ~promainwindow();
    void random();
    int snum[44];
    int num[24];
    void allphoto();
    void photo();
    void midphoto();
    void stringg();
    int prowhichone;
    QPixmap pixmap[43];
    QString *string=new QString[43];
    QLabel *labelch=new QLabel[42];
    QTextEdit *editt=new QTextEdit();
    mylabel *label=new mylabel[18];
    mylabel *label2=new mylabel[8];
    mylabel *label_0=new mylabel();
    mylabel *labelc=new mylabel();
    mylabel *labelk=new mylabel();
    mylabel *labelr=new mylabel();
    mylabel *labeltui1=new mylabel();
    mylabel *labelfan1=new mylabel();
    mylabel *labeltui2=new mylabel();
    mylabel *labelfan2=new mylabel();
    QMediaPlayer *player;
    QMediaPlayer *player1;
    QMediaPlayer *player2;
    QMediaPlayer *playerend;
    QTextEdit *scoredit=new QTextEdit();
    QTextEdit *scoredit2=new QTextEdit();
    void replace(mylabel *,int);
    proCombine * mycombine;
    proai * aicombine;
    void informationshow(QTextEdit *);
    void scoreshow();
    int ischose(proCombine*com);
    void exchange(proCombine*com,bool personorai);
    void exchange(proai*com,bool personorai);
    void showcard();
    bool isend(proCombine*com);
    bool isend(proai*com);

private:
    Ui::promainwindow *ui;
signals:
    void fan();
    void tui();
};

#endif // PROMAINWINDOW_H
