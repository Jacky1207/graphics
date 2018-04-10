#ifndef IGRAPHICSPIXMAPITEM_H
#define IGRAPHICSPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QPainter>

#include "SuspensionDialog.h"

class IGraphicsScene;
class IGraphicsPixmapItem : public QGraphicsPixmapItem
{
public:
    IGraphicsPixmapItem(IGraphicsScene *parent = 0);
    IGraphicsPixmapItem(const int w, const int h);
    ~IGraphicsPixmapItem();

    void setPixmapInfo(const int x, const int y);
    void setPixmapInfo(const int x, const int y, const int w, const int h);
    void setPixmapPath(const QString path);
    void setRotate(const float degree) { _degree = degree;}

    void setItemText(const QString str);
protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    void rotate() const;
    QPixmap _pixmap_item;
    QString _pixmap_path;
    int _width;
    int _height;
    int _offset_x;
    int _offset_y;
    int _degree = 0;

    QString _str_text;
    const int _string_width = 100;
    const int _string_height = 20;

    SuspensionDialog* suspensionDialog = NULL;
    IGraphicsScene *_scene;
};

#endif // IGRAPHICSPIXMAPITEM_H
