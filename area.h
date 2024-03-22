#include "figura.h"
#include <QWidget>
#include<QDebug>

class Area: public QWidget
{
    int MyTimer;
    float alpha;
public:
    Area(QWidget * parent = nullptr);
    ~Area();
    MyLine * myline;
    MyRect * myrect;
protected:
    void paintEvent(QPaintEvent *event);
    virtual void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent * event);
    void hideEvent(QHideEvent * event);
};

