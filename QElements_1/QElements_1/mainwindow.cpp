#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "a" << "b" << "c" << "d");
    ui->tableWidget->setVerticalHeaderLabels(QStringList() << "a" << "b" << "c" << "d");

    int count = 1;
    for(int i(0); i < ui->tableWidget->rowCount(); i++){
        for(int j(0); j < ui->tableWidget->columnCount(); j++){
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(count));
            ui->tableWidget->setItem(i,j,itm);
            count++;
        }
    }

    QTimer *time = new QTimer(this);
    connect( time, SIGNAL(timeout()), this, SLOT(ActionTimer()) );
    time->start(2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QTableWidgetItem *item = ui->tableWidget->currentItem();
    QMessageBox::information(this, "Info", item->text());
}

void MainWindow::ActionTimer(){
    srand(time(NULL));
    int i = rand()%ui->tableWidget->rowCount();
    int j = rand()%ui->tableWidget->columnCount();

    QTableWidgetItem *itm = new QTableWidgetItem("rand");
    itm->setBackgroundColor(QColor(rand()%255,rand()%255,rand()%255,255));
    ui->tableWidget->setItem(i,j,itm);

}
