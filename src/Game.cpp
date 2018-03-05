#include "Game.h"
#include "myrect.h"
#include<QMediaPlayer>
#include<QVideoWidget>
#include "Button.h"
#include <QGraphicsTextItem>
#include<QObject>
#include<QAbstractButton>
#include<QPushButton>
#include <QDebug>
#include<QTimer>
#include<QMediaPlaylist>
#include<QtConcurrent/qtconcurrentrun.h>
using namespace QtConcurrent;
extern void esp();
Game::Game( ){

    
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
  

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    


}

void Game::displayMainMenu()
{

    QGraphicsTextItem *titleText = new QGraphicsTextItem(QString("BASIC GAME"));
    QFont titleFont("comicsans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2-titleText->boundingRect().width()/2;
    int tyPos =150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);
    Button *playbutton = new Button(QString("Play"));

    int bxPos = this->width()/2-playbutton->boundingRect().width()/2;
    int byPos =275;
    playbutton->setPos(bxPos,byPos);
    connect(playbutton,SIGNAL(clicked()),this,SLOT(starti()));
    scene->addItem(playbutton);
    Button *quitbutton = new Button(QString("Quit"));
    int qxPos = this->width()/2-quitbutton->boundingRect().width()/2;
    int qyPos =350;
    quitbutton->setPos(qxPos,qyPos);
    connect(quitbutton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitbutton);
   // show();
}

void Game::starti()
{
    scene->clear();
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    
    player = new MyRect();
    player->setRect(0,0,50,50);	//setting the player position and dimensions

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);		//setting the window size

    
    scene->addItem(player);
    
    score = new Score();
    scene->addItem(score);
    
    score2 = new Score2();
    score2->setPos(score2->x(),score2->y()+25);
    scene->addItem(score2);
  
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();




    QMediaPlaylist *playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl("qrc:/sound/bgm.mp3"));
    playlist->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *music = new QMediaPlayer();
    music->setPlaylist(playlist);
    music->play();




    player->setPos(800-player->rect().width(),(600/2) - player->rect().height()/2);

 
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
 
}


