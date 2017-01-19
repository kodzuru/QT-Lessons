#include "mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setCentralWidget(ui->treeWidget);

    ui->statusBar->showMessage("It WORK !!!");
    /*
    ui->comboBox->clear();
    for(int i(0); i < 10; i++){
        ui->comboBox->addItem(QString::number(i));
        ui->listWidget->addItem(QString::number(i));
    }

    QTreeWidgetItem *item = new QTreeWidgetItem(2);
    QTreeWidgetItem *child = new QTreeWidgetItem(2);
    QTreeWidgetItem *child2 = new QTreeWidgetItem(2);
    item->setText(0, "Hello");
    item->setText(1, "Descr");
    child->setText(0, "Hello");
    child2->setText(0, "Descr");
    item->addChild(child);
    item->addChild(child2);
    */

    ui->treeWidget->setColumnCount(2);
    //ui->treeWidget->addTopLevelItem(item);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionPrint_Path_Tree_triggered()
{
    enterpath *wnd = new enterpath(this);
    wnd->show();

    connect(wnd, SIGNAL(FilePath(QString)), this, SLOT(PrintTee(QString)) );
}

void MainWindow::PrintTee(const QString &filePath)
{

    ui->textEdit->setText(TreeRecFunc(filePath, 0));


}


QString MainWindow::TreeRecFunc(QString filePath, int level)
{

    QString star = "";
    QDir mDir(filePath);
    QString buf;
    int cnt = 1;
    for(int i(0); i < level; i++){
        star += "**************";
    }

    for(QFileInfo temp : mDir.entryInfoList())
    {
        if(cnt > 2)
        {
            buf += star + temp.absoluteFilePath() + '\n';
            if(temp.isDir()){
                buf += TreeRecFunc(temp.absoluteFilePath(), ++level);
            }
        }
        cnt++;
    }
    return buf;
}


void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::information(this, "Title", ui->comboBox->currentText());
    //QListWidgetItem *item = ui->listWidget->currentItem();
    //item->setBackground(Qt::red);
    //QMessageBox::warning(this, "warning", item->text());
    //QMessageBox::warning(this, "warning", ui->treeWidget->currentItem()->text(0));

    QTreeWidgetItem *item = new QTreeWidgetItem(2);
    item->setText(0, "Root");

    TreeRecFunc("e:/Work/QT_PROJECTS/lessons/QFile/QFile/", 0, item);


    ui->treeWidget->addTopLevelItem(item);


}

QString MainWindow::TreeRecFunc(QString filePath, int level, QTreeWidgetItem * item)
{

    QString star = "";
    QDir mDir(filePath);
    QString buf;
    int cnt = 1;
    for(int i(0); i < level; i++){
        star += "**************";
    }

    for(QFileInfo temp : mDir.entryInfoList())
    {
        if(cnt > 2)
        {
            QTreeWidgetItem *item2 = new QTreeWidgetItem(2);
            item2->setText(0, temp.fileName());
            item2->setText(1, temp.absoluteFilePath());
            item->addChild(item2);
            buf += star + temp.absoluteFilePath() + '\n';
            if(temp.isDir()){
                buf += TreeRecFunc(temp.absoluteFilePath(), ++level, item2);
            }
        }
        cnt++;
    }
    return buf;
}
