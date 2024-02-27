#ifndef WIDGET_H
#define WIDGET_H
#include <QtGui>
#include "area.h"
#include <QPushButton>
#include <QVBoxLayout>

class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;

public:
    Window();
};
#endif
