#include "Score2.h"
#include<QFont>
Score2::Score2(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //intializing the score to zero
    score2=10;
    //drawing the text
    setPlainText(QString("Health: ")+QString::number(score2));\
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));

}
void Score2::decrease(){
    score2--;
    setPlainText(QString("Health: ")+QString::number(score2));\
}
int Score2::gethealth(){
    return score2;
}

