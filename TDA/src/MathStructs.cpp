#include "MathStructs.h"
vec3 multiplyMatrixByVector(mat3 m, vec3 v)
{
    vec3 result = vec3();
    result.x=m.a11*v.x+m.a12*v.y+m.a13*v.y;
    result.y=m.a21*v.x+m.a22*v.y+m.a23*v.y;
    result.z=m.a31*v.x+m.a32*v.y+m.a33*v.y;
    return result;
}
vec3 cross(vec3 a, vec3 b)
{
    //A→×B→=(a2b3−a3b2;a3b1−a1b3;a1b2−a2b1)
    vec3 r=vec3(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x);
    return r;
}
vec3 sum(vec3 a, vec3 b)
{
    //A→×B→=(a2b3−a3b2;a3b1−a1b3;a1b2−a2b1)
    vec3 r=vec3(a.x+b.x, a.y+b.y, a.z+b.z);
    return r;
}
vec3 subtract(vec3 a, vec3 b)
{
    //A→×B→=(a2b3−a3b2;a3b1−a1b3;a1b2−a2b1)
    vec3 r=vec3(a.x-b.x, a.y-b.y, a.z-b.z);
    return r;
}
vec3 normalize(vec3 a)
{
    float sqr = sqrt( a.x*a.x + a.y*a.y + a.z*a.z);
    vec3 r=vec3(a.x/sqr, a.y/sqr, a.z/sqr);
    return r;
}

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

std::string show(vec3 v)
{
    std::ostringstream ss;
    ss << "x: " << v.x << " y: "<< v.y << " z: "<< v.z;
    return ss.str();
}
std::string show(mat3 m)
{
    std::ostringstream ss;
    ss
    <<m.a11<<", "<<m.a12<<", "<<m.a13<<"\r\n"
    <<m.a21<<", "<<m.a22<<", "<<m.a23<<"\r\n"
    <<m.a31<<", "<<m.a32<<", "<<m.a33<<"\r\n";
    return ss.str();
}
std::string show(vec2 v)
{
    std::ostringstream ss;
    ss << "x: " << v.x << " y: "<< v.y;
    return ss.str();
}
