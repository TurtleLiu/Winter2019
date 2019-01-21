#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTimer>
#include <QMessageBox>
#include <QMainWindow>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QtCore/qmath.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
public:
    void paintEvent(QPaintEvent*);
private slots:
    void start1();
    void start2();
    void updateoutput();
private:
    //宽度组
    QLabel *WidthLabel;
    QLineEdit *WidthEdit;
    int width=0;
    int realw=0;
    int startx=0;//x轴起点
    //高度组
    QLabel *HeighLabel;
    QLineEdit *HeighEdit;
    int heigh=0;
    int realh=0;
    int starty=0;//y轴起点
    //间隔组
    QLabel *DistanceLabel;
    QLineEdit *DistanceEdit;
    int distance=5;
    //按钮组
    QPushButton *Start1Button;
    QPushButton *Start2Button;
    //计时器
    QTimer *timer;

};

#endif // MAINWINDOW_H

