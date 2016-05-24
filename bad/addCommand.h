#include <QMainWindow>
#include <QtWidgets>

class AddCommand : public QUndoCommand
{
public:
	AddCommand(DiagramItem::DiagramType addType, QGraphicsScene *graphicsScene,
		QUndoCommand *parent = 0);
	void undo();
	void redo();
private:
	DiagramItem *myDiagramItem;
	QGraphicsScene *myGraphicsScene;
	QPointF initialPosition;
};