//Definitions
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

// Functions
void mergeSort(int arr[], int l, int r) {
	if (l >= r) {
		return;//returns recursively
	}
	int m = l + (r - l) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

void merge(int arr[], int l, int m, int r)
{
	int n11 = m - l + 1;
	int n22 = r - m;

	const int n1 = n11;
	const int n2 = n22;

	// Create temp arrays
	int* L = new int[n1];
	int* R = new int[n2];

	// Copy data to temp arrays L[] and R[]
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back into arr[l..r]

	// Initial index of first subarray
	int i = 0;

	// Initial index of second subarray
	int j = 0;

	// Initial index of merged subarray
	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of
	// L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
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
