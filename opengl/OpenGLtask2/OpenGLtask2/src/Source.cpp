#include <gl\glut.h>

using namespace std;

int WinWidth = 640;		// Øèðèíà â³êíà
int WinHeight = 640;		// Âèñîòà â³êíà

GLfloat  rx = 0;			// Êóò ïîâîðòó ñöåíè íàâêîëî îñ³ X
GLfloat  ry = 0;			// Êóò ïîâîðòó ñöåíè íàâêîëî îñ³ Y
GLfloat  tx = 0;			// Çñóâ ïî îñ³ X
GLfloat	 ty = 0;		// Çñóâ ïî îñ³ Y
GLfloat	 tz = 0;		// Çñóâ ïî îñ³ Z
GLint	 tt = 0;			// Àêòèâíà ïëîùèíà: 0 - XY, 1 - XZ
GLint spin1 = 0;    // Êóò ïîâîðòó ëàìïè íàâêîëî îñ³ X 
GLint spin2 = 0;    // Êóò ïîâîðòó ëàìïè íàâêîëî îñ³ Y
GLfloat light0_position[] = { 0.0, 0.0, 2.5, 1.0 }; // Ïîçèö³ÿ ëàìïè

int mx, my;				// Êîîðäèíàòè ìèø³
bool ldown = false;		// Íàæàòà ë³âà êëàâ³øà ìèø³?
bool rdown = false;		// Íàæàòà ïðàâà êëàâ³øà ìèø³?

GLuint list = 0;

void Init()				// ²í³ö³àë³çàö³ÿ OpenGL
{
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glClearDepth(1.0f);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glEnable(GL_LINE_SMOOTH);

	glEnable(GL_STENCIL_TEST);

	glEnable(GL_CULL_FACE);

	glClearColor(0.9, 0.9, 0.6, 1);

}

//int angle = 0;
void MySolid()
{
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0.3, -0.5, 0.5);
	glRotatef(100, 1, 1, 0);
	glutSolidCube(0.35);
	glPopMatrix();
	//boxside+
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, -1);
	glVertex3f(-1.5, 0.0, -1.5);
	glVertex3f(1.5, 0.0, -1.5);
	glVertex3f(1.5, -1.0, -1.5);
	glVertex3f(-1.5, -1.0, -1.5);
	glEnd();
	///////////////////////////////////////////////////////////////////
	glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	glDepthMask(GL_FALSE);
	//glCullFace(GL_FRONT_AND_BACK);
	////trafa
	glStencilFunc(GL_ALWAYS, 1, ~0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(-1.1, -0.8, 1.5);
	glVertex3f(1.1, -0.8, 1.5);
	glVertex3f(1.1, -0.2, 1.5);
	glVertex3f(-1.1, -0.2, 1.5);
	glEnd();
	//glCullFace(GL_FRONT);
	glCullFace(GL_BACK);
	//////
	glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
	glDepthMask(GL_TRUE);

	////side
	glStencilFunc(GL_NOTEQUAL, 1, ~0);
	glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glNormal3f(0, 0, 1);
	glVertex3f(-1.5, -1.0, 1.5);
	glVertex3f(1.5, -1.0, 1.5);
	glVertex3f(1.5, 0.0, 1.5);
	glVertex3f(-1.5, 0.0, 1.5);
	glEnd();
	// 
	// 
	// 
	// 
	// 
	///////////////////////////////////////////////////////////////////////////////////
	////444
	//glColor3f(1.0, 1.0, 1.0);
	//glBegin(GL_QUADS);
	//glNormal3f(0, 0, 1);
	//glVertex3f(-1.5, -1.0, 1.5);
	//glVertex3f(-1.1, -1.0, 1.5);
	//glVertex3f(-1.1, 0.0, 1.5);
	//glVertex3f(-1.5, 0.0, 1.5);
	//glEnd();

	//glColor3f(1.0, 1.0, 1.0);
	//glBegin(GL_QUADS);
	//glNormal3f(0, 0, 1);
	//glVertex3f(1.1, -1.0, 1.5);
	//glVertex3f(1.5, -1.0, 1.5);
	//glVertex3f(1.5, 0.0, 1.5);
	//glVertex3f(1.1, 0.0, 1.5);
	//glEnd();

	//glColor3f(1.0, 1.0, 1.0);
	//glBegin(GL_QUADS);
	//glNormal3f(0, 0, 1);
	//glVertex3f(-1.1, -1.0, 1.5);
	//glVertex3f(1.1, -1.0, 1.5);
	//glVertex3f(1.1, -0.8, 1.5);
	//glVertex3f(-1.1, -0.8, 1.5);
	//glEnd();

	//glColor3f(1.0, 1.0, 1.0);
	//glBegin(GL_QUADS);
	//glNormal3f(0, 0, 1);
	//glVertex3f(-1.1, -0.2, 1.5);
	//glVertex3f(1.1, -0.2, 1.5);
	//glVertex3f(1.1, 0.0, 1.5);
	//glVertex3f(-1.1, 0.0, 1.5);
	//glEnd();

	//glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
	//glDepthMask(GL_FALSE);
	//////////////////////////////////////////////////////////////////////////
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
void Display()			// Çì³ñò åêðàíó
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT| GL_STENCIL_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//	glPolygonMode(GL_FRONT, GL_FILL);
	//	glPolygonMode(GL_BACK, GL_LINE);


	glPushMatrix();
	glTranslatef(tx, ty, tz);		//Çì³ùåííÿ îá'ºêòà
	glRotatef(rx, 1, 0, 0);         //Ïîâîðîò îá'ºêòà
	glRotatef(ry, 0, 1, 0);

	//Âèâ³ä îá'ºêòà íà åêðàí

// Êîë³ð îñ³ X
	glColor3f(1.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);

	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(3.0, 0.0, 0.0);
	glEnd();

	// Êîë³ð îñ³ Y
	glColor3f(0.0, 0.8, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 3.0, 0.0);
	glEnd();

	// Êîë³ð îñ³ Z
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 3.0);
	glEnd();

	MySolid();

	glPopMatrix();

	glPushMatrix();
	glRotated((GLdouble)spin1, 1.0, 0.0, 1.0);
	glRotated((GLdouble)spin2, 0.0, 1.0, 0.0);
	glTranslated(light0_position[0], light0_position[1], -light0_position[2]);
	glColor3f(0.2, 0.5, 0.5);
	//glutWireCube(0.04);
	glutSolidCube(0.2);
	glPopMatrix();
	glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y)			//Îáðîáêà ïîâ³äîìëåíü â³ä êëàâ³àòóðè
{
	switch (key)
	{
	case VK_ESCAPE:		//ßêùî íàæàòà êëàâ³øà ESC - âèõ³ä
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
	case GLUT_KEY_F1:	//ßêùî íàæàòà êëàâ³øà F1
	{
		tt = (tt + 1) % 2;	//Çì³íà ïëîùèíè çì³ùåííÿ
	}

	}
}

