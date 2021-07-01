#ifndef IMPULSE_H
#define IMPULSE_H

#include <QObject>

class Impulse : public QObject
{
    Q_OBJECT
public:
    explicit Impulse(QObject *parent = nullptr);
    int speed = 2;
    int deltaX = 0;
    int deltaY = -3;

    void SetDeltaXY(int DeltaX, int DeltaY);
signals:

};

#endif // IMPULSE_H
