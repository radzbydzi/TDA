#include "Object.h"

Object::Object(string name, Model model,int x, int y)
{
    //ctor
}

Object::~Object()
{
    //dtor
}

void Object::setX(float x)
{
    this->x = x;
}
void Object::setY(float y)
{
    this->y = y;
}
void Object::setZ(float z)
{
    this->y = y;
}
void Object::setXYZ(float x, float y, float z)
{
    setX(x);
    setY(y);
    setZ(z);
}
float Object::getX()
{
    return x;
}
float Object::getY()
{
    return y;
}
float Object::getZ()
{
    return z;
}
float* Object::getXYZ()
{
    float tab[3];
    tab['x']=x;
    tab['y']=y;
    tab['z']=z;
    return tab;
}
