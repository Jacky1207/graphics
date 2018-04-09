#include "SuspensionDialog.h"

#include <QGridLayout>

SuspensionDialog::SuspensionDialog(QWidget *parent):QDialog(parent)
{
	this->resize(300,150);

	nameLabel = new QLabel(tr("name "));
	nameLineEdit = new QLineEdit;
    nameLineEdit->setText(QString("router"));
	ipLabel = new QLabel(tr("ip "));
	ipLineEdit = new QLineEdit;
	ipLineEdit->setText(QString("192.168.0.1"));
	QGridLayout *layout = new QGridLayout;
	layout->addWidget(nameLabel,0,0);
	layout->addWidget(nameLineEdit,0,1);
	layout->addWidget(ipLabel,1,0);
	layout->addWidget(ipLineEdit,1,1);
	setLayout(layout);
	setModal(false);
    setAttribute(Qt::WA_DeleteOnClose);
}
SuspensionDialog::~SuspensionDialog()
{
}
