//#include "learnqt5.h"
#include <QtWidgets/QApplication>
//#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon("stupid.gif"));
	//learnQt5 w;
	//w.show();

	//QLabel *label = new QLabel("Hello Qt!");
	//QLabel *label = new QLabel("<h2><i>Hello</i> <font color=red>Qt!<font></h2>");
	//label->show();
	
	QPushButton *button = new QPushButton("Quit");
	QObject::connect(button, SIGNAL(clicked()), &a, SLOT(quit()));
	button->show();
	return a.exec();
}
