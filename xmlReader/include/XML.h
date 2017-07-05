#ifndef XML_H
#define XML_H
#include<string>
#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <windows.h>

using namespace std;
class XMLAttr
{
    public:
        XMLAttr(string name, string value);
        virtual ~XMLAttr();
        string name;
        string value;

};
class XMLObj
{
    public:
        XMLObj(string name);
        XMLObj();
        virtual ~XMLObj();
        addObj(XMLObj o);
        addAttr(XMLAttr a);
        string getName();
        setName(string name);
        vector <XMLAttr> getAttrVector();
        vector <XMLObj> getObjVector();
        void setText(string text);
        string getText();
        vector <XMLObj> obj;
    private:

        vector <XMLAttr> attr;
        string name;
        string text;
};
class XML
{
    public:
        XML(string filename);
        virtual ~XML();
        void show(XMLObj obj);
    protected:

    private:
        XMLObj root;
        void removeCharsFromString( string &str, char* charsToRemove );
        XMLObj getTag(string text);
        bool findNearestTag(string text, int from, XMLObj& obj,int &pocz, int &kon);
        XMLObj getElementByTag(string tag);
        vector<string> explode(string delim, string str);
};

#endif // XML_H
