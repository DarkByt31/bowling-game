#include <GL/glut.h>
#include <stdlib.h>
#include <cmath>
#include <stdio.h>
#include <SOIL/SOIL.h>

const float pi = 3.1415926535897;
// Dsiplay list
int base, PIN = 1, FLOOR = 2, BALL = 3;
// angle of rotation for the camera direction
float angle=0.0, angle2=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-5.0f, ly=-2.0f;
// XZ position of the camera
float x=0.0f,z=10.0f, y=3.5f;
// position of sphere
float sx = 0.0f, sy = 0.5f, sz = 5.0f, szz = 0.0f, sradius = 0.5f, bowlrot = 0.0f, brr = 0.0f;
// position of pins
float cx=0.0f, cy=0.5f, cz=-5.0f, cradius = 0.5f, rot = -90.0f; // cy is mid point
// screen size
float w = 320, h = 320;
// Collsion
bool isfalling = false;

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;

    // Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

    // Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void drawsinglepin(){

	glNewList(base + PIN, GL_COMPILE);
		GLUquadricObj *quadratic;
		quadratic = gluNewQuadric();
	    float x = 0.0, y = 0.0,r = 2.5f;
	    int segments = 50;
	    glColor3f(1.0f, 1.0f, 1.0f);
	    //glRotatef(rot, 1.0f, 0.0f, 0.0f);
	    glBegin( GL_TRIANGLE_FAN );
	        glVertex2f(x, y);
	        for( int n = 0; n <= segments; ++n ) {
	            float const t = 2 * M_PI * (float)n / (float)segments;
	            glVertex2f(x + sin(t) * r, y + cos(t) * r);
	        }
	    glEnd();

		glColor3f(1.0f, 1.0f, 1.0f);
	    float height = 0.03f,increment = 0.0f,base = 2.5f, top = 2.55f,position = 0.0;
	    for(int i =0; i< 891; i++){
	        glTranslatef(0.0, 0.0, position+0.03);
	        gluCylinder(quadratic, base, top, height, 20, 20);
	        base = top;
	        if((i>=520 && i<545) || (i>=575 && i<600)) glColor3f(1.0f, 0.0f, 0.0f);
	        if((i>=545 && i<575) || (i>600 && i<906)) glColor3f(1.0f, 1.0f, 1.0f);
	        if(i < 20)    top += 0.0093f;
	        else if(i<40)     top += 0.0092f;
	        else if(i<60)    top += 0.0091f;
	        else if(i<80)     top += 0.009f;
	        else if(i<100)    top += 0.0087f;
	        else if(i<120)    top += 0.0085f;
	        else if(i<140)    top += 0.0082f;
	        else if(i<160)    top += 0.0080f;
	        else if(i<180)    top += 0.0075f;
	        else if(i<200)    top += 0.0065f;
	        else if(i<220)    top += 0.0055f;
	        else if(i<240)    top += 0.0045f;
	        else if(i<260)    top += 0.0042f;
	        else if(i<280)    top += 0.0039f;
	        else if(i<300)    top += 0.0037f;
	        else if(i<320)    top += 0.0035;
	        else if(i<340)    top += 0.0031f;
	        else if(i<360)    top += 0.0028f;
	        else if(i<380)    top -= 0.0001f;
	        else if(i<400)    top -= 0.0005f;
	        else if(i<420)    top -= 0.0009f;
	        else if(i<440)    top -= 0.0011f;
	        else if(i<460)    top -= 0.0028f;
	        else if(i<480)    top -= 0.0055f;
	        else if(i<500)    top -= 0.0085f;
	        else if(i<520)    top -= 0.0115f;
	        else if(i<540)    top -= 0.019f;
	        else if(i<560)    top -= 0.025f;
	        //
	        else if(i<562)    top -= 0.038f;
	        else if(i<564)    top -= 0.039f;
	        else if(i<566)    top -= 0.021f;
	        else if(i<568)    top -= 0.024f;
	        else if(i<570)    top -= 0.098f;
	        else if(i<572)    top -= 0.018f;
	        else if(i<574)    top -= 0.028f;
	        else if(i<576)    top -= 0.028f;
	        else if(i<578)    top -= 0.028f;
	        else if(i<580)    top -= 0.028f;
	        else if(i<600)    top -= 0.022f;
	        else if(i<610)    top -= 0.019f;
	        else if(i<620)    top -= 0.003f;
	        else if(i<630)    top -= 0.0038f;
	        else if(i<640)    top -= 0.0035f;
	        else if(i<650)    top += 0.0039f;
	        else if(i<660)    top += 0.0045f;
	        else if(i<670)    top += 0.0053f;
	        else if(i<680)    top += 0.006f;
	        //
	        else if(i<682)    top += 0.0036f;
	        else if(i<683)    top += 0.0046f;
	        else if(i<684)    top += 0.0056f;
	        else if(i<685)    top += 0.0066f;
	        else if(i<686)    top += 0.0076f;
	        else if(i<687)    top += 0.0086f;
	        else if(i<688)    top += 0.0096f;
	        else if(i<689)    top += 0.0106f;
	        else if(i<690)    top += 0.0136f;
	        else if(i<691)    top += 0.0145f;
	        else if(i<692)    top += 0.0149f;
	        else if(i<693)    top += 0.0158f;
	        else if(i<694)    top += 0.0178f;
	        else if(i<695)    top += 0.0232f;
	        else if(i<700)    top += 0.0255f;
	        else if(i<705)    top += 0.0032f;
	        else if(i<710)    top += 0.0024f;
	        else if(i<715)    top += 0.0021f;
	        else if(i<720)    top += 0.0019f;
	        else if(i<725)    top += 0.0015f;
	        else if(i<730)    top += 0.0017f;
	        else if(i<735)    top += 0.0018f;
	        else if(i<740)    top += 0.0020f;
	        else if(i<745)    top += 0.0022f;
	        else if(i<750)    top += 0.0020f;
	        else if(i<755)    top += 0.0018f;
	        else if(i<760)    top += 0.0015f;
	        else if(i<765)    top += 0.0013f;
	        else if(i<770)    top += 0.0011f;
	        else if(i<775)    top += 0.0009f;
	        else if(i<780)    top += 0.0008f;
	        else if(i<785)    top += 0.0005f;
	        else if(i<790)    top += 0.0004f;
	        else if(i<795)    top += 0.0003f;
	        else if(i<800)    top += 0.0002f;
	        else if(i<805)    top += 0.0001f;
	        //
	        else if(i<770+40)    top -= 0.003f;
	        else if(i<773+40)    top -= 0.004f;
	        else if(i<776+40)    top -= 0.005f;
	        else if(i<779+40)    top -= 0.006f;
	        else if(i<782+40)    top -= 0.007f;
	        else if(i<785+40)    top -= 0.009f;
	        else if(i<788+40)    top -= 0.010f;
	        else if(i<791+40)    top -= 0.012f;
	        else if(i<794+40)    top -= 0.014f;
	        else if(i<797+40)    top -= 0.016f;
	        else if(i<800+40)    top -= 0.018f;
	        else if(i<803+40)    top -= 0.020f;
	        else if(i<806+40)    top -= 0.023f;
	        else if(i<809+40)    top -= 0.026f;
	        else if(i<812+40)    top -= 0.030f;
	        else if(i<815+40)    top -= 0.032f;
	        else if(i<818+40)    top -= 0.035f;
	        else if(i<821+40)    top -= 0.038f;
	        else if(i<824+40)    top -= 0.040f;
	        else if(i<827+40)    top -= 0.043f;
	        else if(i<830+40)    top -= 0.048f;
	        else if(i<833+40)    top -= 0.053f;
	        else if(i<836+40)    top -= 0.058f;
	        else if(i<839+40)    top -= 0.065f;
	        else if(i<842+40)    top -= 0.069f;
	        else if(i<845+40)    top -= 0.072f;
	        else if(i<848+40)    top -= 0.078f;
	        else if(i<851+40)    top -= 0.070f;

	    }
	glEndList();
}

