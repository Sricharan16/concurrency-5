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
Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    //set random position
    int random_number = rand() % 550;
    setPos(0,random_number);

    // drew the rect
    setPixmap(QPixmap(":/images/enemy.png"));
        //setTransformOriginPoint(50,50);
        setScale(0.15);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down
    setPos(x()+5,y());
    if (pos().x() > 800){
        scene()->removeItem(this);
        game->score2->decrease();
        if(game->score2->gethealth()==0)
            game->close();
        //qDebug() << "this reached";
        delete this;
    }
}
