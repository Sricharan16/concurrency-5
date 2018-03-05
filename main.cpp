#include <QApplication>
#include "Game.h"
#include <QMovie>
#include <QLabel>
#include <QDebug>
#include<QElapsedTimer>
#include<QMediaPlayer>
#include "Button.h"

Game * game;
QMediaPlayer *bulletsound;
void sound_func()   //the function to run the sound of bulle shot concurrently
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/resources/sound/bullet.wav"));
    if(bulletsound->state()==QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else
       {
        bulletsound->setMedia(QUrl("qrc:/sound/resources/sound/bullet.wav"));
        bulletsound->play();
       }
}

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
        QElapsedTimer timer;
         timer.start();


       QTimer::singleShot(3000,game,SLOT(show()));
       game->displayMainMenu();

    return a.exec();
}
