#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "streamthread.h"
#include <opencv2/opencv.hpp>
#include <QTimer>

mainWindow::mainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    streamThread = nullptr;
    connect(this,&mainWindow::newFrame,this,&mainWindow::updateFrame);
}

mainWindow::~mainWindow()
{
    if(streamThread){
        streamThread->requestInterruption();
        streamThread->wait();
        delete streamThread;
    }
    delete ui;
}


void mainWindow::on_pushButton_clicked()
{
    this->url = ui->urlLine->text().toStdString();
    if (streamThread) {
        streamThread->requestInterruption();
        streamThread->wait();
        delete streamThread;
    }
    streamThread = new StreamThread(this->url);
    connect(streamThread,&StreamThread::sendFrame,this,&mainWindow::updateFrame);
    connect(streamThread,&StreamThread::error,[](QString err){
        std::string errorMessage = "error : " + err.toStdString();
        qDebug(errorMessage.c_str());
    });
    streamThread->start();

}


void mainWindow::updateFrame(QImage img){
      ui->imgLabel->setPixmap(QPixmap::fromImage(img));

}