void Reshape(int Width, int Height)		//Îáðîáêà çì³íè ðîçì³ð³â â³êíà
{
	glViewport(0, 0, Width, Height);
	WinWidth = Width;					//Çàïàìÿòàòè íîâ³ ðîçì³ðè
	WinHeight = Height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0, 3.0, -3.0, 3.0, -10.0, 10.0);

	//	gluPerspective(45,GLdouble(WinWidth)/WinHeight,1,100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)		//Îáðîáêà ïîâ³äîìëåíü â³ä  ìèø³
{
	if (button == GLUT_LEFT_BUTTON)		//Ë³âà êíîïêà
	{
		switch (state)
		{
		case GLUT_DOWN:		//ßêùî íàæàòà
			ldown = true;		    //Âñòàíîâèòè ôëàã
			mx = x;			        //Çàïàìÿòàòè êîîðäèíàòè
			my = y;
			break;
		case GLUT_UP:
			ldown = false;
			break;
		}
	}
	if (button == GLUT_RIGHT_BUTTON)	//Ïðàâà êíîïêà
	{
		switch (state)
		{
		case GLUT_DOWN:    //ßêùî íàæàòà
			rdown = true;         //Âñòàíîâèòè ôëàã
			mx = x;                 //Çàïàìÿòàòè êîîðäèíàòè
			my = y;
			break;
		case GLUT_UP:
			rdown = false;
			break;
		}
	}
}

void MouseMotion(int x, int y)	//Ïåðåì³ùåííÿ ìèø³
{
	if (ldown)		//Ë³âà êíîïêà
	{
		rx += 0.5 * (y - my);	//Çì³íà êóòà ïîâîðîòó
		ry += 0.5 * (x - mx);
		mx = x;
		my = y;
		glutPostRedisplay();	//Ïåðåðèñóâàòè åêðàí
	}
	if (rdown)	    //Ïðàâà êíîïêà
	{
		tx += 0.01 * (x - mx);	//Ïåðåì³ùåííÿ âçäîâæ àêòèâíî¿ ïëîùèíè
		if (tt)
			tz += 0.01 * (y - my);
		else
			ty += 0.01 * (my - y);
		mx = x;
		my = y;
		glutPostRedisplay();      //Ïåðåðèñóâàòè åêðàí
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