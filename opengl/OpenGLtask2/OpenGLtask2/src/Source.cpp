#include <gl\glut.h>

using namespace std;

int WinWidth = 640;		// Ширина вікна
int WinHeight = 640;		// Висота вікна

GLfloat  rx = 0;			// Кут поворту сцени навколо осі X
GLfloat  ry = 0;			// Кут поворту сцени навколо осі Y
GLfloat  tx = 0;			// Зсув по осі X
GLfloat	 ty = 0;		// Зсув по осі Y
GLfloat	 tz = 0;		// Зсув по осі Z
GLint	 tt = 0;			// Активна площина: 0 - XY, 1 - XZ
GLint spin1 = 0;    // Кут поворту лампи навколо осі X 
GLint spin2 = 0;    // Кут поворту лампи навколо осі Y
GLfloat light0_position[] = { 0.0, 0.0, 2.5, 1.0 }; // Позиція лампи
GLfloat light1_position[] = { -2.5, 0.0, 2.5, 1.0 };

int mx, my;				// Координати миші
bool ldown = false;		// Нажата ліва клавіша миші?
bool rdown = false;		// Нажата права клавіша миші?

GLuint list = 0;

void Init()				// Ініціалізація OpenGL
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_LINE_SMOOTH);
	//glClearColor(0.9, 0.9, 0.6, 1.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_DEPTH_TEST);


	GLfloat lightOneColor[] = {0.5, 0.2, 0.9, 1.0};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightOneColor);


	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightOneColor);

	//glDisable(GL_LIGHTING);

}

