#ifndef OBJECT_H
#define OBJECT_H
#include "Model.h"
#include "Position.h"
#include <iostream>
using namespace std;
class Object : public Position
{
    public:
        Object(string name, Model model,int x, int y, int z);
        virtual ~Object();

        //nazwa
        void setName(string name);
        string getName();
        //model
        void setModel(Model model);
        Model* getModel(); //wskaznik poniewaz modyfikujemy konkretny model, nie jego kopie
        void addText(char* str, int x, int y);
    protected:

    private:
        string name;
        Model model;
};

#endif // OBJECT_H
