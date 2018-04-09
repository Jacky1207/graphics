#include "IGrapgicsScene.h"
#include "IGraphicsRectItem.h"
#include "IGraphicsPixmapItem.h"
#include "IGraphicsLineItem.h"
#include <QDebug>
#include <QWheelEvent>

IGraphicsScene::IGraphicsScene()
{
//    initNode();
//    setSceneRect(0,0, 800,800);
}

IGraphicsScene::~IGraphicsScene()
{

}

void IGraphicsScene::initNode()
{
    _root_node = new INode(0);
    _root_node->setChildNodePoint(this->width()/2, this->height()/2);

    for(int i=0;i<12;i++)
    {
        INode *node = new INode(i, _root_node);
        node->setChildNodePoint(node->getChildNodePoint(i));
#if 1
        if(i == 5){
            for(int j=0;j<2;j++)
            {
                INode *nodeChild = new INode(j, node);
                nodeChild->setChildNodePoint(nodeChild->getChildNodePoint(j));
                for(int n=0;n<2;n++)
                {
                    INode *nodeChild2 = new INode(n, nodeChild);
                    nodeChild2->setChildNodePoint(nodeChild2->getChildNodePoint(n));
#if 1
                    for(int m=0;m<2;m++)
                    {
                        INode *nodeChild3 = new INode(m, nodeChild2);
                        nodeChild3->setChildNodePoint(nodeChild3->getChildNodePoint(m));
                        nodeChild2->addChildNode(nodeChild3);
                    }
#endif
                    nodeChild->addChildNode(nodeChild2);
                }
                node->addChildNode(nodeChild);
            }
        }
#endif
        _root_node->addChildNode(node);
    }
/*
    _root_node = new INodeInformation("root");
    _root_node->setNodePoint(this->width()/2, this->height()/2);
    for(int i=0; i<12; i++)
    {
        INodeInformation *node = new INodeInformation("child", _root_node);
        node->setChildIndex(i);
        node->setNodePoint(_root_node->getChildPoint(i));
#if 1
        if(i == 5){
            for(int j=0;j<2;j++)
            {
                INodeInformation *nodeChild = new INodeInformation("child", node);
                nodeChild->setChildIndex(j);
                nodeChild->setNodePoint(node->getChildPoint(j));
                for(int n=0;n<2;n++)
                {
                    INodeInformation *nodeChild2 = new INodeInformation("child", nodeChild);
                    nodeChild2->setChildIndex(n);
                    nodeChild2->setNodePoint(nodeChild->getChildPoint(n));
#if 0
                    for(int m=0;m<2;m++)
                    {
                        INodeInformation *nodeChild3 = new INodeInformation("child", nodeChild2);
                        nodeChild3->setNodePoint(nodeChild2->getChildPoint(m));
                        nodeChild2->addChild(nodeChild3);
                    }
#endif
                    nodeChild->addChild(nodeChild2);
                }
                node->addChild(nodeChild);
            }
        }
#endif
        _root_node->addChild(node);
    }

*/    getChildrenNode(_root_node);

}

INodeInformation* IGraphicsScene::getChildrenNode(INodeInformation *root)
{
    IGraphicsPixmapItem *pixmapItem = new IGraphicsPixmapItem();
    if(root->getParentNode() == NULL)
    {
        pixmapItem->setPixmapPath(":/host.png");
        pixmapItem->setPixmapInfo(root->x(), root->y(), 29, 42);
    }
    else
    {
        pixmapItem->setPixmapPath(":/router.png");
        pixmapItem->setPixmapInfo(root->x(), root->y(), 46, 42);

        IGraphicsLineItem *line = new IGraphicsLineItem();
        line->connectNode(root, root->getParentNode());
        this->addItem(line);
    }
    this->addItem(pixmapItem);

    int size = root->getChildNodeSize();
    if(size < 0)
        return NULL;
    for(int i=0; i<size; i++)
    {
        INodeInformation *p = root->getChildNode(i);
        if(getChildrenNode(p) == NULL)
        {

        }
    }
}

INode* IGraphicsScene::getChildrenNode(INode *root)
{
    IGraphicsPixmapItem *pixmapItem = new IGraphicsPixmapItem();
    if(root->getParentNode() == NULL)
    {
        pixmapItem->setPixmapPath(":/host.png");
        pixmapItem->setPixmapInfo(root->x(), root->y(), 29, 42);
    }
    else
    {
        pixmapItem->setPixmapPath(":/router.png");
        pixmapItem->setPixmapInfo(root->x(), root->y(), 46, 42);

        IGraphicsLineItem *line = new IGraphicsLineItem();
        line->connectNode(root, root->getParentNode());
        this->addItem(line);
    }
    this->addItem(pixmapItem);

    int size = root->getChildNodeSize();
    if(size < 0)
        return NULL;
    for(int i=0; i<size; i++)
    {
        INode *p = root->getChildNodeOfIndex(i);
        if(getChildrenNode(p) == NULL)
        {

        }
    }
}

void IGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    _start_point = event->scenePos();
//    qDebug()<<"scene press"<<_start_point;
//    _item = new IGraphicsRectItem(_start_point.x(), _start_point.y(), 0, 0);
}

void IGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//    if(_item != NULL)
//    {
//        int w = event->scenePos().x() - _start_point.x();
//        int h = event->scenePos().y() - _start_point.y();
//        qDebug()<<event->scenePos()<<h<<w<<event->screenPos();
//        _item->resizeRect(w, h,1);
//    }
}

void IGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
//    if(_item != NULL)
//    {
//        this->addItem(_item);
//    }
}

