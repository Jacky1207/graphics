#include <QtGui>
#include <QtCore>
#include <QApplication>
#include "nodeframe.h"

int main(int argc, char **argv)
{
	QApplication app(argc, argv);
	NodeFrame p_MainWindow;
	p_MainWindow.setWindowFlags(Qt::WindowMinMaxButtonsHint);
    p_MainWindow.setGeometry(100,100,870,520);
	p_MainWindow.show();
	return app.exec();
}
