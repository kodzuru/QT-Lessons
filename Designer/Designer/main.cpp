#include <QApplication>
#include "mydialogwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyDialogWindow *wnd = new MyDialogWindow();
    wnd->show();


    return a.exec();
}
