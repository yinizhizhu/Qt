#include "learnqt5.h"

learnQt5::learnQt5()
{
	undoStack = new QUndoStack();
	createActions();
	createMenus();
	connect(undoStack, SIGNAL(canRedoChanged(bool)),
		redoAction, SLOT(setEnabled(bool)));
	connect(undoStack, SIGNAL(canUndoChanged(bool)),
		undoAction, SLOT(setEnabled(bool)));
	createUndoView();
	diagramScene = new DiagramScene();
	QBrush pixmapBrush(QPixmap(":/images/cross.png").scaled(30, 30));
	diagramScene->setBackgroundBrush(pixmapBrush);
	diagramScene->setSceneRect(QRect(0, 0, 500, 500));
	connect(diagramScene, SIGNAL(itemMoved(DiagramItem *, const QPointF &)),
		this, SLOT(itemMoved(DiagramItem *, const QPointF &)));
	setWindowTitle("Undo Framework");
	QGraphicsView *view = new QGraphicsView(diagramScene);
	setCentralWidget(view);
	resize(700, 500);
}
void learnQt5::createUndoView()
{
	undoView = new QUndoView(undoStack);
	undoView->setWindowTitle(tr("Command List"));
	undoView->show();
	undoView->setAttribute(Qt::WA_QuitOnClose, false);
}
void learnQt5::createActions()
{
	deleteAction = new QAction(tr("&Delete Item"), this);
	deleteAction->setShortcut(tr("Del"));
	connect(deleteAction, SIGNAL(triggered()), this, SLOT(deleteItem()));
		undoAction = new QAction(tr("&Undo"), this);
	undoAction->setShortcut(tr("Ctrl+Z"));
	undoAction->setEnabled(false);
	connect(undoAction, SIGNAL(triggered()), undoStack, SLOT(undo()));
	redoAction = new QAction(tr("&Redo"), this);
	QList<QKeySequence> redoShortcuts;
	redoShortcuts << tr("Ctrl+Y") << tr("Shift+Ctrl+Z");
	redoAction->setShortcuts(redoShortcuts);
	redoAction->setEnabled(false);
	connect(redoAction, SIGNAL(triggered()), undoStack, SLOT(redo()));
}
void learnQt5::createMenus()
{
		editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(undoAction);
	editMenu->addAction(redoAction);
	editMenu->addSeparator();
	editMenu->addAction(deleteAction);
	connect(editMenu, SIGNAL(aboutToShow()),
		this, SLOT(itemMenuAboutToShow()));
	connect(editMenu, SIGNAL(aboutToHide()),
		this, SLOT(itemMenuAboutToHide()));
}
void learnQt5::itemMoved(DiagramItem *movedItem,
	const QPointF &oldPosition)
{
	undoStack->push(new MoveCommand(movedItem, oldPosition));
}
void learnQt5::itemMenuAboutToHide()
{
	deleteAction->setEnabled(true);
}
void learnQt5::itemMenuAboutToShow()
{
	undoAction->setText(tr("Undo ") + undoStack->undoText());
	redoAction->setText(tr("Redo ") + undoStack->redoText());
	deleteAction->setEnabled(!diagramScene->selectedItems().isEmpty());
}
void learnQt5::addBox()
{
	QUndoCommand *addCommand = new AddCommand(DiagramItem::Box, diagramScene);
	undoStack->push(addCommand);
}
void learnQt5::addTriangle()
{
	QUndoCommand *addCommand = new AddCommand(DiagramItem::Triangle, diagramScene);
	undoStack->push(addCommand);
}
void learnQt5::about()
{
	QMessageBox::about(this, tr("About Undo"),
		tr("The <b>Undo</b> example demonstrates how to "
		"use Qt's undo framework."));
}