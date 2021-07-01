#include "paddle.h"

Paddle::Paddle(QWidget *parent) : QWidget(parent)
{

}

Impulse *Paddle::getNewImpulse(int x_ball)
{
    Impulse *newImpulse = new Impulse;

    int difference_x = x_ball - x_left;

    if(difference_x < 6 && difference_x > -10) newImpulse->SetDeltaXY(-4, 3);
    if(difference_x > 5 && difference_x < 12) newImpulse->SetDeltaXY(-4, 4);
    if(difference_x > 11 && difference_x < 18) newImpulse->SetDeltaXY(-3, 5);
    if(difference_x > 17 && difference_x < 24) newImpulse->SetDeltaXY(-3, 5);
    if(difference_x > 23 && difference_x < 30) newImpulse->SetDeltaXY(-2, 5);
    if(difference_x > 29 && difference_x < 36) newImpulse->SetDeltaXY(0, 3);
    if(difference_x > 35 && difference_x < 42) newImpulse->SetDeltaXY(2, 5);
    if(difference_x > 41 && difference_x < 48) newImpulse->SetDeltaXY(3, 5);
    if(difference_x > 47 && difference_x < 54) newImpulse->SetDeltaXY(3, 5);
    if(difference_x > 53 && difference_x < 60) newImpulse->SetDeltaXY(4, 4);
    if(difference_x > 59 && difference_x < 66) newImpulse->SetDeltaXY(4, 3);

    return newImpulse;
}

