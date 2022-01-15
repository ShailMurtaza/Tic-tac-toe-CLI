/*
 * Tic Tac Toe single/2 player console game
 * This will not work in Sololearn playground
 * SHAIL MURTAZA
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void game_mode();
void start_game();
void display_board();
void reset_board();
short check_win();
void clear();
short input(char turn_of);
short get_rand();

short board[9];
short computer = 0;


int main()
{
	while(1) {
		game_mode();
		start_game();
		printf("Wanna play again ....");
		getchar();
		getchar();
	}
	return 0;

}


void game_mode()
{
	clear();
	short choice;
	printf(" 1) Play with COMPUTER\n");
	printf(" 2) 2 PLAYER GAME\n");
	printf(" 3) Exit\n");
	printf(" Enter: ");
	scanf("%hd", &choice);
	
	switch(choice)
	{
		case 1:
			computer = 1;
			break;
		case 2:
			computer = 0;
			break;
		case 3:
			exit(0);
	}
}


void start_game()
{
	short turn = 0;
	short value, part, win;
	char turn_of;
	
	clear();
	reset_board();

	while (turn<9) {
		display_board();
		(turn%2) ? (turn_of = 'X') : (turn_of = 'O');

		if(computer && turn_of == 'X')
			value = get_rand();
		else
			value = input(turn_of);

		value--;
		part = board[value];
		if (value > -1 && value < 9)
		{

			if (part == 10 || part == 11)
			{
				clear();
				printf("Already in use you fool\n");
				continue;
			}
			
			switch(turn_of)
			{
				case 'O':
					board[value] = 10;
					break;
				case 'X':
					board[value] = 11;
					break;
			}
			turn++;
		}
		clear();
		win = check_win();
		if(win)
		{
			switch(win)
			{
				case 10:
					printf("Winner is O\n");
					break;
				case 11:
					printf("Winner is X\n");
					break;
			}
			display_board();
			return;
		}

	}
	display_board();
	printf("This is tie\n");

}


short get_rand()
{
	short num, part;
	srand(time(0));
	
	while(1) {
		num = (rand() % (9 - 1+ 1));
		part = board[num];
		if(!(part == 10 || part == 11))
			return (num+1);
	}
}


void display_board()
{
	short part;


	printf("|---+---+---|\n");
	for(short i=1;i<=9;i++)
	{
		part = board[i-1];

		switch(part)
		{
			case 10:
				printf("| O ");
				break;
			case 11:
				printf("| X ");
				break;
			default:
				printf("| %hd ", part+1);
		}
		if (i%3 == 0)
			printf("|\n|---+---+---|\n");
	}
}


void reset_board()
{
	for(short i=0;i<9;i++)
		board[i] = i;
}


short check_win()
{
	short a, b, c;
	for(short i=0;i<9;i+=3)
	{
		a = board[i];
		b = board[i+1];
		c = board[i+2];
		if(a==b && b==c)
			return a;
	}

	for(short i=0;i<3;i++)
	{
		a = board[i];
		b = board[i+3];
		c = board[i+6];
		if(a==b && b==c)
			return a;
	}
	a = board[0];
	b = board[4];
	c = board[8];
	if(a==b && b==c)
		return a;

	a = board[2];
	b = board[4];
	c = board[6];
	if(a==b && b==c)
		return a;
	return 0;
}


void clear()
{
	// if(system("clear"))
		system("cls");
}

short input(char turn_of)
{
	short n;
	char c;
	short error = 0;

	while(1)
	{
		if(!error)
			printf("Turn of %c: ", turn_of);
		else
			error = 0;

		if(!scanf("%hd", &n))
		{
			clear();
			printf("What you are trying to do fool\n");
			display_board();
			printf("Turn of %c: ", turn_of);
			do
			{
				c = getchar();
			}
			while (!isdigit(c));

			ungetc(c, stdin);
			error = 1;
			continue;
		}
		return n;
	}
}
