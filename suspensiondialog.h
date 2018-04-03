#ifndef PROPERTIESDIALOG_UI_H
#define PROPERTIESDIALOG_UI_H

#include <QtGui>
#include <QDialog>
#include <QLine>
#include <QLineEdit>
#include <QLabel>

class NetNode;

class SuspensionDialog : public QDialog
{
    	Q_OBJECT
public:
    	SuspensionDialog(NetNode *selectedNode,QWidget *parent = 0);
    	~SuspensionDialog();

private:
    	NetNode *node;
        QLabel *nameLabel;
    	QLineEdit *nameLineEdit;
    	QLabel *ipLabel;
        QLineEdit *ipLineEdit;
};

#endif
