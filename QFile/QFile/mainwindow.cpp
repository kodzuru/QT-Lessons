#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);

    ui->statusBar->showMessage("Ready to work !!!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionRead_triggered()
{
    Dialog *wnd = new Dialog(this);
    wnd->show();

    connect( wnd, SIGNAL(FilePath(QString)), this, SLOT(ReadToFile(QString)) );
}

void MainWindow::ReadToFile(const QString &filePath)
{
    QFile mFile(":/Document/QFile.pro");
    if(!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Path not correct !!! ");
        ui->statusBar->showMessage("Error !!!");
        return;
    }else{
        ui->statusBar->showMessage("Succes read to file !!!");

    }

    QTextStream stream(&mFile);

    QString buffer = stream.readAll();

    ui->textEdit->setText(buffer);

    mFile.flush();
    mFile.close();


}

void MainWindow::on_actionWrite_to_file_triggered()
{
    QFile mFile(".//text.txt");
    if(!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this, "Error", "Path not correct !!! ");
        ui->statusBar->showMessage("Error !!!");

        return;
    }else{
        ui->statusBar->showMessage("Succes write to file !!!");

    }

    QTextStream stream(&mFile);

    stream << ui->textEdit->toPlainText();

    mFile.close();

}

void MainWindow::on_actionPrint_Dir_triggered()
{
    Dialog *wnd = new Dialog(this);
    wnd->show();

    connect( wnd, SIGNAL(FilePath(QString)), this, SLOT(PrintDir(QString)) );
}

void MainWindow::PrintDir(const QString &filePath)
{

    QDir mDir(filePath);

    QString buffer;

    for(QFileInfo temp : mDir.entryInfoList())
    {
        buffer += temp.absoluteFilePath() + '\n';
    }

    mDir.mkdir("Hello");
    ui->textEdit->setText(buffer);

}
