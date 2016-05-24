#ifndef LEARNQT5_H
#define LEARNQT5_H

#include <QMainWindow>
#include <QtWidgets>


class learnQt5 : public QWidget
{
	Q_OBJECT
public:
	learnQt5(QWidget *parent = 0);
private:
	QLineEdit *nameLine;
	QTextEdit *addressText;
};

#endif // LEARNQT5_H
