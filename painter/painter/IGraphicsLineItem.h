#ifndef IGRAPHICSLINEITEM_H
#define IGRAPHICSLINEITEM_H

#include <QGraphicsLineItem>

class INodeInformation;
class INode;

class IGraphicsLineItem : public QGraphicsLineItem
{
public:
    IGraphicsLineItem();
    ~IGraphicsLineItem();

    void connectNode(INodeInformation *src, INodeInformation *dst);
    void connectNode(INode *src, INode *dst);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // IGRAPHICSLINEITEM_H
