#include <QtGui>
#include <QtCore/QProcess>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkAddressEntry>
#include <iostream>
#include <QScrollBar>
#include <QMessageBox>
#include "nodelink.h"
#include "nodeframe.h"

NodeFrame::NodeFrame(QWidget *parent):QGraphicsView(parent),
        _node_size(0)
{
	
    setGeometry(0,0,NodeFrame::_kwidth,NodeFrame::_kheight);
    scene = new QGraphicsScene(0, 0, this->width(), this->height());
	setScene(scene);

    centerOn(this->width()/2, this->height()/2);    //set view center.
	
	QScrollBar *horBar = this->horizontalScrollBar();
    QScrollBar *verBar = this->verticalScrollBar();
    horBar->setValue(horBar->maximum());
    verBar->setValue(verBar->maximum());

	this->pHead = NULL;
	this->initList();
 	
    initNode = new NetNode(false, "", scene);
    initNode->setNodeIndex(_node_size);

    if(!initNode)
        QMessageBox::critical(this, "Ip error", "Can't init node info");
    if(!setupTopo(initNode))
        QMessageBox::critical(this, "Topo init", "Init topo graph error");
}

NodeFrame::~NodeFrame()
{
    delete scene;
	while(this->pHead != NULL)
	{
		PNODE pTemp = pHead->pNext;
		delete pHead;
		pHead = pTemp;
	}
}

void NodeFrame::addListItem(int key, int value, int nops)
{
    if(pHead == NULL)
    {
        pHead = new NODE;
        pHead->key = key;
        pHead->value = value;
        pHead->hops = nops;
        pHead->pNext = NULL;
        return ;
    }

    PNODE pNew, pTmp=pHead;
    while(pTmp->pNext != NULL)
        pTmp = pTmp->pNext;
    pNew = new NODE;
    pNew->key = key;
    pNew->value = value;
    pNew->hops = nops;
    pNew->pNext = NULL;
    pTmp->pNext = pNew;
}

void NodeFrame::initList()
{
    addListItem(0,0,0);
    addListItem(1,0,1);
    addListItem(2,0,1);
    addListItem(3,0,1);
    addListItem(4,0,1);
    addListItem(5,0,1);
    addListItem(6,0,1);
    addListItem(7,0,1);
    addListItem(8,2,2);
    addListItem(9,2,2);
    addListItem(10,8,3);
    addListItem(11,7,2);
    addListItem(12,10,4);
    addListItem(13,11,3);
    PNODE p = pHead;
    while(p->pNext!= NULL)
    {
        qDebug()<<p->key<<p->value;
        p++;
    }

    return;
}

void NodeFrame::refresh()
{
    destroyed(scene);
    setGeometry(0,0,870,520);

    seqPerLvl.clear();
    scene = new QGraphicsScene(0, 0, this->width(), this->height());
    this->setScene(scene);
//	scene->setSceneRect(25,100,870,520);

    initNode = new NetNode(false, "", scene);
    if(!initNode)
    QMessageBox::critical(this, "Ip error", "Can't init node info");
    if(!setupTopo(initNode))
         QMessageBox::critical(this, "Topo init", "Init topo graph error");
}

void NodeFrame::freshFrame()
{
    refresh();
}

bool NodeFrame::setupTopo(NetNode *initNode)
{
	seqPerLvl.clear();
	
	if(!initNode)
    {
		qDebug() << "NodeFrame::setupTopo" << "initNode is NULL";
                        return false;
    }
    for(int i =0;i<5;i++)
	{
        seqPerLvl.append(i);
//		seqPerLvl[i]=0;
	}
	PNODE pTemp = this->pHead;
	for(;pTemp !=NULL;pTemp=pTemp->pNext)
	{
		int hops = pTemp->hops;
		int key = pTemp->key;
		int value = pTemp->value;
		int n =0;
		PNODE ptem = this->pHead;
		for(;ptem != NULL;ptem=ptem->pNext)
        {
            if(key == ptem->value)
            {
                n++;
            }
        }

		if(key == 0)
		{	
			initNode->drawPixmap(0,0,0,0,INITMAXLEVEL, NODEPERLEVEL);
			node<<initNode;
		}
		else
		{
			seqPerLvl[hops]++;
			if(seqPerLvl[hops] >10 || hops > 5)
			{
	//			seqPerLvl.append(0);
          //      		seqPerLvl[hops]=0;
	//			scene->setSceneRect(0,0,870+40*(seqPerLvl[hops] - 10),520+80*(hops - 10));
			}

			NetNode *subNetNode = NULL;
            subNetNode = new NetNode(true, "", scene);
            subNetNode->setNodeIndex(++_node_size);
            subNetNode->drawPixmap(n,key,hops,seqPerLvl[hops], INITMAXLEVEL, NODEPERLEVEL);
            node<<subNetNode;
			NodeLink *link = new NodeLink(node.at(value), node.at(key));
            if(link)
            {
                scene->addItem(link);
            }
            link = new NodeLink(node.at(key), node.at(value), 1);
            scene->addItem(link);
        }
	}
    	return true;
}
	
