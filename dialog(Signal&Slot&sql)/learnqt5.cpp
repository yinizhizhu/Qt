#include "learnqt5.h"

learnQt5::learnQt5(QWidget *parent)
	: QDialog(parent)
{
	createConnection();//connect to mysql
	
	label = new QLabel(tr("Find &what:"));//tr is for transfer. '&' is to define the shortcut "Alt + 'w'"
	lineEdit = new QLineEdit;
	label->setBuddy(lineEdit);

	caseCheckBox = new QCheckBox(tr("Match & case"));//'&' is to define the shortcut "Alt + 'c'"
	backwardCheckBox = new QCheckBox(tr("Search &backward"));//'&' is to define the shortcut "Alt + 'b'"
	
	findButton = new QPushButton(tr("&Find"));//'&' is to define the shortcut "Alt + 'f'"
	findButton->setDefault(true);//set the findButton as the default(for pressing 'enter')
	findButton->setEnabled(false);

	closeButton = new QPushButton(tr("Close"));

	connect(lineEdit, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &)));
	connect(findButton, SIGNAL(clicked()), this, SLOT(findClicked()));
	connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));

	QHBoxLayout *topLeftLayout = new QHBoxLayout;//the horizontal layout
	topLeftLayout->addWidget(label);
	topLeftLayout->addWidget(lineEdit);

	QVBoxLayout *leftLayout = new QVBoxLayout;//the vertex layout
	leftLayout->addLayout(topLeftLayout);
	leftLayout->addWidget(caseCheckBox);
	leftLayout->addWidget(backwardCheckBox);

	QVBoxLayout *rightLayout = new QVBoxLayout;
	rightLayout->addWidget(findButton);
	rightLayout->addWidget(closeButton);
	rightLayout->addStretch();
	
	QHBoxLayout *mainLayout = new QHBoxLayout;
	mainLayout->addLayout(leftLayout);
	mainLayout->addLayout(rightLayout);
	setLayout(mainLayout);

	setWindowTitle(tr("Find"));
	setFixedHeight(sizeHint().height());
}

learnQt5::~learnQt5()//beacause the parent class will free the room, and we do not do this job, which is useless
{
	delete label;
	delete lineEdit;
	delete caseCheckBox;
	delete backwardCheckBox;
	delete findButton;
	delete closeButton;
}

void learnQt5::findClicked()
{
	QString result = "";
	QSqlQuery query;
	query.exec("select * from h_p_d;");
	if (!query.isActive())
		QMessageBox::warning(this, tr("Database Error"), query.lastError().text());
	while (query.next())
	{
		result += query.value(0).toString();
		result += ", ";
		result += query.value(1).toString();
	}
	
	QString text = lineEdit->text();
	Qt::CaseSensitivity cs = (caseCheckBox->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive);//the CaseSensitivity is an Enumeration variable(2)
	if (backwardCheckBox->isChecked())
		emit findPrevious(text, cs);
	else
		emit findNext(text, cs);
	lineEdit->setText(result);
	return;
}

void learnQt5::enableFindButton(const QString &text)
{
	findButton->setEnabled(!text.isEmpty());//set the findButton is not ready
	return;
}

bool learnQt5::createConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setDatabaseName("live");
	db.setHostName("localhost");
	db.setUserName("root");
	db.setPassword("");
	if (!db.open())
	{
		QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
		return false;
	}
	return true;
}