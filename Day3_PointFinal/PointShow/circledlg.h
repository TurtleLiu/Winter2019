#ifndef CIRCLEDLG_H
#define CIRCLEDLG_H
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
class CircleDlg : public QWidget
{
    Q_OBJECT
public:
    explicit CircleDlg(QWidget *parent=0);
    ~CircleDlg();
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
#endif // CIRCLEDLG_H
