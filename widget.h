#ifndef win_h
#define win_h

#include <QtGui>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <iostream>
#include <QCoreApplication>

class Counter: public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString & contents, QWidget *parent=nullptr): QLineEdit(contents, parent)
    {
        this->setReadOnly(true);
    }
signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str=text();
        int r=str.toInt();
        r++;
        if (r!=0 && r%5 ==0) emit tick_signal();
        str.setNum(r);
        setText(str);
    }
};


class Win: public QWidget
{
    Q_OBJECT
protected:
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcbutton;
    QPushButton *exitbutton;
public:
    Win(QWidget *parent = 0);
    ~Win();
};
#endif
