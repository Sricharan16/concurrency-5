#ifndef BUTTON_H
#define BUTTON_H
#include<QGraphicsRectItem>
#include<QGraphicsSceneMouseEvent>
#include<QAbstractButton>
class Button:public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    //constructors being defined
    Button(QString name,QGraphicsItem *parent=NULL);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();


private:
    QGraphicsTextItem* text;
};

#endif // BUTTON_H
