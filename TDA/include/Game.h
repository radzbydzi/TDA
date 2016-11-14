#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include <iostream>
#include <vector>
#include "Camera.h"
using namespace std;
class Game
{
    public:
        Game();
        virtual ~Game();
        bool isRunning = true;//zmienna bool odpowiadajaca za dzialanie petli glownych interakcji, logiki i renderu
    protected:

    private:
        SDL_Window *window; // klasa okna
        SDL_Thread *logicThread;//obiekt w¹tku dla elementow logicznych gry
        SDL_Thread *renderThread;//obiekt w¹tku dla renderu scen
        void logicThreadFunction(Game &obj);//tutaj znajdowac sie maja sie znajdowac wszystkie zmiany polozenia obiektow itp.
        void renderThreadFunction(Game &obj);//tutaj renderowane sa obiekty brane z odpowiednich list
        void interactionThreadFunction();//obsluga klawiatury myszy itp.; wywolane w watku glownym; tworzy takze okno
        //--------------------------------------------------\\
        //kamery
        vector<Camera> cameras;
        Camera* currentCamera;
        void addCamera(string name, float x, float y, float z);
        Camera* getCamera(int id);
        Camera* getCamera(string name);

};

#endif // GAME_H
