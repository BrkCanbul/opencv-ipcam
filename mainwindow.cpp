#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QTimer>
mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{

    cap = new cv::VideoCapture();
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    qDebug("geldin mi");
    connect(timer,SIGNAL(timeout()),this,SLOT(updateFrame()));
    timer->start(1);
}

mainWindow::~mainWindow()
{
    delete ui;
}


void mainWindow::on_pushButton_clicked()
{
    this->url = ui->urlLine->text().toStdString();
    qDebug("url: %s", this->url.c_str());
    cap->open(this->url);
    qDebug("capture was opened");

}


void mainWindow::updateFrame(){


        cv::Mat frame;
        *cap >> frame;

        if(frame.empty()){
            qDebug("frame is empty");
            return;
        }
        cv::resize(frame,frame,cv::Size(1000,600));
        cv::cvtColor(frame,frame,cv::COLOR_BGR2RGB);
        QImage img(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
        ui->imgLabel->setPixmap(QPixmap::fromImage(img));

}

