#ifndef LEARNQT5_H
#define LEARNQT5_H

#include <QMainWindow>
#include <QtWidgets>
#include "highLighter.h"
//#include <QtPrintSupport/QPrinter>
//#include  <QtPrintSupport/QPrintDialog>

class learnQt5 : public QMainWindow
{
	Q_OBJECT
public:
	learnQt5(QWidget *parent = 0);
public slots:
	void about();
	void newFile();
	void openFile(const QString &path = QString());
private:
	void setupEditor();
	void setupFileMenu();
	void setupHelpMenu();
	QTextEdit *editor;
	Highlighter *highlighter;
};

#endif // LEARNQT5_H
