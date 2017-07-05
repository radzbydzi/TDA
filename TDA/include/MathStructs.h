#ifndef MATHSTRUCTS_H_INCLUDED
#define MATHSTRUCTS_H_INCLUDED
#include <Math.h>
#include <sstream>
#ifndef PI    //if the pi is not defined in the cmath header file
#define PI 3.1415926535       //define it
#endif
struct mat3
{
    float   a11,a12,a13,
            a21,a22,a23,
            a31,a32,a33;

    mat3(){};
    mat3(float a11, float a12, float a13, float a21, float a22, float a23, float a31, float a32, float a33):
        a11(a11), a12(a12), a13(a13),a21(a21), a22(a22), a23(a23), a31(a31), a32(a32), a33(a33) {};

    mat3 operator *(const mat3& a)
    {
        /*
        a11*b11 + a12*b21 + a13*b31     |   a11*b12 + a12*b22 + a13*b32     |   a11*b13 + a12*b23 + a13*b33
        a21*b11 + a22*b21 + a23*b31     |   a21*b12 + a22*b22 + a23*b32     |   a21*b13 + a22*b23 + a23*b33
        a31*b11 + a32*b21 + a33*b31     |   a31*b12 + a32*b22 + a33*b32     |   a31*b13 + a32*b23 + a33*b33
        */
        mat3 r =mat3(
                        a11*a.a11 + a12*a.a21 + a13*a.a31     ,   a11*a.a12 + a12*a.a22 + a13*a.a32     ,   a11*a.a13 + a12*a.a23 + a13*a.a33,
                        a21*a.a11 + a22*a.a21 + a23*a.a31     ,   a21*a.a12 + a22*a.a22 + a23*a.a32     ,   a21*a.a13 + a22*a.a23 + a23*a.a33,
                        a31*a.a11 + a32*a.a21 + a33*a.a31     ,   a31*a.a12 + a32*a.a22 + a33*a.a32     ,   a31*a.a13 + a32*a.a23 + a33*a.a33
                     );

        return r;
    }
    mat3 operator +(const mat3& a)
    {
        mat3 r =mat3(
                        a11+a.a11, a12+a.a12, a13+a.a13,
                        a21+a.a21, a22+a.a22, a23+a.a23,
                        a31+a.a31, a32+a.a32, a33+a.a33
                     );
        return r;
    }
    mat3 operator -(const mat3& a)
    {
        mat3 r =mat3(
                        a11-a.a11, a12-a.a12, a13-a.a13,
                        a21-a.a21, a22-a.a22, a23-a.a23,
                        a31-a.a31, a32-a.a32, a33-a.a33
                     );
        return r;
    }
    mat3 operator -()
    {
        mat3 r =mat3(
                        -a11, -a12, -a13,
                        -a21, -a22, -a23,
                        -a31, -a32, -a33
                     );
        return r;
    }

};
struct vec3
{
    float x,y,z;

    vec3(){};
    vec3(float x, float y, float z): x(x),y(y),z(z) {};
    vec3 operator *(const vec3& a)
    {
        vec3 r=vec3(y*a.z-z*a.y, z*a.x-x*a.z,x*a.y-y*a.x);
        return r;
    }
    vec3 operator *(const mat3& a)
    {
        vec3 r =vec3(
                        a.a11*x + a.a12*y + a.a13*z,
                        a.a21*x + a.a22*y + a.a23*z,
                        a.a31*x + a.a32*y + a.a33*z
                     );
        return r;
    }
    vec3 operator *(const float &a)
    {
        vec3 r=vec3(y*a-z*a, z*a-x*a,x*a-y*a);
        return r;
    }
    vec3 operator +(const vec3& a)
    {
        vec3 r=vec3(x+a.x, y+a.y, z+a.z);
        return r;
    }
    vec3 operator -(const vec3& a)
    {
        vec3 r=vec3(x-a.x, y-a.y, z-a.z);
        return r;
    }
};
struct vec2
{
    float x,y;

    vec2(){};
    vec2(float x, float y): x(x),y(y){};
};
struct quat
{
    float x,y,z,w;//wspolrzedne kwaterniona

    quat(){};
    quat(float x, float y, float z, float w): x(x), y(y),z(z), w(w) {};
};

vec3 multiplyMatrixByVector(mat3 m, vec3 v);
vec3 cross(vec3 a, vec3 b);
vec3 sum(vec3 a, vec3 b);
vec3 subtract(vec3 a, vec3 b);
vec3 normalize(vec3 a);
void AxisToQuaternion(quat *Out, const vec3 &Axis, float Angle);
void QuaternionRotationX(quat *Out, float a);
void QuaternionRotationY(quat *Out, float a);
void QuaternionRotationZ(quat *Out, float a);
void Mul(quat *Out, const quat &q1, const quat &q2);
void QuaternionTransform(vec3 *Out, const vec3 &p, const quat &q);
std::string show(vec2 v);
std::string show(vec3 v);
std::string show(mat3 m);
#endif // MATHSTRUCTS_H_INCLUDED
