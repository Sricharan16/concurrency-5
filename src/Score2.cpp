#include "Score2.h"
#include<QFont>
Score2::Score2(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //intializing the score to zero
    score2=0;
    //drawing the text
    setPlainText(QString("Score2: ")+QString::number(score2));\
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));

}
void Score2::increase(){
    score2++;
    setPlainText(QString("Score2: ")+QString::number(score2));\
}
int Score2::gethealth(){
    return score2;
}
