// Author: Visethboti Sin
// Date: 9/July/2020

#include "pch.h"
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <time.h>
#include <conio.h>

using namespace std;

//Global variables
boolean gameOver;
int width, height;
int snakeX, snakeY, ballX, ballY;
enum eMoveDirection {STOP, UP, DOWN, LEFT, RIGHT};
eMoveDirection moveDirection;
char key;
int score;
int snakeSize;
int snakeBody[100][2];

boolean flag_draw_body;

void setup() {
	gameOver = false;
	width = 60;
	height = 20;
	snakeX = width / 2;
	snakeY = height / 2;

	srand(time(NULL));
	ballX = (rand() % (width-2))+1;
	ballY = (rand() % (height-2))+1;

	moveDirection = STOP;
	score = 0;
	snakeSize = 0;
}

void draw() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			// Draw edges
			if (i == 0 || i == height - 1)
				cout << "#";
			else if (j == 0 || j == width - 1)
				cout << "#";
			else if (i == ballY && j == ballX)
				cout << "W";
			else if (i == snakeY && j == snakeX)
				cout << "O";
			else if (snakeSize > 0) {
				flag_draw_body = false;
				for (int k = 0; k < snakeSize; k++) {
					if (i == snakeBody[k][1] && j == snakeBody[k][0]) {
						cout << "o";
						k = snakeSize;
						flag_draw_body = true;
					}
				}
				if (!flag_draw_body)
					cout << " ";
			}
			else
				cout << " ";
		}
		cout << endl;
	}
}

void move() {
	// Snake body
	if (snakeSize > 0) {
		if (snakeSize > 1) {
			for (int i = snakeSize; i > 0; i--) {
				snakeBody[i][0] = snakeBody[i-1][0];
				snakeBody[i][1] = snakeBody[i-1][1];
			}
		}
		snakeBody[0][0] = snakeX;
		snakeBody[0][1] = snakeY;
	}

	key = _getch();
	switch (key) {
	case 'w':
		moveDirection = UP;
		break;
	case 's':
		moveDirection = DOWN;
		break;
	case 'a':
		moveDirection = LEFT;
		break;
	case 'd':
		moveDirection = RIGHT;
		break;
	}

	switch (moveDirection) {
	case UP:
		snakeY--;
		break;
	case DOWN:
		snakeY++;
		break;
	case LEFT:
		snakeX--;
		break;
	case RIGHT:
		snakeX++;
		break;
	}
}

void check() {
	// Check if it hit the edge
	if (snakeX == width-1)
		snakeX = 1;
	else if (snakeX == 0)
		snakeX = width - 2;
	else if (snakeY == height-1)
		snakeY = 1;
	else if (snakeY == 0)
		snakeY = height - 2;
	// Eat the ball
	else if (snakeX == ballX && snakeY == ballY) {
		score++;
		snakeSize++;

		// change ball location
		ballX = (rand() % (width - 2)) + 1;
		ballY = (rand() % (height - 2)) + 1;
	}
}



void printReport() {
	cout << "====|Game Status|====" << endl
		<< "SnakeX: " << snakeX << " | SnakeY:" << snakeY << endl
		<< "BallX: " << ballX << " | BallY: " << ballY << endl
		<< "Score: " << score << "| Snake Size: " << snakeSize << endl;

	for (int i = 0; i < snakeSize; i++) {
		cout << i+1 << ">>>"<< snakeBody[i][0] << "-" << snakeBody[i][1] << endl;
	}
}

int main()
{
	//setup();
	//draw();
	setup();
	for (int i = 0; i < 500; i++) {
		system("cls");
		draw();
		printReport();
		move();
		check();
		//Sleep(500);
	}
}
