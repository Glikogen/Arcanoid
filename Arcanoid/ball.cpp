#include "ball.h"

Ball::Ball(QWidget *parent) : QWidget(parent)
{
    impulse = new Impulse();
    timer = new QTimer();
    timer->setInterval(30);

    connect(timer, SIGNAL(timeout()), this, SLOT(GetCoordnates()));
    timer->start();

    connect(this, SIGNAL(BallIsDropped()), timer, SLOT(stop()));
}

void Ball::GetCoordnates()
{
    CheckForWallsAndPaddle();
    x += impulse->deltaX;
    y -= impulse->deltaY;
    emit NewCoordinates();
}

void Ball::CheckForWallsAndPaddle()
{
    SURFACES surface = NONE;
    int dx = impulse->deltaX;
    int dy = impulse->deltaY;
    if (x + dx < 0) surface = LEFT_WALL;
    if (x + dx > WIDTH - BALL_DIAMETER) surface = RIGHT_WALL;
    if (y - dy < 0) surface = CELLING;
    if (x + dx < 0 && y + dy < 0) surface = LEFT_CORNER;
    if (x + dx > WIDTH - BALL_DIAMETER && y + dy < 0) surface = RIGHT_CORNER;
    if (x + dx >= paddle->x_left - BALL_DIAMETER && x + dx <= paddle->rightmost && y - dy >= HEIGHT-PADDLE_HEIGHT-BALL_DIAMETER)
        surface = PADDLE;
    if (CheckForAllBricksBottoms())
        surface = BRICK_BOTTOM;
    if (CheckForAllBricksTops())
        surface = BRICK_TOP;
    if (y > HEIGHT - BALL_DIAMETER) surface = BOTTOM;
    Rebound(surface);
    //если мяч касается стен, потолка делаем ребаунд
    //если лопатки, то вызываем гетНьюИмпульс (все равно в ребаунс)
    //если пола, то все останавливаем (мб через сигнал луза)
}

bool Ball::CheckForAllBricksBottoms()
{
    int dx = impulse->deltaX;
    int dy = impulse->deltaY;

    for(int k = 0; k < bricks.count(); k++)
    {
        Brick *b = bricks.at(k);
        if (x + dx >= b->x_left - BALL_DIAMETER && x + dx <= b->x_right
                && y - dy <= b->y + BRICK_HEIGHT && y - dy >= b->y)
        {
            currentBrick = b;
            emit BallHitsBrick(k);
            return true;
        }
    }

    return false;
}

bool Ball::CheckForAllBricksTops()
{
    int dx = impulse->deltaX;
    int dy = impulse->deltaY;

    for(int k = 0; k < bricks.count(); k++)
    {
        Brick *b = bricks.at(k);
        if (x + dx >= b->x_left - BALL_DIAMETER && x + dx <= b->x_right
                && y - dy >= b->y - BALL_DIAMETER && y - dy <= b->y)
        {
            currentBrick = b;
            emit BallHitsBrick(k);
            return true;
        }
    }

    return false;
}

void Ball::Rebound(SURFACES surface)
{
    int dx = impulse->deltaX;
    int dy = impulse->deltaY;
    if (surface == NONE) return;
    if (surface == LEFT_WALL || surface == RIGHT_WALL) impulse->SetDeltaXY(-dx, dy);
    if (surface == CELLING) impulse->SetDeltaXY(dx, -dy);
    if (surface == LEFT_CORNER || surface == RIGHT_CORNER) impulse->SetDeltaXY(-dx, -dy);
    if (surface == PADDLE) impulse = paddle->getNewImpulse(x);
    if (surface == BRICK_BOTTOM) impulse = currentBrick->getNewImpulseForBottomRebound(x);
    if (surface == BRICK_TOP) impulse = currentBrick->getNewImpulseForTopRebound(x);
    if (surface == BOTTOM) emit BallIsDropped();
    //пересчитываем импульс в зависимости от "поверхности"
}
