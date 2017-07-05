#include "Game.h"
#include "../font_lib/arial/stb_font_arial_22_latin_ext.inl"


void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   //glShadeModel(GL_SMOOTH);   // Enable smooth shading
   //glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
   glEnable(GL_LIGHTING);  //we enable lighting, to make the 3D object to 3D
    glEnable(GL_LIGHT0);
    //float col[]={1.0,1.0,1.0,1.0};  //light color is white
    //glLightfv(GL_LIGHT0,GL_DIFFUSE,col);
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

void Game::renderThreadFunction(Game &obj)
{
    SDL_LockMutex(obj.lock);            //czeka az utworzy sie okno
    while (!obj.condition) {            //
        SDL_CondWait(obj.cond, obj.lock);   //
    }                               //
    SDL_UnlockMutex(obj.lock);          //

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
        for(int i=0; i<obj.objects.size(); i++)//obiekty, teoretyczny byt
        {
            glTranslatef(obj.objects[i].getX(), obj.objects[i].getY(), obj.objects[i].getZ());
            glColor3f(-0.5f, 1.0f, 0.0f);

            for(int j=0; j<obj.objects[i].getModel()->meshes.size(); j++)//bryly w obiektach
            {
                vector <vec3> vtx = obj.objects[i].getModel()->meshes[j].vertex;

                for(int k=0; k<obj.objects[i].getModel()->meshes[j].faces.size(); k++)//plaszczyzny
                {
                    uint8_t q_or_t;//quady czy trojkoty
                    if(obj.wireframe || k<obj.objects[i].getModel()->meshes[j].wireframe)
                    {
                        glDisable(GL_LIGHTING);
                        q_or_t=GL_LINES;
                    }
                    else if(obj.objects[i].getModel()->meshes[j].faces[k].face.size()==3)
                    {
                        glEnable(GL_LIGHTING);
                        q_or_t=GL_TRIANGLES;
                    }
                    else if(obj.objects[i].getModel()->meshes[j].faces[k].face.size()==4)
                    {
                        glEnable(GL_LIGHTING);
                        q_or_t=GL_QUADS;
                    }
                    else
                    {
                        q_or_t=GL_POLYGON;
                    }
                    if(q_or_t!=NULL)
                    {
                        obj.test=false;

                        glBegin(q_or_t);
                        glNormal3f(obj.objects[i].getModel()->meshes[j].normal[k].x,
                                   obj.objects[i].getModel()->meshes[j].normal[k].y,
                                   obj.objects[i].getModel()->meshes[j].normal[k].z);
                        for(int l=0; l<obj.objects[i].getModel()->meshes[j].faces[k].face.size(); l++)
                        {
                            vec2 crd = obj.objects[i].getModel()->meshes[j].faces[k].face[l].cord;
                            glVertex3f(vtx[crd.x-1].x, vtx[crd.x-1].y, vtx[crd.x-1].z);
                        }
                        glEnd();
                    }
                }

            }
            glTranslatef(-obj.objects[i].getX(), -obj.objects[i].getY(), -obj.objects[i].getZ());
        }

        //display();

        SDL_GL_SwapWindow(obj.window);//odswiezanie okna
        glFlush();
    }
}

