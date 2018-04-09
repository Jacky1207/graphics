#include "IGraphicsRectItem.h"
#include <QPainter>
#include <QDebug>

IGraphicsRectItem::IGraphicsRectItem(QRect rect) :
    QGraphicsRectItem(rect)
{
    _start = QPoint(rect.x(),rect.y());
//    setBrush(getColor());
    setBrush(QColor(247, 160, 57));
}

IGraphicsRectItem::IGraphicsRectItem(const int sx, const int sy, const int w, const int h) :
    QGraphicsRectItem(sx, sy, w, h)
{
    _start = QPoint(sx, sy);
//    setBrush(getColor());
    setBrush(QColor(247, 160, 57));
}

void IGraphicsRectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    this->setFocus();
    qDebug()<<"dragEnter";
}

void IGraphicsRectItem::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"dragMove";

}

void IGraphicsRectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug()<<"dragLeave";

}

void IGraphicsRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawRect(this->rect());
}

QColor IGraphicsRectItem::getColor()
{
    int red = qrand()%256;
    int green = qrand()%256;
    int blue = qrand()%256;

    return QColor(red, green, blue, _transparence);
}

void IGraphicsRectItem::resizeRect(const int width, const int height, int direc)
{
    _end = QPoint(_start.x()+width, _start.y()+height);
    qDebug()<<_end<<width<<height;
    this->setRect(_start.x(), _start.y(), width, height);
    update();
}

