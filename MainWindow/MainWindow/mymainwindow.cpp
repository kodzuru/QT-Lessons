#include "mymainwindow.h"
#include "ui_mymainwindow.h"

MyMainWindow::MyMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyMainWindow)
{
    ui->setupUi(this);

    /*
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(ui->pushButton, 0, 0);
    grid->addWidget(ui->pushButton_2, 1, 1);

    QWidget* as = new QWidget;
    as->setLayout(grid);
    setCentralWidget(as);
    */
    /*
    QMenu *file = menuBar()->addMenu("File");
    QMenu *edit = menuBar()->addMenu("Edit");

    QAction *NewFile = new QAction(tr("New"), this);
    NewFile->setShortcut(QKeySequence::New);
    QAction *Open = new QAction(tr("New"), this);
    Open->setShortcut(QKeySequence::Cut);

    connect( NewFile, SIGNAL(triggered()), this, SLOT(action()) );

    file->addAction(NewFile);
    file->addAction(Open);
    file->addMenu(edit);
    */
    ui->actionNewWindow->setIcon(QIcon(":/Images/PlayStation_1_Logo.png"));
    setCentralWidget(ui->textEdit);

}

MyMainWindow::~MyMainWindow()
{
    delete ui;
}

void MyMainWindow::on_actionNewWindow_triggered()
{
    /*
    MyWindow *wnd = new MyWindow(this);
    str *b = new str;
    QObject::connect(wnd, SIGNAL(Simple(QString)), b, SLOT(Simple(QString)) );
    QObject::connect(wnd, SIGNAL(Invers(QString)), b, SLOT(Inversia(QString)) );
    QObject::connect(wnd, SIGNAL(Register(QString)), b, SLOT(RegisterUpper(QString)) );
    QObject::connect(wnd, SIGNAL(SimpleTogetherSignal(QString)), b, SLOT(SimpleTogetherSlot(QString)) );
    wnd->show();
    */
    MyWindow wind(this);
    str *b = new str;
    QObject::connect(&wind, SIGNAL(Simple(QString)), b, SLOT(Simple(QString)) );
    QObject::connect(&wind, SIGNAL(Invers(QString)), b, SLOT(Inversia(QString)) );
    QObject::connect(&wind, SIGNAL(Register(QString)), b, SLOT(RegisterUpper(QString)) );
    QObject::connect(&wind, SIGNAL(SimpleTogetherSignal(QString)), b, SLOT(SimpleTogetherSlot(QString)) );

    wind.show();
    wind.exec();

}

void MyMainWindow::on_actionClose_triggered()
{
    close();
}
