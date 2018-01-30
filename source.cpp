#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#include "glut.h"
#include<stdlib.h>

#define drawOneLine(x1,y1,x2,y2)  glBegin(GL_LINES);  \
   glVertex3f ((x1),(y1),(-5.0)); glVertex3f ((x2),(y2),(-5.0)); glEnd();   //draw...dotted line 

float tx=0.0f;    //X-axis translation varaible 
float ty = 0.0f;	//Y-axis translation varaible
float giftTanslat = 0.0;  //Translation varaible for gift Box
float giftMov = 0.00575;   //Translation increament value (speed)
float Maxtx = 6.0f;
float forwardIncrmt = 0.0015f; 
bool forwardTrans = false;
float backwardIncrmt = 0.0013f;        //backward movement speed
float maxTheta = 35.0f;					//maximum rotation angle 
float movTheta = 0.0f;
float incTheta = 1.5f;
bool forwardMov = false;
int timer =30;
int counter;
float Cx = 0.0f;
float Cincrmt = 0.03f;





//Initializes 3D 
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 800, 0.0, 800, -1000.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
}



void handleResize(int w, int h) {
	
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(45.0,(double)w / (double)h, 1.0, 200.0);                
}
void init(void)
{
	glClearColor(0.2, 0.2, 0.2, 1.0);
	glShadeModel(GL_FLAT);
}
void circle(float rad, float xx, float yy) {

	float thetha = 2 * 3.1415 / 20;
	float x, y;
	glColor3f(1.1, 1.1, 1.10);
	glLineWidth(1.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 20; i++) {
		x = rad * cos(i*thetha) + xx;
		y = rad*sin(i*thetha) + yy;
		float z = -5.0f;
		glVertex3f(x,y,z);
	}
	glEnd();
}
void head()
{
	circle(0.08, -1.0f, 0.97f);

}
void print(float x, float y, float z, char *string) {
	glRasterPos3f(x, y, z);
	int len = (int)strlen(string);
	for (int i = 0; i < len; i++)
	{

		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	}
}
void cloud(float rad, float xx, float yy) {

	float thetha = 2 * 3.1415 / 20;
	float x, y;
	glColor3f(1.1, 1.1, 1.10);
	glLineWidth(1.0);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < 20; i++) {
		x = rad * cos(i*thetha) + xx;
		y = rad*sin(i*thetha) + yy;
		float z = -5.0f;
		glVertex3f(x, y, z);
	}
	glEnd();
}
void think()
{
	glColor3f(1.1, 1.1, 1.1);
	cloud(0.4, -0.90f, 0.97f);
	cloud(0.4, -1.4f, 0.97f);
	cloud(0.4, -2.0f, 0.97f);
	cloud (0.4, -1.5f, 0.67f);
	cloud(0.2, -1.3, 0.1);
	cloud(0.1, -1.0, -0.1);
	cloud(0.05, -0.8, -0.3);
	glColor3ub(25, 10, 91);
	print(-2.4, 0.95, -5.0, "..good deals???..");  
	glRasterPos3f(-3.5, 1.5, -5.0);
}
void front()
{
	glColor3ub(153, 0, 76);
	glLineWidth(5.0);
	glBegin(GL_QUADS);
	glVertex3f(-0.7f, -1.5f, -5.0f);
	glVertex3f(0.1f, -1.5f, -5.0f);
	glVertex3f(0.1f, -0.5f, -5.0f);
	glVertex3f(-0.7f, -0.5f, -5.0f);
	glEnd();
}
void Door()
{
	//door 
	glColor3ub(223, 255, 214);
	glLineWidth(5.0);
	glBegin(GL_QUADS);
	glVertex3f(-0.65f, -1.5f, -5.0f);
	glVertex3f(0.05f, -1.5f, -5.0f);
	glVertex3f(0.05f, -1.0f, -5.0f);
	glVertex3f(-0.65f, -1.0f, -5.0f);
	glEnd();
	glColor3f(0.80, 0.70, 0.60);
	glLineWidth(5.0);
	glBegin(GL_QUADS);
	glVertex3f(-0.65f, -1.5f, -5.0f);
	glVertex3f(-0.45f, -1.4f, -5.0f);
	glVertex3f(-0.45f, -1.1f, -5.0f);
	glVertex3f(-0.65f, -1.0f, -5.0f);
	glEnd();
	glColor3f(0.80, 0.70, 0.60);
	glLineWidth(5.0);
	glBegin(GL_QUADS);
	glVertex3f(0.05f, -1.5f, -5.0f);
	glVertex3f(-0.15f, -1.4f, -5.0f);
	glVertex3f(-0.15f, -1.1f, -5.0f);
	glVertex3f(0.05f, -1.0f, -5.0f);
	glEnd();
}
void drawHouse() {

	
	//side
	glColor3f(0.1, 0.1, 1.0);
	glLineWidth(5.0);
	glBegin(GL_QUADS);
	glVertex3f(0.1f, -0.5f, -5.0f);
	glVertex3f(0.1f, -1.5, -5.0f);
	glVertex3f(1.5f, -1.5f, -5.0f);
	glVertex3f(1.5f, -0.5f, -5.0f);
	glEnd();

	//roof
	glLineWidth(5.0);
	glColor3ub(229.0, 229.0, 214.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.8f, -0.5f, -5.0f);
	glVertex3f(-0.3f, 0.5f, -5.0f);
	glVertex3f(0.10f, -0.5f, -5.0f);
	glEnd();
	//roof2
	glLineWidth(5.0);
	glColor3ub(98.0, 98.0, 8.0);
	glBegin(GL_QUADS);
	glVertex3f(-0.3f, 0.5f, -5.0f);
	glVertex3f(0.15f, -0.6f, -5.0f);
	glVertex3f(1.60f, -0.6f, -5.0f);
	glVertex3f(1.10f, 0.5f, -5.0f);
	glEnd();

	

	//window1
	glColor3f(0.80, 0.70, 0.60);
	glBegin(GL_QUADS);
	glVertex3f(0.35, -0.8, -5.0);
	glVertex3f(0.35, -1.1, -5.0);
	glVertex3f(0.75, -1.1, -5.0);
	glVertex3f(0.75, -0.8, -5.0);
	glEnd();
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.35, -0.8, -5.0);
	glVertex3f(0.75, -1.1, -5.0);
	glEnd();
	//window2
	glColor3f(0.80, 0.70, 0.60);
	glBegin(GL_QUADS);
	glVertex3f(0.85, -0.8, -5.0);
	glVertex3f(0.85, -1.1, -5.0);
	glVertex3f(1.25, -1.1, -5.0);
	glVertex3f(1.25, -0.8, -5.0);
	glEnd();
	glLineWidth(2.0);
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(0.85, -0.8, -5.0);
	glVertex3f(1.25, -1.1, -5.0);
	glEnd();
}
void giftBox()
{
	//giftBox
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(0.15, -1.1, -5.0);
	glVertex3f(0.15, -1.2, -5.0);
	glVertex3f(0.25, -1.2, -5.0);
	glVertex3f(0.25, -1.1, -5.0);
	glEnd();

	glColor3f(1.0, 0.2, 1.0);
	glBegin(GL_QUADS);
	glVertex3f(0.15, -1.1, -5.0);
	glVertex3f(0.2, -1.05, -5.0);
	glVertex3f(0.3, -1.05, -5.0);
	glVertex3f(0.25, -1.1, -5.0);
	glEnd();
	glColor3f(1.1, 0.1, 0.2);
	glBegin(GL_QUADS);
	glVertex3f(0.25, -1.1, -5.0);
	glVertex3f(0.25, -1.2, -5.0);
	glVertex3f(0.3, -1.15, -5.0);
	glVertex3f(0.3, -1.05, -5.0);
	glEnd();


}
void road()
{
	glColor3ub(0, 0, 0);
	glLineWidth(5.0);
	glBegin(GL_QUADS);
	glVertex3f(-1.5f, -1.8f, -5.0f);
	glVertex3f(-1.6f, -2.1f, -5.0f);
	glVertex3f(0.5f, -2.1f, -5.0f);
	glVertex3f(0.6f, -1.80f, -5.0f);
	glEnd();
}
	//road mark(white)
