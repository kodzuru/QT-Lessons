#include <QApplication>
#include "mywindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    {
        /*
        std::shared_ptr<QPushButton> pb(new QPushButton("Close"));
        pb->show();
        QObject::connect(pb.get(), SIGNAL(clicked()), &a, SLOT(quit()));
        */
        /*
        //std::shared_ptr<QSpinBox> sb(new QSpinBox); //создаём спинбокс
        //std::shared_ptr<QSlider> sl(new QSlider(Qt::Horizontal)); //создаёмгоризонтальный ползунок
        QSpinBox* sb = new QSpinBox;
        QSlider *sl = new QSlider(Qt::Horizontal);
        sb->setMaximum(100);
        sl->setMaximum(100);

        //std::shared_ptr<QWidget> window(new QWidget); // окно виджетов
        //std::shared_ptr<QHBoxLayout> layout(new QHBoxLayout); // создаём слой
        QWidget *window = new QWidget;
        QHBoxLayout* layout = new QHBoxLayout;
        //помещаем виджеты на слой
        //layout->addWidget(sb.get());
        //layout->addWidget(sl.get());
        layout->addWidget(sb);
        layout->addWidget(sl);
        //помещаем слой на окно
        //window->setLayout(layout.get());
        window->setLayout(layout);
        window->show();

        //QObject::connect(sb.get(), SIGNAL(valueChanged(int)), sl.get(), SLOT(setValue(int)));
        //QObject::connect(sl.get(), SIGNAL(valueChanged(int)), sb.get(), SLOT(setValue(int)));
        QObject::connect(sb, SIGNAL(valueChanged(int)), sl, SLOT(setValue(int)));
        QObject::connect(sl, SIGNAL(valueChanged(int)), sb, SLOT(setValue(int)));
        */
    }

    MyWindow *window = new MyWindow();

    window->show();

    str *b = new str;
    QObject::connect(window, SIGNAL(Simple(QString)), b, SLOT(Simple(QString)) );
    QObject::connect(window, SIGNAL(Invers(QString)), b, SLOT(Inversia(QString)) );
    QObject::connect(window, SIGNAL(Register(QString)), b, SLOT(RegisterUpper(QString)) );
    QObject::connect(window, SIGNAL(SimpleTogetherSignal(QString)), b, SLOT(SimpleTogetherSlot(QString)) );

    return a.exec();
}
