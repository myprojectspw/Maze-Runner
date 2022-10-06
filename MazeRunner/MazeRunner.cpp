
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include "Sorting.h"
using namespace std;

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
			if (maze[r][c] == 'a') { // znalazłem start
				start_row = r;
				start_col = c;
			}
			if (maze[r][c] == 'b') { // znalazłem stop
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

	// czy stanąłem w wyjściu?
	if (me->r == stop_row && me->c == stop_col)
		return 1; // tak! wracam natychmiat do punktu startowego, bo znam już drogę. Droga jest oznaczona 'x' w mapie

	maze[me->r][me->c] = '+'; // oznacz miejsce, w którym byłem

	// czy mogę iść w górę?
	if (maze[me->r - 1][me->c] == ' ') {
		me->up = make_step(me->c, me->r - 1);
		if (go(me->up)) // idę do góry
			return 1; // wszedłem na STOP
	}

	// czy moge iśc w lewo?
	if (maze[me->r][me->c - 1] == ' ') {
		me->left = make_step(me->c - 1, me->r);
		if (go(me->left)) // no to idę w lewo
			return 1; // wpadłem na STOP
	}

	// czy mogę iść w dół
	if (maze[me->r + 1][me->c] == ' ') {
		me->down = make_step(me->c, me->r + 1);
		if (go(me->down)) // idę w dół
			return 1; // wpadłem na STOP
	}

	// czy mogę iść w prawo?
	if (maze[me->r][me->c + 1] == ' ') {
		me->right = make_step(me->c + 1, me->r);
		if (go(me->right)) // idę w prawo
			return 1; // wszedłem na STOP
	}

	// niczego nie znalazłem, cofamy się
	maze[me->r][me->c] = ' '; // wycofujemy się
	return 0; // wracam jedno pole, bo nie znalazłem STOPU
}

void maze_solve(const char* file_name, int size)
{
	// wczytaj labirynt
	maze_read(file_name, size);

	// ustal punkt startowy
	step_t* pstart = make_step(start_col, start_row);

	// idź na start
	int result = go(pstart);

	// ustaw ponownie a i b, bo zostały zamazne w trakcie zabawy
	maze[start_row][start_col] = 'a';
	maze[stop_row][stop_col] = 'b';

	// wyświetl labirynt z trasą
	maze_show(size);
}
//Bubble sort 
int* sortowanie_b(int tab[], int n)
{
	int aa, p;
	int N = n - 1;
	do
	{
		p = 0;
		for (int i = 0; i < N; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				aa = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aa;
				p = 1;
			}
		}
	} while (p != 0);
	return tab;
}

//Insertion sort
int* sortowanie_w(int tab[], int n)
{
	int pom, i, j;
	int N = n;
	
	for (i = 1; i < N; i++)
	{
		pom = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > pom)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = pom;
	}
	return tab;
}

void selection_sort(int tab[], int n) //n - ilość elementów do posortowania
{
	int mn_index; //zmienna pomocnicza przechowująca indeks komórki 
			//z minimalną wartością
	for (int i = 0; i < n - 1; i++)
	{
		mn_index = i;
		for (int j = i + 1; j < n; j++) //pętla wyszukuje najmniejszy element w podzbiorze nieposortowanym
			if (tab[j] < tab[mn_index])
				mn_index = j;

		//zamiana elementu najmniejszego w podzbiorze z pierwszą pozycją nieposortowaną
		swap(tab[i], tab[mn_index]);
	}
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
}

int main()
{
	// możliwość podania nazwy pliku oraz wielkości labiryntu
	int n;
	do
	{
		cout << "\nWelcome to algorithm projects\n" << endl;
		cout << "Select operation: \n" << endl;
		cout << "1 -- Maze Runner Algorithm\n" << endl;
		cout << "2 -- Boubble sort\n" << endl;
		cout << "3 -- Insertion sort\n" << endl;
		cout << "4 -- Merge Sort\n" << endl;
		cout << "5 -- Selection Sort\n" << endl;
		cout << "6 -- Exit from project\n" << endl;
		cin >> n;
		int *tab3 = (int*)malloc(sizeof(int) * 5);
		switch (n)
		{
		case 1:
			maze_solve("C:\\Users\\pa-wo\\source\\repos\\MazeRunner\\Labirynth.txt", 29);
			break;
		case 2:
			cout << "Sort elements: " << endl;
			tab3[0] = 1;
			tab3[1] = 5;
			tab3[2] = 3;
			tab3 = sortowanie_b(tab3, 3);
			for (int i = 0; i < 3; i++) cout << tab3[i] << endl;
			break;
		case 3:
			cout << "Sort elements: " << endl;
			tab3[0] = 1;
			tab3[1] = 5;
			tab3[2] = 3;
			tab3 = sortowanie_w(tab3, 3);
			for (int i = 0; i < 3; i++) cout << tab3[i] << endl;
			break;
		case 4:
			cout << "Merge elements: " << endl;
			tab3[0] = 1;
			tab3[1] = 5;
			tab3[2] = 3;
			mergeSort(tab3, 0, 3-1);
			printArray(tab3, 3);
			break;
		case 5:
			cout << "Selection sort" << endl;
			tab3[0] = 1;
			tab3[1] = 5;
			tab3[2] = 3;
			selection_sort(tab3, 3);
			printArray(tab3, 3);
			break;
		default:
			cout << "Error" << endl;
			break;
		}
	} while (n != 6);

	return 0;
}