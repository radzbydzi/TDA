#include "Object.h"
#include "../font_lib/arial/stb_font_arial_6_latin_ext.inl"

Object::Object(string name, Model model,int x, int y, int z)
{
    //ctor
    this->name=name;
    this->model=model;
    this->x=x;
    this->y=y;
    this->z=z;
}

Object::~Object()
{
    //dtor
}

void Object::setModel(Model model)
{
    this->model = model;
}
Model* Object::getModel()
{
    return &model;
}
void Object::addText(char* str, int x, int y)
{
    static stb_fontchar fontdata[STB_SOMEFONT_NUM_CHARS];
    //init
    // optionally replace both STB_SOMEFONT_BITMAP_HEIGHT with STB_SOMEFONT_BITMAP_HEIGHT_POW2
    static unsigned char fontpixels[STB_SOMEFONT_BITMAP_HEIGHT][STB_SOMEFONT_BITMAP_WIDTH];
    STB_SOMEFONT_CREATE(fontdata, fontpixels, STB_SOMEFONT_BITMAP_HEIGHT);
    //... create texture ...
    // for best results rendering 1:1 pixels texels, use nearest-neighbor sampling
    // if allowed to scale up, use bilerp

    //draw string integer

    //... use texture ...
    //... turn on alpha blending and gamma-correct alpha blending ...
    model.meshes.push_back(Mesh());
    Mesh* m = &model.meshes[model.meshes.size()-1];
    //glBegin(GL_QUADS);
    while (*str) {
        int char_codepoint = *str++;
        stb_fontchar *cd = &fontdata[char_codepoint - STB_SOMEFONT_FIRST_CHAR];
        /*
        glTexCoord2f(cd->s0, cd->t0); glVertex2i(x + cd->x0, y + cd->y0);
        glTexCoord2f(cd->s1, cd->t0); glVertex2i(x + cd->x1, y + cd->y0);
        glTexCoord2f(cd->s1, cd->t1); glVertex2i(x + cd->x1, y + cd->y1);
        glTexCoord2f(cd->s0, cd->t1); glVertex2i(x + cd->x0, y + cd->y1);
        */
        m->vertex.push_back(vec3(x + cd->x0, y + cd->y0, 0));
        m->vertex.push_back(vec3(x + cd->x1, y + cd->y0, 0));
        m->vertex.push_back(vec3(x + cd->x1, y + cd->y1, 0));
        m->vertex.push_back(vec3(x + cd->x0, y + cd->y1, 0));

        // if bilerping, in D3D9 you'll need a half-pixel offset here for 1:1 to behave correct
        x += cd->advance_int;
    }
   // glEnd();


}
