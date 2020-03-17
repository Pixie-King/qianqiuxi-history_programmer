#include "mypushbutton1.h"
#include <QTimer>
Mypushbutton1::Mypushbutton1(QString normalimg,QString mouseinimg)
{
    this->normalimgPath=normalimg;
    this->mouseinimgPath=mouseinimg;
    QPixmap pix;
    bool ret = pix.load(this->normalimgPath);
    if(!ret)
    {
        QString str=QString("%1 Í¼Æ¬¼ÓÔØÊ§°Ü").arg(this->normalimgPath);
        qDebug()<<str;
        return;
    }

    this->setFixedSize(pix.width(),pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");

    this->setIcon(pix);

    this->setIconSize(QSize(pix.width(),pix.height()));




}
void Mypushbutton1::enterEvent(QEvent* e)
{

    emit mousein();
}
void Mypushbutton1::leaveEvent(QEvent* e)
{

    emit mouseout();
}
