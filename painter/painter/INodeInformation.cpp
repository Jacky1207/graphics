#include "INodeInformation.h"

#include "math.h"
#include <QDebug>
#include <QtMath>

INodeInformation::INodeInformation(INodeInformation *parent):
    _parent(parent)
{
    _index = 0;
}

INodeInformation::INodeInformation(const QString str, INodeInformation *parent):
    _parent(parent), _node_text(str)
{
    _index = 0;
}

INodeInformation::~INodeInformation()
{
    for(int i=0;i<_child.size();i++)
    {
        delete _child.at(i);
    }
    _child.clear();
}

void INodeInformation::addChild(INodeInformation *child)
{
    child->setChildIndex(_child.size());
    _child.append(child);
}

INodeInformation* INodeInformation::getChildNode(const int index) const
{
    return _child.at(index);
}

void INodeInformation::setNodePoint(const int x, const int y)
{
    _node_x = x;
    _node_y = y;
}

void INodeInformation::setNodePoint(const QPoint point)
{
    _node_x = point.x();
    _node_y = point.y();
}

QPoint INodeInformation::getChildPoint(const int index)
{
    _index = index;
    float degrees;
    int count = 0;
//    INodeInformation *p = getParentNode();
    if(_parent != NULL)
    {
        if(index == 0)
            degrees = _parent->getNodeRotate();
        else if(index % 2 == 0)
        {
            count = index / 2;
            degrees = _parent->getNodeRotate() + getChildNodeRotate(count);
        }
        else
        {
            count = index / 2 + index % 2;
            degrees = _parent->getNodeRotate() - getChildNodeRotate(count);
        }
        qDebug("parent : %d - %d", _parent->getNodeRotate(), getChildNodeRotate(count));
    }
    else
    {
        degrees = getChildNodeRotate(index);
    }

    double x = qCos(qDegreesToRadians(degrees)) * _kdefault_radius + _node_x;
    double y = qSin(qDegreesToRadians(degrees)) * _kdefault_radius + _node_y;
    qDebug()<<_index << degrees <<  x << y << _node_x << _node_y;
    return QPoint(x, y);
}

