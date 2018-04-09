#ifndef IGRAPHICSRECTITEM_H
#define IGRAPHICSRECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneDragDropEvent>

#include <QPoint>
#include <QRect>

class IGraphicsRectItem : public QGraphicsRectItem
{
public:
    explicit IGraphicsRectItem(QRect rect);
    IGraphicsRectItem(const int sx, const int sy, const int ex, const int ey);

    void resizeRect(const int width, const int height, int direc);
protected:
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    QColor getColor();

    const float _transparence = 0.8;

    QPoint _start;
    QPoint _end;
};

#endif // IGRAPHICSRECTITEM_H
