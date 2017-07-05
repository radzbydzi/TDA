#include "Model.h"

Model::Model()
{
    //ctor
}

Model::~Model()
{
    //dtor
}
std::vector<std::string> explode(const std::string& text, const std::string& delims)
{
    std::vector<std::string> tokens;
    std::size_t start = text.find_first_not_of(delims), end = 0;

    while((end = text.find_first_of(delims, start)) != std::string::npos)
    {
        tokens.push_back(text.substr(start, end - start));
        start = text.find_first_not_of(delims, end);
    }
    if(start != std::string::npos)
        tokens.push_back(text.substr(start));

    return tokens;
}
void Model::loadObj(string path)
{
    fstream plik;
    plik.open( path.c_str(), ios::in );
    if( plik.good() )
    {
        string napis;
        bool first_occure=false;
        int v_sub = 0; //liczba plaszczyzn poprzedniego obiektu
        int v_count=0;
        while( !plik.eof() )
        {
            getline( plik, napis );
            vector <string> exp = explode(napis, " ");
            Mesh* tmp;


            if(exp[0]=="o")
            {
                v_sub=v_count;
                v_count=0;
                meshes.push_back(Mesh());
                tmp = &meshes[meshes.size()-1];
            }else if(tmp!=NULL)
            {
                if(exp[0]=="v")
                {
                    tmp->vertex.push_back(vec3(atof(exp[1].c_str()), atof(exp[2].c_str()), atof(exp[3].c_str())));
                    v_count++;
                }else if(exp[0]=="vn")
                {
                    tmp->normal.push_back(vec3(atof(exp[1].c_str()), atof(exp[2].c_str()), atof(exp[3].c_str())));
                }else if(exp[0]=="f")
                {
                    tmp->faces.push_back(Face());
                    Face* tmp_f= &tmp->faces[tmp->faces.size()-1];
                    int f_num = tmp->faces.size()-1;
                    for(int i=1; i<exp.size(); i++)
                    {
                        vector <string> f_ex = explode(exp[i], "//");
                            vec2 a = vec2(atoi(f_ex[0].c_str())-v_sub, atoi(f_ex[0].c_str())-v_sub);
                            tmp_f->face.push_back(FaceCord(a));

                    }
                }else if(exp[0]=="vt")
                {
                    //tmp->texture.push_back(vec2(atof(exp[1].c_str()), atof(exp[2].c_str())));
                }
            }
        }
        plik.close();
    } else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;
}
