#ifndef LEARNQT5_H
#define LEARNQT5_H

#include <QLabel>
#include <QDialog>
#include <QCheckBox>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class learnQt5 : public QDialog
{
	Q_OBJECT//to annouce the QObject

public:
	learnQt5(QWidget *parent = 0);
	~learnQt5();
	bool createConnection();
signals: //annouce the function of signals
	void findNext(const QString &str, Qt::CaseSensitivity cs);
	void findPrevious(const QString &str, Qt::CaseSensitivity cs);
private slots:	//annouce the function of slots
	void findClicked();
	void enableFindButton(const QString &text);
private:
	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *backwardCheckBox;
	QPushButton *findButton;
	QPushButton *closeButton;
};

#endif // LEARNQT5_H
