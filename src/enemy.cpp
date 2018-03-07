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
	int speed=50;
    setPos(0,random_number);

    // drew the rect
    setPixmap(QPixmap(":/images/resources/images/enemy.png"));
        //setTransformOriginPoint(50,50);
        setScale(0.15);

    // connect
	if(game->score->getscore() >5 && game->score->getscore()<=10 )
		speed=40;
	else if(game->score->getscore() >10 && game->score->getscore()<=15)
		speed=35;
	else if(game->score->getscore() >15 && game->score->getscore()<=20)
		speed=30;
	else if(game->score->getscore() >20 && game->score->getscore()<=25)
		speed=25;
	else if(game->score->getscore() >25 && game->score->getscore()<=30)
            speed=20;
    else
	{
		if(game->score->getscore() >30)
			speed=10;
	}
			
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(speed);
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
