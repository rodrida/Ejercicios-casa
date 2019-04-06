//Semestre 2019 - 2
//*************************************************************//
//*************************************************************//
//************* Alumno (s): Cedillo N�jera Eric Rodrigo *******//
//*************	Pr�ctica No. 9 ******//
//*************	Visual Studio 2017 ******//
//*************	Ejercicio Clase 9 ******//
//*** Texturizado de una Mesa de Ajedrez con transparencia ****//
//*************************************************************//
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; //Posicion de la camara en los tres ejes coordenado
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;//Lo que se observa atraves de la camara


GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;//Textura de Ajedrez
CTexture t_Ajedrez2;//Textura de Ajedrez
CTexture t_metal01;//Textura de Metal


int font = (int)GLUT_BITMAP_TIMES_ROMAN_24;


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);


	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA("01.tga");//Textura de Ajedrez sin esta no se puede visualizar la imagen
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");//Textura de Metal sin esta no se puede visualizar la imagen
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");//Textura de Ajedrez2 sin esta no se puede visualizar la imagen
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

}


void renderBitmapCharacter(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
	//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++) //Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void prisma(GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice[8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
	};


	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(4.0f, 0.0f); glVertex3fv(vertice[1]);//Son las veces que se va a repetir el patron en (u,v)
	glTexCoord2f(4.0f, 4.0f); glVertex3fv(vertice[2]);//Son las veces que se va a repetir el patron en (u,v)
	glTexCoord2f(0.0f, 4.0f); glVertex3fv(vertice[3]);//Son las veces que se va a repetir el patron en (u,v)
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(4.0, 0.0f); glVertex3fv(vertice[4]);//Son las veces que se va a repetir el patron en (u,v)
	glTexCoord2f(4.0, 4.0f); glVertex3fv(vertice[5]);//Son las veces que se va a repetir el patron en (u,v)
	glTexCoord2f(0.0, 4.0f); glVertex3fv(vertice[6]);//Son las veces que se va a repetir el patron en (u,v)
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);//Son las veces que se va a repetir el patron en (u,v)
	glEnd();
}


void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
	glRotatef(eye_camX, 1.0, 0.0, 0.0);
	glRotatef(eye_camY, 0.0, 1.0, 0.0);
	glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	//Borde1:Metal
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glScalef(2.0, 1.0, 0.5);
	prisma(t_Ajedrez1.GLindex, t_metal01.GLindex);
	glPopMatrix();
	//Tabla de Ajedrez
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.0, 1.5);
	glScalef(2.0, 1.0, 2.5);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.1);
	prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
	glDisable(GL_ALPHA_TEST);
	glPopMatrix();
	//Borde2:Metal
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(0.0, 0.0, 3.0);
	glScalef(2.0, 1.0, 0.5);
	prisma(t_Ajedrez1.GLindex, t_metal01.GLindex);
	glPopMatrix();
	//Borde3:Metal
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-1.25, 0.0, 1.5);
	glScalef(0.5, 1.0, 3.5);
	prisma(t_Ajedrez1.GLindex, t_metal01.GLindex);
	glPopMatrix();
	//Borde4:Metal
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(1.25, 0.0, 1.5);
	glScalef(0.5, 1.0, 3.5);
	prisma(t_Ajedrez1.GLindex, t_metal01.GLindex);
	glPopMatrix();
	//Pata de metal
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(1.25, -2.5, 3.0);
	glScalef(0.5, 4.0, 0.5);
	prisma(t_metal01.GLindex, t_metal01.GLindex);
	glPopMatrix();
	//Pata de metal
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-1.25, -2.5, 3.0);
	glScalef(0.5, 4.0, 0.5);
	prisma(t_metal01.GLindex, t_metal01.GLindex);
	glPopMatrix();

	//Pata de metal
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(-1.25, -2.5, 0.0);
	glScalef(0.5, 4.0, 0.5);
	prisma(t_metal01.GLindex, t_metal01.GLindex);
	glPopMatrix();
	//Pata de metal
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	glTranslatef(1.25, -2.5, 0.0);
	glScalef(0.5, 4.0, 0.5);
	prisma(t_metal01.GLindex, t_metal01.GLindex);
	glPopMatrix();

	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 9");
	renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Mesa de Ajedrez");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{


	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		pos_camZ += 0.5f;
		//eye_camZ -= 0.5f;
		break;

	case 's':
	case 'S':
		pos_camZ -= 0.5f;
		//eye_camZ += 0.5f;
		break;

	case 'a':
	case 'A':
		pos_camX += 0.5f;
		//eye_camX -= 0.5f;
		break;
	case 'd':
	case 'D':
		pos_camX -= 0.5f;
		//eye_camX += 0.5f;
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX - 15) % 360;
		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX + 15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY - 15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY + 15) % 360;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(5000, 5000);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 9"); // Nombre de la Ventana
	//glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}