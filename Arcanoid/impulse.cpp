#include "impulse.h"

Impulse::Impulse(QObject *parent) : QObject(parent)
{

}

void Impulse::SetDeltaXY(int DeltaX, int DeltaY)
{
    deltaX = DeltaX;
    deltaY = DeltaY;
}
