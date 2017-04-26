#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusLabel = new QLabel;
    statusLabel->setText(tr("Now Position:"));
    //statusLabel->setFixedWidth(100);

//    mousePosLabel = new QLabel;
//    mousePosLabel->setText(tr(""));
//    mousePosLabel->setFixedWidth(100);

    statusBar()->addWidget(statusLabel);
    //statusBar()->addPermanentWidget(mousePosLabel);
    //this->setMouseTracking(true);


    cam = NULL;
    timer = new QTimer(this);
    imag = new QImage();
    startX=startY=width=hight=0;

    /*信号和槽*/
    connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));  // 时间到，读取当前摄像头信息
    connect(ui->opencamara_btn, SIGNAL(clicked()), this, SLOT(openCamara()));
    connect(ui->paizhao_btn, SIGNAL(clicked()), this, SLOT(takingPictures()));
    connect(ui->closecamara_btn, SIGNAL(clicked()), this, SLOT(closeCamara()));
    connect(ui->image_label, SIGNAL(position(int,int,int,int)), this, SLOT(showKuang(int, int, int, int )));


}

MainWindow::~MainWindow()
{
    delete ui;
}


/******************************
********* 打开摄像头 ***********
*******************************/
void MainWindow::openCamara()
{
    cam = cvCreateCameraCapture(0);//打开摄像头，从摄像头中获取视频

    timer->start(33);              // 开始计时，超时则发出timeout()信号
}

/*********************************
********* 读取摄像头信息 ***********
**********************************/
void MainWindow::readFarme()
{
    frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧
    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped();
    ui->camara_label->setPixmap(QPixmap::fromImage(image));  // 将图片显示到label上
}

/*************************
********* 拍照 ***********
**************************/
void MainWindow::takingPictures()
{
    frame = cvQueryFrame(cam);// 从摄像头中抓取并返回每一帧

    // 将抓取到的帧，转换为QImage格式。QImage::Format_RGB888不同的摄像头用不同的格式。
    image_capture = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped();

    ui->image_label->setPixmap(QPixmap::fromImage(image_capture));  // 将图片显示到label上
}

/*******************************
***关闭摄像头，释放资源，必须释放***
********************************/
void MainWindow::closeCamara()
{
    timer->stop();         // 停止读取数据。

    cvReleaseCapture(&cam);//释放内存；
}

void MainWindow::showKuang(int startX, int startY, int width, int hight)
{
    QString str="StartX:" + QString::number(startX) + ",   StartY:" + QString::number(startY) + ",   width:" + QString::number(width) + ",   hight:" + QString::number(hight);
    statusLabel->setText(str);
    //ui->statusBar()->showMessage(str);
    //mousePosLabel->setText(str);

}

//void MainWindow::huakuang()
//{
//    *image_kuang=image_capture.scaled(ui->image_label->width(),
//                           ui->image_label->height(),
//                           Qt::IgnoreAspectRatio,Qt::FastTransformation);
//    kuangW=(float)image_capture.width()/image_kuang->width();
//    kuangH=(float)image_capture.height()/image_kuang->height();
//    ui->image_label->setPixmap(QPixmap::fromImage(*image_kuang));

//    _needDraw=true;

//}
//void MainWindow::paintEvent(QPaintEvent *event)
//{
//    if(_needDraw)
//    {
//        ui->image_label->setPixmap(QPixmap::fromImage(*image_kuang));

//    }

//}


//void MainWindow::mousePressEvent(QMouseEvent *e)
//{
//    QString str="(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
//    startX = e->x();
//    startY = e->y();

//    if(e->button() == Qt::LeftButton)
//    {
//        statusBar()->showMessage(tr("LeftMouse:") + str);
//    }
//    else if(e->button() == Qt::RightButton)
//    {
//        statusBar()->showMessage(tr("RightMouse:") + str);
//    }
//    else if(e->button() == Qt::MidButton)
//    {
//        statusBar()->showMessage(tr("MidMouse:") + str);
//    }
//}

//void MainWindow::mouseMoveEvent(QMouseEvent *e)
//{
//    QString str="(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";

//    mousePosLabel->setText(str);
//}

//void MainWindow::mouseReleaseEvent(QMouseEvent *e)
//{
//    QString str="(" + QString::number(e->x()) + "," + QString::number(e->y()) + ")";
//    statusBar()->showMessage(tr("Release at:")+str, 3000);
//    endX=e->x();
//    endY=e->y();
//}

//void MainWindow::mouseDoubleClickEvent(QMouseEvent *e)
//{

//}


