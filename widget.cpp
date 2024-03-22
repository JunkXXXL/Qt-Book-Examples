#include "widget.h"


Win::Win(QWidget *parent): QWidget(parent)
{
    this->setWindowTitle("Счетчик");
    label1 = new QLabel("Cчет по 1",this);
    label2 = new QLabel("Cчет по 5",this);
    edit1 = new Counter("0",this);
    edit2 = new Counter("0",this);
    calcbutton=new QPushButton("+1",this);
    exitbutton=new QPushButton("Выход",this);
    QHBoxLayout *layout1 = new QHBoxLayout();
    QHBoxLayout *layout2 = new QHBoxLayout();
    QHBoxLayout *layout3 = new QHBoxLayout();
    QVBoxLayout *layout4 = new QVBoxLayout(this);

    if (label1 == nullptr or label2 == nullptr or edit1 == nullptr or calcbutton == nullptr or exitbutton == nullptr
        or layout1 == nullptr or layout2 == nullptr or layout3 == nullptr or layout4 == nullptr)
    {
        std::cerr << "Not enough memory";
        QMessageBox msgBox(QMessageBox::Information,
                           "Счетчик",
                           "Не удалось выделить достаточное количество памяти",
                           QMessageBox::Ok);
        msgBox.exec();
    }
    else
    {
        layout1->addWidget(label1);
        layout1->addWidget(label2);

        layout2->addWidget(edit1);
        layout2->addWidget(edit2);

        layout3->addWidget(calcbutton);
        layout3->addWidget(exitbutton);

        layout4->addLayout(layout1);
        layout4->addLayout(layout2);
        layout4->addLayout(layout3);
    }

    // связь сигнала нажатия кнопки и слота закрытия окна
    connect(calcbutton, &QPushButton::clicked,
            edit1, &Counter::add_one);
    connect(edit1,&Counter::tick_signal,
            edit2,&Counter::add_one);
    connect(exitbutton,&QPushButton::clicked,
            this, &QWidget::close);
}

Win::~Win()
{
    delete label1;
    delete label2;
    delete edit1;
    delete edit2;
    delete calcbutton;
    delete exitbutton;
}
