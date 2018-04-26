//Seth Perts
//CPSC 444
//Project Connect 4
//Main where game takes place and glut is handled. Uses mouse clicks and text
//to make game feel natural
#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <stdlib.h>
using namespace std;

#include "Board.h"

void display();
void processMouse(int button, int state, int x, int y);
void NormalKeys(unsigned char key, int x, int y);
void myInit();
void text();
void printString(const char *string, float x, float y);
void handleReshape(GLsizei width, GLsizei height);
void error();
void playerWin();
void AIWin();
void AIMove();

int background;
int board;
int WIDTH = 1000;
int HEIGHT = 1000;
Board b;

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Seth Perts Connect 4");

	glClearColor(0.35, 0.35, 0.35, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	myInit();
	glutReshapeFunc(handleReshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(NormalKeys);
	glutMouseFunc(processMouse);
	glutMainLoop();

	int t;
	cin >> t;
	return 0;
}

void myInit(void)
{
	srand(time(0));
	background = glGenLists(1);
	glNewList(background, GL_COMPILE);
	glColor3f(0.0, 0.0, .8);
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex2f(1.0, 3.0);
	glVertex2f(1.0, 9.0);
	glVertex2f(2, 3.0);
	glVertex2f(2, 9.0);
	glVertex2f(3, 3.0);
	glVertex2f(3, 9.0);
	glVertex2f(4, 3.0);
	glVertex2f(4, 9.0);
	glVertex2f(5, 3.0);
	glVertex2f(5, 9.0);
	glVertex2f(6, 3.0);
	glVertex2f(6, 9.0);
	glVertex2f(7, 3.0);
	glVertex2f(7, 9.0);
	glVertex2f(8, 3.0);
	glVertex2f(8, 9.0);

	glVertex2f(1, 3.0);
	glVertex2f(8, 3.0);
	glVertex2f(1, 4.0);
	glVertex2f(8, 4.0);
	glVertex2f(1, 5.0);
	glVertex2f(8, 5.0);
	glVertex2f(1, 6.0);
	glVertex2f(8, 6.0);
	glVertex2f(1, 7.0);
	glVertex2f(8, 7.0);
	glVertex2f(1, 8.0);
	glVertex2f(8, 8.0);
	glVertex2f(1, 9.0);
	glVertex2f(8, 9.0);
	glEnd();
	glEndList();
}


void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius, string color)
{
	int i;
	int triangleAmount = 20; //# of triangles used to draw circle

							 //GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * M_PI;
	if (color == "black")
	{
		glColor3f(0.0, 0.0, 0.0);
		//this code beneath was from github https://gist.github.com/linusthe3rd/803118
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
		//this code above was from github https://gist.github.com/linusthe3rd/803118
	}
	else if (color == "red")
	{
		glColor3f(.7, 0.0, 0.0);
		//this code beneath was from github https://gist.github.com/linusthe3rd/803118
		glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for (i = 0; i <= triangleAmount; i++) {
			glVertex2f(
				x + (radius * cos(i *  twicePi / triangleAmount)),
				y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
		glEnd();
		//this code above was from github https://gist.github.com/linusthe3rd/803118
	}

}

void display()
{
	using namespace std::this_thread; 
	using namespace std::chrono;
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	text();
	glCallList(background);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (b.board[i][j].getControlledBy() == "P")
			{
				drawFilledCircle(j + 1.5, 8.5 - i, 0.4, "black");
			}
			else if (b.board[i][j].getControlledBy() == "A")
			{
				drawFilledCircle(j + 1.5, 8.5 - i, 0.4, "red");
			}
		}
	}
	glPopMatrix();
	if (b.gameOver() == "P")
	{
		playerWin();
		sleep_for(seconds(5));
		b.resetBoard();
		glutPostRedisplay();
	}
	else if (b.gameOver() == "A")
	{
		AIWin();
		sleep_for(seconds(5));
		b.resetBoard();
		glutPostRedisplay();
	}
	glFlush();
}


void NormalKeys(unsigned char key, int x, int y)
{
	if (key == 27 || key == 'q' || key == 'Q')
	{
		exit(0);
	}
	glFlush();
}


void printString(const char *string, float x, float y)
{
	const char *c;
	glRasterPos2f(x, y);
	glLineWidth(5);
	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *c);
	}
}


