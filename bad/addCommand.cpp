#include "addCommand.h"

AddCommand::AddCommand(DiagramItem::DiagramType addType,
	QGraphicsScene *scene, QUndoCommand *parent)
	: QUndoCommand(parent)
{
	static int itemCount = 0;
	myGraphicsScene = scene;
	myDiagramItem = new DiagramItem(addType);
	initialPosition = QPointF((itemCount * 15) % int(scene->width()),
		(itemCount * 15) % int(scene->height()));
	scene->update();
	++itemCount;
	setText(QObject::tr("Add %1")
		.arg(createCommandString(myDiagramItem, initialPosition)));
}
void AddCommand::undo()
{
	myGraphicsScene->removeItem(myDiagramItem);
	myGraphicsScene->update();
}