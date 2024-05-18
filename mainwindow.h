#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>

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
    void updateFrame();

private:
    Ui::mainWindow *ui;
    std::string url;
    cv::VideoCapture *cap;

};

#endif // MAINWINDOW_H
