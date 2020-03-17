#ifndef MYMAINSCENE_H
#define MYMAINSCENE_H

#include <QWidget>
#include "mypushbutton1.h"
#include <QMediaPlayer>
#include<QLabel>
namespace Ui {
class MyMainScene;
}

class MyMainScene : public QWidget
{
    Q_OBJECT

public:
    explicit MyMainScene(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent*);
    Mypushbutton1 *ptn1;
    Mypushbutton1 *ptn2;
    Mypushbutton1 *ptn3;
    Mypushbutton1 *ptn4;
    Mypushbutton1 *ptn5;
    QMovie *movie;
    ~MyMainScene();

private:
    Ui::MyMainScene *ui;
signals:
    void wannaback();
};

#endif // MYMAINSCENE_H
