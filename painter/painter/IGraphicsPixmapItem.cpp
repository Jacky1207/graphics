#include "IGraphicsPixmapItem.h"
#include <QDebug>

IGraphicsPixmapItem::IGraphicsPixmapItem()
{
    setFlag(QGraphicsItem::ItemIsSelectable, true);
}

IGraphicsPixmapItem::IGraphicsPixmapItem(const int w, const int h) :
    _width(w), _height(h)
{
    _pixmap_item = QPixmap(w, h);
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

void IGraphicsPixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap = this->pixmap();
    QRect rect = pixmap.rect();

    painter->drawPixmap(rect,pixmap);
}

