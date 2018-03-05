#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include<typeinfo>
#include <QDebug>
#include<QKeyEvent>
#include <QPixmap>
#include<qmath.h>
#include "Game.h"
#include<QGraphicsPixmapItem>
extern Game * game;
Bullet::Bullet(): QObject(), QGraphicsPixmapItem(){
    // drew the rect
    setPixmap(QPixmap(":/images/bullet.png"));
    setScale(0.15);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score also here
            game->score->increase();
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    int STEP_SIZE = 30;
        double theta = rotation(); // degrees

        double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
        double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

        setPos(x()+dx, y()+dy);
    if (pos().y() < 0 || pos().x()<0 || pos().y() + 50>600 ){
        scene()->removeItem(this);
        //qDebug()<<"Removed";
        delete this;
    }
}

