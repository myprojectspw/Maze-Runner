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
			if (maze[r][c] == 'a') { // znalaz³em start
				start_row = r;
				start_col = c;
			}
			if (maze[r][c] == 'b') { // znalaz³em stop
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

	// czy stan¹³em w wyjœciu?
	if (me->r == stop_row && me->c == stop_col)
		return 1; // tak! wracam natychmiat do punktu startowego, bo znam ju¿ drogê. Droga jest oznaczona 'x' w mapie

	maze[me->r][me->c] = '+'; // oznacz miejsce, w którym by³em

	// czy mogê iœæ w górê?
	if (maze[me->r - 1][me->c] == ' ') {
		me->up = make_step(me->c, me->r - 1);
		if (go(me->up)) // idê do góry
			return 1; // wszed³em na STOP
	}

	// czy moge iœc w lewo?
	if (maze[me->r][me->c - 1] == ' ') {
		me->left = make_step(me->c - 1, me->r);
		if (go(me->left)) // no to idê w lewo
			return 1; // wpad³em na STOP
	}

	// czy mogê iœæ w dó³
	if (maze[me->r + 1][me->c] == ' ') {
		me->down = make_step(me->c, me->r + 1);
		if (go(me->down)) // idê w dó³
			return 1; // wpad³em na STOP
	}

	// czy mogê iœæ w prawo?
	if (maze[me->r][me->c + 1] == ' ') {
		me->right = make_step(me->c + 1, me->r);
		if (go(me->right)) // idê w prawo
			return 1; // wszed³em na STOP
	}

	// niczego nie znalaz³em, cofamy siê
	maze[me->r][me->c] = ' '; // wycofujemy siê
	return 0; // wracam jedno pole, bo nie znalaz³em STOPU
}

void maze_solve(const char* file_name, int size)
{
	// wczytaj labirynt
	maze_read(file_name, size);

	// ustal punkt startowy
	step_t* pstart = make_step(start_col, start_row);

	// idŸ na start
	int result = go(pstart);

	// ustaw ponownie a i b, bo zosta³y zamazne w trakcie zabawy
	maze[start_row][start_col] = 'a';
	maze[stop_row][stop_col] = 'b';

	// wyœwietl labirynt z tras¹
	maze_show(size);
}