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
    setPalette(QPalette(QColor(240,255,255)));
    //各种标签
    //宽度组
    WidthLabel = new QLabel(this);
    WidthLabel->setGeometry(190,30,260,40);//set the position and size(int x,int y,int w,int h)
    WidthLabel->setFont(QFont("Timers" , 14));//字体编辑
    WidthLabel->setText(tr("图形宽度："));
    WidthEdit = new QLineEdit(this);
    WidthEdit->setGeometry(300,30,310,40);//位置、尺寸编辑
    WidthEdit->setFont(QFont("Timers" , 14 ));//字体编辑
    WidthEdit->setPlaceholderText(tr("请输入图形宽度"));
    //高度组
    HeighLabel = new QLabel(this);
    HeighLabel->setGeometry(190,80,260,40);//set the position and size(int x,int y,int w,int h)
    HeighLabel->setFont(QFont("Timers" , 14));//字体编辑
    HeighLabel->setText(tr("图形高度："));
    HeighEdit = new QLineEdit(this);
    HeighEdit->setGeometry(300,80,310,40);//位置、尺寸编辑
    HeighEdit->setFont(QFont("Timers" , 14 ));//字体编辑
    HeighEdit->setPlaceholderText(tr("请输入图形高度"));
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
    //timer = new QTimer(this);
    //画布
    JumpButton=new QPushButton(this);
    JumpButton->setGeometry(0, 0, 150, 40);
    JumpButton->setFont(QFont("Timers" , 14 ));//字体编辑
    JumpButton->setText(tr("切换为矩形"));
    paint_flag=0;//初始为画圆
    RectanglePainter=new RectangleDlg(this);
    RectanglePainter->move(0,250);
    CirclePainter=new CircleDlg(this);
    CirclePainter->move(0,250);
    //信号槽绑定
    connect(Start1Button,&QPushButton::clicked,this,&MainWindow::startDirect);
    connect(Start2Button,&QPushButton::clicked,this,&MainWindow::startStep);
    connect(JumpButton,&QPushButton::clicked,this,&MainWindow::jump);
}

MainWindow::~MainWindow()
{

}
void MainWindow::startDirect(){
    inter(0);
}
void MainWindow::startStep(){
    inter(1);
}
void MainWindow::inter(int way){//界面交互
    QString Width;
    QString Heigh;
    QString Distance;
    int width;
    int heigh;
    int distance;
    int paintwidth=800;
    int paintheigh=550;
    //取得文本内容信息
    Width=WidthEdit->text().trimmed();
    Heigh=HeighEdit->text().trimmed();
    Distance=DistanceEdit->text().trimmed();
    width=Width.toInt();
    heigh=Heigh.toInt();
    if(DistanceEdit->text().isEmpty())
        {distance=5;}
    else
        distance=Distance.toInt();
    //条件判断，是否可以完整显示图形
    if(paintwidth-width*distance<0||paintheigh-heigh*distance<0){
        QMessageBox::warning(this, tr("警告！"),tr("图形太大，超出画布范围！"),QMessageBox::Yes);
        // 清空内容并定位光标
        WidthEdit->clear();
        HeighEdit->clear();
        DistanceEdit->clear();
        WidthEdit->setFocus();
    }
    else if(paint_flag==0){
        CirclePainter->set(width,heigh,distance,way);
        if(way==1)
            CirclePainter->timer->start(500);
    }
    else{
        RectanglePainter->set(width,heigh,distance,way);
        if(way==1)
            RectanglePainter->timer->start(500);
    }
}
void MainWindow::jump(){
    if(paint_flag==0){
        JumpButton->setText(tr("切换为圆形"));
        RectanglePainter->show();
        RectanglePainter->set(0,0,0,0);
        CirclePainter->close();
        paint_flag=1;
    }
    else{
        JumpButton->setText(tr("切换为矩形"));
        CirclePainter->show();
        CirclePainter->set(0,0,0,0);
        RectanglePainter->close();
        paint_flag=0;
    }
}
