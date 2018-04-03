#ifndef NODELINK_H
#define NODELINK_H
#include <QGraphicsLineItem>
#include <QColor>
#include "netnode.h"

class NetNode;
class NodeLink : public QGraphicsLineItem
{
public:
    	NodeLink(NetNode *fromNode, NetNode *toNode);
        NodeLink(NetNode *fromNode, NetNode *toNode, int direc);
        ~NodeLink();

    	NetNode *getFromNode() const;
    	NetNode *getToNode() const;
    	void setColor(const QColor &color);
    	QColor getColor() const;
    	void trackNodes();
        void trackNodes( int direc);
private:
    	NetNode *myFromNode;
    	NetNode *myToNode;
        const int _line_space = 3;
};
#endif // NODELINK_H
