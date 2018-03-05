#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include<QMediaPlayer>
#include<QtConcurrent/qtconcurrentrun.h>
#include<QThread>
class MyRect:public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public:
    double angle=180;
    void keyPressEvent(QKeyEvent * event); //for the player inputs
    QGraphicsRectItem *item;
    int flags=0;
public slots:
    void spawn(); //member function to create enemies

};

#endif // MYRECT_H

