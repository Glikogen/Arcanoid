#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <QList>
#include <QWidget>
#include "paddle.h"
#include "Constants.h"
#include <QTimer>
#include "ball.h"
#include "brick.h"

class GameField : public QWidget
{
    Q_OBJECT
public:
    explicit GameField(QWidget *parent = nullptr);
private:
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *event);

    //paddle
    Paddle *paddle;

    //ball
    Ball *ball;

    //List of bricks
    QList<Brick*> bricks;

    void InitializeListOfBricks();
signals:
    void NewPaddleCoordinates(Paddle*);
    void GameOver();
public slots:
    void BallHitBrick(int);
};

#endif // GAMEFIELD_H