void roadMark()
{
	
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(3.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(5, 0x1C47);  /*  draw dash/dot/dash lines  */
	drawOneLine(-5.95, -1.70, 5.50, -1.70);
	glDisable(GL_LINE_STIPPLE);
}
void neck()
{
	glColor3f(1.1, 0.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f, 0.9f, -5.0f);
	glVertex3f(-1.0f, 0.8f, -5.0f);
	glEnd();
}
void body()
{
	glColor3f(0.1, 1.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f,0.8f,-5.0f);
	glVertex3f(-1.0f, 0.5f,-5.0f);
	glEnd();
}
void leftHand()
{
	glColor3f(1.1, 1.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f, 0.8f, -5.0f);
	glVertex3f(-1.01f, 0.6f, -5.0f);
	glEnd();
}
void rightHand()
{
	glColor3f(1.1, 1.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f, 0.8f, -5.0f);
	glVertex3f(-0.99f, 0.6f, -5.0f);
	glEnd();
}
void leftArm()
{
	glColor3f(1.1, 0.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.01f, 0.6f, -5.0f);
	glVertex3f(-1.02f, 0.5f, -5.0f);
	glEnd();
}

void rightArm()
{
	glColor3f(1.1, 0.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.99f, 0.6f, -5.0f);
	glVertex3f(-0.98f, 0.5f, -5.0f);
	glEnd();
}
void leftLeg()
{
	glColor3f(1.1, 0.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f, 0.5f, -5.0f);
	glVertex3f(-1.01f, 0.4f, -5.0f);
	glEnd();
}
void rightLeg()
{
	glColor3f(1.1, 0.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f, 0.5f, -5.0f);
	glVertex3f(-0.99f, 0.4f, -5.0f);
	glEnd();
}
void leftShin()
{
	glColor3f(1.1, 0.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f, 0.4f, -5.0f);
	glVertex3f(-1.01f, 0.3f, -5.0f);
	glEnd();
}
void rightShine()
{
	glColor3f(1.1, 0.1, 0.0);
	glLineWidth(1.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.0f, 0.4f, -5.0f);
	glVertex3f(-0.99f, 0.3f, -5.0f);
	glEnd();
}
void drawEllipse(float radX, float radY)
{
	int i;
	glColor3ub(24,236,66);
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < 360; i++)
	{
		float rad = i*(3.14159 / 180);
		glVertex3f(cos(rad)*radX, sin(rad)*radY,-5.0f);
	}
	glEnd();
}
void chopper()
{
	
	drawEllipse(1.0f, 0.5f);
	//centre line
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3f(1.0f, 0.0f,-5.0f);
	glVertex3f(-0.30f, 0.0f, -5.0f);
	glEnd();
	//perpendicular line
	glBegin(GL_LINES);
	glVertex3f(-0.30f, 0.0f, -5.0f);
	glVertex3f(-0.30f, 0.5f, -5.0f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-1.0f, 0.1f, -5.0f);
	glVertex3f(-1.50f, 0.1f, -5.0f);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-1.0f, -0.1f, -5.0f);
	glVertex3f(-1.50f, -0.1f, -5.0f);
	glEnd();
	//wing stand
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex3f(-0.1f, 0.5f, -5.0f);
	glVertex3f(-0.1f, 0.7f, -5.0f);
	glEnd();
	//wing 
	glBegin(GL_LINES);
	glVertex3f(-0.6f, 0.7f, -5.0f);
	glVertex3f(0.4f, 0.7f, -5.0f);
	glEnd();

	//tail
	glBegin(GL_LINE_STRIP);
	glVertex3f(-1.5f, 0.1f, -5.0f);
	glVertex3f(-1.7f, 0.2f, -5.0f);
	glVertex3f(-1.7f, -0.2f, -5.0f);
	glVertex3f(-1.5f, -0.1f, -5.0f);
	glEnd();
	//banner-
	glBegin(GL_LINES);
	glVertex3f(-1.7f, 0.0f, -5.0f);
	glVertex3f(-2.1f, 0.0f, -5.0f);
	glEnd();
	//banner
	glColor3f(1.2, 1.2, 0.1);
	glLineWidth(2.0);
	
	glBegin(GL_LINE_LOOP);
	glVertex3f(-2.1f, 0.3f, -5.0f);
	glVertex3f(-4.8f, 0.3f, -5.0f);
	glVertex3f(-4.8f, -0.3f, -5.0f);
	glVertex3f(-2.1f, -0.3f, -5.0f);
	glEnd();

}

