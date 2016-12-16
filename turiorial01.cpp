#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#include <iostream>

using std::cout;
using std::endl;

bool init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glClearColor(0.0f,0.0f,0.0f,0.0f);
    GLenum error = glGetError();
    if(error != GL_NO_ERROR)
    {
        cout << "some error happened when init" << endl;
        return false;
    }
    return true;
}

void render()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glVertex2f(-0.5f,-0.5f);
        glVertex2f(0.5f,-0.5f);
        glVertex2f(0.5f,0.5f);
        glVertex2f(-0.5f,0.5f);
    glEnd();

    glutSwapBuffers();
}

void Loop(int internal)
{
    render();
}

int main(int argc,char* argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(300,300);
    glutCreateWindow("Test");
    init();
    glutDisplayFunc(render);
    glutTimerFunc(1000/60,Loop,0);
    glutMainLoop();
    return 0;
}
