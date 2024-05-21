#include "streamthread.h"
#include "mainwindow.h"
#include <opencv2/opencv.hpp>
#include <QImage>
#include <QDebug>

StreamThread::StreamThread(std::string url,QObject *parent)
    : QThread(parent),url(url){}

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
        
        cv::resize(frame,frame,cv::Size(1000,600));
        cv::cvtColor(frame,frame,cv::COLOR_BGR2RGB);
        cv::putText(frame,"FPS: "+std::to_string(cap.get(cv::CAP_PROP_FPS)),cv::Point(10,100),cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(255,0,0),2);
        cv::putText(frame,"IP CAM ADDRESS : "+url,cv::Point(10,50),cv::FONT_HERSHEY_SIMPLEX,1,cv::Scalar(255,0,0),2);


        QImage img(frame.data,frame.cols,frame.rows,frame.step,QImage::Format_RGB888);
        emit sendFrame(img);
        
    }
}