void text()
{
	glColor3f(1.0, .8, 0.0);
	printString("Welcome to Connect 4", .25, 2.75);
	printString("By: Seth Perts", .25, 2.5);
	printString("---------------------", .25, 2.25);
	printString("The game is played by placing your black pieces on the board.", .25, 2);
	printString("You win when there is four in a row vertically, horizontally, or diagonally.", .25, 1.75);
	printString("You are playing against the computer's red pieces.", .25, 1.5);
	printString("---------------------", .25, 1.25);
	printString("Use the mouse and click a column to get started and remember you must start from the bottom of the board.", .25, 1);
	printString("Good Luck!", .25, .75);
	printString("---------------------", .25, .5);
	printString("Press 'q' or 'esc' to exit the game", .25, .25);
	glFlush();
}


void error()
{
	glColor3f(1.0, 0.0, 0.0);
	printString("Invalid Move, Try Again!", 1, 9.5);
	glFlush();
}


void playerWin()
{
	glColor3f(1.0, 1.0, 1.0);
	printString("PLAYER WIN!   Restarting in 5...", 7, 9.5);
	glFlush();
}


void AIWin()
{
	glColor3f(1.0, 0.0, 0.0);
	printString("AI WIN!   Restarting in 5...", 7, 9.5);
	glFlush();
}

void processMouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
	{
		//cout << x << "  " << y << endl;
		int colSize = WIDTH / 10;
		if (x > colSize && x < 2 * colSize && y < (.7*HEIGHT))
		{
			//cout << "col1\n";
			if (b.isLegalMove(0))
			{
				int move = b.makeMove("P", 0);
				glFlush();
				AIMove();
			}
			else
			{
				error();
			}
		}
		else if (x > 2 * colSize && x < 3 * colSize && y < (.7*HEIGHT))
		{
			//cout << "col2\n";
			if (b.isLegalMove(1))
			{
				int move = b.makeMove("P", 1);
				glFlush();
				AIMove();
			}
			else
			{
				error();
			}
		}
		else if (x > 3 * colSize && x < 4 * colSize && y < (.7*HEIGHT))
		{
			//cout << "col3\n";
			if (b.isLegalMove(2))
			{
				int move = b.makeMove("P", 2);
				glFlush();
				AIMove();
			}
			else
			{
				error();
			}
		}
		else if (x > 4 * colSize && x < 5 * colSize && y < (.7*HEIGHT))
		{
			//cout << "col4\n";
			if (b.isLegalMove(3))
			{
				int move = b.makeMove("P", 3);
				glFlush();
				AIMove();
			}
			else
			{
				error();
			}
		}
		else if (x > 5 * colSize && x < 6 * colSize && y < (.7*HEIGHT))
		{
			//cout << "col5\n";
			if (b.isLegalMove(4))
			{
				int move = b.makeMove("P", 4);
				glFlush();
				AIMove();
			}
			else
			{
				error();
			}
		}
		else if (x > 6 * colSize && x < 7 * colSize && y < (.7*HEIGHT))
		{
			//cout << "col6\n";
			if (b.isLegalMove(5))
			{
				int move = b.makeMove("P", 5);
				glFlush();
				AIMove();
			}
			else
			{
				error();
			}
		}
		else if (x > 7 * colSize && x < 8 * colSize && y < (.7*HEIGHT))
		{
			//cout << "col7\n";
			if (b.isLegalMove(6))
			{
				int move = b.makeMove("P", 6);
				glFlush();
				AIMove();
			}
			else
			{
				error();
			}
		}
		//b.printBoard();
	}
}


void AIMove()
{
	bool found = false;
	while (found != true)
	{
		int num = rand() % 7;
		if (b.isLegalMove(num))
		{
			b.makeMove("A", num);
			glutPostRedisplay();
			found = true;
		}
	}
}


void handleReshape(GLsizei width, GLsizei height)
{
	WIDTH = width;
	HEIGHT = height;
	if (height == 0)
	{
		height = 1;
	}
	//cout << width << "  " << height << endl;
	GLfloat aspect = width / height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height)
	{
		gluOrtho2D(0 * aspect, 10.0 * aspect, 0, 10.0);
	}
	else
	{
		gluOrtho2D(0, 10.0, 0 / aspect, 10 * aspect);
	}
}