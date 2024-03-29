#include <assert.h>
#include <iostream>

char** maze;
int maze_size;
int start_row, start_col;
int stop_row, stop_col;

//Structure of labirynth
typedef struct step_t {
	struct step_t* up, *down, *left, *right;
	int r, c;
} step_t;

void maze_read(const char* file_name, int size)
{
	FILE* f = fopen(file_name, "r");
	assert(f != NULL);

	// alokacja wierszy
	maze = (char**)malloc(sizeof(char*) * size);
	maze_size = size;
	assert(maze != NULL);

	// alokacja i wczytanie kolumn
	for (int r = 0; r < size; r++) {
		maze[r] = (char*)malloc(sizeof(char) * size);
		assert(maze[r] != NULL);

		for (int c = 0; c < size; c++) {
			maze[r][c] = fgetc(f);
			if (maze[r][c] == 'a') { // znalaz�em start
				start_row = r;
				start_col = c;
			}
			if (maze[r][c] == 'b') { // znalaz�em stop
				stop_row = r;
				stop_col = c;
				maze[r][c] = ' ';
			}
		}

		fgetc(f); // zjedz znak nowej linii
	}

	fclose(f);
}
void maze_show(int size)
{
	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
			putchar(maze[r][c]);
		putchar('\n');
	}
}

step_t* make_step(int new_col, int new_row)
{
	step_t* pstep = (step_t*)calloc(1, sizeof(step_t));
	assert(pstep != NULL);
	pstep->r = new_row;
	pstep->c = new_col;
	return pstep;
}

int go(step_t* me) {

	// czy stan��em w wyj�ciu?
	if (me->r == stop_row && me->c == stop_col)
		return 1; // tak! wracam natychmiat do punktu startowego, bo znam ju� drog�. Droga jest oznaczona 'x' w mapie

	maze[me->r][me->c] = '+'; // oznacz miejsce, w kt�rym by�em

	// czy mog� i�� w g�r�?
	if (maze[me->r - 1][me->c] == ' ') {
		me->up = make_step(me->c, me->r - 1);
		if (go(me->up)) // id� do g�ry
			return 1; // wszed�em na STOP
	}

	// czy moge i�c w lewo?
	if (maze[me->r][me->c - 1] == ' ') {
		me->left = make_step(me->c - 1, me->r);
		if (go(me->left)) // no to id� w lewo
			return 1; // wpad�em na STOP
	}

	// czy mog� i�� w d�
	if (maze[me->r + 1][me->c] == ' ') {
		me->down = make_step(me->c, me->r + 1);
		if (go(me->down)) // id� w d�
			return 1; // wpad�em na STOP
	}

	// czy mog� i�� w prawo?
	if (maze[me->r][me->c + 1] == ' ') {
		me->right = make_step(me->c + 1, me->r);
		if (go(me->right)) // id� w prawo
			return 1; // wszed�em na STOP
	}

	// niczego nie znalaz�em, cofamy si�
	maze[me->r][me->c] = ' '; // wycofujemy si�
	return 0; // wracam jedno pole, bo nie znalaz�em STOPU
}

void maze_solve(const char* file_name, int size)
{
	// wczytaj labirynt
	maze_read(file_name, size);

	// ustal punkt startowy
	step_t* pstart = make_step(start_col, start_row);

	// id� na start
	int result = go(pstart);

	// ustaw ponownie a i b, bo zosta�y zamazne w trakcie zabawy
	maze[start_row][start_col] = 'a';
	maze[stop_row][stop_col] = 'b';

	// wy�wietl labirynt z tras�
	maze_show(size);
}