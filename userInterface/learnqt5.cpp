#include "learnqt5.h"

learnQt5::learnQt5(QWidget *parent)
	: QWidget(parent)
{
	QLabel *nameLabel = new QLabel(tr("Name:"));
	nameLine = new QLineEdit;

	QLabel *addressLabel = new QLabel(tr("Address:"));
	addressText = new QTextEdit;

	QGridLayout *mainLayout = new QGridLayout;
	mainLayout->addWidget(nameLabel, 0, 0);
	mainLayout->addWidget(nameLine, 0, 1);
	mainLayout->addWidget(addressLabel, 1, 0, Qt::AlignTop);
	mainLayout->addWidget(addressText, 1, 1);
	setLayout(mainLayout);
	setWindowTitle(tr("Simple Address Book"));
}
