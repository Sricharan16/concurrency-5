#include "myrect.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "enemy.h"
#include <QDebug>
#include "Game.h"
#include <QPixmap>
#include<QGraphicsRectItem>
#include<QtConcurrent/qtconcurrentrun.h>
extern Game *game;
extern void sound_func();
extern QMediaPlayer *bulletsound;

using namespace QtConcurrent;
void MyRect::keyPressEvent(QKeyEvent *event){
    if(flags==0){
        flags=1;
        item = new QGraphicsRectItem();
        item->setRect(this->x()+25-100,this->y()+25,100,10);
        item->setTransformOriginPoint(this->x()+25,this->y()+25);
        scene()->addItem(item);
    }

    if (event->key() == Qt::Key_Up){ //rotating the gun upwards
        if(angle<260)
            angle=angle+10;
        scene()->removeItem(item);
        item->setRotation(180+angle);
        scene()->addItem(item);
    }
    else if (event->key() == Qt::Key_Down){ //rotating the gun downwards
        if(angle>100)
            angle=angle-10;

        scene()->removeItem(item);
        item->setRotation(180+angle);
        scene()->addItem(item);

       }
    else if (event->key() == Qt::Key_Space){ //to create the bullet
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y()+37.5);
        bullet->setTransformOriginPoint(12.5,12.5);
        bullet->setRotation(angle);
        scene()->addItem(bullet);
        QFuture<void> f1 = QtConcurrent::run(sound_func);//run the sound of the bullet shot concurrently on a different thread
    }
}
void MyRect::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

