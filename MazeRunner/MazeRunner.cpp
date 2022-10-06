
#include <iostream>
#include <assert.h>
#include <cstdlib>
#include <string>
#include "sorting.h"
#include "mazerunner.h"
#include "utils.h"
#include "constans.h"
using namespace std;

int main()
{
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