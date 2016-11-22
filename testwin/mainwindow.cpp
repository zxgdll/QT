#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDialog>
#include <QDebug>
#include <QTextEdit>
#include <QFileDialog>
#include <QWidget>
#include <QIODevice>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main window"));
    openAction=new QAction(QIcon(":/images/doc-open"),tr("&open..."),this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));

    saveAction=new QAction(QIcon(":/images/save"),tr("&Save..."),this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file"));

//    connect(openAction,&QAction::triggered,this,&MainWindow::open);
    QMenu *file=menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar=addToolBar(tr("&File"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    textEdit=new QTextEdit(this);
    setCentralWidget(textEdit);

    connect(openAction,&QAction::triggered,this,&MainWindow::openFile);
    connect(saveAction,&QAction::triggered,this,&MainWindow::saveFile);

    statusBar();
}

MainWindow::~MainWindow()
{

}
//void MainWindow::open()
//{
//    QMessageBox::information(this,tr("Information"),tr("Open"));
//}
void MainWindow::openFile()
{
    /*QDialog *dialog=new QDialog;
    dialog->setAttribute((Qt::WA_DeleteOnClose));
    dialog->setWindowTitle("hello ,dailog");
    dialog->show();*/
//    QDialog dialog(this);
//    dialog.setWindowTitle((tr("Hello,dialog!")));
//    dialog.exec();
//    if(QMessageBox::Yes==QMessageBox::question(this,tr("Question"),
//                                               tr("Are you Ok?"),
//                                               QMessageBox::Yes|QMessageBox::No,
//                                               QMessageBox::Yes)){
//        QMessageBox::information(this,tr("Hmmm..."),tr("I'm glad to hear that!"));
//    }
//    else{
//    QMessageBox::information(this,tr("Hmmm..."),tr("I'm sorry!"));}
//    QMessageBox msgBox;
//    msgBox.setText(tr("The document has been midified."));
//    msgBox.setInformativeText(tr("Do you want to save your changes?"));
//    msgBox.setDetailedText(tr("differences here ..."));
//    msgBox.setStandardButtons(QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel);
//    msgBox.setDefaultButton(QMessageBox::Save);
//    int ret=msgBox.exec();
//    switch(ret){
//    case QMessageBox::Save:
//        qDebug()<<"Save document!";
//        break;
//    case QMessageBox::Discard:
//        qDebug()<<"Discard changes!";
//        break;
//    case QMessageBox::Cancel:
//        qDebug()<<"Cacel!";
//        break;
//    }
    QString path=QFileDialog::getOpenFileName(this,tr("Open File"),".",tr("Text file (*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
            QMessageBox::warning(this,tr("Read File"),
                                 tr("Cannot open file:\n%1").arg(path));
            return;
        }
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
    }else{
        QMessageBox::warning(this,tr("Path"),tr("You did not select any file."));
    }
}
void MainWindow::saveFile()
{
    QString path=QFileDialog::getSaveFileName(this,tr("Save file"),
                                              ".",tr("Text Files(*.txt)"));
    if(!path.isEmpty()){
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){
            QMessageBox::warning(this,tr("Write File"),
                                 tr("Cannot write file:\n%1").arg(path));
            return;
        }
        QTextStream out(&file);
        out<<textEdit->toPlainText();
        file.close();
    }else{
        QMessageBox::warning(this,tr("Path"),tr("You did not select any file."));
    }

}
