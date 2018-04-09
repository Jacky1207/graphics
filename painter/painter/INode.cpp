#include "INode.h"
#include "math.h"
#include <QDebug>
#include <QtMath>

INode::INode(const int index, INode *parent) :
    _node_index(index), _node_parent(parent)
{
    _node_rotate = initNodeRotate(_node_index);
}

INode::~INode()
{
    for(int i=0; i<getChildNodeSize(); i++)
    {
        delete _node_child_list.at(i);
    }
    _node_child_list.clear();
}

void INode::addChildNode(INode *node)
{
    _node_child_list.append(node);
}

float INode::initNodeRotate(const int index)
{
    float degrees;
    int count = 0;

    if(_node_parent == NULL)
        return 0;

    if(index == 0)
        degrees = _node_parent->getNodeRotate();
    else if(index % 2 == 0)
    {
        count = index / 2;
        degrees = _node_parent->getNodeRotate() + getChildNodeRotate(count);
    }
    else
    {
        count = index / 2 + index % 2;
        degrees = _node_parent->getNodeRotate() - getChildNodeRotate(count);
    }
    qDebug("parent : %d - %d", _node_parent->getNodeRotate(), getChildNodeRotate(count));

    return degrees;
}

QPoint INode::getChildNodePoint(const int index)
{
//    float degrees = initNodeRotate(index);
    double x = qCos(qDegreesToRadians(_node_rotate)) * _kdefault_radius + _node_parent->x();
    double y = qSin(qDegreesToRadians(_node_rotate)) * _kdefault_radius + _node_parent->y();
    qDebug()<<index << _node_rotate <<  x << y << _node_x << _node_y;
    return QPoint(x, y);
}

void INode::setChildNodePoint(const QPoint point)
{
    _node_x = point.x();
    _node_y = point.y();
}

void INode::setChildNodePoint(const int x, const int y)
{
    _node_x = x;
    _node_y = y;
}
