#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
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
#include<circledlg.h>
#include<rectangledlg.h>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void startDirect();
    void startStep();
    void jump();
    void inter(int way);//界面交互函数
private:
    //宽度组，变量声明不要初始化，类内部可以以m_开头
    QLabel *WidthLabel;
    QLineEdit *WidthEdit;
    //高度组
    QLabel *HeighLabel;
    QLineEdit *HeighEdit;
    //间隔组
    QLabel *DistanceLabel;
    QLineEdit *DistanceEdit;
    //按钮组
    QPushButton *Start1Button;
    QPushButton *Start2Button;
    //跳转组
    QPushButton *JumpButton;
    //画布组
    CircleDlg *CirclePainter;
    RectangleDlg *RectanglePainter;
    int paint_flag;
};

#endif // MAINWINDOW_H