void MySolid()
{
	//boxside+
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glVertex3f(-1.5, 0.0, -1.5);
	glVertex3f(1.5, 0.0, -1.5);
	glVertex3f(1.5, -1.0, -1.5);
	glVertex3f(-1.5, -1.0, -1.5);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(-1.5, -1.0, 1.5);
	glVertex3f(1.5, -1.0, 1.5);
	glVertex3f(1.5, 0.0, 1.5);
	glVertex3f(-1.5, 0.0, 1.5);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glNormal3f(0, -1, 0);
	glVertex3f(-1.5, -1.0, 1.5);
	glVertex3f(-1.5, -1.0, -1.5);
	glVertex3f(1.5, -1.0, -1.5);
	glVertex3f(1.5, -1.0, 1.5);
	glEnd();

	glColor3f(1.0, 0.5, 0.5);
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glVertex3f(-1.5, -1.0, -1.5);
	glVertex3f(-1.5, -1.0, 1.5);
	glVertex3f(-1.5, 0.0, 1.5);
	glVertex3f(-1.5, 0.0, -1.5);
	glEnd();

	glColor3f(0.5, 1.0, 0.5);
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glVertex3f(1.5, -1.0, -1.5);
	glVertex3f(1.5, 0.0, -1.5);
	glVertex3f(1.5, 0.0, 1.5);
	glVertex3f(1.5, -1.0, 1.5);
	glEnd();
	//boxup+
	glColor3f(0.5, 0.5, 1.0);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-1.5, 0.0, 1.5);
	glVertex3f(-0.17, 0.0, 1.5);
	glVertex3f(-0.17, 0.0, -1.5);
	glVertex3f(-1.5, 0.0, -1.5);
	glEnd();

	glColor3f(0.5, 0.0, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(1.5, 0.0, 1.5);
	glVertex3f(1.5, 0.0, -1.5);
	glVertex3f(0.17, 0.0, -1.5);
	glVertex3f(0.17, 0.0, 1.5);
	glEnd();

	glColor3f(0.5, 0.8, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-0.17, 0.0, 0.17);
	glVertex3f(-0.17, 0.0, 1.5);
	glVertex3f(0.17, 0.0, 1.5);
	glVertex3f(0.17, 0.0, 0.17);
	glEnd();

	glColor3f(0.9, 0.0, 0.3);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-0.17, 0.0, -1.5);
	glVertex3f(-0.17, 0.0, -0.17);
	glVertex3f(0.17, 0.0, -0.17);
	glVertex3f(0.17, 0.0, -1.5);
	glEnd();
	//sixside
	glColor3f(0.0, 0.5, 0.8);
	glBegin(GL_QUADS);
	glNormal3f(0.5, 0, 0.75);
	glVertex3f(-1.0, 0.0, 0.75);
	glVertex3f(0.0, 0.0, 1.3);
	glVertex3f(0.0, 1.0, 1.3);
	glVertex3f(-1.0, 1.0, 0.75);
	glEnd();

	glColor3f(0.4, 0.1, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(-0.5, 0, 0.75);
	glVertex3f(0.0, 0.0, 1.3);
	glVertex3f(1.0, 0.0, 0.75);
	glVertex3f(1.0, 1.0, 0.75);
	glVertex3f(0.0, 1.0, 1.3);
	glEnd();

	glColor3f(0.0, 0.9, 1.0);
	glBegin(GL_QUADS);
	glNormal3f(0.5, 0, -0.75);
	glVertex3f(-1.0, 1.0, -0.75);
	glVertex3f(0.0, 1.0, -1.3);
	glVertex3f(0.0, 0.0, -1.3);
	glVertex3f(-1.0, 0.0, -0.75);
	glEnd();

	glColor3f(1.0, 0.1, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(-0.5, 0, -0.75);
	glVertex3f(0.0, 1.0, -1.3);
	glVertex3f(1.0, 1.0, -0.75);
	glVertex3f(1.0, 0.0, -0.75);
	glVertex3f(0.0, 0.0, -1.3);
	glEnd();

	glColor3f(1.0, 0.9, 0.2);
	glBegin(GL_QUADS);
	glNormal3f(-1, 0, 0);
	glVertex3f(-1.0, 0.0, -0.75);
	glVertex3f(-1.0, 0.0, 0.75);
	glVertex3f(-1.0, 1.0, 0.75);
	glVertex3f(-1.0, 1.0, -0.75);
	glEnd();

	glColor3f(0.1, 1.0, 0.6);
	glBegin(GL_QUADS);
	glNormal3f(1, 0, 0);
	glVertex3f(1.0, 0.0, -0.75);
	glVertex3f(1.0, 1.0, -0.75);
	glVertex3f(1.0, 1.0, 0.75);
	glVertex3f(1.0, 0.0, 0.75);
	glEnd();
	//sixup
	glColor3f(1.0, 0.4, 0.0);
	glBegin(GL_TRIANGLES);
	glNormal3f(0, 1, 0);
	glVertex3f(-1.0, 1.0, -0.75);
	glVertex3f(1.0, 1.0, -0.75);
	glVertex3f(0.0, 1.0, -1.3);
	glEnd();

	glColor3f(0.1, 0.4, 0.2);
	glBegin(GL_TRIANGLES);
	glNormal3f(0, 1, 0);
	glVertex3f(-1.0, 1.0, 0.75);
	glVertex3f(0.0, 1.0, 1.3);
	glVertex3f(1.0, 1.0, 0.75);
	glEnd();

	glColor3f(0.0, 0.1, 0.2);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-1.0, 1.0, -0.5);
	glVertex3f(-1.0, 1.0, 0.5);
	glVertex3f(-0.5, 1.0, 0.5);
	glVertex3f(-0.5, 1.0, -0.5);
	glEnd();

	glColor3f(0.9, 0.1, 0.2);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(1.0, 1.0, -0.5);
	glVertex3f(0.5, 1.0, -0.5);
	glVertex3f(0.5, 1.0, 0.5);
	glVertex3f(1.0, 1.0, 0.5);
	glEnd();

	glColor3f(0.4, 0.4, 0.2);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-1.0, 1.0, -0.75);
	glVertex3f(-1.0, 1.0, -0.5);
	glVertex3f(1.0, 1.0, -0.5);
	glVertex3f(1.0, 1.0, -0.75);
	glEnd();

	glColor3f(0.4, 0.0, 0.7);
	glBegin(GL_QUADS);
	glNormal3f(0, 1, 0);
	glVertex3f(-1.0, 1.0, 0.75);
	glVertex3f(1.0, 1.0, 0.75);
	glVertex3f(1.0, 1.0, 0.5);
	glVertex3f(-1.0, 1.0, 0.5);
	glEnd();
	//piramida
	glColor3f(0.8, 0.4, 0.0);
	glBegin(GL_TRIANGLES);
	glNormal3f(-0.5, 0.75, 0);
	glVertex3f(-0.5, 1.0, 0.5);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(-0.5, 1.0, -0.5);
	glEnd();

	glColor3f(0.3, 0.9, 0.0);
	glBegin(GL_TRIANGLES);
	glNormal3f(0.5, 0.75, 0);
	glVertex3f(0.5, 1.0, -0.5);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(0.5, 1.0, 0.5);
	glEnd();
	
	glColor3f(0.3, 0.1, 0.4);
	glBegin(GL_TRIANGLES);
	glNormal3f(0, 0.75, -0.5);
	glVertex3f(0.5, 1.0, 0.5);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(-0.5, 1.0, 0.5);
	glEnd();

	glColor3f(0.1, 0.1, 0.5);
	glBegin(GL_TRIANGLES);
	glNormal3f(0, 0.75, 0.5);
	glVertex3f(-0.5, 1.0, -0.5);
	glVertex3f(0.0, -0.5, 0.0);
	glVertex3f(0.5, 1.0, -0.5);
	glEnd();
}
void Display()			// Зміст екрану
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//	glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_LINE);

	glPushMatrix();
	glTranslatef(tx, ty, tz);		//Зміщення об'єкта
	glRotatef(rx, 1, 0, 0);         //Поворот об'єкта
	glRotatef(ry, 0, 1, 0);

	//Вивід об'єкта на екран

