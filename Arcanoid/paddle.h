#ifndef PADDLE_H
#define PADDLE_H

#include <QWidget>
#include "Constants.h"
#include "impulse.h"

class Paddle : public QWidget
{
    Q_OBJECT
public:
    explicit Paddle(QWidget *parent = nullptr);

    //paddle
    int x_left = WIDTH/2 - X_LEFT_PADDLE_CIRCL;
    int x_right = WIDTH/2 + X_RIGHT_PADDLE_CIRCL;
    int x = WIDTH/2;

    int rightmost = x_right + 16;

    Impulse* getNewImpulse(int x_ball);
private:

signals:

};

#endif // PADDLE_H
