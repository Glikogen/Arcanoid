#ifndef BALL_H
#define BALL_H

#include <QWidget>
#include <QTimer>
#include "Constants.h"
#include "impulse.h"
#include "paddle.h"
#include "brick.h"

class Ball : public QWidget
{
    Q_OBJECT
public:
    explicit Ball(QWidget *parent = nullptr);

    QTimer *timer;
    //ball
    int x = WIDTH/2-BALL_DIAMETER/2;
    int y = HEIGHT/2;

    Impulse *impulse;
    Paddle *paddle;

    void CheckForWallsAndPaddle();

    //List of bricks
    QList<Brick*> bricks;
    Brick *currentBrick;

    bool CheckForAllBricksBottoms();
    bool CheckForAllBricksTops();
signals:
    void NewCoordinates();
    void BallIsDropped();
    void BallHitsBrick(int);
public slots:
    void GetCoordnates();
    void Rebound(SURFACES surface);
};

#endif // BALL_H
