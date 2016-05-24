#ifndef LEARNQT5_H
#define LEARNQT5_H

#include <QMainWindow>
#include <QtWidgets>
//#include <QtPrintSupport/QPrinter>
//#include  <QtPrintSupport/QPrintDialog>

class learnQt5 : public QMainWindow
{
	Q_OBJECT
public:
	learnQt5();
	private slots:
	void open();
	//void print();
	void zoomIn();
	void zoomOut();
	void normalSize();
	void fitToWindow();
	void about();
private:
	void createActions();
	void createMenus();
	void updateActions();
	void scaleImage(double factor);
	void adjustScrollBar(QScrollBar *scrollBar, double factor);
	QLabel *imageLabel;
	QScrollArea *scrollArea;
	double scaleFactor;
	//QPrinter printer;
	QAction *openAct;
	QAction *printAct;
	QAction *exitAct;
	QAction *zoomInAct;
	QAction *zoomOutAct;
	QAction *normalSizeAct;
	QAction *fitToWindowAct;
	QAction *aboutAct;
	QAction *aboutQtAct;
	QMenu *fileMenu;
	QMenu *viewMenu;
	QMenu *helpMenu;
};

#endif // LEARNQT5_H
