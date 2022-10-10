// include system liblaries
#include <iostream>
//#include <assert.h>
#include <cstdlib>
#include <string>

// include main liblaries
#include "sorting.h"
#include "mazerunner.h"
#include "utils.h"
#include "constans.h"

// include exercises
#include "../unit1/1.1.h"
#include "../unit1/1.2.h"
#include "../unit1/1.3.h"
#include "../unit1/1.4.h"
#include "../unit1/1.5.h"
#include "../unit1/1.6.h"
#include "../unit1/1.7.h"
using namespace std;

void excercises_01() {
	int option;
	cout << "Select excercises: (1-7)" << endl;
	cin >> option;
	
	switch (option)
	{
		case 1:
			excercise0101_main();
			break;
		case 2:
			excercise0102_main();
			break;
		case 3:
			excercise0103_main();
			break;
		case 4:
			excercise0104_main();
			break;
		case 5:
			excercise0105_main();
			break;
		case 6:
			excercise0106_main();
			break;
		case 7:
			excercise0107_main();
			break;
		default:
			break;
	}
}

int main()
{
	excercises_01();

	int n;
	do
	{
		cout << main_label << endl;
		cout << select_label << endl;
		cout << maze_label << endl;
		cout << bubble_label << endl;
		cout << insertion_label << endl;
		cout << merge_label << endl;
		cout << exit_label << endl;
		cin >> n;
		int *tab3 = (int*)malloc(sizeof(int) * 5);
		switch (n)
		{
		case 1:
			maze_solve("C:\\Users\\pa-wo\\source\\repos\\MazeRunner\\Labirynth.txt", 29);
			break;
		case 2:
			cout << sort_elements << endl;
			tab3[0] = 1;
			tab3[1] = 5;
			tab3[2] = 3;
			tab3 = sortowanie_b(tab3, 3);
			for (int i = 0; i < 3; i++) cout << tab3[i] << endl;
			break;
		case 3:
			cout << sort_elements << endl;
			tab3[0] = 1;
			tab3[1] = 5;
			tab3[2] = 3;
			tab3 = sortowanie_w(tab3, 3);
			for (int i = 0; i < 3; i++) cout << tab3[i] << endl;
			break;
		case 4:
			cout << sort_elements << endl;
			tab3[0] = 1;
			tab3[1] = 5;
			tab3[2] = 3;
			mergeSort(tab3, 0, 3-1);
			printArray(tab3, 3);
			break;
		case 5:
			cout << exit_program_label << endl;
			break;
		default:
			break;
		}
	} while (n != 5);

	return 0;
}