#include <QMainWindow>
#include <QtWidgets>

class MoveCommand : public QUndoCommand
{
public:
	enum { Id = 1234 };
	MoveCommand(DiagramItem *diagramItem, const QPointF &oldPos,
		QUndoCommand *parent = 0);
	void undo();
	void redo();
	bool mergeWith(const QUndoCommand *command);
	int id() const { return Id; }
private:
	DiagramItem *myDiagramItem;
	QPointF myOldPos;
	QPointF newPos;
};