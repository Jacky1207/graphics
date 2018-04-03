#include "netnode.h"
#include "nodeframe.h"
#include <QtGui>
#include <QMenu>

NetNode::NetNode(bool , QString , QGraphicsScene *scene)
{
    inNet = false;
    level = -1;
	setFlag(QGraphicsItem::ItemIsSelectable, true);
    pScene = scene;
	setAcceptHoverEvents(true);
    _root_location = QPoint(NodeFrame::getSceneWidth()/2-15,NodeFrame::getSceneWidth()/2-21);
}

NetNode::NetNode(QGraphicsScene *scene)
{
	inNet = true;
	level = -1;
	pScene = scene;
}

NetNode::~NetNode()
{
}

void NetNode::drawPixmap(int count,int key,int hops, int items,int /*maxlevel*/, int nodePerLevel)
{
    QPixmap pix;
	int width = 0;
	int height = 0;

    if(key == 0)
	{
        pix.load(QLatin1String(":/router.png"));
		setPixmap(pix.scaled(46,42, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		width = 46;
		height = 42;
	}
	else
	{
        pix.load(QLatin1String(":/host.png"));
		setPixmap(pix.scaled(29,42, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
		width = 29;
		height = 42;
	}

    if( key == 0)
   	{
		qDebug()<<"here: key"<<key;
		//setPos(QPoint((pScene->width())/2, 20));
//         setPos(870/2, 20);
        setPos(_root_location);
        qDebug()<<"root ";
    }
    else
    {
        qreal x = _root_location.x()  + 40 + 800 / nodePerLevel * (items-1) - _max_line_node*60;
        qreal y = 90 * hops + _root_location.y();
        setPos(x, y);
        x = x + width - 8;
        y = y + height - 8;
        addText(x,y);
    }
    pScene->addItem(this);
}

void NetNode::addText(int x,int y)
{
    QGraphicsTextItem* i = pScene->addText(QString::number(x)+"-"+QString::number(y));
//    i->setFlag(QGraphicsItem::ItemIsMovable);
//    i->setPos(qrand()%int(canvas.width()),qrand()%int(canvas.height()));
    i->setPos(x-20,y+5);
}

void NetNode::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
	scene()->clearSelection();
	setSelected(true);
	QMenu menu;
	menu.setWindowOpacity(0.8);
	QAction *removeAction = menu.addAction(tr("select"));
	QAction *actAction = menu.addAction(tr("clear"));
	menu.exec(event->screenPos());
}

void NetNode::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
	suspensionDialog = new SuspensionDialog(this,event->widget());
	int nodeX = pos().x();
    int nodeY = pos().y();
    int sceneW = pScene->width();
    int sceneH = pScene->height();
    int mapW = pixmap().width();
    int mapH = pixmap().height();
    int x = suspensionDialog->width();
    int y = suspensionDialog->height();

    pScene->addWidget(suspensionDialog);

    if(nodeX + mapW + x + 5 <= sceneW && nodeY + mapH + y + 5 <= sceneH)
            suspensionDialog->move(nodeX + mapW + 5,  nodeY + mapH + 5);
    else if(nodeX + mapW + x + 5 >= sceneW && nodeY + mapH + y + 5 <= sceneH)
            suspensionDialog->move(sceneW - mapW - x - 5, nodeY + mapH + 5);
    else if(nodeX + mapW + x + 5 <= sceneW && nodeY + mapH + y + 5 >= sceneH)
            suspensionDialog->move(nodeX + mapW + 5, sceneH - y);
    else
    suspensionDialog->move(nodeX - x - 5, nodeY - y - 5);
    suspensionDialog->show();
}

void NetNode::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
	suspensionDialog->close();
}
