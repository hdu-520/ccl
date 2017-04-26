#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QPainter>
#include <QMouseEvent>
#include <QPaintEvent>

/*
 *自定义的label类,主要实现在labeli显示整张图片然后画目标框,
 * 使用***改进法(promotion)***将自定义的label功能装入ui的label里面,还有一种方法也可以实现类似功能，叫插件法(plugin), 前者比较简单
 *
 *
 */

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    //MyLabel();
    explicit MyLabel(QWidget *parent = 0);

signals:
    void clicked();
    void position(int, int, int, int);

public slots:

public:
    QPoint p1;
    QPoint p2;

    static int ROI_X;
    static int ROI_Y;
    static int ROI_Width;
    static int ROI_Height;

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void paintEvent(QPaintEvent *);


};

#endif // MYLABEL_H
