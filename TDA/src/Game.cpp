#include "Game.h"

#include "MathStructs.h"
#include<windows.h>
SDL_mutex *lock;
SDL_cond *cond = SDL_CreateCond();
SDL_bool condition = SDL_FALSE;

//SDL_Window *window;
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
double lookat[] = {0.0, 0.0, 0.0, 2.0, 0.0, -7.0, 0.0, 1.0, 0.0};
void display() {
   glTranslatef(0.0f, 0.0f, -7.0f);  // Move right and into the screen

   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out

      glColor3f(-0.5f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();  // End of drawing color-cube

   /*// Render a pyramid consists of 4 triangles
   glLoadIdentity();                  // Reset the model-view matrix
   gluLookAt(lookat[0], lookat[1], lookat[2], lookat[3], lookat[4], lookat[5], lookat[6], lookat[7], lookat[8]);
   glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen

   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(1.0f, -1.0f, 1.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);

      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, 1.0f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(1.0f, -1.0f, -1.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f, -1.0f, -1.0f);

      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, 1.0f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-1.0f,-1.0f,-1.0f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-1.0f,-1.0f, 1.0f);
   glEnd();   // Done drawing the pyramid
*/
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

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
    while(isRunning)//glowna petla logiki gry
    {
    }
}

void Game::renderThreadFunction(Game &obj)
{
    SDL_LockMutex(lock);            //czeka az utworzy sie okno
    while (!condition) {            //
        SDL_CondWait(cond, lock);   //
    }                               //
    SDL_UnlockMutex(lock);          //

    //context = SDL_GL_CreateContext(window);

    SDL_GLContext mainGlContext = SDL_GL_CreateContext(obj.window);//tworzenie nowego kontekstu
    //mainGlContext = SDL_GL_CreateContext(window);
    //std::cout<<&context<<" "<<&mainGlContext<<std::endl;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);//wybieranie wersji zalecanej Opengl
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);//wybieranie minimalnej wersji opengl
    // Double Buffer
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);//deklarowanie podwojnego bufora
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);//glebkosc bufora (???)
    SDL_GL_MakeCurrent(obj.window, mainGlContext);//ustawianie stworzonego kontekstu jako aktualny
    SDL_GL_SwapWindow(obj.window);//odswiezanie okna
    glLoadIdentity();
    while(isRunning)
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);//czyszczenie okna kolorem czarnym
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//kolejne czyszczenie
        reshape(640,480);
        initGL();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
        glLoadIdentity();
        gluPerspective(45,640.0/480.0,1.0,500.0);
        glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
        glLoadIdentity();
        // Render a color-cube consisting of 6 quads with different colors
        Camera* CuCam = obj.currentCamera;

        if(CuCam!=NULL)
        {
            //glTranslatef(CuCam->getX(), CuCam->getY(), CuCam->getZ());
            glRotatef(CuCam->getRY(),1.0,0.0,0.0);
            //glTranslatef(CuCam->getX(), CuCam->getY(), CuCam->getZ());
            glRotatef(CuCam->getRZ(),0.0,0.0,1.0);
            //glTranslatef(CuCam->getX(), CuCam->getY(), CuCam->getZ());
            glRotatef(CuCam->getRX(),0.0,1.0,0.0);
        }
        glTranslatef(CuCam->getX(), CuCam->getY(), CuCam->getZ());
        display();

        SDL_GL_SwapWindow(obj.window);//odswiezanie okna
        glFlush();
    }
}

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
