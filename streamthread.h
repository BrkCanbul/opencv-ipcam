#ifndef STREAMTHREAD_H

#define STREAMTHREAD_H

#include <QThread>
#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>

class StreamThread : public QThread
{
    Q_OBJECT
public:
    StreamThread(std::string url,int h,int w,QObject *parent = nullptr);
    ~StreamThread();
    
protected:
    void run() override;

signals:
    void sendFrame(QImage img);
    void error(QString err);
    
private:
    std::string url;
    int height;
    int width;


};

#endif // STREAMTHREAD_H
