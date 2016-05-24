#include <QtWidgets/QApplication>
#include "learnqt5.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setWindowIcon(QIcon("stupid.gif"));	//to set the logo
	learnQt5 *dialog = new learnQt5;
	dialog->show();
	return a.exec();
}
