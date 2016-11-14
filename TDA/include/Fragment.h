#ifndef FRAGMENT_H
#define FRAGMENT_H
#include <iostream>
#include <vector>
#include "Object.h"
using namespace std;

class Fragment
{
    public:
        Fragment();
        virtual ~Fragment();
        void addObject(string name, Model model, int x, int y);//dodaje do fragmentu obiekt o podanej nazwie i odpowiednim modelu graficznym
        void delObject(string name);//usuwa obiekt po nazwie
        void delObject(int id);//usuwa obiekt po id
        Object* getObject(string name);//zwraca wskaznik na dany obiekt (bo nie modyfikujemy kopii tylko w³aœnie ten obiekt)
        Object* getObject(int id);//jak wyzej
    protected:

    private:
        vector<Object> objects;
};

#endif // FRAGMENT_H