void ads()
{
	glColor3f(1.0, 0.0, 0.0);
	print(-4.50, 0.0, -5.0, "SG SALE-50% OFF");
	
}
void logo()
{
	glColor3ub(10, 10, 9);
	print(-0.60, -0.3, -5.0, "SG STORE");
	glRasterPos3f(-0.75, 0.0, -5.0);
}

void chopperMovement()
{
		glTranslatef(Cx, 0.0, 0.0);
		Cx = Cx + Cincrmt;
		counter++;
		if (Cx >= 15.5)
		{
			Cx = -6;
		}
}

void bodyMovement()
{
	if (counter <= 5500)
	{
		glTranslatef(tx, 0.0, 0.0);
		tx = tx + forwardIncrmt;
		counter++;
	}
	else if (counter > 5500 && counter <= 9000)
	{
		glTranslatef(tx, 0.0, 0.0);
		counter++;
	}
	else if (counter > 9000 && counter<=15000)
	{
		glTranslatef(tx, 0.0, 0.0);
		tx = tx + forwardIncrmt;
		counter++;
	}
	else if (counter > 15000 && counter <=16500)
	{
		glTranslatef(tx, 0.0, 0.0);
		counter++;

	}
	else
	{
		glTranslatef(tx, 0.0, 0.0);
		tx = tx - backwardIncrmt;
	}
}

