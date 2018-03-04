#include"Button.h"
#include<QGraphicsTextItem>
#include<QBrush>
#include<QGraphicsSceneHoverEvent>
#include<QGraphicsSceneMouseEvent>
Button::Button(QString name, QGraphicsItem *parent):QGraphicsRectItem(parent)
{
    //draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
    text  = new QGraphicsTextItem(name,this);
    int xPos =rect().width()/2- text->boundingRect().width()/2;
    int yPos =rect().height()/2- text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    //allow responding to hover events
    setAcceptHoverEvents(true);


}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //changing color
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}

