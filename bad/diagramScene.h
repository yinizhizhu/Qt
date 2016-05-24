#include <QMainWindow>
#include <QtWidgets>

class DiagramScene : public QGraphicsScene
{
	Q_OBJECT
public:
	DiagramScene(QObject *parent = 0);
signals:
	void itemMoved(DiagramItem *movedItem, const QPointF &movedFromPosition);
protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
	QGraphicsItem *movingItem;
	QPointF oldPos;
};