#include "finddialog.h"
#include"mainwindow.h"
#include "ui_finddialog.h"
#include<QMessageBox>


finddialog::finddialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finddialog)
{
    ui->setupUi(this);
}

finddialog::~finddialog()
{
    delete ui;
}

void finddialog::on_findtext_clicked()
{
    QString index;
    int mode=0;
    MainWindow *ptr = (MainWindow*)parentWidget();
    index=ui->lineEdit->text();
    //设置模式
    if(ui->checkBox->isChecked())
    {
        mode+=1;
    }
    if(ui->up->isChecked())
    {
        mode=mode*10;
        mode+=0;
    }
    else
    {
        mode=mode*10;
        mode+=1;
    }
    if (!ptr->FindStr(index,mode))
    {
        QMessageBox::warning(this, tr("查找"),
        tr("找不到%1").arg(index));
    }
}
