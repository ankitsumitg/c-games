#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int table[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 0 } };
int count = 0;

void displayTable(void);
void moveNumbers(void);
void moveRight(void);
void moveLeft(void);
void moveUp(void);
void moveDown(void);
void ownsetup(void);
void randomizer(void);
int checkForFinish(void);

int main(void)
{
	int RorY;
	printf("Hello, and welcome to Hunter's 15-puzzle!\n");
	printf("To play a Randomly Generated Puzzle Press r\n");
	printf("To set up your own puzzle press y\n");
	RorY = getchar();
	if (RorY == 'r')
		randomizer();
	if (RorY == 'o')
		ownsetup();
	displayTable();
	while (true){
		moveNumbers();
		if (checkForFinish()){
			printf("You win.\n");
			break;
		}
	}
}

//function used to set up your own grid
void ownsetup(){
	printf("\nPlease enter the numbers for the top row from left to right\n");
	printf("followed by the numbers for the second row from left to right, etc.\n");
	printf("Please do not forget to press enter in between each number.\n");
	scanf("%d", &table[0][0]);
	scanf("%d", &table[0][1]);
	scanf("%d", &table[0][2]);
	scanf("%d", &table[0][3]);
	scanf("%d", &table[1][0]);
	scanf("%d", &table[1][1]);
	scanf("%d", &table[1][2]);
	scanf("%d", &table[1][3]);
	scanf("%d", &table[2][0]);
	scanf("%d", &table[2][1]);
	scanf("%d", &table[2][2]);
	scanf("%d", &table[2][3]);
	scanf("%d", &table[3][0]);
	scanf("%d", &table[3][1]);
	scanf("%d", &table[3][1]);
	scanf("%d", &table[3][1]);
}

//function used to move the numbers in the grid
void moveNumbers(){
	int key;
	printf("\n\nEnter a letter(I, J, K or M): ");
	key = getchar();
	if (key == 'j')
		moveLeft();
	if (key == 'k')
		moveRight();
	if (key == 'i')
		moveUp();
	if (key == 'm')
		moveDown();
	displayTable();
}

//moves the number to the right
void moveRight(){
	int temp, i, j;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if (table[i][j] == 0 && j != 0){
				temp = table[i][j - 1];
				table[i][j - 1] = 0;
				table[i][j] = temp;
			}
		}
	}
}

//moves the number to the left
void moveLeft(){
	int temp, i, j;
	for (i = 3; i >= 0; i--){
		for (j = 3; j >= 0; j--){
			if (table[i][j] == 0 && j != 3){
				temp = table[i][j + 1];
				table[i][j + 1] = 0;
				table[i][j] = temp;
			}
		}
	}
}

//moves the number up
void moveUp(){
	int temp, i, j;
	for (i = 3; i >= 0; i--){
		for (j = 3; j >= 0; j--){
			if (table[i][j] == 0 && i != 3){
				temp = table[i + 1][j];
				table[i + 1][j] = 0;
				table[i][j] = temp;
			}
		}
	}
}

//moves the number down
void moveDown(){
	int temp, i, j;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if (table[i][j] == 0 && i != 0){
				temp = table[i - 1][j];
				table[i - 1][j] = 0;
				table[i][j] = temp;
			}
		}
	}
}

//function used to display the table 
void displayTable(){
	int i, j;
	for (i = 0; i < 4; i++){
		printf("\n\n");
		for (j = 0; j < 4; j++){
			if (table[i][j] == 0)
				printf("      ");
			else if (table[i][j] < 10)
				printf(" %d    ", table[i][j]);
			else
				printf("%d    ", table[i][j]);
		}
	}
	printf("\n");
}

//function used to randomize the grid
void randomizer(){
	srand(time(NULL));
	char unsigned x = rand() % 4;
	if (x = 0)
	{
		moveUp();
	}
	else if (x = 1)
	{
		moveDown();
	}
	else if (x = 2)
	{
		moveLeft();
	}
	else if (x = 3)
	{
		moveRight();
	}
}

//function used to spot a winning board
int checkForFinish(void){
	int i, j, temp, result;
	result = 0;
	temp = 1;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			if (table[i][j] == temp){
				temp += 1;
			}
		}
	}
	if (temp == 15)
		result = 1;
	return result;
}