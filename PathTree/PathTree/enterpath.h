#ifndef ENTERPATH_H
#define ENTERPATH_H

#include <QDialog>

namespace Ui {
class enterpath;
}

class enterpath : public QDialog
{
    Q_OBJECT

public:
    explicit enterpath(QWidget *parent = 0);
    ~enterpath();

private:
    Ui::enterpath *ui;
private slots:
    void okClicked();
signals:
    void FilePath(const QString &);
};

#endif // ENTERPATH_H
