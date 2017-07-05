#ifndef MODEL_H
#define MODEL_H
#include<vector>
#include <iostream>
#include <fstream>
#include "MathStructs.h"
#include <sstream>
#include <utility>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <Mesh.h>
using namespace std;

class Model
{
    public:
        Model();
        virtual ~Model();
        void loadObj(string path);
        vector<Mesh> meshes;
    protected:

    private:

};

#endif // MODEL_H
