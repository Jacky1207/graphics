#ifndef PROPERTIESDIALOG_UI_H
#define PROPERTIESDIALOG_UI_H

#include <QLabel>
#include <QLineEdit>
#include <QDialog>

class SuspensionDialog : public QDialog
{
    	Q_OBJECT
public:
        SuspensionDialog(QWidget *parent = 0);
    	~SuspensionDialog();

private:
	QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *ipLabel;
	QLineEdit *ipLineEdit;	
};

#endif
