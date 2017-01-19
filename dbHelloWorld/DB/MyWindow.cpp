#include "MyWindow.h"

MyWindow::MyWindow(QWidget* parent) : QDialog(parent)
{
   lbl_login = new QLabel("LogIn");
   line_login = new QLineEdit;

   lbl_pass = new QLabel("Password");
   line_pass = new QLineEdit;

   ok = new QPushButton("ok");
   ok->setDefault(true);
   ok->setEnabled(false);
   close = new QPushButton("Выход");


   QHBoxLayout *layout1 = new QHBoxLayout;
   layout1->addWidget(lbl_login);
   layout1->addWidget(line_login);

   QHBoxLayout *layout2 = new QHBoxLayout;
   layout2->addWidget(lbl_pass);
   layout2->addWidget(line_pass);

   QVBoxLayout *left = new QVBoxLayout;
   left->addLayout(layout1);
   left->addLayout(layout2);

    QVBoxLayout *right = new QVBoxLayout;
    right->addWidget(ok);
    right->addWidget(close);

    QHBoxLayout *main = new QHBoxLayout;
    main->addLayout(left);
    main->addLayout(right);

    connect( line_login, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)) );
    connect( close, SIGNAL(clicked()), this, SLOT(close()) );
    connect( ok, SIGNAL(clicked()), this, SLOT(okClicked()) );



    setLayout(main);
    setWindowTitle("LogIn");
}

void MyWindow::TextChanged(QString str)
{
    ok->setEnabled(!str.isEmpty());
}
void MyWindow::okClicked()
{
    emit LogIn(line_login->text(), line_pass->text());
}





















