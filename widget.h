#ifndef WIDGET_H
#define WIDGET_H
#include <QtGui>
#include "area.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <iostream>

class Window : public QWidget
{
protected:
    Area * area; // область отображения рисунка
    QPushButton * btn;

public:
    Window();
    ~Window();
};
#endif
