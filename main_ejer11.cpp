//Semestre 2019 - 2
//*************************************************************//
//*************************************************************//
//************* Alumno (s): Cedillo Nájera Eric Rodrigo *******//
//*************	Práctica No. 11 ******//
//*************	Visual Studio 2017 ******//
//*************	Ejercicio Casa 11 ******//
//* Realizar la animación por Keyframes del brazo *************//
//*************** de la práctica 5 ****************************//
//*************************************************************//

//Teclas Especiales para activar la animacion
//K,k =>Para guardar la animacion
//L,l =>Para correr la animacion

#include "Main.h"
float pulgar, indice, medio, anular, menique = 0;
float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;

float anguloHombro = 0.0f;
float anguloCodo = 0.0f;
float anguloMuneca = 0.0f;
float anguloDedos = 0.0f;

int tam = 0;
FILE *archivo; //Apuntador
int contador = 0;
#define MAX_FRAMES 600
int i_max_steps = 100;
int i_curr_steps = 0;
//Frame de la mano
typedef struct _frame
{
	float pulgar;
	float pulgarInc;
	float indice;
	float indiceInc;
	float medio;
	float medioInc;
	float anular;
	float anularInc;
	float menique;
	float meniqueInc;
}FRAME;
//Arreglo frame
FRAME KeyFrame[MAX_FRAMES];
int FrameIndex = 0;
bool play = false;
int playIndex = 0;
//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
char s[30];

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font = (int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = { 18 };

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = { 22 };


void saveFrame2(void) {		 // Movimientos guardados 

	int contador = -1;
	float arreglo[] = {
		//Valores de la animacion
		//PIEDRA
		0.000,0.000,0.000,0.000,0.000,
		16.000,13.000,13.000,13.000,13.000,
		34.000,32.000,32.000,32.000,32.000,
		46.000,48.000,48.000,48.000,48.000,
		55.000,51.000,51.000,51.000,51.000,
		65.000,63.000,63.000,63.000,63.000,
		74.000,96.000,96.000,96.000,96.000,
		82.000,81.000,81.000,81.000,81.000,
		91.000,90.000,90.000,90.000,90.000,
		98.000,95.000,95.000,95.000,95.000,
		106.000,104.000,104.000,104.000,104.000,
		92.000,90.000,90.000,90.000,90.000,
		79.000,80.000,80.000,80.000,80.000,
		72.000,73.000,73.000,73.000,73.000,
		65.000,64.000,64.000,64.000,64.000,
		57.000,56.000,56.000,56.000,56.000,
		50.000,49.000,49.000,49.000,49.000,
		41.000,40.000,40.000,40.000,40.000,
		33.000,32.000,32.000,32.000,32.000,
		24.000,23.000,23.000,23.000,23.000,
		15.000,16.000,16.000,16.000,16.000,
		10.000,11.000,11.000,11.000,11.000,
		//PAPEL
		7.000,8.000,8.000,8.000,8.000,
		3.000,4.000,4.000,4.000,4.000,
		0.000,0.000,0.000,0.000,0.000,
		30.000,0.000,0.000,28.000,28.000,
		53.000,0.000,0.000,42.000,42.000,
		62.000,0.000,0.000,51.000,51.000,
		72.000,0.000,0.000,61.000,61.000,
		83.000,0.000,0.000,71.000,71.000,
		89.000,0.000,0.000,78.000,78.000,
		98.000,0.000,0.000,87.000,87.000,
		105.000,0.000,0.000,95.000,95.000,
		116.000,0.000,0.000,106.000,106.000,
		126.000,0.000,0.000,116.000,116.000,
		136.000,0.000,0.000,126.000,126.000,
		143.000,0.000,0.000,133.000,133.000,
		152.000,0.000,0.000,142.000,142.000,
		157.000,0.000,0.000,147.000,147.000,
		127.000,0.000,0.000,117.000,117.000,
		114.000,0.000,0.000,104.000,104.000,
		103.000,0.000,0.000,93.000,93.000,
		97.000,0.000,0.000,87.000,87.000,
		90.000,0.000,0.000,80.000,80.000,
		82.000,0.000,0.000,72.000,72.000,
		75.000,0.000,0.000,65.000,65.000,
		64.000,0.000,0.000,54.000,54.000,
		57.000,0.000,0.000,47.000,47.000,
		50.000,0.000,0.000,40.000,40.000,
		44.000,0.000,0.000,34.000,34.000,
		34.000,0.000,0.000,24.000,24.000,
		27.000,0.000,0.000,17.000,17.000,
		20.000,0.000,0.000,12.000,12.000,
		15.000,0.000,0.000,9.000,9.000,
		10.000,0.000,0.000,5.000,5.000,
		5.000,0.000,0.000,2.000,2.000,
		0.000,0.000,0.000,0.000,0.000,
		//TIJERAS Y LIKE
		0.000,0.000,10.000,11.000,11.000,
		0.000,10.000,25.000,26.000,26.000,
		0.000,35.000,35.000,36.000,36.000,
		0.000,42.000,42.000,43.000,43.000,
		0.000,50.000,50.000,51.000,51.000,
		0.000,56.000,56.000,57.000,57.000,
		0.000,62.000,62.000,63.000,63.000,
		0.000,68.000,68.000,69.000,69.000,
		0.000,76.000,76.000,77.000,77.000,
		0.000,83.000,83.000,84.000,89.000,
		0.000,89.000,89.000,90.000,90.000,
		0.000,95.000,95.000,96.000,96.000,
		0.000,103.000,103.000,104.000,104.000,
		0.000,112.000,112.000,113.000,113.000,
		0.000,121.000,121.000,122.000,122.000,
		0.000,130.000,130.000,131.000,131.000,
		0.000,139.000,139.000,140.000,140.000,
		0.000,123.000,123.000,124.000,124.000,
		0.000,113.000,113.000,114.000,114.000,
		0.000,109.000,109.000,110.000,110.000,
		0.000,102.000,102.000,103.000,103.000,
		0.000,93.000,93.000,94.000,94.000,
		0.000,83.000,83.000,84.000,84.000,
		0.000,72.000,72.000,73.000,73.000,
		0.000,59.000,59.000,60.000,60.000,
		0.000,51.000,51.000,52.000,52.000,
		0.000,41.000,41.000,42.000,42.000,
		0.000,31.000,31.000,32.000,32.000,
		0.000,24.000,24.000,25.000,25.000,
		0.000,17.000,17.000,18.000,18.000,
		0.000,12.000,12.000,13.000,13.000,
		0.000,9.000,9.000,10.000,10.000,
		0.000,5.000,5.000,5.000,5.000,
		0.000,0.000,0.000,0.000,0.000,

	};

	//Ciclo para realizar las señales
	for (int i = 0; i < 81; i++) {
		contador++;
		KeyFrame[i].pulgar = arreglo[contador];
		contador++;
		KeyFrame[i].indice = arreglo[contador];
		contador++;
		KeyFrame[i].medio = arreglo[contador];
		contador++;
		KeyFrame[i].anular = arreglo[contador];
		contador++;
		KeyFrame[i].menique = arreglo[contador];
		FrameIndex++;
	}
}
//Interpolacion
void interpolation(void)
{
	//Incremento de las rotaciones de los dedos
	KeyFrame[playIndex].pulgarInc = (KeyFrame[playIndex + 1].pulgar - KeyFrame[playIndex].pulgar) / i_max_steps; //Pulgar
	KeyFrame[playIndex].indiceInc = (KeyFrame[playIndex + 1].indice - KeyFrame[playIndex].indice) / i_max_steps; //Indice
	KeyFrame[playIndex].medioInc = (KeyFrame[playIndex + 1].medio - KeyFrame[playIndex].medio) / i_max_steps; //Medio
	KeyFrame[playIndex].anularInc = (KeyFrame[playIndex + 1].anular - KeyFrame[playIndex].anular) / i_max_steps;//Anular
	KeyFrame[playIndex].meniqueInc = (KeyFrame[playIndex + 1].menique - KeyFrame[playIndex].menique) / i_max_steps; //Meñique
}
void saveFrame(void)
{
	//Se guardan los movimientos de los dedos
	printf("frameindex %d\n", FrameIndex);
	KeyFrame[FrameIndex].pulgar = pulgar; //Guardar pulgar
	KeyFrame[FrameIndex].indice = indice; //guardar indice
	KeyFrame[FrameIndex].medio = medio; //Guardar medio
	KeyFrame[FrameIndex].anular = anular; //Guardar anular
	KeyFrame[FrameIndex].menique = menique;//Guardar menique
//Se guardan en un archivo el cual muestra los valores adquiridos en los angulos de rotacion de cada dedo
	fprintf(archivo, "%.3f\n,", pulgar);
	fprintf(archivo, "%.3f\n,", indice);
	fprintf(archivo, "%.3f\n,", medio);
	fprintf(archivo, "%.3f\n,", anular);
	fprintf(archivo, "%.3f\n, ", menique);
	printf("Pulgar: %.3f \n", KeyFrame[FrameIndex].pulgar);
	printf("Indice: %.3f \n", KeyFrame[FrameIndex].indice);
	printf("Medio: %.3f \n", KeyFrame[FrameIndex].medio);
	printf("Anular: %.3f \n", KeyFrame[FrameIndex].anular);
	printf("Meñique: %.3f \n ", KeyFrame[FrameIndex].menique);
	FrameIndex++;
}

//Reinicio de los dedos
void resetElements(void)
{

	pulgar = KeyFrame[0].pulgar;
	indice = KeyFrame[0].indice;
	medio = KeyFrame[0].medio;
	anular = KeyFrame[0].anular;
	menique = KeyFrame[0].menique;
}

void prisma()
{
	GLfloat vertice[8][3] = {
		{ 0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 0 V 0
		{ -0.5 ,-0.5, 0.5 },    //Coordenadas Vértice 1 V 1
		{ -0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 2 V 2
		{ 0.5 ,-0.5, -0.5 },    //Coordenadas Vértice 3 V 3
		{ 0.5 ,0.5, 0.5 },    //Coordenadas Vértice 4 V 4
		{ 0.5 ,0.5, -0.5 },    //Coordenadas Vértice 5 V 5
		{ -0.5 ,0.5, -0.5 },    //Coordenadas Vértice 6 V 6
		{ -0.5 ,0.5, 0.5 },    //Coordenadas Vértice 7 V 7
	};

	glBegin(GL_POLYGON);	//Front
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}

void mano() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
		//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    // Palma
	glPushMatrix(); // stack palma
	glTranslatef(0.0, 0.0, -5);
	glTranslatef(-2.0f, 0.0f, transZ); // Traslación para la palma
	glRotatef(0, 0, 1, 0);
	glRotatef(0, 0, 0, 1);
	glPushMatrix();//nudillo1
	glTranslatef(1.5, 1.5, 0.0);
	glRotatef(indice, 0, 1, 0);
	glPushMatrix(); //Falange 1
	glTranslatef(1.05f, 0.0f, 0.0f);//centro a centro
	glPushMatrix();//nudillo2
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(indice, 0, 1, 0);
	glPushMatrix();//falangina 1
	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();//nudillo3
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(indice, 0, 1, 0);
	glPushMatrix();//falangeta 1
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, 0.5, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, .75, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(90, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange 1
	glPopMatrix();//pop nudillo

	glPushMatrix();//nudillo1.1
	glTranslatef(1.5, .5, 0.0);
	glRotatef(medio, 0, 1, 0);
	glPushMatrix(); //Falange 2
	glTranslatef(1.05f, 0.0, 0.0f);
	glPushMatrix();//nudillo2.1
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(medio, 0, 1, 0);
	glPushMatrix();//falangina 2
	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();//nudillo3.1
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(medio, 0, 1, 0);
	glPushMatrix();//falangeta 2
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, .5, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, .75, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(180, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange2
	glPopMatrix();//pop nudillo 1

	glPushMatrix();//nudillo1.2
	glTranslatef(1.5, -0.5, 0.0);
	glRotatef(anular, 0, 1, 0);
	glPushMatrix(); //Falange 3
	glTranslatef(1.05f, 0.0f, 0.0f);
	glPushMatrix();//nudillo2.2
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(anular, 0, 1, 0);
	glPushMatrix();//falangina 3
	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();//nudillo3.2
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(anular, 0, 1, 0);
	glPushMatrix();//falangeta 3
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, .5, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, .75, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(270, 1, 0, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange3
	glPopMatrix();

	glPushMatrix();//nudillo1.3
	glTranslatef(1.5, -1.5, 0.0);
	glRotatef(menique, 0, 1, 0);
	glPushMatrix(); //Falange 4
	glTranslatef(1.05f, 0.0f, 0.0f);
	glPushMatrix();//nudillo2.3
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(menique, 0, 1, 0);
	glPushMatrix();//falangina 4
	glTranslatef(1.0f, 0.0f, 0.0f);
	glPushMatrix();//nudillo3.3
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(menique, 0, 1, 0);
	glPushMatrix();//falangeta 4
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, .5, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, .75, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange4
	glPopMatrix();

	glPushMatrix();//nudillo1.4
	glTranslatef(-1, .9, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(1.5, -1.5, 0.0);
	glRotatef(pulgar, 0, 1, 0);
	glPushMatrix(); //Falange 5
	glTranslatef(1.05f, 0.0f, 0.0f);
	glPushMatrix();//nudillo2.4
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef(pulgar, 0, 1, 0);
	glPushMatrix();//falangina 5
	glTranslatef(1.0f, 0.0f, 0.0f);
	glScalef(2.0, .75, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix();
	glPopMatrix();
	glScalef(2.0, 1.0, 2.0);
	glRotatef(90, 0, 1, 0);
	prisma();
	glPopMatrix(); // Sale del stack de la falange4
	glPopMatrix();


	glScalef(3, 5, 1);
	prisma();           // Dibujar palma
	glPopMatrix(); // Sale del stack de la palma 

	//fin dibujo

	//Movimiento
	glTranslatef(-0.5f, 1.5f, 0.0f);
	glRotatef(pulgar, 1.0, 0.0, 0.0);
	glTranslatef(0.5f, -1.5f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(-0.5f, 1.75f, 0.0f);
	glScalef(0.4f, 0.5f, 0.5f);
	prisma();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	//Movimiento
	glTranslatef(1.0f, 1.25f, 0.0f);
	glRotatef(indice, 0.0, -1.0, 0.0);
	glTranslatef(-1.0f, -1.25f, 0.0f);
	//Indice
	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.25f, 0.75f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();
	//Movimiento
	glTranslatef(1.5f, 1.25f, 0.0f);
	glRotatef(indice, 0.0, -1.0, 0.0);
	glTranslatef(-1.5f, -1.25f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.75f, 0.75f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();
	//Movimiento
	glTranslatef(2.0f, 1.25f, 0.0f);
	glRotatef(indice, 0.0, -1.0, 0.0);
	glTranslatef(-2.0f, -1.25f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(2.25f, 0.75f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	//Movimiento
	glTranslatef(1.0f, 0.25f, 0.0f);
	glRotatef(medio, 0.0, -1.0, 0.0);
	glTranslatef(-1.0f, -0.25f, 0.0f);
	//Medio
	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.25f, 0.25f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();
	//Movimiento
	glTranslatef(1.5f, 0.25f, 0.0f);
	glRotatef(medio, 0.0, -1.0, 0.0);
	glTranslatef(-1.5f, -0.25f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.75f, 0.25f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();
	//Movimiento
	glTranslatef(2.0f, 0.25f, 0.0f);
	glRotatef(medio, 0.0, -1.0, 0.0);
	glTranslatef(-2.0f, -0.25f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(2.25f, 0.25f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();
	//Movimiento
	glTranslatef(1.0f, -0.25f, 0.0f);
	glRotatef(anular, 0.0, -1.0, 0.0);
	glTranslatef(-1.0f, 0.25f, 0.0f);
	//Anular
	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.25f, -0.25f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();
	//Movimiento
	glTranslatef(1.5f, -0.25f, 0.0f);
	glRotatef(anular, 0.0, -1.0, 0.0);
	glTranslatef(-1.5f, 0.25f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.75f, -0.25f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();
	//Movimiento
	glTranslatef(2.0f, -0.25f, 0.0f);
	glRotatef(anular, 0.0, -1.0, 0.0);
	glTranslatef(-2.0f, 0.25f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(2.25f, -0.25f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();

	glPopMatrix();
	//Meñique
	glPushMatrix();
	//Movimiento
	glTranslatef(1.0f, -0.75f, 0.0f);
	glRotatef(menique, 0.0, -1.0, 0.0);
	glTranslatef(-1.0f, 0.75f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.25f, -0.75f, 0.0f);
	glScalef(0.5f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();
	//Movimiento
	glTranslatef(1.5f, -0.75f, 0.0f);
	glRotatef(menique, 0.0, -1.0, 0.0);
	glTranslatef(-1.5f, 0.75f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.65f, -0.75f, 0.0f);
	glScalef(0.3f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();
	//Movimiento
	glTranslatef(1.8f, -0.75f, 0.0f);
	glRotatef(menique, 0.0, -1.0, 0.0);
	glTranslatef(-1.8f, 0.75f, 0.0f);

	glPushMatrix();
	glColor3f(0.0, 0.6, 0.5);
	glTranslatef(1.9f, -0.75f, 0.0f);
	glScalef(0.2f, 0.4f, 0.5f);
	prisma();
	glPopMatrix();

	glPopMatrix();
}

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.1f, 0.1f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	for (int i = 0; i < MAX_FRAMES; i++)
	{
		KeyFrame[i].anular = 0;					//Declaracion de keyframes
		KeyFrame[i].anularInc = 0;
		KeyFrame[i].indice = 0;
		KeyFrame[i].indiceInc = 0;
		KeyFrame[i].medio = 0;
		KeyFrame[i].medioInc = 0;
		KeyFrame[i].menique = 0;
		KeyFrame[i].meniqueInc = 0;
		KeyFrame[i].pulgar = 0;
		KeyFrame[i].pulgarInc = 0;
	}
	//NEW//////////////////NEW//////////////////NEW///////////
	//Archivo
	archivo = fopen("datos.txt", "w");

	saveFrame2();

}

void pintaTexto(float x, float y, float z, void *font, char *string)
{

	char *c;     //Almacena los caracteres a escribir
	glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
							//glWindowPos2i(150,100);
	for (c = string; *c != '\0'; c++)//Condicion de fin de cadena
	{
		glutBitmapCharacter(font, *c); //imprime
	}
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix();


	glRotatef(g_lookupdown, 1.0f, 0, 0);
	mano();

	glPopMatrix();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 0.0, 0.0);
	pintaTexto(-11, 12.0, -14.0, (void *)font, "Ejercicio Casa 11: Seniales con la mano");
	glColor3f(0.0, 0.40, 0.40);
	glColor3f(0.0, 0.40, 0.40);
	glEnable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers();

}

void animacion()
{
	//Mano
	if (play)
	{

		if (i_curr_steps >= i_max_steps) //end of animation between frames?
		{
			playIndex++;
			if (playIndex > FrameIndex - 2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex = 0;
				play = false;
				//resetElements();
			}
			else
			{
				i_curr_steps = 0; //Reset counter
								  //Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			pulgar += KeyFrame[playIndex].pulgarInc; //avanzar cuadro
			indice += KeyFrame[playIndex].indiceInc;
			medio += KeyFrame[playIndex].medioInc;
			//Rotacion de los dedos
			anular += KeyFrame[playIndex].anularInc;

			menique += KeyFrame[playIndex].meniqueInc;
			i_curr_steps++;
		}

	}


	glutPostRedisplay();
}

void reshape(int width, int height)   //Reshape
{
	if (height == 0)
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);			// Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 170.0);

	glMatrixMode(GL_MODELVIEW);			//Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard 
{
	switch (key) {
		//Atras
	case 's':
	case 'S':
		transZ -= 0.2f;

		break;
		//Adelante
	case 'w':
	case 'W':
		transZ += 0.2f;
		break;
		//Derecha
	case 'a':
	case 'A':
		transX += 0.2f;
		break;
		//Izquierda
	case 'd':
	case 'D':
		transX -= 0.2f;
		break;
		//PIEDRA
	case 'o':
		indice++;
		pulgar++;
		menique++;
		anular++;
		medio++;
		break;

	case 'O':
		indice--;
		pulgar--;
		menique--;
		anular--;
		medio--;
		break; 
		//PAPEL
	case 'v':
		indice--;
		pulgar--;
		menique--;
		anular--;
		medio--;
		break;

	case 'V':
		indice++;
		pulgar++;
		menique++;
		anular++;
		medio++;
		break;
		//TIJERAS
	case 'm':
		menique++;
		anular++;
		pulgar++;
		break;

	case 'M':
		menique--;
		anular--;
		pulgar--;
		break;
		//LIKE
	case 'j':
		menique++;
		anular++;
		medio++;
		indice;
		break;

	case 'J':
		menique--;
		anular--;
		medio--;
		indice--;
		break;
		//Mover Hombro
	case 'h':
		if (anguloHombro <= 80.0)
			anguloHombro += 1.0;
		break;

	case 'H':
		if (anguloHombro >= -80.0)
			anguloHombro -= 1.0;
		break;
		//Se guarda la animacion
	case 'k':
	case 'K':
		if (FrameIndex < MAX_FRAMES)
		{

			saveFrame();


		}

		break;

	case 'l':				//correr animacion
	case 'L':
		if (play == false && (FrameIndex > 1))
		{

			resetElements();
			//First Interpolation				
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;

	case 27:
		fclose(archivo);// Esc para salir
		exit(0);
		break;
	default:
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
	case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 2.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

void menuKeyFrame(int id)
{
	switch (id)
	{
	case 0:	//Save KeyFrame
		if (FrameIndex < MAX_FRAMES)
		{
			saveFrame();
		}
		break;

	case 1:	//Play animation
		if (play == false && FrameIndex > 1)
		{


			resetElements();

			//First Interpolation
			interpolation();

			play = true;
			playIndex = 0;
			i_curr_steps = 0;
		}
		else
		{
			play = false;
		}
		break;


	}
}


void menu(int id)
{

}

int main(int argc, char** argv)   // Main Function
{
	int submenu;
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Ejercicio Casa 11"); // Nombre de la Ventana
									 //glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);

	submenu = glutCreateMenu(menuKeyFrame);
	glutAddMenuEntry("Guardar KeyFrame", 0);
	glutAddMenuEntry("Reproducir Animacion", 1);
	glutCreateMenu(menu);
	glutAddSubMenu("Animacion Monito", submenu);

	glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();          // 

	return 0;
}