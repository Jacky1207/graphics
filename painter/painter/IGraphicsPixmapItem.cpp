#include "IGraphicsPixmapItem.h"
#include "IGrapgicsScene.h"
#include <QDebug>

IGraphicsPixmapItem::IGraphicsPixmapItem(IGraphicsScene *parent):
    _scene(parent)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

IGraphicsPixmapItem::IGraphicsPixmapItem(const int w, const int h) :
    _width(w), _height(h)
{
    _pixmap_item = QPixmap(w, h);
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

IGraphicsPixmapItem::~IGraphicsPixmapItem()
{

}

void IGraphicsPixmapItem::setPixmapInfo(const int x, const int y)
{
    _offset_x = x;
    _offset_y = y;
}

void IGraphicsPixmapItem::setPixmapInfo(const int x, const int y, const int w, const int h)
{
    _offset_x = x-w/2;
    _offset_y = y-h/2;
    _width = w;
    _height = h;
    _pixmap_item = QPixmap(w, h);
    if(_pixmap_item.load(_pixmap_path) != true)
        qDebug()<<"load fail"<<_pixmap_path;
    setPixmap(_pixmap_item.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    setPos(_offset_x, _offset_y);

    update();
}

void IGraphicsPixmapItem::setPixmapPath(const QString path)
{
    _pixmap_path = path;
}

void IGraphicsPixmapItem::setItemText(const QString str)
{
    _str_text = str;
}

void IGraphicsPixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap = this->pixmap();
    QRect rect = pixmap.rect();

    painter->drawPixmap(rect,pixmap);
    if(!_str_text.isEmpty())
    {
        int y = rect.y() + rect.height() + 10;
        painter->drawText(rect.x(), y, _str_text);
    }
}

void IGraphicsPixmapItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    qDebug()<<"hover enter";
    suspensionDialog = new SuspensionDialog(event->widget());
    int nodeX = pos().x();
    int nodeY = pos().y();
    int sceneW = _scene->width();
    int sceneH = _scene->height();
    int mapW = pixmap().width();
    int mapH = pixmap().height();
    int x = suspensionDialog->width();
    int y = suspensionDialog->height();

    _scene->addWidget(suspensionDialog);

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

void IGraphicsPixmapItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    suspensionDialog->close();
    suspensionDialog = NULL;
}

void IGraphicsPixmapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("mouse press");
}

void IGraphicsPixmapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("mouse release");
}

