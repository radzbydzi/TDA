#ifndef MATHSTRUCTS_H_INCLUDED
#define MATHSTRUCTS_H_INCLUDED
#include <Math.h>
struct vec3
{
    float x,y,z;

    vec3(){};
    vec3(float x, float y, float z): x(x),y(y),z(z) {};
};
struct mat3
{

};
struct quat
{
    float x,y,z,w;//wspolrzedne kwaterniona

    quat(){};
    quat(float x, float y, float z, float w): x(x), y(y),z(z), w(w) {};
};

void AxisToQuaternion(quat *Out, const vec3 &Axis, float Angle)
{
  Angle *= 0.5f;
  float Sin = sinf(Angle);
  Out->x = Sin * Axis.x;
  Out->y = Sin * Axis.y;
  Out->z = Sin * Axis.z;
  Out->w = cosf(Angle);
}
void QuaternionRotationX(quat *Out, float a)
{
  a *= 0.5f;
  Out->x = sinf(a); Out->y = 0.0f; Out->z = 0.0f;
  Out->w = cosf(a);
}

void QuaternionRotationY(quat *Out, float a)
{
  a *= 0.5f;
  Out->x = 0.0f; Out->y = sinf(a); Out->z = 0.0f;
  Out->w = cosf(a);
}

void QuaternionRotationZ(quat *Out, float a)
{
  a *= 0.5f;
  Out->x = 0.0f; Out->y = 0.0f; Out->z = sinf(a);
  Out->w = cosf(a);
}
void Mul(quat *Out, const quat &q1, const quat &q2)
{
  Out->x = q1.w*q2.x + q1.x*q2.w + q1.y*q2.z - q1.z*q2.y;
  Out->y = q1.w*q2.y + q1.y*q2.w + q1.z*q2.x - q1.x*q2.z;
  Out->z = q1.w*q2.z + q1.z*q2.w + q1.x*q2.y - q1.y*q2.x;
  Out->w = q1.w*q2.w - q1.x*q2.x - q1.y*q2.y - q1.z*q2.z;
}
void QuaternionTransform(vec3 *Out, const vec3 &p, const quat &q)
{
  float
    xx = q.x * q.x, yy = q.y * q.y, zz = q.z * q.z,
    xy = q.x * q.y, xz = q.x * q.z,
    yz = q.y * q.z, wx = q.w * q.x,
    wy = q.w * q.y, wz = q.w * q.z;

  Out->x =
    (1.0f - 2.0f * ( yy + zz )) * p.x +
    (2.0f * ( xy - wz )) * p.y  +
    (2.0f * ( xz + wy )) * p.z;
  Out->y =
    (2.0f * ( xy + wz )) * p.x +
    (1.0f - 2.0f * ( xx + zz )) * p.y +
    (2.0f * ( yz - wx )) *p.z;
  Out->z =
    (2.0f * ( xz - wy )) * p.x +
    (2.0f * ( yz + wx )) * p.y +
    (1.0f - 2.0f * ( xx + yy )) * p.z;
}
void makeSimpleQuat()
{
    //quat a = quat(10.0, 10.0, 10.0, 10.0);
    quat b = quat();
    vec3 axis = vec3(10.0, 10.0, 10.0);
    vec3 result = vec3();
    float angle = 45*(3.14/180);
    AxisToQuaternion(&b,axis,angle);
    QuaternionRotationX(&b, 45*(3.14/180));
    QuaternionTransform(&result, axis, b);
    cout<<"Original:"<<endl<<"x: "<<axis.x<<" y: "<<axis.y<<" z: "<<axis.z<<endl;
    cout<<"Quaternion:"<<endl<<"x: "<<result.x<<" y: "<<result.y<<" z: "<<result.z<<endl;
}
#endif // MATHSTRUCTS_H_INCLUDED
