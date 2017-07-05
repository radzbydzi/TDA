#include "Position.h"

Position::Position()
{
    //ctor
}

Position::~Position()
{
    //dtor
}

void Position::setX(float x)
{
    this->x = x;
}
void Position::setY(float y)
{
    this->y = y;
}
void Position::setZ(float z)
{
    this->z = z;
}
void Position::setXYZ(float x, float y, float z)
{
    setX(x);
    setY(y);
    setZ(z);
}
float Position::getX()
{
    return x;
}
float Position::getY()
{
    return y;
}
float Position::getZ()
{
    return z;
}
float* Position::getXYZ()
{
    float tab[3];
    tab['x']=x;
    tab['y']=y;
    tab['z']=z;
    return tab;
}
void Position::setRX(float rx)
{
    this->rx = rx;
}
void Position::setRY(float ry)
{
    this->ry = ry;
}
void Position::setRZ(float rz)
{
    this->rz = rz;
}
void Position::setRXYZ(float rx, float ry, float rz)
{
    setRX(rx);
    setRY(ry);
    setRZ(rz);
}
float Position::getRX()
{
    return rx;
}
float Position::getRY()
{
    return ry;
}
float Position::getRZ()
{
    return rz;
}
float* Position::getRXYZ()
{
    float tab[3];
    tab['x']=rx;
    tab['y']=ry;
    tab['z']=rz;
    return tab;
}
