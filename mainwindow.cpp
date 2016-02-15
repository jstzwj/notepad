#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"finddialog.h"
#include<QMenu>
#include<QMessageBox>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 初始化文件为未保存状态
    isUntitled = true;
    // 初始化文件名为"未命名.txt"
    curFile = tr("未命名.txt");
    FileName=tr("未命名.txt");
    // 初始化窗口标题为文件名
    setWindowTitle(curFile+" - 记事本");
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::loadFile(const QString &fileName)
{
   QFile file(fileName); // 新建QFile对象
   if (!file.open(QFile::ReadOnly | QFile::Text))
   {
       QMessageBox::warning(this, tr("多文档编辑器"),
                             tr("无法读取文件 %1:\n%2.")
                             .arg(fileName).arg(file.errorString()));
       return false; // 只读方式打开文件，出错则提示，并返回false
   }
   QTextStream in(&file); // 新建文本流对象
    QApplication::setOverrideCursor(Qt::WaitCursor);
    // 读取文件的全部文本内容，并添加到编辑器中
     ui->plainTextEdit->setPlainText(in.readAll());
     QApplication::restoreOverrideCursor();
     // 设置当前文件
     curFile = QFileInfo(fileName).canonicalFilePath();
     setWindowTitle(curFile);
     return true;
}

void MainWindow::NewFile()
{
   if (maybeSave()) {
       isUntitled = true;
       curFile = tr("未命名.txt");
       FileName= tr("未命名.txt");
       setWindowTitle(curFile);
       ui->plainTextEdit->clear();
       ui->plainTextEdit->setVisible(true);
   }
}

bool MainWindow::maybeSave()
{
        // 如果文档被更改了
        if (ui->plainTextEdit->document()->isModified())
        {
        // 自定义一个警告对话框
       QMessageBox box;
       box.setWindowTitle(tr("记事本"));
       //改变颜色
      // box.setIcon(QMessageBox::Warning);
       //box.setFont(QFont( "宋体" , 12 ,  QFont::Bold) );
       box.setText(tr(" 是否将更改保存到\n") + curFile + "?");
       QPushButton *yesBtn = box.addButton(tr("保存(&S)"),
                        QMessageBox::YesRole);
       box.addButton(tr("不保存(&N)"), QMessageBox::NoRole);
       QPushButton *cancelBut = box.addButton(tr("取消"),
                        QMessageBox::RejectRole);
       box.exec();
        if ((QPushButton *)box.clickedButton() == yesBtn)
            return save();
        else if ((QPushButton *)box.clickedButton() == cancelBut)
            return false;
        }
        return true;
}

bool MainWindow::save()
{
   if (isUntitled)
   {
       return saveAs();
   }
   else
   {
       return saveFile(curFile);
   }
}

bool MainWindow::saveAs()
{
   QString fileName = QFileDialog::getSaveFileName(this,tr("另存为"),curFile,tr("文本文档(*.txt);;所有文件(*.*)"));
   if (fileName.isEmpty()) return false;
   return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName)
{
   QFile file(fileName);

   if (!file.open(QFile::WriteOnly | QFile::Text)) {

       // %1和%2分别对应后面arg两个参数，/n起换行的作用
       QMessageBox::warning(this, tr("多文档编辑器"),
                   tr("无法写入文件 %1：/n %2")
                  .arg(fileName).arg(file.errorString()));
       return false;
   }
   QTextStream out(&file);
   // 鼠标指针变为等待状态
   QApplication::setOverrideCursor(Qt::WaitCursor);
   out << ui->plainTextEdit->toPlainText();
   // 鼠标指针恢复原来的状态
   QApplication::restoreOverrideCursor();
   isUntitled = false;
   // 获得文件的标准路径
   curFile = QFileInfo(fileName).canonicalFilePath();
   setWindowTitle(fileName+" - 记事本");
   return true;
}

void MainWindow::on_newfile_triggered()
{
    NewFile();
}

void MainWindow::on_openfile_triggered()
{
    if (maybeSave())
    {

          QString fileName = QFileDialog::getOpenFileName(this);

          // 如果文件名不为空，则加载文件
          if (!fileName.isEmpty())
          {
               loadFile(fileName);
               ui->plainTextEdit->setVisible(true);
          }
      }
}

void MainWindow::on_savefile_triggered()
{
    save();
}


void MainWindow::on_saveas_triggered()
{
    saveAs();
}

void MainWindow::on_exit_triggered()
{
    if (maybeSave())
    {
        ui->plainTextEdit->setVisible(false);
    }
    // 先执行关闭操作，再退出程序
    // qApp是指向应用程序的全局指针
    qApp->quit();
}

void MainWindow::on_undo_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::on_cut_triggered()
{
    ui->plainTextEdit->cut();
}

void MainWindow::on_copy_triggered()
{
    ui->plainTextEdit->copy();
}

void MainWindow::on_paste_triggered()
{
    ui->plainTextEdit->paste();
}

void MainWindow::on_delete_2_triggered()
{
    ui->plainTextEdit->cut();
}
void MainWindow::closeEvent(QCloseEvent *event)
{
   // 如果maybeSave()函数返回true，则关闭程序
   if (maybeSave())
   {
       event->accept();
   }
   else
   {   // 否则忽略该事件
       event->ignore();
   }
}

void MainWindow::on_find_triggered()
{
    finddialog *find=new finddialog(this);
    find->show();
}

void MainWindow::on_status_triggered()
{
    static bool isStatus;//是否有状态栏
    if(isStatus==true)
    {
        isStatus=false;
        ui->statusBar->show();
        //ui->autoline->setChecked(false);
    }
    else
    {
        isStatus=true;
        ui->statusBar->hide();
        //ui->autoline->setChecked(true);
    }
}

void MainWindow::on_autoline_triggered()
{
    static bool isAuto;//是否自动换行
    if(isAuto==true)
    {
        isAuto=false;
        ui->autoline->setChecked(false);
        ui->status->setEnabled(true);
    }
    else
    {
        isAuto=true;
        ui->autoline->setChecked(true);
        ui->status->setEnabled(false);
    }
}
bool MainWindow::FindStr(QString &index,int mode)
{
    //ui->plainTextEdit->moveCursor(QTextCursor::StartOfLine,QTextCursor::MoveAnchor);
    int temp=mode%10;
    if(mode-temp==0)
    {
       //上下
       if(temp==0)
       {

       }
       else
       {
           ui->plainTextEdit->find(index, QTextDocument::FindBackward);
       }
    }
    else if(mode-temp==1)
    {
        //上下
        if(temp==0)
        {

        }
        else
        {
            ui->plainTextEdit->find(index, QTextDocument::FindBackward|QTextDocument::FindCaseSensitively);
        }
    }

    return true;
}
