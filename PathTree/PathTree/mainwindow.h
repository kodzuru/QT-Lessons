#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include <QMainWindow>
#include "enterpath.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QtGui>
#include <QtCore>

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
    void on_actionPrint_Path_Tree_triggered();
    void PrintTee(const QString &);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
private:
    QString TreeRecFunc(QString, int);
    QString TreeRecFunc(QString, int, QTreeWidgetItem *);
};

#endif // MAINWINDOW_H
