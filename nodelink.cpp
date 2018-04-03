 #include <QtGui>
#include "nodelink.h"
#include "netnode.h"

NodeLink::NodeLink(NetNode *fromNode, NetNode *toNode)
{
	myFromNode = fromNode;
    myToNode = toNode;
    //myFromNode->addLink(this);
    //myToNode->addLink(this);

//    setFlags(QGraphicsItem::ItemIsSelectable);
    setZValue(-1);
    setColor(Qt::green);
    trackNodes();
}

NodeLink::NodeLink(NetNode *fromNode, NetNode *toNode, int direc) :
    myFromNode(fromNode), myToNode(toNode)
{
    setZValue(-1);
    setColor(Qt::red);
    trackNodes(direc);
}

NodeLink::~NodeLink()
{
    	//myFromNode->removeLink(this);
    	//myToNode->removeLink(this);
}

void NodeLink::setColor(const QColor &color)
{
    setPen(QPen(color, 1.0));
}

QColor NodeLink::getColor() const
{
    return pen().color();
}

NetNode *NodeLink::getFromNode() const
{
    	return myFromNode;
}

NetNode *NodeLink::getToNode() const
{
    	return myToNode;
}

void NodeLink::trackNodes()
{
	//qDebug()<<myFromNode->pos().x()<<myFromNode->pixmap().width()/2<< myToNode->pos().x()+myToNode->pixmap().width()/2<<myToNode->pos().y()+myToNode->pixmap().height()/2;
    setLine(QLineF(myFromNode->pos().x()+myFromNode->pixmap().width()/2-_line_space,
    myFromNode->pos().y()+myFromNode->pixmap().height()/2,
    myToNode->pos().x()+myToNode->pixmap().width()/2-1-_line_space,
    myToNode->pos().y()+myToNode->pixmap().height()/2));
}

void NodeLink::trackNodes( int direc)
{
    //qDebug()<<myFromNode->pos().x()<<myFromNode->pixmap().width()/2<< myToNode->pos().x()+myToNode->pixmap().width()/2<<myToNode->pos().y()+myToNode->pixmap().height()/2;
    setLine(QLineF(myFromNode->pos().x()+myFromNode->pixmap().width()/2+_line_space,
    myFromNode->pos().y()+myFromNode->pixmap().height()/2,
    myToNode->pos().x()+myToNode->pixmap().width()/2-1+_line_space,
    myToNode->pos().y()+myToNode->pixmap().height()/2));
}
