#ifndef IGRAPHICSVIEW_H
#define IGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

#include "IGrapgicsScene.h"

class IGraphicsView : public QGraphicsView
{
public:
    IGraphicsView();
    ~IGraphicsView();

    virtual void wheelEvent(QWheelEvent *event);
protected:
private:
    void zoomIn();
    void zoomOut();
    void zoom(const float scaleFactor);

    const float _zoomDelta = 0.1;


    IGraphicsScene *_graphics_scene;
};

#endif // IGRAPHICSVIEW_H