void floor_texture()
{
	glNewList(base + FLOOR, GL_COMPILE);
		glEnable(GL_TEXTURE_2D);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		GLuint tex_2d = SOIL_load_OGL_texture
			 (	 "floor1a.tga",
				 SOIL_LOAD_AUTO,
				 SOIL_CREATE_NEW_ID,
				 SOIL_FLAG_COMPRESS_TO_DXT
			 );
		glBindTexture(GL_TEXTURE_2D, tex_2d);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		glBegin(GL_POLYGON);						// Middle Floor
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-4.0f, 0, -12.0f);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(4.0f, 0, -12.0f);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(4.0f, 0, 12.0f);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(-4.0f, 0, 12.0f);
		glEnd();

		glBegin(GL_POLYGON);						// Left Floor
			glTexCoord2f(0.0, 0.0);
			glVertex3f(-12.0f, 0, -12.0f);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(-4.0001f, 0, -12.0f);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(-4.0001f, 0, 12.0f);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(-12.0f, 0, 12.0f);
		glEnd();

		glBegin(GL_POLYGON);						// Right Floor
			glTexCoord2f(0.0, 0.0);
			glVertex3f(4.0f, 0, -12.0f);
			glTexCoord2f(1.0, 0.0);
			glVertex3f(12.0f, 0, -12.0f);
			glTexCoord2f(1.0, 1.0);
			glVertex3f(12.0f, 0, 12.0f);
			glTexCoord2f(0.0, 1.0);
			glVertex3f(4.0f, 0, 12.0f);
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glEndList();
}

