#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QAction *openAction,*saveAction;
    QTextEdit *textEdit;
    void openFile();
    void saveFile();
};

#endif // MAINWINDOW_H
