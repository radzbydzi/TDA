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
#include "Object.h"
#include "MathStructs.h"
#include "lodepng.h"
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
        SDL_Thread *logicThread;//obiekt w�tku dla elementow logicznych gry
        SDL_Thread *renderThread;//obiekt w�tku dla renderu scen
        void logicThreadFunction(Game &obj);//tutaj znajdowac sie maja sie znajdowac wszystkie zmiany polozenia obiektow itp.
        void renderThreadFunction(Game &obj);//tutaj renderowane sa obiekty brane z odpowiednich list
        void interactionThreadFunction();//obsluga klawiatury myszy itp.; wywolane w watku glownym; tworzy takze okno
        //--------------------------------------------------\\
        //mutexy
        SDL_mutex *lock;
        SDL_cond *cond = SDL_CreateCond();
        SDL_bool condition = SDL_FALSE;
        //kamery
        vector<Camera> cameras;
        Camera* currentCamera;
        void addCamera(string name, float x, float y, float z);
        Camera* getCamera(int id);
        Camera* getCamera(string name);
        //do przeniesienia
        vector<Object> objects;//temporary
        vector<Model> models;//nie wiem czy tymczasowo
        bool wireframe=false;
        bool test = false;
};

#endif // GAME_H
