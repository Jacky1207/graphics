#ifndef IGRAPHICSPIXMAPITEM_H
#define IGRAPHICSPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QPainter>

class IGraphicsPixmapItem : public QGraphicsPixmapItem
{
public:
    IGraphicsPixmapItem();
    IGraphicsPixmapItem(const int w, const int h);
    ~IGraphicsPixmapItem();

    void setPixmapInfo(const int x, const int y);
    void setPixmapInfo(const int x, const int y, const int w, const int h);
    void setPixmapPath(const QString path);
    void setRotate(const float degree) { _degree = degree;}
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    void rotate() const;
    QPixmap _pixmap_item;
    QString _pixmap_path;
    int _width;
    int _height;
    int _offset_x;
    int _offset_y;
    int _degree = 0;
};

#endif // IGRAPHICSPIXMAPITEM_H
