#include "circledlg.h"

CircleDlg::CircleDlg(QWidget *parent):
    QWidget (parent)
{
    //初始化
    m_realh=0;
    m_realw=0;
    m_width=0;
    m_heigh=0;
    this->resize(QSize(800,550));
    setMinimumSize(800,550);
    setMaximumSize(800,550);
    //背景色设置
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(250,255,240)));
    //计时器设置
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateOutput()));
}
CircleDlg::~CircleDlg()
{

}
void CircleDlg::set(int width,int heigh,int distance,int way){
    m_realh=heigh;
    m_realw=width;
    m_width=width;
    if(way==1)//逐步输出
        m_heigh=0;
    else
        m_heigh=heigh;
    m_distance=distance;
    m_startx=(800-m_realw*m_distance)/2;
    m_starty=(550-m_realh*m_distance)/2;
    update();
}

void CircleDlg::paintEvent(QPaintEvent*){
    int pointx = 399;//圆心坐标
    int pointy = 274;
    QPainter painter(this);
    QPen pen; //画笔
    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(4);
    painter.setPen(pen); //添加画笔
    //QBrush brush(QColor(0, 255, 0, 125)); //画刷
    //painter.setBrush(brush); //添加画刷
    //painter.drawLine(QPointF(0, 0), QPointF(100, 100));//绘制矩形
    QPointF pointff[100][100];
    //计算每个点的坐标
    for(int i=0;i<100;i++)
    for (int j=0; j<100; j++)
    {
       pointff[i][j].setX(m_startx+i*m_distance);
       pointff[i][j].setY(m_starty+j*m_distance);
    }
    //按坐标画点
    for(int i=0;i<m_width;i++)
    for (int j=0; j<m_heigh; j++)
    {
        if(qPow(pointff[i][j].x()-pointx,2)+qPow(pointff[i][j].y()-pointy,2)<=qPow(m_realw*m_distance/2,2))
            painter.drawPoint(pointff[i][j].x(),pointff[i][j].y());
    }
    return;
}

void CircleDlg::updateOutput(){
    m_width=m_realw;
    m_heigh++;
    if(m_heigh>m_realh){
        timer->stop();
    }
    update();
}
