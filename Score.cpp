#include "Score.h"
#include<QFont>
Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //intializing the score to zero
    score=0;
    //drawing the text
    setPlainText(QString("Score: ")+QString::number(score));\
    setDefaultTextColor(Qt::magenta);
    setFont(QFont("times",16));

}
void Score::increase(){
    score++;
    setPlainText(QString("Score: ")+QString::number(score));\
}
int Score::getscore(){
    return score;
}

