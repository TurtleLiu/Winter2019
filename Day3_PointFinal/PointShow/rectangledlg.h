#ifndef RECTANGLEDLG_H
#define RECTANGLEDLG_H
#include<QWidget>
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

class RectangleDlg : public QWidget
{
    Q_OBJECT
public:
    explicit RectangleDlg(QWidget *parent=0);
    ~RectangleDlg();
public:
    void set(int width,int heigh,int distance,int way);
    void paintEvent(QPaintEvent*);
    QTimer *timer;
private slots:
    void updateOutput();
private:
    //计时器
    //变量
    int m_realw,m_realh;//图形最大宽，高
    int m_width,m_heigh;//图形实际宽，高
    int m_distance;//点阵间距
    int m_startx,m_starty;//起点位置
};

#endif // RECTANGLEDLG_H
