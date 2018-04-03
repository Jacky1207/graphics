#ifndef NETNODE_H
#define NETNODE_H
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsPixmapItem>
#include <QContextMenuEvent>
#include <QCoreApplication>
#include <QGridLayout>
#include <QList>
#include "suspensiondialog.h"

class NetNode : public QObject, public QGraphicsPixmapItem
{
	Q_OBJECT
public:
	NetNode(bool ipKnown, QString ip, QGraphicsScene *scene);
	NetNode( QGraphicsScene *scene);
    	~NetNode();
	void drawPixmap(int count,int level,int seqNum,int layer, int maxlevel, int nodePerLevel);
	void addText(int x, int y);

    void setNodeIndex(const int index){ _index_of_node = index; }
private:
	QGraphicsScene *pScene;
	bool inNet;
        int level;
	SuspensionDialog *suspensionDialog; 

    QPoint _root_location;
    const int _max_line_node = 7;
    int _node_array[7][7];
    int _index_of_node;
protected:
	void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
	void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
	void hoverEnterEvent(QGraphicsSceneHoverEvent *event);

//    void mousePressEvent(QGraphicsSceneMouseEvent *event);
//    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
};
#endif
