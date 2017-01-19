#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QDialog> //содержит свойства show и т.д. БАЗОВЫЙ КЛАСС
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

class MyWindow : public QDialog
{
    Q_OBJECT //макрос для работы компилятора private slots
public:
    MyWindow(QWidget* parent=0);
private:
    QLabel *lbl;
    QLineEdit *line;
    QCheckBox *cb1;
    QCheckBox *cb2;
    QPushButton *ok;
    QPushButton *close;
private slots: // секция доступная с макросом Q_OBJECT
    void OkClicked();
    void TextChanged(QString);
signals:
    void Register(QString);
    void Invers(QString);
    void Simple(QString);
    void SimpleTogetherSignal(QString);
};


class str : public QObject
{
    Q_OBJECT
public slots:
    void Simple(QString str)
    {
        QMessageBox msg;
        msg.setText(str);
        msg.exec();
    }
    void Inversia(QString str)
    {
        QString result = str;
        for(int i = str.size(), j = 0; i >= 0; i--, j++){
            result[j] = str[i];
        }
        QMessageBox msg;
        msg.setText(result);
        msg.exec();
    }
    void RegisterUpper(QString str)
    {
        QString result = str;
        for(int i = 0; i < str.size(); i++)
        {
            result[i] = str[i].toUpper();
        }
        QMessageBox msg;
        msg.setText(result);
        msg.exec();
    }
    void SimpleTogetherSlot(QString str)
    {
        QString result = str;
        for(int i = str.size(), j = 0; i >= 0; i--, j++){
            result[j] = str[i];
            result[j] = result[j].toUpper();
        }
        QMessageBox msg;
        msg.setText(result);
        msg.exec();
    }
};

#endif // MYWINDOW_H
