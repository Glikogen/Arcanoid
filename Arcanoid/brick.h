#ifndef BRICK_H
#define BRICK_H

#include <QWidget>
#include "Constants.h"
#include "impulse.h"

class Brick : public QWidget
{
    Q_OBJECT
public:
    explicit Brick(QWidget *parent = nullptr);

    Brick(const Brick&);
    Brick& operator=(const Brick&);

    int x_left;
    int x_right;
    int y;

    Impulse* getNewImpulseForTopRebound(int x_ball);
    Impulse* getNewImpulseForBottomRebound(int x_ball);
signals:

};

#endif // BRICK_H
