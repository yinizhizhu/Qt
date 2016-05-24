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
	QGroupBox *createFirstExclusiveGroup();
	QGroupBox *createSecondExclusiveGroup();
	QGroupBox *createNonExclusiveGroup();
	QGroupBox *createPushButtonGroup();
};

#endif // LEARNQT5_H
