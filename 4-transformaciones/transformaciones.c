

#include <GL/glut.h>
 #include <math.h> 
GLfloat anguloCuboX = 0.0f;
GLfloat anguloCuboY = 0.0f;
int anguloEsferax = 0.0f;
int anguloEsferay = 0.0f;
int anguloEsferaz = 0.0f;
GLfloat esferax = 0.0f;
GLfloat esferay = 0.0f;
GLfloat esferaz = -5.0f;

GLint ancho=400;

GLint alto=400;
 
int hazPerspectiva = 0;
 
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    if(hazPerspectiva)
     gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 20.0f);
    else

      glOrtho(-4,4, -4, 4, 1, 10);

    glMatrixMode(GL_MODELVIEW);
 
    ancho = width;
    alto = height;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*hombro*/
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef((GLfloat)anguloEsferax, 1.0f, 0.0f, 0.0f);
    glRotatef((GLfloat)anguloEsferay, 0.0f, 1.0f, 0.0f);
    glRotatef((GLfloat)anguloEsferaz, 0.0f, 0.0f, 1.0f);
    glPushMatrix();
    glutWireSphere(0.5f, 8, 8);
    glPopMatrix();
    /*brazo*/
    
    glTranslatef(0.0f,-1.0f,0.0f);
    glPushMatrix();
    glutSolidCube(1.0f);
    glPopMatrix();

        /*codo*/
    glTranslatef(0.0f, -1.0f, 0.0f);
    glPushMatrix();
    glutWireSphere(0.5f, 8, 8);    
    glPopMatrix();
   
    /*antebrazo*/
    glTranslatef(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glutSolidCube(1.0f);
    glPopMatrix();


    /*mano*/
    glTranslatef(1.0f, 0.0f, 0.0f);
    glPushMatrix();
    glutWireSphere(0.5f, 8, 8);
    glPopMatrix();

    glFlush();
    glPopMatrix();
    glutSwapBuffers();

}

void init()
{
    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    ancho = 400;
    alto = 400;
}
 

void idle()
{
    display();
}

 
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'p':
    case 'P':
      hazPerspectiva=1;
      reshape(ancho,alto);
      break;
 
    case 'o':
    case 'O':
      hazPerspectiva=0;
      reshape(ancho,alto);
      break;
    //EJE X
    case 'q':
    case 'Q':
    anguloEsferax=(anguloEsferax+5)%360;
      break;
    case 'a':
    case 'A':
    anguloEsferax=(anguloEsferax-5)%360;
      break;
    //eje Y
    case 'w':
    case 'W':
        anguloEsferay=(anguloEsferay+5)%360;
      break;
    case 'S':
    case 's':
        anguloEsferay=(anguloEsferay-5)%360;
      break;
    case 'e':
    case 'E':
        anguloEsferaz=(anguloEsferaz+5)%360;
      break;
    case 'd':
    case 'D':
        anguloEsferaz=(anguloEsferaz-5)%360;
      break;	
    case 27:   // escape
      exit(0);
      break;
    }
}
 
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ancho, alto);
    glutCreateWindow("Cubo 1");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}


