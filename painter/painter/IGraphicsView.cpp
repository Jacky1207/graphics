#include "IGraphicsView.h"

IGraphicsView::IGraphicsView()
{
    _graphics_scene = new IGraphicsScene();
    _graphics_scene->setSceneRect(0, 0, 800, 480);
    this->setScene(_graphics_scene);
}

IGraphicsView::~IGraphicsView()
{
    if(_graphics_scene != NULL)
    {
        _graphics_scene->clear();
        delete _graphics_scene;
    }
}

void IGraphicsView::wheelEvent(QWheelEvent *event)
{
    QPoint scrollAmount = event->angleDelta();
    scrollAmount.y() > 0 ? zoomIn() : zoomOut();
}

void IGraphicsView::zoomIn()
{
    zoom(1 + _zoomDelta);
}

void IGraphicsView::zoomOut()
{
    zoom(1 - _zoomDelta);
}

void IGraphicsView::zoom(const float scaleFactor)
{
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
//    m_scale *= scaleFactor;
}
