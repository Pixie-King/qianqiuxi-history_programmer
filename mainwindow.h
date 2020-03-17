#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QLabel"
#include "mylabel.h"
#include<QSoundEffect>
#include<QMediaPlayer>
#include<combine.h>
#include<azcombine.h>
#include"QTextEdit"

extern int whichone;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void random();
    int snum[44];
    int num[24];
    void allphoto();
    void photo();
    void midphoto();
    void stringg();
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
    combine * mycombine;
    azcombine * aicombine;
    void informationshow(QTextEdit *);
    void scoreshow();
    int ischose(combine*com);
    void exchange(combine*com,bool personorai);
    void exchange(azcombine*com,bool personorai);
    void showcard();
    bool isend(combine*com);
    bool isend(azcombine*com);

private:
    Ui::MainWindow *ui;

signals:
    void fan();
    void tui();
};

#endif // MAINWINDOW_H
