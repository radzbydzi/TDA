#ifndef MAP_H
#define MAP_H
#include "Fragment.h"
#include <iostream>
using namespace std;
//w obecnej formie wysokosc mapy nie ma znaczenie, moznaby dzialac na mapie 3d, przydatne do np. wojen w powietrzu i na ladzie, gdy wysokosc jest duza
//i obiekty znajduja sie na wyzszych wysokosciach, ktorych ci na ladzie nie powinni widziec
class Map
{
    public:
        Map();
        virtual ~Map();
        void loadFragmentsTable(int x, int y);//laduje tablice fragmentow na podstawie globalnego x i y aktywnego gracza
    protected:

    private:
        //obsluga fragmentow
        int fragmentWidth;//szerokosc fragmentu
        int fragmentHeight;//wysokosc fragmentu
        //fragmenty maja swoje lokalne koordynaty od 0 do fragmentWidth i od 0 do fragmentHeight
        //sa one obliczane z globalnego x i y gracza i wiedzy ktory fragment jest w uzyciu
        //dlugosc mapy to fragmentWidth*ilosc_fragmentow, podobnie dla wysokosci
        //punkt globalny 0,0 jest punktem 0,0 pierwszego fragmentu
        //punkt globalny n*fragmentWidth, m*fragmentHeight sa punktem 0,0 dla fragmentu n,m

        Fragment fragments[3][3];//tablica 9 fragmentow; jest to macierz 3x3; zawsze  znajdujemy sie w punkcie 2x2 czyli fr...ts[1][1]
                                //zawartosc jest automatycznie
                                //TODO: zrobiæ sprawdzalke pozycji globalnej i lokalnej we fragmencie

};

#endif // MAP_H
