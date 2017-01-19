#include "mydialogwindow.h"
#include "ui_mydialogwindow.h"

MyDialogWindow::MyDialogWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialogWindow)
{
    ui->setupUi(this);
    ui->okButton->setEnabled(false);

    QRegExp exp("[a-zA-Z]{,5}[1-9]{1}[0-9]{,3}");
    ui->lineEdit->setValidator(new QRegExpValidator(exp, this)); // указывать родителя(this)для освобождения памяти
    connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(okEnabled()) );


}

MyDialogWindow::~MyDialogWindow()
{
    delete ui;
}

void MyDialogWindow::okEnabled()
{
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}

void MyDialogWindow::on_pushButton_clicked()
{
    static bool open = true;
    open = !open;
    ui->groupBox_2->setVisible(open);
}
