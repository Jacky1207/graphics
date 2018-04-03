#ifndef NODE_H
#define NODE_H

#include <QGraphicsView>
#include "netnode.h"
using namespace std;
//#include "nodelink.h"

#define NODEPERLEVEL 10
#define INITMAXLEVEL 10

QT_BEGIN_NAMESPACE
class NodeFrame;
QT_END_NAMESPACE

class NodeFrame: public QGraphicsView
{
	Q_OBJECT
public:
	NodeFrame(QWidget *parent=0);
	~NodeFrame();

	QVector<int> seqPerLvl;
	QVector<int> lineMaxNum;
	int level;	
	bool setupTopo(NetNode *initNode);
	void refresh();
	void initList();
	NetNode *initNode;
	QList<QString> list;
	typedef struct NodeList
	{
        int key;
        int value;
        int hops;
		struct NodeList *pNext;
	}NODE,*PNODE;
    void addListItem(int key, int value, int nops);
    //QMap<int,int> map;
	QList<NetNode*> node;
	//QScrollBar *horBar;
    //QScrollBar *verBar;

    static int getSceneWidth(){return _kwidth;}
    static int getSceneHeight(){return _kheight;}
protected slots:
	void freshFrame();
	
private:
	QGraphicsScene *scene;
	PNODE pHead;
    const static int _kwidth = 5000;
    const static int _kheight = 5000;
    int _node_size;
};
#endif
