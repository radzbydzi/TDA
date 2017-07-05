#include "Game.h"
#include<windows.h>

Game::Game()
{
    //ctor
    //odpalamy watki
    logicThread = SDL_CreateThread((SDL_ThreadFunction)&logicThreadFunction, "logicThread", (void *)this);//tworzy watek logiczny
    renderThread = SDL_CreateThread((SDL_ThreadFunction)&renderThreadFunction, "renderThread", (void *)this);//tworzy watek renderu
    interactionThreadFunction();

}

Game::~Game()
{
    //dtor

	//Destroy window
	SDL_DestroyWindow( window );//niszczenie okna

	//Quit SDL subsystems
	SDL_Quit();//zamykanie SDL
}



void Game::addCamera(string name, float x, float y, float z)
{
    Camera tmp = Camera(name,x,y,z);
    cameras.push_back(tmp);
}

Camera* Game::getCamera(int id)
{
    return &cameras[id];
}
Camera* Game::getCamera(string name)
{
    for(int i=0; i<cameras.size(); i++)
    {
        if(name==cameras[i].getName())
            return &cameras[i];
    }
    return false;
}
