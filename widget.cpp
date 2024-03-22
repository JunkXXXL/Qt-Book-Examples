#include "widget.h"

Window::Window()
{
    this->setWindowTitle("Обработка событий");
    area = new Area( this );

    btn = new QPushButton("Завершить",this );
    QVBoxLayout *layout = new QVBoxLayout(this);
    if (layout == nullptr)
    {
        std::cerr << "no enough memory";
    }
    else
    {
        layout->addWidget(area);
        layout->addWidget(btn);
    }

    connect(btn, &QPushButton::clicked, this, &QWidget::close);
};

Window::~Window()
{
    delete area;
    delete btn;
}
