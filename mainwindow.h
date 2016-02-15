#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//private:
    Ui::MainWindow *ui;
protected:
    // 为真表示文件没有保存过，为假表示文件已经被保存过了
    bool isUntitled;
    // 保存当前文件的路径
    QString curFile;
    //保存文件名
    QString FileName;
protected:
    bool loadFile(const QString &fileName); // 加载文件
    void NewFile();
    bool maybeSave();
    bool save();
    bool saveAs();
    bool saveFile(const QString &fileName);
    void closeEvent(QCloseEvent *event); // 关闭事件
private slots:
    void on_newfile_triggered();
    void on_openfile_triggered();
    void on_savefile_triggered();
    void on_saveas_triggered();
    void on_exit_triggered();
    void on_undo_triggered();
    void on_cut_triggered();
    void on_copy_triggered();
    void on_paste_triggered();
    void on_delete_2_triggered();
    void on_find_triggered();
    void on_status_triggered();
    void on_autoline_triggered();
public:
    //对外
    bool FindStr(QString &index,int mode);
};

#endif // MAINWINDOW_H