void leftHandMovement()
{
	if (counter <= 5500)
	{
		glTranslatef(-1.0, 0.8, -5.0);
		glRotatef(movTheta, 0.0, 0.0, 1.0);
		glTranslatef(1.0, -0.8, 5.0);
	}
	else if (counter > 5500 && counter <= 9000)
	{
		glTranslatef(-1.0, 0.8, -5.0);
		glRotatef(-15, 0.0, 0.0, 1.0);
		glTranslatef(1.0, -0.8, 5.0);
	}
	else if (counter > 9000 && counter <= 15000)
	{
		glTranslatef(-1.0, 0.8, -5.0);
		glRotatef(movTheta, 0.0, 0.0, 1.0);
		glTranslatef(1.0, -0.8, 5.0);
	}
	else if (counter > 15000)
	{
		glTranslatef(-1.0f, 0.8f, -5.0f);
		glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.0f, -0.8f, 5.0f);
	}
}
void rightHandMovement()
{
	if (counter <= 5500)
	{
		glTranslatef(-1.0f, 0.8f, -5.0f);
		glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.0f, -0.8f, 5.0f);
	}
	else if (counter > 5500 && counter <= 9000)
	{
		glTranslatef(-1.0, 0.8, -5.0);
		glRotatef(120, 0.0, 0.0, 1.0);
		glTranslatef(1.0, -0.8, 5.0);
	}
	
	else if (counter > 9000 && counter <=15000) 
	{
		glTranslatef(-1.0f, 0.8f, -5.0f);
		glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.0f, -0.8f, 5.0f);
	}
	else if (counter > 15000)
	{
		glTranslatef(-1.0f, 0.8f, -5.0f);
		glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.0f, -0.8f, 5.0f);
	}
}
void leftArmMovement()
{
	if (counter <= 5500)
	{
		glTranslatef(-1.01f, 0.6f, -5.0f);
		glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.01f, -0.6f, 5.0f);
	}
	else if (counter > 5500 && counter <= 9000)
	{
		glTranslatef(-1.01f, 0.6f, -5.0f);
		glRotatef(15, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.01f, -0.6f, 5.0f);
	}
	else if (counter > 9000 && counter <= 15000)
	{
		glTranslatef(-1.01f, 0.6f, -5.0f);
		glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.01f, -0.6f, 5.0f);
	}
	else if (counter >15000)
	{
		glTranslatef(-1.01f, 0.6f, -5.0f);
		glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(1.01f, -0.6f, 5.0f);
	}

}
void rightArmMovement()
{
	if (counter <= 5500)
	{
		glTranslatef(-0.99f, 0.6f, -5.0f);
		glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.99f, -0.6f, 5.0f);
	}
	else if (counter > 5500 && counter <=7800)
	{
		
		glTranslatef(-0.99f, 0.6f, -5.0f);
		glRotatef(120, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.99f, -0.6f, 5.0f);
					
	}
	else if (counter > 7800 && counter <= 9000)
	{
		glTranslatef(-0.99f, 0.6f, -5.0f);
		glRotatef(180, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.99f, -0.6f, 5.0f);
	}
	
	else if (counter > 9000 && counter <= 15000)
	{
		glTranslatef(-0.99f, 0.6f, -5.0f);
		glRotatef(-movTheta, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.99f, -0.6f, 5.0f);
	}
	else if (counter > 15000)
	{
		glTranslatef(-0.99f, 0.6f, -5.0f);
		glRotatef(-45.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(0.99f, -0.6f, 5.0f);

	}
}
void leftLegMovement()
{
	if (counter <= 5500)
	{
		glTranslatef(-1.0, 0.5, -5.0);
		glRotatef(-movTheta, 0.0, 0.0, 1.0);
		glTranslatef(1.0, -0.5, 5.0);
	}
	else if (counter > 5500 && counter <=9000)
	{
		glTranslatef(-1.0, 0.5, -5.0);
		glRotatef(15, 0.0, 0.0, 1.0);
		glTranslatef(1.0, -0.5, 5.0);
	}
	else  
	{
		glTranslatef(-1.0, 0.5, -5.0);
		glRotatef(-movTheta, 0.0, 0.0, 1.0);
		glTranslatef(1.0, -0.5, 5.0);
	}
}

