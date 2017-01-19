#ifndef MYMAINWINDOW_H
#define MYMAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QWidget>
#include <QToolBar>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include "mywindow.h"

namespace Ui {
class MyMainWindow;
}

class MyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyMainWindow(QWidget *parent = 0);
    ~MyMainWindow();

private:
    Ui::MyMainWindow *ui;
private slots:
    void action()
    {
        QMessageBox msg;
        msg.setText("Action");
        msg.exec();
    }
    void on_actionNewWindow_triggered();
    void on_actionClose_triggered();
};

#endif // MYMAINWINDOW_H
