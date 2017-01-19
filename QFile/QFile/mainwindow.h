#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "dialog.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionRead_triggered();
    void ReadToFile(const QString &);
    void PrintDir(const QString &);
    void on_actionWrite_to_file_triggered();
    void on_actionPrint_Dir_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
