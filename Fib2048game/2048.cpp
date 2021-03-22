#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int score = 0;
int count = 0;
int arr[4][4];
void generate();
int check();
int move(char);
void display();
void rotatematrix();
int fib[32] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,514229, 832040, 1346269, 2178309 };
int arepair(int, int);
void move2();
char name[50];

struct person
{
	char name2[50];
	int sc;
};

int main()
{
	int x, y, z = 1;
	for (x = 0; x < 4; x++)
		for (y = 0; y < 4; y++)
			arr[x][y] = 0;
	char choice;
	generate();
	printf("Enter name: ");
	gets(name);
	while (check())
	{
		system("CLS");
		printf("Welcome %s\n\n",name);
		printf("To move use W, A, S, D\n\n");
		generate();
		display();
		do{
			printf("\n\nEnter move: ");
			choice = _getch();
			//scanf_s("%c", &choice);
			z = move(choice);
			if (z == 1)
				printf("Invalid move");
		} while (z == 1);
	}
	score = arr[0][0];

	for (int c = 0; c < 4; c++)
	{
		for (int d = 0; d < 4; d++)
		{
			if (arr[c][d] > score)
				score = arr[c][d];
		}
	}

	//Writing
	FILE *outfile;

	// open file for writing
	outfile = fopen("score.txt", "a");
	fprintf(outfile, "%s score is : %d\n",name,score);
	fclose(outfile);
	system("CLS");
	display();
	printf("\nWell played %s", name);
	printf("\nGame Over and your score is %d",score);
	printf("\n\n");
	int choice2 = 0;


	FILE *infile;
	struct person input2;
	char buff[254];
	infile = fopen("score.txt", "r");
	//printf("Do you want to see how many playes played the game. Enter 1 to see : ");
	//scanf("%d", choice2);
	/*if (choice2 == 1)
	{*/
	printf("\nPlayes played the game:\n");
	//Reading
	while (fgets(buff, 254, infile))
	{
		puts(buff);
		printf("\n");
	}
	fclose(infile);
	system("PAUSE");
	/*}
	system("PAUSE");*/
}
int check()
{
	int i, j;
	int flag = 1;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			if (arr[i][j] == 0)
				flag = 0;
	if (flag == 0)
		return 1;
	return 0;
}

void generate()
{
	int x, y;
	do
	{
		x = rand() % 4;
		y = rand() % 4;
	} while (arr[x][y] != 0);
	arr[x][y] = 1;
}
void display()
{
	int i, j;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			if (arr[i][j] == 0)
				printf("|   |");
			else
			printf("| %d |", arr[i][j]);
		printf("\n");
	}
}
int move(char ch)
{
	int i, j;
	int k = 0;
	int flag;
	int max;
	//int x, y;
	if (ch == 'd')
	{
		move2();
		return 0;
	}
	else if (ch == 's')
	{
		rotatematrix();
		move2();
		rotatematrix();
		rotatematrix();
		rotatematrix();
		return 0;
	}
	else if (ch == 'a')
	{
		rotatematrix();
		rotatematrix();
		move2();
		rotatematrix();
		rotatematrix();
		return 0;
	}
	else if (ch == 'w')
	{
		rotatematrix();
		rotatematrix();
		rotatematrix();
		move2();
		rotatematrix();
		return 0;
	}
	else return 1;
}
void move2()
{
	int i, j;
	int k = 0;
	int flag;
	int max;
	//int x, y;
		for (i = 0; i < 4; i++)
		{
			k = 3;
			max = arr[i][3];
			for (j = 2; j >= 0; j--)
			{
				if (arepair(arr[i][j], max))
				{
					if (max != 0)
					{
						flag = 1;
						arr[i][k] = arr[i][j] + max;
						arr[i][j] = 0;
						max = 0;
						k = j;
					}
				}
				if (arr[i][j])
				{
					max = arr[i][j];
					k = j;
				}
			}
			for (j = 2; j >= 0; j--)
			{
				k = j;
				while (arr[i][k + 1] == 0 && (k + 1) <= 3)
				{
					if (arr[i][k])
						flag = 1;
					arr[i][k + 1] = arr[i][k];
					arr[i][k] = 0;
					k++;
				}
			}

		}
}
int arepair(int a, int b)
{
	if ((a == 1 && b == 1) || (a == 2 && b == 1) || (a == 1 && b == 2) )
		return 1;
	if (a == 2178309 && b == 1346269)
		return 1;
	for (int i = 0; i < 32;i++)
		if (a == fib[i])
		{
			if (b == fib[i - 1] || b == fib[i + 1])
				return 1;
			return 0;
		}
	return 0;
}
void rotatematrix()
{
	for (int x = 0; x < 4 / 2; x++)
	{
		for (int y = x; y < 4 - x - 1; y++)
		{
			int temp = arr[x][y];
			arr[x][y] = arr[y][4 - 1 - x];
			arr[y][4 - 1 - x] = arr[4 - 1 - x][4 - 1 - y];
			arr[4 - 1 - x][4 - 1 - y] = arr[4 - 1 - y][x];
			arr[4 - 1 - y][x] = temp;
		}
	}
}
//system("CLS"); to clear the screen