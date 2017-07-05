#ifndef CAMERA_H
#define CAMERA_H
#include <string>
#include "MathStructs.h"
#include "Position.h"
using namespace std;
class Camera : public Position
{
    public:
        Camera(string name);
        Camera(string name, float x, float y, float z);
        Camera(string name, float x, float y, float z, float lx, float ly, float lz);
        virtual ~Camera();
        //nazwa
        void setName(string name);
        string getName();
        void moveForward(int dir, float magnitude);
        void moveRight(int dir, float magnitude);
        void moveUp(int dir, float magnitude);
    protected:

    private:
        string name;
};

#endif // CAMERA_H
