#include <gl\glut.h>

using namespace std;

int WinWidth = 640;		// ������ ����
int WinHeight = 640;		// ������ ����

GLfloat  rx = 0;			// ��� ������� ����� ������� �� X
GLfloat  ry = 0;			// ��� ������� ����� ������� �� Y
GLfloat  tx = 0;			// ���� �� �� X
GLfloat	 ty = 0;		// ���� �� �� Y
GLfloat	 tz = 0;		// ���� �� �� Z
GLint	 tt = 0;			// ������� �������: 0 - XY, 1 - XZ
GLint spin1 = 0;    // ��� ������� ����� ������� �� X 
GLint spin2 = 0;    // ��� ������� ����� ������� �� Y
GLfloat light0_position[] = { 0.0, 0.0, 2.5, 1.0 }; // ������� �����
GLfloat light1_position[] = { -2.5, 0.0, 2.5, 1.0 };

int mx, my;				// ���������� ����
bool ldown = false;		// ������ ��� ������ ����?
bool rdown = false;		// ������ ����� ������ ����?

GLuint list = 0;

void Init()				// ����������� OpenGL
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
void Display()			// ���� ������
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//	glPolygonMode(GL_FRONT, GL_FILL);
		glPolygonMode(GL_BACK, GL_LINE);

	glPushMatrix();
	glTranslatef(tx, ty, tz);		//������� ��'����
	glRotatef(rx, 1, 0, 0);         //������� ��'����
	glRotatef(ry, 0, 1, 0);

	//���� ��'���� �� �����

// ���� �� X
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);

	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(3.0, 0.0, 0.0);
	glEnd();

	// ���� �� Y
	glColor3f(0.0, 0.8, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 3.0, 0.0);
	glEnd();

	// ���� �� Z
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

void Keyboard(unsigned char key, int x, int y)			//������� ���������� �� ���������
{
	switch (key)
	{
	case VK_ESCAPE:		//���� ������ ������ ESC - �����
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
	case GLUT_KEY_F1:	//���� ������ ������ F1
	{
		tt = (tt + 1) % 2;	//���� ������� �������
	}

	}
}

void Reshape(int Width, int Height)		//������� ���� ������ ����
{
	glViewport(0, 0, Width, Height);
	WinWidth = Width;					//���������� ��� ������
	WinHeight = Height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);

	//	gluPerspective(45,GLdouble(WinWidth)/WinHeight,1,100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)		//������� ���������� ��  ����
{
	if (button == GLUT_LEFT_BUTTON)		//˳�� ������
	{
		switch (state)
		{
		case GLUT_DOWN:		//���� ������
			ldown = true;		    //���������� ����
			mx = x;			        //���������� ����������
			my = y;
			break;
		case GLUT_UP:
			ldown = false;
			break;
		}
	}
	if (button == GLUT_RIGHT_BUTTON)	//����� ������
	{
		switch (state)
		{
		case GLUT_DOWN:    //���� ������
			rdown = true;         //���������� ����
			mx = x;                 //���������� ����������
			my = y;
			break;
		case GLUT_UP:
			rdown = false;
			break;
		}
	}
}

void MouseMotion(int x, int y)	//���������� ����
{
	if (ldown)		//˳�� ������
	{
		rx += 0.5 * (y - my);	//���� ���� ��������
		ry += 0.5 * (x - mx);
		mx = x;
		my = y;
		glutPostRedisplay();	//������������ �����
	}
	if (rdown)	    //����� ������
	{
		tx += 0.01 * (x - mx);	//���������� ������ ������� �������
		if (tt)
			tz += 0.01 * (y - my);
		else
			ty += 0.01 * (my - y);
		mx = x;
		my = y;
		glutPostRedisplay();      //������������ �����
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