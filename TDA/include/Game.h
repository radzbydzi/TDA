#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <string>
#include <exception>
#include <iostream>

class Game
{
    public:
        Game();
        virtual ~Game();
        SDL_Thread *logicThread;//obiekt w¹tku dla elementow logicznych gry
        SDL_Thread *renderThread;//obiekt w¹tku dla renderu scen
        bool isRunning = true;
    protected:

    private:
        //SDL_Window *window; // klasa okna
        //SDL_GLContext context;//klasa kontekstu renderujacego
        void logicThreadFunction();//tutaj znajdowac sie maja sie znajdowac wszystkie zmiany polozenia obiektow itp.
        void renderThreadFunction();//tutaj renderowane sa obiekty brane z odpowiednich list
        void interactionThreadFunction();//obsluga klawiatury myszy itp.; wywolane w watku glownym; tworzy takze okno
        bool windowCreated = false;//jesli okno

};

#endif // GAME_H
