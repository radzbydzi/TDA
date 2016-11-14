#ifndef OBJECT_H
#define OBJECT_H
#include "Model.h"
#include <iostream>
using namespace std;
class Object
{
    public:
        Object(string name, Model model,int x, int y);
        virtual ~Object();
        //wspolrzedne
        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void setXYZ(float x, float y, float z);
        float getX();
        float getY();
        float getZ();
        float* getXYZ();
        //nazwa
        void setName(string name);
        string getName();
        //model
        void setModel(Model model);
        Model* getModel(); //wskaznik poniewaz modyfikujemy konkretny model, nie jego kopie
    protected:

    private:
        float x;
        float y;
        float z;
        string name;
        Model model;
};

#endif // OBJECT_H
