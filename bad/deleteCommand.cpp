#include "deleteCommand.h"

DeleteCommand::DeleteCommand(QGraphicsScene *scene, QUndoCommand *parent)
	: QUndoCommand(parent)
{
	myGraphicsScene = scene;
	QList<QGraphicsItem *> list = myGraphicsScene->selectedItems();
	list.first()->setSelected(false);
	myDiagramItem = static_cast<DiagramItem *>(list.first());
	setText(QObject::tr("Delete %1")
		.arg(createCommandString(myDiagramItem, myDiagramItem->pos())));
}
void DeleteCommand::undo()
{
	myGraphicsScene->addItem(myDiagramItem);
	myGraphicsScene->update();
}
void DeleteCommand::redo()
{
	myGraphicsScene->removeItem(myDiagramItem);
}