void ball_texture()
{
	glNewList(base + BALL, GL_COMPILE);
		glEnable(GL_TEXTURE_2D);
		glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
		GLuint tex2_2d = SOIL_load_OGL_texture
			 (	 "bowl.tga",
				 SOIL_LOAD_AUTO,
				 SOIL_CREATE_NEW_ID,
				 SOIL_FLAG_COMPRESS_TO_DXT
			 );
		glBindTexture(GL_TEXTURE_2D, tex2_2d);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		GLUquadricObj *sphere=NULL;
		sphere = gluNewQuadric();
		gluQuadricDrawStyle(sphere, GLU_FILL);
		gluQuadricTexture(sphere, GLU_TRUE);
		gluQuadricNormals(sphere, GLU_SMOOTH);
		gluSphere(sphere, sradius, 20, 20);
		glDisable(GL_TEXTURE_2D);
	glEndList();
}

void drawpins(){
	float x=0.0f, y = 0.0f, z = 0.0f;

    for(int i = 1; i<= 4; i++){
            x = (i-1)*(-6);
        for(int j = 1; j <= i; j++){
            glPushMatrix();
            glTranslatef(x,y,z);
            glRotatef(rot, 1.0f, 0.0f, 0.0f);
            glCallList(base + PIN);
            glPopMatrix();
            x += 12;
        }
        z -= 6;
	}
}

void drawWall()
{
	// Back Wall
	glPushMatrix();
	glColor3f(226.0/255.0, 187.0/255.0, 56.0/255.0);
	glTranslatef(0, 3.5f, -12.0f);
	glScalef(25, 7, 1);
	glutSolidCube(1);
	glPopMatrix();

	// Left Wall
	glPushMatrix();
	glColor3f(226.0/255.0, 102.0/255.0, 56.0/255.0);
	glTranslatef(-12.5f, 3.5f, -6.0f);
	glRotatef(90.0f, 0, 1, 0);
	glScalef(35, 7, 1);
	glutSolidCube(1);
	glPopMatrix();

	// Right Wall
	glPushMatrix();
	glColor3f(226.0/255.0, 102.0/255.0, 56.0/255.0);
	glTranslatef(12.5f, 3.5f, -6.0f);
	glRotatef(90.0f, 0, 1, 0);
	glScalef(35, 7, 1);
	glutSolidCube(1);
	glPopMatrix();
}

