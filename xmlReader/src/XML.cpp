#include "XML.h"
XMLAttr::XMLAttr(string name, string value)
{
    this->name=name;
    this->value=value;
}
XMLAttr::~XMLAttr()
{

}
XMLObj::XMLObj()
{

}
XMLObj::XMLObj(string name)
{
    this->name=name;
}

XMLObj::~XMLObj()
{

}
XMLObj::addObj(XMLObj o)
{
    obj.push_back(o);
}
XMLObj::addAttr(XMLAttr a)
{
    attr.push_back(a);
}
XMLObj::setName(string name)
{
    this->name=name;
}
vector <XMLAttr> XMLObj::getAttrVector()
{
    return attr;
}
vector <XMLObj> XMLObj::getObjVector()
{
    return obj;
}
string XMLObj::getName()
{
    return name;
}
void XMLObj::setText(string text)
{
    this->text=text;
}
string XMLObj::getText()
{
    return text;
}
vector<string> XML::explode(string delim, string str)
{
    vector<string> data;
    string current_string;
    bool newString=false;
    for(int i=0; i<str.size(); i++)
    {
        for(int d=0; d<delim.size(); d++)//sprawdza czy dla danego miejsca kazdy znak z delima pasuje po kolei jak tak daje flage
        {
            if((i+d)<str.size())
            {
                if(str[i+d]==delim[d])
                    newString=true;
            }
        }
        if(newString)
        {
            data.push_back(current_string);
            current_string="";
            newString=false;
            i+=delim.size()-1;
        }else
        {
            current_string+=str[i];
        }
    }
    if(newString==false && current_string!="")
    {
        data.push_back(current_string);
    }
    return data;
}
bool XML::findNearestTag(string text, int from, XMLObj& obj,int &pocz, int &kon)//obiekt do którego zapiszemy pozniej rzeczy
{
    //koordynaty z nazwa jako nazwa|pocz|kon
    string name="";
    string tmp_name;//na przechowywanie kazdego znacznika
    string endTagName;
    bool savingName=false;
    bool gettingNameOfEndTag=false;
    bool checkEndAndStartTagName=false;
    bool parentExist=false;
    int omit=0;
    for(int i=from; i<text.size(); i++)
    {
        if((i+1)<text.size())// numer nastepnego znaku jest nadal mniejszy od wielkosc calego ciagu (w przypadku pliku z samym <)
        {
            if(text[i]=='<' && text[i+1]!='/' && text[i+1]!='?')//jesli pierwszy znak to < //jesli znak to nie ?(deklaracja xml) i / (traktuje jako znak zwykly nie funkcyjny [/< /" etc.])
            {
                    savingName=true;
                    continue;//skipujemy reszte
            }
            else if((i-1)>=0)
            {
                if(text[i-1]=='<' && text[i]=='/')
                {
                    gettingNameOfEndTag=true;
                    continue;
                }
            }
        }
            if(savingName)
            {
                if(text[i]!='>')//zapisuj nazwe tego znaku
                {
                    tmp_name+=text[i];//z atrubutami
                }else
                {
                    string tmp_only_name = explode(" ", tmp_name)[0];//uwalamy atrybuty
                    if(text[i-1]!='/')
                    {
                        if(name!="" && tmp_only_name==name)
                        {
                            omit++;//jesli taka nazwa juz sie raz pojawila, innymi slowy jesli jest dziecko takiej samej nazwy to dodaj 1 do ominiecia
                        }else if(!parentExist)//jesli pierwszy raz i nie ma rodzica
                        {
                            vector <string> att= explode(" ", tmp_name);//bierzemy atrybuty
                            name = tmp_only_name;
                            obj.setName(name);
                            for(int j=1; j<att.size(); j++)//zaczynaja sie od 1 bo 0 to nazwa taga
                            {
                                vector <string> tmp=explode("=", att[j]);
                                if((tmp[1][0]=='\'' || tmp[1][0]=='\"') && (tmp[1][tmp[1].size()-1]=='\'' || tmp[1][tmp[1].size()-1]=='\"') )
                                {
                                    tmp[1]=tmp[1].substr(1,tmp[1].size()-2);
                                }
                                obj.addAttr(XMLAttr(tmp[0],tmp[1]));
                            }
                            pocz=i+1;
                            parentExist=true;
                        }
                    }
                    savingName=false;
                    tmp_name="";
                }
            }
            if(gettingNameOfEndTag)
            {
                if(text[i]!='>')//zapisuj nazwe do tego znaku
                {
                    endTagName+=text[i];
                }else
                {
                    gettingNameOfEndTag=false;
                    checkEndAndStartTagName=true;
                }
            }
            if(checkEndAndStartTagName)
            {
                if(endTagName==name)
                {
                    if(omit>0)
                    {
                        omit--;//jesli mielismy cos ominac to usuwamy z listy do ominiecia i nic nie robimy
                        endTagName="";
                        checkEndAndStartTagName=false;
                    }
                    else
                    {
                        kon=i-3-name.size();//i to jest miejsce > tego znacznika, odejmujemy 3 bo </ ...> i dlugosc nazwy;koncowa dlugosc
                        return true;
                    }
                }
                else
                {
                    endTagName="";
                    checkEndAndStartTagName=false;
                }
            }
    }
    return false;
}
string showed="";
XMLObj XML::getTag(string text)//string to parse, objvect where we save it
{
    int pocz=0,kon=0;
    XMLObj tmpObj;

    while(kon<text.size())
    {
        if(findNearestTag(text,kon,tmpObj,pocz,kon)==true)
        {
            string tresc="";
            for(int i=pocz; i<=kon; i++)
            {
                tresc+=text[i];
            }

            //Sprawdzanko
            //


            XMLObj t = getTag(tresc);
            cout<<"Obiekt: "<<tmpObj.getName()<<endl<<endl;
            cout<<tresc<<endl;
            cout<<"Pod spodem "<<t.getObjVector().size()<<" obiektow"<<endl;
            char i;
            cin>>i;
            system("CLS");
            //

            tmpObj.obj.push_back(t);//niebezpieczne
        }else
        {
            if(tmpObj.getName()=="")
            {
                tmpObj.setText(text);
            }
            break;
        }
    }
    return tmpObj;

}
void XML::show(XMLObj obj)
{

}
void XML::removeCharsFromString( string &str, char* charsToRemove ) {
   for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}
