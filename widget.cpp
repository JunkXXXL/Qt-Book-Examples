#include "widget.h"
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QTextCodec>
#include<QMessageBox>
#include<QPushButton>
#include<limits>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Возведение в квадрат");
    frame = new QFrame(this);
    frame->setFrameShadow(QFrame::Raised);
    frame->setFrameShape(QFrame::Panel);
    inputLabel = new QLabel("Введите число:", this);
    inputEdit = new QLineEdit("",this);
    StrValidator *v = new StrValidator(inputEdit);
    inputEdit->setValidator(v);
    outputLabel = new QLabel("Результат:", this);
    outputEdit = new QLineEdit("",this);
    nextButton = new QPushButton("Следующее", this);
    exitButton = new QPushButton("Выход", this);

    QVBoxLayout *vLayout1 = new QVBoxLayout(frame);
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();

    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();

    connect(exitButton, &QPushButton::clicked,this, &QWidget::close);

    connect(nextButton, &QPushButton::clicked,this, &Widget::begin);

    connect(inputEdit, &QLineEdit::returnPressed, this, &Widget::calc);
}

Widget::~Widget()
{
}

void Widget::begin()
{
    inputEdit->clear();
    nextButton->setEnabled(false);
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);
    outputLabel->setVisible(false);
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();
}

void Widget::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok); //диапазон 10^-308 до 10^308
    r=a*a;
    qDebug() << r;
    if (Ok and r < std::numeric_limits<double>::max())
    {
        str.setNum(r);
        outputEdit->setText(str);
        inputEdit->setEnabled(false);
        outputLabel->setVisible(true);
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else if (r >= std::numeric_limits<double>::max())
    {
        QMessageBox msgBox(QMessageBox::Information,
                           "Возведение в квадрат.",
                           "Возведённое в квадрат число слишком большое",
                           QMessageBox::Ok);
        msgBox.exec();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,
                               "Возведение в квадрат.",
                               "Введено неверное значение.",
                               QMessageBox::Ok);
            msgBox.exec();
        }
}

