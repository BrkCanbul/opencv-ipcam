#include "streamthread.h"
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QDebug>

StreamThread::StreamThread(std::string url,int h ,int w,QObject *parent)
    : QThread(parent),url(url){
    this->height = h;
    this->width = w;

}

StreamThread::~StreamThread(){}
void StreamThread::run(){
    cv::VideoCapture cap;
    cap.set(cv::CAP_PROP_FPS,30);
    qDebug("url: %s",url.c_str());
    cap.open(url);
    if(!cap.isOpened()){
        qDebug("error: cannot open the stream");
        return;
    }
    qDebug("stream is opened");
    cv::Mat frame;

    while(!isInterruptionRequested() && cap.read(frame)){
        if(frame.empty()){
            qDebug("frame is empty");
            return;
        }
        cv::resize(frame,frame,cv::Size(width,height));
        cv::cvtColor(frame,frame,cv::COLOR_BGR2RGB);
        cv::putText(frame,"IPCAM VİEW",cv::Point(0,10),cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(0,255,0),1,cv::LINE_AA);
    
        QImage img(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
        emit sendFrame(img);
        
    }
}
