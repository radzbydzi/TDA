#include "Game.h"

void Game::interactionThreadFunction()
{
    SDL_LockMutex(lock);    //blokuje mutex
    SDL_Init(SDL_INIT_VIDEO);//inicjuje cos SDLa
    SDL_Event e;
    SDL_GL_SetSwapInterval(1);//jakas synchronizacja, czas miedzy updateami okna
    // Check that the window was successfully created
    int window_w = 640;
    int window_h = 480;
    window = SDL_CreateWindow("Third Dimension Adventure",SDL_WINDOWPOS_UNDEFINED,
                                                             SDL_WINDOWPOS_UNDEFINED,
                                                             window_w,
                                                             window_h,
                                                             SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);//tworzy okno
    if (window == NULL) {//jesli okono nie zostalo stworzone
        // In the case that the window could not be made...
        printf("Could not create window: %s\n", SDL_GetError());//pokaz error
        isRunning=false;//zatrzymaj petle wszystkich watkow
    }
    int old_mousex=window_w/2;
    int old_mousey=window_h/2;
    condition = SDL_TRUE;   //gdy sie to wykona
    SDL_CondSignal(cond);   //odblokowuje
    SDL_UnlockMutex(lock);  //wtedy render moze dzialac
    int mousex, mousey;
    SDL_WarpMouseInWindow(window, window_w/2, window_h/2);
    SDL_ShowCursor(SDL_DISABLE);
    while( isRunning )//jesli gra ma dzialac
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )//sprawdza czy jest jakis event
        {
            if( e.type == SDL_QUIT )//jesli evenetem jest zamknij
            {
                isRunning = false;//zmien zmienna od dzialania na falsz
            }
            if( e.type == SDL_KEYDOWN)
            {
                switch(e.key.keysym.sym)
                {
                    case (int)'w':
                        currentCamera->moveForward(1,0.5f);
                        break;
                    case (int)'s':
                        currentCamera->moveForward(-1,0.5f);
                        break;
                    case (int)'a':
                        currentCamera->moveRight(1,0.5f);
                        break;
                    case (int)'d':
                        currentCamera->moveRight(-1,0.5f);
                        break;
                    case (int)'p':
                        wireframe=!wireframe;
                        break;
                    //rotacja
                    case 1073741904:
                        currentCamera->setRX(currentCamera->getRX()-1);
                        break;
                    case 1073741903:
                        currentCamera->setRX(currentCamera->getRX()+1);
                        break;
                    case 1073741906:
                        currentCamera->setRY(currentCamera->getRY()-1);
                        break;
                    case 1073741905:
                        currentCamera->setRY(currentCamera->getRY()+1);
                        break;
                    case (int)'r':
                        {
                            currentCamera->setXYZ(0,0,0);
                            currentCamera->setRXYZ(0,0,0);
                        }
                    break;
                }
            }
            if( e.type == SDL_MOUSEMOTION)
            {
                SDL_WarpMouseInWindow(window, window_w/2, window_h/2);//mysz na stoddek
                mousex= e.motion.x;
                mousey = e.motion.y;

                float kx = mousex - window_w/2; //kordynaty x w swiecie
                float ky = mousey - window_h/2; //kordynaty y w swiecie

                //obliczanie kata
                float angleX=atanf(kx/100);//liczba 100 jest czuloscia
                float angleY=atanf(ky/100);

                if(angleX>89)
                    angleX=89;
                if(angleY>89)
                    angleY=89;

                currentCamera->setRX(currentCamera->getRX()+angleX);//ustawiamy kat rotacji dla x
                currentCamera->setRY(currentCamera->getRY()+angleY);//ustawiamy kat rotacji dla y

                if(currentCamera->getRX()>=360)
                {
                    currentCamera->setRX(360-currentCamera->getRX());
                }
                if(currentCamera->getRX()<=-360)
                {
                    currentCamera->setRX(360+currentCamera->getRX());
                }
                if(currentCamera->getRY()>=360)
                {
                    currentCamera->setRY(360-currentCamera->getRY());
                }
                if(currentCamera->getRY()<=-360)
                {
                    currentCamera->setRY(360+currentCamera->getRY());
                }
                //cout<<currentCamera->getRX()<<" "<<currentCamera->getRY()<<endl;
            }

        }

        /**/

    }
}


