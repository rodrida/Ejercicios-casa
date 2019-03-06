//Semestre 2019 - 2
//*************************************************************//
//*************************************************************//
//************* Alumno (s): Cedillo Nájera Eric Rodrigo *******//
//*************	Práctica No. 4 ******//
//*************	Visual Studio 2017 ******//
//*************	Ejercicio Casa 4 ********//
//**** Este programa dibuja un personaje tipo humanoide *******//
//* utilizando las tres transformaciones básicas vistas en lab //
//*************************************************************//

#include "Main.h"

int screenW = 0.0;
int screenH = 0.0;
float angY = 0.0f;
float angX = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;

void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			//glColor3f(2.0,0.0,0.0);   //rojo
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(1.0,1.0,0.0);   //amarillo  
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);   //verde 
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,0.2,0.4);   //rosa
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);   //morado
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.0,0.0,1.0);   //azul
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
        
	    glColor3f(1.0,1.0,1.0);   //blanco
		glTranslatef(transX, transY, transZ);
		glRotatef(angY, 0, 1, 0);
		glRotatef(angX, 1, 0, 0);
		
		//Poner Código Aquí.
		prisma();

		glColor3f(1.0,0.2,0.4);   //rosa
		glTranslatef(0.0f,-0.7f,0.0f);
		glScalef(0.7f, 0.5f, 0.5f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(0.0,0.0,1.0);   //azul
		glTranslatef(0.0f,-3.0f,0.0f);
		glScalef(6.3f, 6.0f, 6.0f);
		glRotatef(0, 0, 0, 0);
		prisma();
		
		glColor3f(0.0,1.0,0.0);   //verde
		glTranslatef(0.6f,0.4f,0.0f);
		glScalef(0.2f, 0.2f, 0.2f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(1.0,1.0,0.0);   //amarillo
		glTranslatef(1.2f,0.0f,0.0f);
		glScalef(1.5f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(1.0,0.0,0.0);   //rojo
		glTranslatef(1.0f,0.0f,0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(1.0,1.0,1.0);   //blanco
		glTranslatef(0.5f,0.0f,0.0f);
		glScalef(0.3f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(1.0,1.0,1.0);   //blanco
		glTranslatef(-28.0f,0.0f,0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(1.0,0.0,0.0);   //rojo
		glTranslatef(1.9f,0.0f,0.0f);
		glScalef(2.9f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(1.0,1.0,0.0);   //amarillo
		glTranslatef(1.0f,0.0f,0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();
		
		glColor3f(0.0,1.0,0.0);   //verde
		glTranslatef(0.8f,0.0f,0.0f);
		glScalef(0.7f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(1.0,0.0,0.0);   //rojo
		glTranslatef(1.5f,-5.8f,0.0f);
		glScalef(2.0f, 2.5f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(1.0,0.0,0.0);   //rojo
		glTranslatef(1.75f,0.0f,0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(0.0,1.0,0.0);   //verde
		glTranslatef(0.0f,-0.65f,0.0f);
		glScalef(1.0f, 0.3f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(0.0,1.0,0.0);   //verde
		glTranslatef(-1.75f,0.0f,0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(0.0,0.0,1.0);   //azul
		glTranslatef(0.0f,-2.1f,0.0f);
		glScalef(1.0f, 3.3f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(0.0,0.0,1.0);   //azul
		glTranslatef(1.75f,0.0f,0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(0.2,0.2,0.0);   //cafe
		glTranslatef(0.4f,-0.75f,0.0f);
		glScalef(1.8f, 0.5f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

		glColor3f(0.2,0.2,0.0);   //cafe
		glTranslatef(-1.41f,0.0f,0.0f);
		glScalef(1.0f, 1.0f, 1.0f);
		glRotatef(0, 0, 0, 0);
		prisma();

  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'q':
		case 'Q':
			transY -=0.2f;
			break;
		case 'e':
		case 'E':
			transY +=0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angX -= 1.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angX += 1.0f;
		break;
	case GLUT_KEY_LEFT:
		angY -= 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angY += 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Ejercicio Casa 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}