#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;
signals:
    void FilePath(const QString &);
private slots:
    void okClicked();
};

#endif // DIALOG_H
