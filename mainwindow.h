#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QThread>
#include "streamthread.h"
#include "opencv2/opencv.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:

    mainWindow(QWidget *parent = nullptr);
    ~mainWindow();
private slots:
    void on_pushButton_clicked();
    void updateFrame(QImage img);

signals:
    void newFrame(QImage img);


private:
    Ui::mainWindow *ui;
    std::string url;
    StreamThread *streamThread;


};

#endif // MAINWINDOW_H
