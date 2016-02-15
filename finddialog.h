#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class finddialog;
}

class finddialog : public QDialog
{
    Q_OBJECT

public:
    explicit finddialog(QWidget *parent = 0);
    ~finddialog();

private slots:
    void on_findtext_clicked();

private:
    Ui::finddialog *ui;
};

#endif // FINDDIALOG_H
