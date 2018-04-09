#include "IGraphicsLineItem.h"
#include "INodeInformation.h"
#include "INode.h"

#include <QPainter>

IGraphicsLineItem::IGraphicsLineItem()
{
    setZValue(-1);
//    setColor(Qt::green);
}

IGraphicsLineItem::~IGraphicsLineItem()
{

}

void IGraphicsLineItem::connectNode(INodeInformation *src, INodeInformation *dst)
{
    int sx = src->x();
    int sy = src->y();
    int dx = dst->x();
    int dy = dst->y();

    setLine(QLineF(sx, sy, dx, dy));
    update();
}

void IGraphicsLineItem::connectNode(INode *src, INode *dst)
{
    int sx = src->x();
    int sy = src->y();
    int dx = dst->x();
    int dy = dst->y();

    setLine(QLineF(sx, sy, dx, dy));
    update();
}

void IGraphicsLineItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QLineF line = this->line();
    painter->drawLine(line);
}
