#include "Game.h"
void Game::logicThreadFunction(Game &obj)
{
    /*
    Na logike gry sklada sie:
    1.Przetwarzanie informacji z wejsc jak mysz, klawiatura
    2.obliczanie fizyki obiektow
    3.animacja obiektow
    4.MOZE sztuczna inteligencja (moze stworze kolejny watek)
    W miare mozliwosci wszystko parse'owane z listy
    */
    obj.addCamera("camera", 0,0,0);
    obj.currentCamera = obj.getCamera("camera");
    obj.models.push_back(Model());
    obj.models[0].loadObj("../Testy/texturedscene.obj");

    //obj.models[0].loadObj("../Testy/monkey.obj");
    obj.objects.push_back(Object("a",obj.models[0],0,0,-7));
    //obj.objects[0].addText("Test1", 10, 10);
    cout<<"sth"<<endl;
    while(isRunning)//glowna petla logiki gry
    {
    }
}


