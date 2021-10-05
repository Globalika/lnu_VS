#include <gl/glut.h>
void display(void)
{
    /* clear all pixels  */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    //
    glColor3f(0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(1.0, 6.0, 0.0);
    glVertex3f(2.0, 5.0, 0.0);
    glVertex3f(2.0, 12.0, 0.0);
    glVertex3f(1.0, 11.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.5, 0.25);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 5.0, 0.0);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(4.0, 5.0, 0.0);
    glVertex3f(2.0, 6.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(4.0, 4.0, 0.0);
    glVertex3f(5.0, 5.0, 0.0);
    glVertex3f(5.0, 6.0, 0.0);
    glVertex3f(4.0, 5.0, 0.0);
    glEnd();

    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(2.0, 11.0, 0.0);
    glVertex3f(4.0, 12.0, 0.0);
    glVertex3f(4.0, 13.0, 0.0);
    glVertex3f(2.0, 12.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.5, 0.25);
    glBegin(GL_QUADS);
    glVertex3f(4.0, 12.0, 0.0);
    glVertex3f(5.0, 11.0, 0.0);
    glVertex3f(5.0, 12.0, 0.0);
    glVertex3f(4.0, 13.0, 0.0);
    glEnd();
    //
    glColor3f(0.5, 1.0, 0.5);
    glBegin(GL_QUADS);
    glVertex3f(6.0, 5.0, 0.0);
    glVertex3f(8.0, 4.0, 0.0);
    glVertex3f(9.0, 4.5, 0.0);
    glVertex3f(7.0, 6.0, 0.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(6.0, 5.0, 0.0);
    glVertex3f(7.0, 6.0, 0.0);
    glVertex3f(7.0, 9.0, 0.0);
    glVertex3f(6.0, 8.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.5, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 8.0, 0.0);
    glVertex3f(8.0, 8.0, 0.0);
    glVertex3f(8.0, 9.0, 0.0);
    glVertex3f(7.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.5, 0.6, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(8.0, 9.0, 0.0);
    glVertex3f(8.0, 7.0, 0.0);
    glVertex3f(9.0, 7.0, 0.0);
    glVertex3f(8.5, 9.0, 0.0);
    glEnd();

    glColor3f(0.1, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(7.0, 7.0, 0.0);
    glVertex3f(7.0, 6.0, 0.0);
    glVertex3f(8.0, 6.0, 0.0);
    glVertex3f(9.0, 7.0, 0.0);
    glEnd();
    //
    glColor3f(0.0, 0.6, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 1.0, 0.0);
    glVertex3f(11.0, 2.0, 0.0);
    glVertex3f(11.0, 8.0, 0.0);
    glVertex3f(10.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.5, 0.5, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(10.0, 9.0, 0.0);
    glVertex3f(11.0, 8.0, 0.0);
    glVertex3f(14.0, 8.0, 0.0);
    glVertex3f(13.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.6);
    glBegin(GL_QUADS);
    glVertex3f(13.0, 8.0, 0.0);
    glVertex3f(13.0, 6.0, 0.0);
    glVertex3f(14.0, 5.5, 0.0);
    glVertex3f(14.0, 8.0, 0.0);
    glEnd();

    glColor3f(0.1, 0.9, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(11.0, 6.0, 0.0);
    glVertex3f(11.0, 5.5, 0.0);
    glVertex3f(14.0, 5.5, 0.0);
    glVertex3f(13.0, 6.0, 0.0);
    glEnd();
    //
    glColor3f(0.5, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(15.0, 5.0, 0.0);
    glVertex3f(17.0, 4.0, 0.0);
    glVertex3f(18.0, 4.5, 0.0);
    glVertex3f(16.0, 6.0, 0.0);
    glEnd();

    glColor3f(0.5, 0.2, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(15.0, 5.0, 0.0);
    glVertex3f(16.0, 6.0, 0.0);
    glVertex3f(16.0, 9.0, 0.0);
    glVertex3f(15.0, 8.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.2);
    glBegin(GL_QUADS);
    glVertex3f(16.0, 8.0, 0.0);
    glVertex3f(17.0, 8.0, 0.0);
    glVertex3f(17.0, 9.0, 0.0);
    glVertex3f(16.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.5, 0.9, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(17.0, 9.0, 0.0);
    glVertex3f(17.0, 7.0, 0.0);
    glVertex3f(18.0, 7.0, 0.0);
    glVertex3f(17.5, 9.0, 0.0);
    glEnd();

    glColor3f(0.1, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(16.0, 7.0, 0.0);
    glVertex3f(16.0, 6.0, 0.0);
    glVertex3f(17.0, 6.0, 0.0);
    glVertex3f(18.0, 7.0, 0.0);
    glEnd();
    //
    glColor3f(0.1, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(20.0, 7.0, 0.0);
    glVertex3f(21.0, 7.0, 0.0);
    glVertex3f(23.0, 8.0, 0.0);
    glVertex3f(23.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.1, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(23.0, 9.0, 0.0);
    glVertex3f(23.0, 8.0, 0.0);
    glVertex3f(25.0, 7.0, 0.0);
    glVertex3f(26.0, 7.0, 0.0);
    glEnd();

    glColor3f(0.1, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(19.0, 7.0, 0.0);
    glVertex3f(20.5, 6.5, 0.0);
    glVertex3f(25.5, 6.5, 0.0);
    glVertex3f(27.0, 7.0, 0.0);
    glEnd();

    glColor3f(0.7, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(20.5, 6.5, 0.0);
    glVertex3f(20.5, 4.0, 0.0);
    glVertex3f(21.5, 5.0, 0.0);
    glVertex3f(21.5, 6.5, 0.0);
    glEnd();

    glColor3f(0.0, 0.6, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(24.5, 6.5, 0.0);
    glVertex3f(24.5, 5.0, 0.0);
    glVertex3f(25.5, 4.0, 0.0);
    glVertex3f(25.5, 6.5, 0.0);
    glEnd();
    //
    glColor3f(0.0, 0.6, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(28.0, 8.5, 0.0);
    glVertex3f(29.0, 9.0, 0.0);
    glVertex3f(32.0, 9.0, 0.0);
    glVertex3f(33.0, 8.5, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(28.0, 8.5, 0.0);
    glVertex3f(28.0, 4.5, 0.0);
    glVertex3f(29.0, 4.0, 0.0);
    glVertex3f(29.0, 8.5, 0.0);
    glEnd();

    glColor3f(0.3, 0.6, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(29.0, 4.0, 0.0);
    glVertex3f(32.0, 4.0, 0.0);
    glVertex3f(32.0, 4.5, 0.0);
    glVertex3f(29.0, 4.5, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(32.0, 8.5, 0.0);
    glVertex3f(32.0, 4.0, 0.0);
    glVertex3f(33.0, 4.5, 0.0);
    glVertex3f(33.0, 8.5, 0.0);
    glEnd();
    //
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(34.0, 5.0, 0.0);
    glVertex3f(35.0, 4.0, 0.0);
    glVertex3f(35.0, 9.0, 0.0);
    glVertex3f(34.0, 8.0, 0.0);
    glEnd();

    glColor3f(0.4, 0.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(35.0, 4.5, 0.0);
    glVertex3f(35.0, 4.0, 0.0);
    glVertex3f(37.0, 4.0, 0.0);
    glVertex3f(38.0, 4.5, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(35.0, 9.0, 0.0);
    glVertex3f(35.0, 8.5, 0.0);
    glVertex3f(38.0, 8.5, 0.0);
    glVertex3f(37.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(35.0, 7.0, 0.0);
    glVertex3f(35.0, 6.0, 0.0);
    glVertex3f(37.0, 6.0, 0.0);
    glVertex3f(37.0, 7.0, 0.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(37.0, 8.5, 0.0);
    glVertex3f(37.0, 7.0, 0.0);
    glVertex3f(38.0, 8.0, 0.0);
    glVertex3f(38.0, 8.5, 0.0);
    glEnd();

    glColor3f(0.3, 0.0, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(37.0, 6.0, 0.0);
    glVertex3f(37.0, 4.5, 0.0);
    glVertex3f(38.0, 4.5, 0.0);
    glVertex3f(38.0, 5.0, 0.0);
    glEnd();
    //
    glColor3f(0.0, 0.4, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(39.0, 9.0, 0.0);
    glVertex3f(39.0, 4.0, 0.0);
    glVertex3f(40.0, 4.0, 0.0);
    glVertex3f(40.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.8, 0.6, 0.1);
    glBegin(GL_QUADS);
    glVertex3f(42.0, 9.0, 0.0);
    glVertex3f(42.0, 4.0, 0.0);
    glVertex3f(43.0, 4.0, 0.0);
    glVertex3f(43.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.7, 0.9, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(40.0, 5.0, 0.0);
    glVertex3f(40.0, 4.0, 0.0);
    glVertex3f(42.0, 8.0, 0.0);
    glVertex3f(42.0, 9.0, 0.0);
    glEnd();
    
    glColor3f(0.7, 0.9, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(44.0, 9.0, 0.0);
    glVertex3f(44.0, 7.0, 0.0);
    glVertex3f(45.0, 6.0, 0.0);
    glVertex3f(45.0, 9.0, 0.0);
    glEnd();

    glColor3f(0.7, 0.0, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(47.0, 9.0, 0.0);
    glVertex3f(47.0, 4.0, 0.0);
    glVertex3f(48.0, 4.0, 0.0);
    glVertex3f(48.0, 9.0, 0.0);
    glEnd();

    glColor3f(1.0, 0.0, 0.4);
    glBegin(GL_QUADS);
    glVertex3f(45.0, 7.0, 0.0);
    glVertex3f(45.0, 6.0, 0.0);
    glVertex3f(47.0, 6.0, 0.0);
    glVertex3f(47.0, 7.0, 0.0);
    glEnd();

    glFlush();
}

void init(void)
{
    /* select clearing color 	*/
    glClearColor(1.0, 1.0, 1.0, 1.0);

    /* initialize viewing values  */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 50.0, 0.0, 15.0, -1.0, 1.0);
}

static void
key(unsigned char k, int x, int y)
{
    switch (k) {
    case 27:  /* Escape */
        exit(0);
        break;
    default:
        return;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 500);
    glutInitWindowPosition(300, 200);
    glutCreateWindow("hello");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();
    return 0;
}
