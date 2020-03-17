#include "mylabel.h"
#include <QLabel>
#include<QTime>
#include"mainwindow.h"
mylabel::mylabel(QWidget *parent) : QLabel(parent)
{
}

void mylabel::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);
    emit clicked();
}
void mylabel::mouseReleaseEvent(QMouseEvent *e){
    Q_UNUSED(e);
    emit clicked2();
}
void mylabel::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    emit enter();
}
