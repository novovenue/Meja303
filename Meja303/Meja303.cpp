////////////////////////////////////////////////////////////////////          
// boxWithLookAt.cpp
//
// Novia Zulfa Fitri                 5222600048
// Devina Yusra Wijaya               5222600055
// Sumanta Guha.
//
////////////////////////////////////////////////////////////////////

#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h> 
#include <GL/gl.h> 
#include <GL/glu.h>

//#include "getBMP.h"

using namespace std;

float _angle = -70.0f;
float rotateX = 0.0f;
float rotateY = 0.0f;

float rotationSpeed = 1.0f;  // Kecepatan rotasi
bool rotating = false;  // Status rotasi

/*void loadTextures()
{
	imageFile *image[1];

	image[0] = getBMP("../../Textures/screen.bmp");


	glBindTexture(GL_TEXTURE_2D, texture[0]);

	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image[0]->width, image[0]->height, 0,
	           	 GL_RGBA, GL_UNSIGNED_BYTE, image[0]->data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}*/

void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH);
}

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void drawTable() {
    // ... (bagian kode gambar meja tetap sama)
    glColor3f(1.0f, 1.0f, 1.0f);  // Atur warna menjadi putih

    // Gambar papan atas meja
    glPushMatrix();
    glScalef(4.0f, 0.2f, 2.0f);  // Atur skala papan atas meja (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    // Gambar lemari bawah meja KANAN
    /*glPushMatrix();
    glScalef(1.4f, 1.0f, 1.6f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glTranslatef(0.6f, -0.6f, 0.0f);  // Geser ke bawah
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();*/

    //LEMARI pop
    glPushMatrix();
    glScalef(1.4f, 0.4f, 0.09f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glTranslatef(0.6f, -2.2f, 9.2f);  // Geser ke bawah
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glScalef(1.4f, 0.4f, 0.09f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glTranslatef(0.6f, -1.0f, 9.2f);  // Geser ke bawah
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //pengangan lemari
    glPushMatrix();
    glTranslatef(0.85f, -0.4f, 0.88f);  // Geser ke bawah
    glScalef(0.4f, 0.05f, 0.08f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.85f, -0.85f, 0.88f);  // Geser ke bawah
    glScalef(0.4f, 0.05f, 0.08f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    // Gambar kaki meja 1
    glPushMatrix();
    glTranslatef(-1.6f, -1.0f, -0.8f);  // Geser ke posisi kaki meja 1
    glScalef(0.2f, 1.8f, 0.2f);  // Atur skala kaki meja 1 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6f, -1.0f, -0.8f);  // Geser ke posisi kaki meja 2
    glScalef(0.2f, 1.8f, 0.2f);  // Atur skala kaki meja 2 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6f, -1.0f, 0.8f);  // Geser ke posisi kaki meja 3
    glScalef(0.2f, 1.8f, 0.2f);  // Atur skala kaki meja 3 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.6f, -1.0f, 0.8f);  // Geser ke posisi kaki meja 4
    glScalef(0.2f, 1.8f, 0.2f);  // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //2 kaki horizontal BAWAH
    glPushMatrix();
    glTranslatef(1.6f, -1.8f, -0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.2f, 1.8f, 0.2f);   // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6f, -1.8f, -0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.2f, 1.8f, 0.2f);   // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //2 kaki horizontal ATAS
    glPushMatrix();
    glTranslatef(1.6f, -0.2f, -0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.2f, 1.8f, 0.2f);   // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6f, -0.2f, -0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.2f, 1.8f, 0.2f);   // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //penutup kaki meja belakang
    glPushMatrix();
    glTranslatef(0.0f, -0.6f, -0.8f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glScalef(1.0f, 3.2f, 0.1f);  // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    //2 penutup samping meja
    glPushMatrix();
    glTranslatef(1.6f, -0.8f, 0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.8f, 1.8f, 0.1f);  // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.6f, -0.8f, 0.0f);  // Geser ke posisi kaki meja 4
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glScalef(0.8f, 1.8f, 0.1f);  // Atur skala kaki meja 4 (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    // Gambar lemari bawah meja KANAN
    glPushMatrix();
    glColor3f(0.1f, 0.1f, 0.1f);  // Atur warna menjadi hitam
    glTranslatef(0.8f, -0.6f, 0.0f);  // Geser ke bawah
    glScalef(1.2f, 1.0f, 1.6f);  // Atur skala lemari meja (panjang, lebar, tinggi)
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();


}

void drawTV() {

    // ... (bagian kode gambar meja tetap sama)
    glColor3f(0.1f, 0.1f, 0.12f);  // Atur warna menjadi

    // Gambar TV
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);  
    glScalef(3.8f, 2.2f, 0.1f);  // Atur skala TV
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.5f, -0.05f);  // Geser ke BELAkang
    glScalef(3.6f, 2.2f, 0.05f);  // perkecil
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0.0f, 1.5f, -0.1f);  // Geser ke belakang
    glScalef(3.5, 2.1f, 0.05f);  // perekcil
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 1.5f, -0.15f);  // Geser ke belakang
    glScalef(3.4, 2.0f, 0.05f);  // pekecil
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    // Gambar KAKI KANAN
    glPushMatrix();
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glTranslatef(1.6f, 0.02f, -0.25f); //Geser ke belakang
    glScalef(0.15f, 0.52f, 0.1f);  // perkecil
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    glPushMatrix();
    glRotatef(45.0, -1.0, 0.0, 0.0);
    glTranslatef(1.6f, -0.02f, 0.25f); // Geser ke depanm
    glScalef(0.15f, 0.52f, 0.1f);  // perkecil
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();

    // Gambar KAKI KIRi
    glPushMatrix();
    glRotatef(45.0, 1.0, 0.0, 0.0);
    glTranslatef(-1.6f, 0.02f, -0.25f); //Geser ke belakang
    glScalef(0.15f, 0.52f, 0.1f);  // perkecil
    glutSolidCube(1.0);  // Gambar kubus solit
    glPopMatrix();

    glPushMatrix();
    glRotatef(45.0, -1.0, 0.0, 0.0);
    glTranslatef(-1.6f, -0.02f, 0.25f); // Geser ke depanm
    glScalef(0.15f, 0.52f, 0.1f);  // perkecil
    glutSolidCube(1.0);  // Gambar kubus solid
    glPopMatrix();
}

void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0.96f, 0.87f, 0.7f, 1.0f); 

    //glBindTexture(GL_TEXTURE_2D, texture[id]);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.0f, 0.0f, -14.0f);
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);

    GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat lightPos0[] = { 0.0f, -8.0f, 8.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    drawTable();
    drawTV();
    glutSwapBuffers();

}



void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
        rotateX -= 5.0f;
        break;
    case GLUT_KEY_DOWN:
        rotateX += 5.0f;
        break;
    case GLUT_KEY_LEFT:
        rotateY -= 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        rotateY += 5.0f;
        break;

    
    }
    glutPostRedisplay();
}

void update(int value) {
    _angle += 1.5f;
    if (_angle > 360) {
        _angle -= 360;
    }

    rotateY += 0.5f;

    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);

    glutCreateWindow("Table");
    initRendering();

    glutDisplayFunc(drawScene);
    glutReshapeFunc(handleResize);

    //glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    update(0);

    glutMainLoop();

    return 0;
}