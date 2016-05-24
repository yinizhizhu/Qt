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
	public slots:
	void itemMoved(DiagramItem *movedDiagram, const QPointF &moveStartPosition);
	private slots:
	void deleteItem();
	void addBox();
	void addTriangle();
	void about();
	void itemMenuAboutToShow();
	void itemMenuAboutToHide();
private:
	void createActions();
	void createMenus();
	void createUndoView();
	QAction *deleteAction;
	QAction *addBoxAction;
	QAction *addTriangleAction;
	QAction *undoAction;
	QAction *redoAction;
	QAction *exitAction;
	QAction *aboutAction;
	QMenu *fileMenu;
	QMenu *editMenu;
	QMenu *itemMenu;
	QMenu *helpMenu;
	DiagramScene *diagramScene;
	QUndoStack *undoStack;
	QUndoView *undoView;
};

#endif // LEARNQT5_H