// Колір осі X
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);

	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(3.0, 0.0, 0.0);
	glEnd();

	// Колір осі Y
	glColor3f(0.0, 0.8, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 3.0, 0.0);
	glEnd();

	// Колір осі Z
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 3.0);
	glEnd();

	MySolid();

	glPopMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);
	glLightfv(GL_LIGHT1, GL_POSITION, light1_position);


	glPushMatrix();
	glRotated((GLdouble)spin1, 1.0, 0.0, 1.0);
	glRotated((GLdouble)spin2, 0.0, 1.0, 0.0);
	glLightfv(GL_LIGHT0, GL_POSITION, light0_position);

	glTranslated(light0_position[0], light0_position[1], -light0_position[2]);
	glColor3f(0.2, 0.5, 0.5);
	glutWireCube(0.04);
	glPopMatrix();
	glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y)			//Обробка повідомлень від клавіатури
{
	switch (key)
	{
	case VK_ESCAPE:		//Якщо нажата клавіша ESC - вихід
		exit(0);
		break;
	}
}

void KeyboardSpecial(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{spin1 = (spin1 + 10) % 360;
	glutPostRedisplay(); }
	break;
	case GLUT_KEY_DOWN:
	{spin1 = (spin1 - 10) % 360;
	glutPostRedisplay(); }
	break;
	case GLUT_KEY_LEFT:
	{spin2 = (spin2 - 10) % 360;
	glutPostRedisplay(); }
	break;
	case GLUT_KEY_RIGHT:
	{spin2 = (spin2 + 10) % 360;
	glutPostRedisplay(); }
	break;
	case GLUT_KEY_F1:	//Якщо нажата клавіша F1
	{
		tt = (tt + 1) % 2;	//Зміна площини зміщення
	}

	}
}

void Reshape(int Width, int Height)		//Обробка зміни розмірів вікна
{
	glViewport(0, 0, Width, Height);
	WinWidth = Width;					//Запамятати нові розміри
	WinHeight = Height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);

	//	gluPerspective(45,GLdouble(WinWidth)/WinHeight,1,100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)		//Обробка повідомлень від  миші
{
	if (button == GLUT_LEFT_BUTTON)		//Ліва кнопка
	{
		switch (state)
		{
		case GLUT_DOWN:		//Якщо нажата
			ldown = true;		    //Встановити флаг
			mx = x;			        //Запамятати координати
			my = y;
			break;
		case GLUT_UP:
			ldown = false;
			break;
		}
	}
	if (button == GLUT_RIGHT_BUTTON)	//Права кнопка
	{
		switch (state)
		{
		case GLUT_DOWN:    //Якщо нажата
			rdown = true;         //Встановити флаг
			mx = x;                 //Запамятати координати
			my = y;
			break;
		case GLUT_UP:
			rdown = false;
			break;
		}
	}
}

void MouseMotion(int x, int y)	//Переміщення миші
{
	if (ldown)		//Ліва кнопка
	{
		rx += 0.5 * (y - my);	//Зміна кута повороту
		ry += 0.5 * (x - mx);
		mx = x;
		my = y;
		glutPostRedisplay();	//Перерисувати екран
	}
	if (rdown)	    //Права кнопка
	{
		tx += 0.01 * (x - mx);	//Переміщення вздовж активної площини
		if (tt)
			tz += 0.01 * (y - my);
		else
			ty += 0.01 * (my - y);
		mx = x;
		my = y;
		glutPostRedisplay();      //Перерисувати екран
	}
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WinWidth, WinHeight);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - WinWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - WinHeight) / 2);
	glutCreateWindow("MySolid");

	Init();

	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(KeyboardSpecial);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMotion);

	glutMainLoop();

	return 0;
}