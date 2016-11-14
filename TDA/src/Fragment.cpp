#include "Fragment.h"

Fragment::Fragment()
{
    //ctor
}

Fragment::~Fragment()
{
    //dtor
}

void Fragment::addObject(string name, Model model, int x, int y)
{
    objects.push_back(Object(name,model,x,y));
}
