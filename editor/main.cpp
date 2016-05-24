#include "learnqt5.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	app.setWindowIcon(QIcon("stupid.gif"));
	learnQt5 *tmp = new learnQt5;
	tmp->show();
	return app.exec();
}