#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect( ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()),this, SLOT(okClicked()) );
    connect( ui->buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),this,  SLOT(close()) );
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::okClicked()
{
    emit FilePath(ui->lineEdit->text());
    close();
}
