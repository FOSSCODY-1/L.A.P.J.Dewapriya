#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int width = 30;
int hight = 15;

int snakeX, snakeY;
int fruitX = 10, fruitY = 10;
int score = 0;

int f, b, r, l;
bool stop = true;


void display(void);
void input(void);
void logic(void);

int main(){
	
	//char c = getch();
	snakeX = 4;
	snakeY = 4;

	while(1){
		display();
		input();
		logic();
		Sleep(100);
	}
	
	
	
	return 0;
}


void display(void){
	
	system("CLS");
	cout << "        Snake Game" << endl;
	
	for(int i = 0; i < hight; i++){
		
		for(int j = 0; j < width; j++){
			
			if( (i == 0 || i == hight - 1 ) || (j == 0 || j == width - 1)){
				cout << "#";
			}
			else{
				
				
				if(i == snakeY && j == snakeX){
					
					cout << "o";
				}
				else if(i == fruitY && j == fruitX){
					cout << "@";
				}
				else{
					
						cout << " ";
					
				}
				
			}
		}
		
		cout << endl;
	}
	
	cout << endl;
	cout << "Score : " << score;
	cout << endl;
	cout << "fx" << fruitX << " fy" << fruitY << endl;
	cout << "sx" << snakeX << " sy" << snakeY;
	
	
}

void input(void){
	
	if(kbhit()){
		switch(getch()){
		
		case 'w': f = 1;
				  b = 0;
				  r = 0;
				  l = 0;
				  break;
		case 's': f = 0;
				  b = 1;
				  r = 0;
				  l = 0;
				  break;
		case 'd': f = 0;
				  b = 0;
				  r = 1;
				  l = 0;
				  break;
		case 'a': f = 0;
				  b = 0;
				  r = 0;
				  l = 1;
				  break;		  
	}
		
	}
	
	
	
}

void logic(){
	if(fruitX == snakeX && fruitY == snakeY){
		score++;
		
		fruitX = rand() % width - 2;
		fruitY = rand() % hight + 2;
	}
	
	if(snakeY == 1 && f == 1){
		
		snakeY = hight - 2;
	}
	else if(snakeY == hight - 2 && b == 1){
		snakeY = 1;
	}
	else if(snakeX == 1 && l == 1){
		snakeX = width - 2;
	}
	else if(snakeX == width - 2 && r == 1){
		snakeX = 1;
	}
	else{
		if(f == 1){
		snakeY--;
	}
	else if(b == 1){
		snakeY++;cd
	}
	else if(r == 1){
		snakeX++;
	}
	else if(l == 1){
		snakeX--;
	}
	}
	
	
	
}

