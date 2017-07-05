#ifndef MESH_H
#define MESH_H
#include "MathStructs.h"
#include <vector>
#include <string>
using namespace std;
struct FaceCord
{
    vec2 cord;
    FaceCord(int f1, int f2)
    {
        cord=vec2(f1,f2);
    }
    FaceCord(vec2 v)
    {
        cord = v;
    }

};
struct Face
{
    vector <FaceCord> face;
};
class Mesh
{
    public:
        Mesh();
        virtual ~Mesh();
        vector<vec3> vertex;
        vector<vec3> normal;
        vector<Face> faces;
        vector<vec2> texture;
        string material;
        bool wireframe=false;
    protected:

    private:

};

#endif // MESH_H