void rightLegMovement()
{
	if (counter <= 5500)
	{
		glTranslatef(-1.0f, 0.5f, -5.0f);
		glRotatef(movTheta, 0.0, 0.0, 1.0);
		glTranslatef(1.0f, -0.5f, 5.0f);
	}
	else if (counter > 5500 && counter <=9000)
	{
		glTranslatef(-1.0, 0.5, -5.0);
		glRotatef(-15, 0.0, 0.0, 1.0);
		glTranslatef(1.0, -0.5, 5.0);
	}
	else
	{
		glTranslatef(-1.0f, 0.5f, -5.0f);
		glRotatef(movTheta, 0.0, 0.0, 1.0);
		glTranslatef(1.0f, -0.5f, 5.0f);
	}
}
void giftBoxMov()
{
	if (counter < 16400)
	{
		glTranslatef(giftTanslat, 0.0, 0.0);
		counter++;
	}
	else 
	{
		glTranslatef(giftTanslat, 0.0, 0.0);
		giftTanslat = giftTanslat-giftMov;
	}
}
void cloudMov()
{
	if (counter < 5500)
	{
		glTranslatef(15, 25, -5.0);
		
	}
	else if (counter > 5000 && counter <= 7800)
	{
		
				
		glTranslatef(-2.9, -0.80, 0.0);
		glScalef(0.4, 0.4, 1.0);
		
		
	}
	
	else
	{
		glTranslatef(-2.9, -0.80, 0.0);
		glTranslatef(0.0, ty, 0.0);
		glScalef(0.4, 0.4, 1.0);
		ty = ty + 0.005;
	}
}


void angleTheta()
{
	if (forwardMov)
	{
		movTheta += incTheta;
		if (movTheta > maxTheta)
			forwardMov = false;
	}
	else if (!forwardMov)
	{
		movTheta -= incTheta;
		if (movTheta < -maxTheta)
		
			forwardMov = true;
		
	}
}


void drawStickman()
{
	//body
	glPushMatrix();
	bodyMovement();
	body();
	head();
	neck();
	glPopMatrix();
	//leftHand
	glPushMatrix();
	bodyMovement();
	leftHandMovement();
	leftHand();
	glPopMatrix();
	//leftArm
	glPushMatrix();
	bodyMovement();
	leftHandMovement();
	leftArmMovement();
	leftArm();
	glPopMatrix();
	

	//rightHand
	glPushMatrix();
	bodyMovement();
	rightHandMovement();
	rightHand();
	glPopMatrix();
	
	//rightarm
	glPushMatrix();
	bodyMovement();
	rightHandMovement();
	rightArmMovement();
	rightArm();
	glPopMatrix();
	
	//leftLeg
	glPushMatrix();
	bodyMovement();
	leftLegMovement();
	leftLeg();
	leftShin();
	glPopMatrix();
	
	//rightLeg
	glPushMatrix();
	bodyMovement();
	rightLegMovement();
	rightLeg();
	rightShine();
	glPopMatrix();
	
	angleTheta();
	
}
void display() 
{
	
	glClear(GL_COLOR_BUFFER_BIT);

	

	glPushMatrix();
	glTranslatef(1.0, 0.25, 0.0);
	glScalef(5.5, 1.0, 1.0);
	road();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.0f, 0.05f, 0.5f);
	glScalef(2.0f, 2.0f, 2.0f);
	front();
	Door();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.45f, 0.02f, 0.5f);
	giftBoxMov();
	giftBox();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6.8f, -1.77f, 0.0f);
	glScalef(0.7, 0.7, 1.0);
	drawStickman();
	glPopMatrix();

	

	glPushMatrix();
	glTranslatef(3.0f,0.05f,0.5f);
	glScalef(2.0f, 2.0f, 2.0f);
	drawHouse();
	logo();
	glPopMatrix();

	//cloud
	glPushMatrix();
	cloudMov();
	think();
	glPopMatrix();

	glPushMatrix();
	glScalef(0.5, 0.5, 1.0);
	glTranslatef(-3.0, 3.0, 0.0);
	chopperMovement();
	chopper();
	ads();
	glPopMatrix();
	
	roadMark();
	
	
	glFlush();
	
}
void Timer(int value)
{
	
	glutPostRedisplay();
	glutTimerFunc(timer, Timer, value);
}


int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 1500); 
	glutInitWindowPosition(0, 0);
	initRendering();
	glutCreateWindow("SG Advert");
	glutDisplayFunc(display);
	glutReshapeFunc(handleResize);
	glutTimerFunc(timer, Timer, 1);
	init();
	glutMainLoop(); 
	return 0;
}