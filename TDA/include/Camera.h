#ifndef CAMERA_H
#define CAMERA_H
#include <string>
using namespace std;
class Camera
{
    public:
        Camera(string name);
        Camera(string name, float x, float y, float z);
        Camera(string name, float x, float y, float z, float lx, float ly, float lz);
        virtual ~Camera();
        //wspolrzedne
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setXYZ(float x, float y, float z);
        float getX();
        float getY();
        float getZ();
        float* getXYZ();
         //wspolrzedne na co ma patrzec
        void setRX(float rx);
        void setRY(float ry);
        void setRZ(float rz);
        void setRXYZ(float rx, float ry, float rz);
        float getRX();
        float getRY();
        float getRZ();
        float* getRXYZ();
        //nazwa
        void setName(string name);
        string getName();
    protected:

    private:
        float x,y,z;
        float rx,ry,rz;//rotation x,y,z in degree
        string name;
};

#endif // CAMERA_H
