#include <QApplication>
#include "MyWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MyWindow *window = new MyWindow();
    window->show();

    str* b = new str();
    QObject::connect( window, SIGNAL(LogIn(QString,QString)), b, SLOT(LogIn_filled(QString,QString)) );

    return a.exec();
}
