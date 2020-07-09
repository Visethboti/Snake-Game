// Author: Visethboti Sin
// Date: 9/July/2020

#include "pch.h"
#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

//Global variables
boolean gameOver = false;
int width = 20, height = 20;
int x, y, ballX, ballY;


void setup() {

}

void draw() {

}

void move() {

}

void check() {

}

int main()
{
	for (int i = 0; i < 10; i++) {
		system("cls");
		cout << i << width << height << endl;
		Sleep(1000);
	}
}
