#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;


int width = 36; /*To Set the Width of the Gamming Area*/
int height = 18;  /*To Set the Height of the Gamming Area*/

int snakeX, snakeY; /*X and Y cordinates of Snake`s Head */
int fruitX = 10, fruitY = 10; /*X and Y cordinates of fruit or the food */
int tailX[30], tailY[15]; /*X and Y cordinates of Snake`s Tail */
int score = 0;  /*Player`s Score*/

int f, b, r, l;//Directions
bool stop = true;
bool gameOver = false;
bool loop = true;

char name[50];//Player`s name
int speed = 100;  //To Set the Speed of the Snake`s Movement


void display(void);//Draw the Graphical interface of the game
void input(void);  //To Take the User Input; Key Board Input
void logic(void);  //Check the Logical Requirements of the Game and Apply Logics through decisions
void setup(void); // To Inialize the Game

void goAnimation(void);

int main(){

	char opt;

	while(loop){
		
		
		system("CLS");
		setup();
		
		cout << "**********************Welcome to The Snake Game***************************";
	
	cout << "\n\nEnter Player`s Name : ";
	cin >> name;
		
		while(!gameOver){
			
			display();
			input();
			logic();
			Sleep(speed);
			
	}
	
	goAnimation(); // To Display a Simple Animation After Game is Over
	
	cout << "\n\n!!!!!!!!!!Game Over!!!!!!!!";
	system("CLS");
	cout << "**********************Welcome to The Snake Game***************************" << endl << endl;
		
		cout << "Do You Want To Play Again? (Y/N) : ";
		cin >> opt;
		
		if(opt == 'n' || opt == 'N'){
			loop = false;
		}
		
	}
	
	system("CLS");
	cout << "\n#########################Good Bye########################";

	
	
	
	
	return 0;
}


void display(void){
	
	system("CLS");
	cout << "**********************Welcome to The Snake Game***************************" << endl << endl;
	
	for(int i = 0; i < height; i++){
		
		for(int j = 0; j < width; j++){
			
			if( (i == 0 || i == height - 1 ) || (j == 0 || j == width - 1)){
				cout << "#";// Draw the Boundaries
			}
			else if(i == snakeY && j == snakeX){	
				cout << "Q";//Draw the Snakes`s Head
				
				
			}
			else if(i == fruitY && j == fruitX){
				cout << "@";// Draw the Fruit
			}
			else{
				
				bool print = false;
				
				/*Drawing the Tail*/
				for(int k = 0; k < score; k++){
					
					if(tailX[k] == j && tailY[k] == i){
						cout << "o";
						print = true;
						
					}
				}
				if(!print){
					cout << " ";
				}
						
			}
				
				
				
		}
		
		cout << endl;
	}
	
	cout << endl;
	cout << name <<  "`s Score : " << score * 5;
	cout << endl;
	
	/*To Debugging Purposes*/
//	cout << "fx" << fruitX << " fy" << fruitY << endl;
//	cout << "sx" << snakeX << " sy" << snakeY;
	
	
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
		case 'W': f = 1;
				  b = 0;
				  r = 0;
				  l = 0;
				  break;
		case 'A': f = 0;
				  b = 0;
				  r = 0;
				  l = 1;
				  break;
		case 'D': f = 0;
				  b = 0;
				  r = 1;
				  l = 0;
				  break;
		case 'S': f = 0;
				  b = 1;
				  r = 0;
				  l = 0;
				  break;
				  		  	  
	}
		
	}
	
	
	
}

void logic(){
	
	/*To Check wether Snake has eaten itself*/
	for(int k = 0; k < score; k++){
		if(tailX[k] == snakeX && tailY[k] == snakeY){
			gameOver = true;
		}
	}
	
	/*Apply the logic to build the Tail According to the Score*/
	int prevX, prevY,prev2X, prev2Y;
	
	prevX = tailX[0];
	prevY = tailY[0];
	tailX[0] = snakeX;
	tailY[0] = snakeY;
	
	for(int i = 1; i < score; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
		
	}
	
	/*To Check Wether Snake has eaten the fruit/food*/
	if(fruitX == snakeX && fruitY == snakeY){
		score++;//Each time Snake eats a fruit Score is Incremented
		speed--;//Each time Snake eats a fruit Speed is Incremented
		
		/*Generate the X and Y Cordinates of the Fruit Randomly*/
		fruitX = rand() % (width - 2) + 1;
		fruitY = rand() % (height - 2) + 1;
	}
	
	/*To check wether Snake has arrived at boundaries and Determine What to do accordingly*/
	if(snakeY == 1 && f == 1){
		
		snakeY = height - 2;
	}
	else if(snakeY == height - 2 && b == 1){
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
		snakeY--;//Set the Backward Motion of Snake
	}
	else if(b == 1){
		snakeY++;//Set the Forward Motion of Snake
	}
	else if(r == 1){
		snakeX++;//Set the leftward Motion of Snake
	}
	else if(l == 1){
		snakeX--;//Set the Rightward Motion of Snake
	}
	}
	
	
	
	
	
}

void goAnimation(void){
	system("CLS");
	cout << "**********************Welcome to The Snake Game***************************" << endl << endl;
	
	cout << "\nOops! You have eaten yourself!!!!!!!\n";
	
	for(int i = 0; i < height; i++){
		
			for(int j = 0; j < width; j++){
			cout << "#";
			
			Sleep(10);
		}
		cout << "\n";
		
	}
	cout <<"\n\n" << name << "`s Highest Score is " << score * 5 << "\n\n";
	cout << "\nTry Again\n";
	Sleep(2000);	
}

void setup(void){
	snakeX = 5;
	snakeY = 5;
	score = 0;
	stop = true;
	gameOver = false;
	f = 0;
	b = 0;
	r = 0;
	l = 0;
	speed = 100;
}

