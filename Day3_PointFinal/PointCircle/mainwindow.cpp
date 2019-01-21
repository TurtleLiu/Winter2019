#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //窗体设置
    setWindowTitle("点阵模拟实践");
    //固定大小
    this->resize(QSize(800,800));
    setMinimumSize(800,800);
    setMaximumSize(800,800);
    //背景色设置
    setAutoFillBackground(true);
    setPalette(QPalette(QColor(250,255,240)));

    //各种标签
    //宽度组
    WidthLabel = new QLabel(this);
    WidthLabel->setGeometry(190,30,260,40);//set the position and size(int x,int y,int w,int h)
    WidthLabel->setFont(QFont("Timers" , 14));//字体编辑
    WidthLabel->setText(tr("圆形半径："));
    WidthEdit = new QLineEdit(this);
    WidthEdit->setGeometry(300,30,310,40);//位置、尺寸编辑
    WidthEdit->setFont(QFont("Timers" , 14 ));//字体编辑
    WidthEdit->setPlaceholderText(tr("请输入圆形半径"));

    //间隔组
    DistanceLabel = new QLabel(this);
    DistanceLabel->setGeometry(190,130,260,40);//set the position and size(int x,int y,int w,int h)
    DistanceLabel->setFont(QFont("Timers" , 14));//字体编辑
    DistanceLabel->setText(tr("点阵间隔："));
    DistanceEdit = new QLineEdit(this);
    DistanceEdit->setGeometry(300,130,310,40);//位置、尺寸编辑
    DistanceEdit->setFont(QFont("Timers" , 14 ));//字体编辑
    DistanceEdit->setPlaceholderText(tr("请输入点阵间隔"));
    //按钮组
    Start1Button = new QPushButton(this);
    Start1Button->setGeometry(220, 180, 150, 40);
    Start1Button->setFont(QFont("Timers" , 14 ));//字体编辑
    Start1Button->setText(tr("直接输出点阵"));
    Start2Button = new QPushButton(this);
    Start2Button->setGeometry(430, 180, 150, 40);
    Start2Button->setFont(QFont("Timers" , 14 ));//字体编辑
    Start2Button->setText(tr("逐步输出点阵"));
    //计时器
    timer = new QTimer(this);
    //信号槽绑定
    connect(Start1Button,&QPushButton::clicked,this,&MainWindow::start1);
    connect(Start2Button,&QPushButton::clicked,this,&MainWindow::start2);
    connect(timer,SIGNAL(timeout()),this,SLOT(updateoutput()));

}

MainWindow::~MainWindow()
{
}
void MainWindow::start1(){
QString Width;
QString Distence;
//初始化
width=0;
heigh=0;
realh=0;
realw=0;
Width=WidthEdit->text().trimmed();
Distence=DistanceEdit->text().trimmed();
width=Width.toInt();
heigh=width;
realw=width;
if(DistanceEdit->text().isEmpty())
{distance=5;}
else distance=Distence.toInt();
//条件判断
startx=(800-width*distance)/2;
starty=250+(550-width*distance)/2;
if(startx<0||starty<250){
    QMessageBox::warning(this, tr("警告！"),
                                tr("图形太大，超出画布范围！"),
                                QMessageBox::Yes);
           // 清空内容并定位光标
           WidthEdit->clear();
           HeighEdit->clear();
           DistanceEdit->clear();
           WidthEdit->setFocus();
}
else
update();
}
void MainWindow::start2(){
    QString Width;
    QString Heigh;
    QString Distence;
    //初始化
    width=0;
    heigh=0;
    realh=0;
    realw=0;
    Width=WidthEdit->text().trimmed();
    Distence=DistanceEdit->text().trimmed();
    realw=Width.toInt();
    realh=realw;
    if(DistanceEdit->text().isEmpty())
    {distance=5;}
    else distance=Distence.toInt();
    startx=(800-realw*distance)/2;
    starty=250+(550-realw*distance)/2;
    if(startx<0||starty<250){
        QMessageBox::warning(this, tr("警告！"),
                                    tr("图形太大，超出画布范围！"),
                                    QMessageBox::Yes);
               // 清空内容并定位光标
               WidthEdit->clear();
               HeighEdit->clear();
               DistanceEdit->clear();
               WidthEdit->setFocus();
    }
    else
    timer->start(500);
}
void MainWindow::updateoutput(){
    width=realw;
    if(heigh<realh) heigh++;
    else timer->stop();
    update();
}
void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPen pen; //画笔
    pen.setColor(QColor(255, 0, 0));
    pen.setWidth(4);
    painter.setPen(pen); //添加画笔
    //QBrush brush(QColor(0, 255, 0, 125)); //画刷
    //painter.setBrush(brush); //添加画刷
    //painter.drawLine(QPointF(0, 0), QPointF(100, 100));//绘制矩形
    QPointF pointff[100][100];
    for(int i=0;i<100;i++)
    for (int j=0; j<100; j++)
    {
       pointff[i][j].setX(startx+i*distance);
       pointff[i][j].setY(starty+j*distance);
    }
    for(int i=0;i<width;i++)
    for (int j=0; j<heigh; j++)
    {
        if(qPow(pointff[i][j].x()-399,2)+qPow(pointff[i][j].y()-524,2)<=qPow(realw*distance/2,2))
        painter.drawPoint(pointff[i][j].x(),pointff[i][j].y());
    }
    return ;
}
