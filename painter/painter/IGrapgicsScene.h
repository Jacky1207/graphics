#ifndef IGRAPGICSSCENE_H
#define IGRAPGICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>

#include "INodeInformation.h"
#include "INode.h"

class IGraphicsRectItem;

class IGraphicsScene : public QGraphicsScene
{
public:
    IGraphicsScene();
    ~IGraphicsScene();
    void initNode();
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent  *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent  *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent  *event);
//    virtual void wheelEvent(QWheelEvent  *event);
private:
    INodeInformation* getChildrenNode(INodeInformation *root);
    INode* getChildrenNode(INode *root);

    QPointF _start_point;
    QPointF _end_point;
    IGraphicsRectItem *_item;

    INode *_root_node;
//    INodeInformation * _root_node;
};

#endif // IGRAPGICSSCENE_H
