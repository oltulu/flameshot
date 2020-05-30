#include "save_location.h"
#include <QHBoxLayout>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <QDebug>
#include <QFileDialog>
#define SHADOW_WIDTH  15     //小三角的阴影宽度
#define TRIANGLE_WIDTH 15    //小三角的宽度
#define TRIANGLE_HEIGHT 15    //小三角的高度
#define BORDER_RADIUS 10       //窗口边角弧度

Save_Location::Save_Location(QWidget *parent)
    : QWidget(parent)
    , m_startx(5)
    , m_triangleWidth(TRIANGLE_WIDTH)
    , m_triangleHeight(TRIANGLE_HEIGHT)
{
    this->setMouseTracking(true);
    setCursor(Qt::ArrowCursor);
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    //设置阴影边框
    auto shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setOffset(0,0);
    shadowEffect->setColor(Qt::gray);
    shadowEffect->setBlurRadius(BORDER_RADIUS);
    this->setGraphicsEffect(shadowEffect);
    setFixedSize(100,100);
}
void Save_Location::setStartPos(int startX)
{
      m_startx = startX;
}
void Save_Location::setCenterWidget(QWidget *widget)
{
    vLayout = new QVBoxLayout(this);
    hMainLayout = new  QHBoxLayout();
    //hMainLayout->addWidget(widget);
    savedir = new QLabel("存储位置");
    SaveDir = new  QPushButton();

    SaveDir->setText("/home");
    savetype = new QLabel("存储格式");

    jpg = new QRadioButton("jpg");
    png = new QRadioButton("png");
    bmp = new QRadioButton("bmp");

    hMainLayout->addWidget(jpg);
    hMainLayout->addWidget(png);
    hMainLayout->addWidget(bmp);

    vLayout->addWidget(savedir);
    vLayout->addWidget(SaveDir);
    vLayout->addWidget(savetype);
    vLayout->addLayout(hMainLayout);
    vLayout->setSpacing(0);
    vLayout->setContentsMargins(SHADOW_WIDTH,SHADOW_WIDTH + TRIANGLE_WIDTH, SHADOW_WIDTH , SHADOW_WIDTH);
}
void Save_Location::setTriangleInfo(int width, int height)
{
    m_triangleWidth = width;
    m_triangleHeight = height;
}

void Save_Location::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255,255,255));
    //
    QPolygon trianglePolygon;
    trianglePolygon << QPoint(m_startx, m_triangleWidth + SHADOW_WIDTH);
    trianglePolygon << QPoint(m_startx+m_triangleWidth/2,SHADOW_WIDTH);
    trianglePolygon << QPoint(m_startx + m_triangleWidth,m_triangleHeight + SHADOW_WIDTH);

    QPainterPath drawPath;
    drawPath.addRoundRect(QRect(SHADOW_WIDTH , m_triangleHeight + SHADOW_WIDTH ,
                                width()-SHADOW_WIDTH *2 ,height() -SHADOW_WIDTH *2 -m_triangleHeight),
                         BORDER_RADIUS,BORDER_RADIUS);
    drawPath.addPolygon(trianglePolygon);
    painter.drawPath(drawPath);
    painter.drawText(20,50,"111111111");
}

