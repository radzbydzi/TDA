#include "Camera.h"
#include <Math.h>
#include "MathStructs.h"
#include <iostream>
#include <windows.h>
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
//moving
void Camera::moveForward(int dir, float magnitude)
{
    //http://www.songho.ca/opengl/files/gl_anglestoaxes05.png
    //http://www.songho.ca/opengl/gl_anglestoaxes.html
    float rad = PI/180;//stopnie na radiany
    float rxr = (rz)*rad;//osi x nie ruszamy, tu pewnie bedzie z
    float ryr = (rx)*rad;//pod os y podkladamy obrot x (nie wiem czemu)
    float rzr = (ry)*rad;//pod os z podkladamy obrot y (tez nie wiem czemu)
    //macierze obrotu
    mat3 m_rx=mat3(
               1, 0, 0,
               0, cosf(rxr), -sinf(rxr),
               0, sinf(rxr), cosf(rxr)
               );
    mat3 m_ry=mat3(
               cosf(ryr), 0, sinf(ryr),
               0, 1, 0,
               -sinf(ryr), 0, cosf(ryr)
               );
    mat3 m_rz=mat3(
               cosf(rzr), -sinf(rzr), 0,
               sinf(rzr), cosf(rzr), 0,
               0,0,1
               );
    mat3 cord = m_rx*m_ry*m_rz;//kordynaty z pomnozonych macierzy obrotu

    vec3 transformed = vec3(cord.a11*magnitude, cord.a21*magnitude, cord.a31*magnitude);//przekladamy na wektor, mnozym kazde przez dlugosc
    //ustawiamy xyz, do poprzednich wartosci dodajemy w odwrotnej kolejnosci z,y,x pomnozone przez kierunke, kierunek jest albo -1 albo 1; i fajno
    setX(x+dir*transformed.z);//transformacja dla osi x
    setY(y+dir*transformed.y);//transformacja dla osi y
    setZ(z+dir*transformed.x);//transformacja dla osi z
    //moim bledem bylo ze dodawalem jakis wektor i to do tego dodawalem x y z, oraz osie
    //teraz dodaje po prostu odpowiednie wektory mnozone przez dlugosc
}
void Camera::moveRight(int dir, float magnitude)
{
    float rad = PI/180;//stopnie na radiany
    float rxr = (rz)*rad;//osi x nie ruszamy, tu pewnie bedzie z
    float ryr = (rx)*rad;//pod os y podkladamy obrot x (nie wiem czemu)
    float rzr = (ry)*rad;//pod os z podkladamy obrot y (tez nie wiem czemu)
    //macierze obrotu
    mat3 m_rx=mat3(
               1, 0, 0,
               0, cosf(rxr), -sinf(rxr),
               0, sinf(rxr), cosf(rxr)
               );
    mat3 m_ry=mat3(
               cosf(ryr), 0, sinf(ryr),
               0, 1, 0,
               -sinf(ryr), 0, cosf(ryr)
               );
    mat3 m_rz=mat3(
               cosf(rzr), -sinf(rzr), 0,
               sinf(rzr), cosf(rzr), 0,
               0,0,1
               );
    mat3 cord = m_rx*m_ry*m_rz;//kordynaty z pomnozonych macierzy obrotu

    vec3 transformed = vec3(cord.a11*magnitude, cord.a21*magnitude, cord.a31*magnitude);//przekladamy na wektor, mnozym kazde przez dlugosc
    transformed = transformed*vec3(0,1,0);
    //ustawiamy xyz, do poprzednich wartosci dodajemy w odwrotnej kolejnosci z,y,x pomnozone przez kierunke, kierunek jest albo -1 albo 1;
    setX(x+dir*transformed.z);//transformacja dla osi x
    setY(y+dir*transformed.y);//transformacja dla osi y
    setZ(z+dir*transformed.x);//transformacja dla osi z
}