void falling()
{
	rot -= 4.0f;
	if(rot <=-180.0 ){
		rot = -180.0;
		isfalling = false;
	}
}

// TODO: slow down ball speed, change camera to see collision, change value of dist
// TODO2: create 10 cylinder with seperate coordinate variables, check for collision with ball and other cylinder
void checkcollision()
{
	float dist = (float) sqrt((cx - sx)*(cx-sx) + (cy - sy)*(cy-sy) + (cz - sz)*(cz-sz));

	if(dist < cradius + sradius)
		isfalling = true;
}


void renderScene(void) {

	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(	x, y, z,
		x+lx, y+ly,  z+lz,
		0.0f, 1.0f,  0.0f);

	// Render Floor
	glCallList(base + FLOOR);

	// draw bowl
	glPushMatrix();
	sz += szz;
	bowlrot += brr;
	if(bowlrot > 360)	bowlrot = -360;
	glTranslatef(sx ,sy, sz);
	glRotatef(bowlrot, 1.0, 0, 0);
	glCallList(base + BALL);
	glPopMatrix();

	// Draw pins
	glPushMatrix();
	glTranslatef(0, 0, -5.0);
	glScalef(0.08,0.08,0.08);
	drawpins();
	glPopMatrix();

	// Create Wall
	glPushMatrix();
	drawWall();
	glPopMatrix();

	//glPopMatrix();
	if(isfalling)	falling();
	else	checkcollision();

	glutSwapBuffers();
}

void init_texture()
{
	base = glGenLists(3);
	
	drawsinglepin();
	floor_texture();
	ball_texture();
}

void processNormalKeys(unsigned char key, int xx, int yy) {

	float fraction = 0.5f;

	if (key == 27)
		exit(0);
	else if(key == 119){		// W, camera fwd
		x += lx * fraction;
		z += lz * fraction;
		y += ly * fraction;
	}
	else if(key == 115){		// S, camera reverse
		x -= lx * fraction;
		z -= lz * fraction;
		y -= ly * fraction;
	}
	else if(key == 106){	// J, ball left
		if(sx > -2.0)
			sx -= 0.1;
	}
	else if(key == 108){	// L, ball right
		if(sx < 2.0)
			sx += 0.1;
	}
	else if(key == 105){	// I, ball launch
		szz = -0.07;
		brr = -10.0;
	}
	else if(key == 107){	// K, ball reset
		szz = 0.0;
		sz = 5.0f;
		rot = -90.0f;
		brr = 0.0;	bowlrot = 0.0;
	}
	else if(key == 112){	// P, pause
		szz = 0.0;
		brr = 0.0;
	}
	else if(key == 49){		// 1 key
		sx = 1.2f;
	}
	else if(key == 50){		// 2 key
		sx = -1.2f;
	}
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.5f;
	switch (key) {
		case GLUT_KEY_LEFT:
			angle -= 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_RIGHT:
			angle += 0.1f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case GLUT_KEY_UP :
			angle2 += 0.1f;
			ly+=0.5;
			//ly += sin(angle2);
			break;
		case GLUT_KEY_DOWN :
			angle2 -= 0.1f;
			ly-=0.5;
			//ly -= sin(angle2);
			break;
	}
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(320,320);
	glutCreateWindow("Bowling Game");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	init_texture();
	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}

/*
Run using-
g++ -o collision_falling main.cpp -lglut -lGL -lSOIL -lGLU -lm && ./main
*/
