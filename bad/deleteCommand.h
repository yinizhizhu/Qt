#include <QMainWindow>
#include <QtWidgets>

class DeleteCommand : public QUndoCommand
{
public:
	DeleteCommand(QGraphicsScene *graphicsScene, QUndoCommand *parent = 0);
	void undo();
	void redo();
private:
	DiagramItem *myDiagramItem;
	QGraphicsScene *myGraphicsScene;
};