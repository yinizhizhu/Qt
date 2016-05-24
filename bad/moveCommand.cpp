#include "moveCommand.h"

MoveCommand::MoveCommand(DiagramItem *diagramItem, const QPointF &oldPos,
	QUndoCommand *parent)
	: QUndoCommand(parent)
{
	myDiagramItem = diagramItem;
	newPos = diagramItem->pos();
	myOldPos = oldPos;
}
void MoveCommand::undo()
{
	myDiagramItem->setPos(myOldPos);
	myDiagramItem->scene()->update();
	setText(QObject::tr("Move %1")
		.arg(createCommandString(myDiagramItem, newPos)));
}
void MoveCommand::redo()
{
	myDiagramItem->setPos(newPos);
	setText(QObject::tr("Move %1")
		.arg(createCommandString(myDiagramItem, newPos)));
}
bool MoveCommand::mergeWith(const QUndoCommand *command)
{
	const MoveCommand *moveCommand = static_cast<const MoveCommand *>(command);
	DiagramItem *item = moveCommand->myDiagramItem;
	if (myDiagramItem != item)
		return false;
	newPos = item->pos();
	setText(QObject::tr("Move %1")
		.arg(createCommandString(myDiagramItem, newPos)));
	return true;
}