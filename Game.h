#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include "myrect.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include<QWidget>
#include <QTimer>
#include<QKeyEvent>
#include "Score.h"
#include "Score2.h"
#include<QGraphicsEllipseItem>
#include "Button.h"
class Game:public QGraphicsView{
    Q_OBJECT
public:
    Game();
    void displayMainMenu();
    QGraphicsScene *scene;
	//declaring the pointer which points to the scene 
   
    MyRect *player;

	//declaring the pointer which points to the player
    Score *score;	
	//this score is the number of enemies player shot
    Score2 *score2;
	//this score represents number of targets player missed
public slots:
    void starti();

};
#endif // GAME_H