XML::XML(string filename)
{
    char a;
    cin>>a;
    cout<<(int)a<<endl;
    int pocz,kon;
    XMLObj o=XMLObj("tet");
    /*
    string t="<root v=\"ee\"><a v=\"ee2\"></a></root>";

    if(findNearestTag(t,0,o,pocz,kon)==true)
    {
        cout<<"TagName: "<<o.getName()<<endl;
        cout<<"Suchy tekst: "<<t<<endl;
        cout<<"Pocz: "<<pocz<<" Kon: "<<kon<<endl;
        string tresc="";
        for(int i=pocz; i<=kon; i++)
        {
            tresc+=t[i];
        }
        cout<<"Tresc:"<<endl;
        cout<<tresc<<endl<<endl<<endl;
        for(int i=0; i<o.getAttrVector().size(); i++)
        {
            cout<<o.getAttrVector()[i].name<<"="<<o.getAttrVector()[i].value<<endl;        }
    }else
    {
        cout<<"Blad"<<endl;
    }*/
    //sczytaj plik
    string s_plik;
    fstream plik;
    plik.open( filename.c_str(), ios::in );
    if( plik.good() )
    {
        string napis;
        while( !plik.eof() )
        {
            getline( plik, napis );
            char chars[] = {'\t', '\r', '\n'};

            removeCharsFromString( napis, chars);
            s_plik += napis;
        }
        plik.close();
    } else cout << "Error! Nie udalo otworzyc sie pliku!" << endl;
    root = getTag(s_plik);
    show(root);
    //cout<<showed<<endl;
    std::fstream baked( "../Testy/ts/baked.xml", std::ios::out );
    baked<<showed;
}

XML::~XML()
{
    //dtor
}
