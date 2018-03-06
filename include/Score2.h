#ifndef SCORE1_H
#define SCORE1_H
#include<QGraphicsTextItem>
class Score2:public QGraphicsTextItem{
public:
    Score2(QGraphicsItem * parent=0);
    void decrease();
    int gethealth();
private:
    int score2;
};
#endif // SCORE1_H

