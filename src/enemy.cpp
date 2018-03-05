#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"
#include <QDebug>
#include "Score2.h"
#include <QFont>
extern Game *game;
Enemy::Enemy(): QObject(), QGraphicsRectItem(){
    //set random position
    int random_number = rand() % 550;
    setPos(0,random_number);

    // drew the rect
    setRect(0,0,50,50);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x()+5,y());
    if (pos().x() + rect().width() > 800){
        scene()->removeItem(this);
        game->score2->increase();
        //qDebug() << "this reached";
        delete this;
    }
}
