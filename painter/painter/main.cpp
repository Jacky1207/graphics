#include <QGraphicsView>
#include "IGrapgicsScene.h"
#include "IGraphicsView.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
    IGraphicsScene w;
    w.setSceneRect(0,0,4000,4000);
    w.initNode();
//    w.setGeometry(100,100,800,480);

    IGraphicsView view;
    view.setScene(&w);
    view.show();

    return a.exec();
}
