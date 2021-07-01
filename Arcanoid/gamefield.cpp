#include "gamefield.h"
#include <QPainter>
#include <QKeyEvent>

GameField::GameField(QWidget *parent) : QWidget(parent)
{
    paddle = new Paddle;
    InitializeListOfBricks();
    ball = new Ball;
    ball->bricks = bricks;

    connect(this, &GameField::NewPaddleCoordinates, [=]() { ball->paddle = paddle; });
    emit NewPaddleCoordinates(paddle);

    connect(ball, SIGNAL(NewCoordinates()), this, SLOT(repaint()));
    connect(ball, SIGNAL(BallHitsBrick(int)), this, SLOT(BallHitBrick(int)));

    connect(ball, SIGNAL(BallIsDropped()), this, SIGNAL(GameOver()));
}

void GameField::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter *qp = new QPainter(this);

    //paddle sircles
    qp->setBrush(Qt::blue);
    qp->drawEllipse(paddle->x_left, Y_FOR_PADDLE, PADDLE_HEIGHT, PADDLE_HEIGHT);
    qp->drawEllipse(paddle->x_right, Y_FOR_PADDLE, PADDLE_HEIGHT, PADDLE_HEIGHT);

    //paddle
    qp->setBrush(Qt::red);
    qp->drawRect(paddle->x-RECT_PADDLE_WIDTH/2, Y_FOR_PADDLE, RECT_PADDLE_WIDTH, PADDLE_HEIGHT);

    //ball
    qp->setBrush(Qt::green);
    qp->drawEllipse(ball->x, ball->y, BALL_DIAMETER, BALL_DIAMETER);

    //bricks
    qp->setBrush(Qt::darkYellow);

    for(int k = 0; k < bricks.count(); k++)
    {
        Brick *b = bricks.at(k);

        qp->drawEllipse(b->x_left, b->y, BRICK_HEIGHT, BRICK_HEIGHT);
        qp->drawEllipse(b->x_left+RECT_BRICK_WIDTH, b->y, BRICK_HEIGHT, BRICK_HEIGHT);
        qp->drawRect(b->x_left+BRICK_HEIGHT/2, b->y, RECT_BRICK_WIDTH, BRICK_HEIGHT);
    }

    qp->end();
}

void GameField::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_Left:
        if (paddle->x_left >= 6)
        {
            paddle->x_left -= 6;
            paddle->x_right -= 6;
            paddle->x -= 6;

            paddle->rightmost -= 6;
        }
        break;
        case Qt::Key_Right:
        if (paddle->x_right + 16 <= WIDTH - 6)
        {
            paddle->x_left += 6;
            paddle->x_right += 6;
            paddle->x += 6;

            paddle->rightmost += 6;
        }
        break;
    }
    emit NewPaddleCoordinates(paddle);
    repaint();
}

void GameField::InitializeListOfBricks()
{
    int currentX = 37;
    int currentY = 50;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            Brick *brick = new Brick;
            brick->x_left = currentX;
            brick->y = currentY;
            brick->x_right = brick->x_left + ALL_BRICK_WIDTH;

            bricks.append(brick);

            currentX += ALL_BRICK_WIDTH + 1;
        }

        currentX = 37;
        currentY += BRICK_HEIGHT + 1;
    }
}

void GameField::BallHitBrick(int k)
{
    bricks.removeAt(k);
    ball->bricks = bricks;
}
