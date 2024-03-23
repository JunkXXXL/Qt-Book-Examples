#include "area.h"

Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}

void Area::showEvent(QShowEvent * event)
{
    MyTimer=startTimer(50); // создать таймер; interval milliseconds
}

void Area::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    myline->move(alpha,&painter);
    myrect->move(alpha*(-0.5),&painter);
}

void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == MyTimer) // если наш таймер
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид
    }
}

void Area::hideEvent(QHideEvent *)
{
    killTimer(MyTimer); // уничтожить таймер
}

Area::~Area()
{
    delete myline;
    delete myrect;
}
