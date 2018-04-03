#include "suspensiondialog.h"
#include "netnode.h"

SuspensionDialog::SuspensionDialog(NetNode *selectNode,QWidget *parent):QDialog(parent)
{
    this->resize(200,100);
	if(!selectNode)
	{
		qDebug()<<"   ";
        exit(-1);
	}
	nameLabel = new QLabel(tr("name "));
	nameLineEdit = new QLineEdit;
	nameLineEdit->setText(QString("host"));
	ipLabel = new QLabel(tr("ip "));
	ipLineEdit = new QLineEdit;
	ipLineEdit->setText(QString("192.168.0.1"));
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(nameLabel,0,0);
	layout->addWidget(nameLineEdit,0,1);
	layout->addWidget(ipLabel,1,0);
	layout->addWidget(ipLineEdit,1,1);
	setLayout(layout);
	this->node = selectNode;
	setModal(false);
    setAttribute(Qt::WA_DeleteOnClose);
}
SuspensionDialog::~SuspensionDialog()
{
}
