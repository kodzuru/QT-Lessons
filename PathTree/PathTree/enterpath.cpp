#include "enterpath.h"
#include "ui_enterpath.h"
#include <QPushButton>

enterpath::enterpath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enterpath)
{
    ui->setupUi(this);
    connect( ui->buttonBox->button(QDialogButtonBox::Ok), SIGNAL(clicked()), this, SLOT(okClicked()) );
    connect( ui->buttonBox->button(QDialogButtonBox::Cancel), SIGNAL(clicked()), this, SLOT(close()) );

}

enterpath::~enterpath()
{
    delete ui;
}
 void enterpath::okClicked()
 {
    emit FilePath(ui->lineEdit->text());
     close();
 }
