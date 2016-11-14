#include "Camera.h"

Camera::Camera(string name)
{
    //ctor
    this->name = name;
}
Camera::Camera(string name, float x, float y, float z)
{
    //ctor
    this->name = name;
    this->x = x;
    this->y = y;
    this->z = z;
    this->rx = x;
    this->ry = y;
    this->rz = z;
}
Camera::Camera(string name, float x, float y, float z, float rx, float ry, float rz)
{
    //ctor
    this->name = name;
    this->x = x;
    this->y = y;
    this->z = z;
    this->rx = rx;
    this->ry = ry;
    this->rz = rz;
}
Camera::~Camera()
{
    //dtor
}

void Camera::setX(float x)
{
    this->x = x;
}
void Camera::setY(float y)
{
    this->y = y;
}
void Camera::setZ(float z)
{
    this->z = z;
}
void Camera::setXYZ(float x, float y, float z)
{
    setX(x);
    setY(y);
    setZ(z);
}
float Camera::getX()
{
    return x;
}
float Camera::getY()
{
    return y;
}
float Camera::getZ()
{
    return z;
}
float* Camera::getXYZ()
{
    float tab[3];
    tab['x']=x;
    tab['y']=y;
    tab['z']=z;
    return tab;
}
void Camera::setRX(float rx)
{
    this->rx = rx;
}
void Camera::setRY(float ry)
{
    this->ry = ry;
}
void Camera::setRZ(float rz)
{
    this->rz = rz;
}
void Camera::setRXYZ(float rx, float ry, float rz)
{
    setRX(rx);
    setRY(ry);
    setRZ(rz);
}
float Camera::getRX()
{
    return rx;
}
float Camera::getRY()
{
    return ry;
}
float Camera::getRZ()
{
    return rz;
}
float* Camera::getRXYZ()
{
    float tab[3];
    tab['x']=rx;
    tab['y']=ry;
    tab['z']=rz;
    return tab;
}
string Camera::getName()
{
    return name;
}
