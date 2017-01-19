#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql>

class MyWindow : public QDialog
{
    Q_OBJECT
public:
    MyWindow(QWidget* parent=0);
private:
    QLabel* lbl_login;
    QLineEdit* line_login;
    QLabel* lbl_pass;
    QLineEdit* line_pass;
    QPushButton* ok;
    QPushButton* close;
private slots:
    void TextChanged(QString);
    void okClicked();
signals:
    void LogIn(QString, QString);
};
class str : public QObject
{
    Q_OBJECT
public:
    QString str_login;
    QString str_pass;
    str(){
        str_login;
        str_pass;
    }
private:
    void DB_connect()
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("QT_simple_bd");
        db.setUserName("root");
        db.setPassword("");
        bool ok = db.open();
        if(ok)
        {
            QSqlQuery query;
            query.exec( "SELECT login, password FROM account" );
            while (query.next()) {
                 str_login = query.value(0).toString();
                 str_pass = query.value(1).toString();
             }
        }

    }
public slots:
    void LogIn_filled(QString login, QString pass)
    {

        QMessageBox msg;
        DB_connect();
        if(str_login == login && str_pass == pass){
            msg.setText("LogIn SUCCES !!!");
            msg.exec();
        }else{
            msg.setText("LogIn проёбан !!!");
            msg.exec();
        }
    }
};

#endif // MYWINDOW_H
