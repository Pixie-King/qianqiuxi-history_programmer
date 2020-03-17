#ifndef MYPUSHBUTTON1_H
#define MYPUSHBUTTON1_H

#include <QPushButton>
#include <QDebug>

class Mypushbutton1 : public QPushButton
{
    Q_OBJECT
public:
    //explicit Mypushbutton1(QWidget *parent = nullptr);
    Mypushbutton1(QString normalimg,QString mouseinimg="");
    QString normalimgPath;
    QString mouseinimgPath;
    void enterEvent(QEvent* e);
    void leaveEvent(QEvent* e);
signals:
    void mousein();
    void mouseout();
public slots:
};

#endif // MYPUSHBUTTON1_H
